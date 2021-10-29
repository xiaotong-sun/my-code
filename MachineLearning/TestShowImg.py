import torch
import torchvision
import torchvision.transforms as transforms
import ssl
import matplotlib.pyplot as plt
import numpy as np
import torch.nn as nn
import torch.nn.functional as F
import torch.optim as optim

def imshow(img, i):
    img = img / 2 + 0.5
    show = transforms.ToPILImage()  # 可以把Tensor转成Image，方便可视化
    url = 'F:\CNN\\' + str(i) + '.png'
    print(url)
    show(img).save(url)

ssl._create_default_https_context = ssl._create_unverified_context
transform = transforms.Compose(
    [transforms.ToTensor(),
     transforms.Normalize((0.5, 0.5, 0.5), (0.5, 0.5, 0.5))]
)

batch_size = 1

trainset = torchvision.datasets.CIFAR10(root = 'F:\CNN\data', train = True, download = True, transform = transform)
trainloader = torch.utils.data.DataLoader(trainset, batch_size = batch_size, shuffle =True, num_workers = 0)
testset = torchvision.datasets.CIFAR10(root = 'F:\CNN\data', train = False, download = True, transform = transform)
testloader = torch.utils.data.DataLoader(testset, batch_size = batch_size, shuffle = True, num_workers = 0)

classes = ('plane', 'car', 'bird', 'cat', 'deer', 'dog', 'frog', 'horse', 'ship', 'truck')

class Net(nn.Module):
    def __init__(self):
        super(Net, self).__init__()
        self.conv1 = nn.Conv2d(3, 6, 5)
        self.pool = nn.MaxPool2d(2, 2)
        self.conv2 = nn.Conv2d(6, 16, 5)
        self.fc1 = nn.Linear(16 * 5 * 5, 120)
        self.fc2 = nn.Linear(120, 84)
        self.fc3 = nn.Linear(84, 10)

    def forward(self, x):
        x = self.pool(F.relu(self.conv1(x)))
        x = self.pool(F.relu(self.conv2(x)))
        x = torch.flatten(x,1)
        x = F.relu(self.fc1(x))
        x = F.relu(self.fc2(x))
        x = self.fc3(x)
        return x

features = []

def hook(module, input, output):
    # module: model.conv2
    # input :in forward function  [#2]
    # output:is  [#3 self.conv2(out)]
    features.append(output.clone().detach())
    # output is saved  in a list

dataiter = iter(testloader)
images, labels = dataiter.next()
print(images.size())
# print images
imshow(images[0], 0)
print('GroundTruth: ', ' '.join('%5s' % classes[labels[j]] for j in range(1)))

net = Net()
PATH = 'F:\CNN\cifar_net.pth'
# device = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")
# net.to(device)
net.load_state_dict(torch.load(PATH))
handle = net.conv1.register_forward_hook(hook)  ## 获取整个Lenet模型 conv2的中间结果
handle2 = net.conv2.register_forward_hook(hook)
# images = images.to(device)
outputs = net(images)

_, predicted = torch.max(outputs, 1)
print('Predicted: ', ' '.join('%5s' % classes[predicted[j]] for j in range(1)))

for i in range(6):
    imshow(features[0][0][i], i + 1)
for i in range(16):
    imshow(features[1][0][i], i + 7)
# print(features[0].size())  # 即 [#3 self.conv2(out)]
handle.remove()  ## hook删除
handle2.remove()  ## hook删除