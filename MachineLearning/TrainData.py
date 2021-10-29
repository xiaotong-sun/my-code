import torch
import torchvision
import torchvision.transforms as transforms
import ssl
import matplotlib.pyplot as plt
import numpy as np
import torch.nn as nn
import torch.nn.functional as F
import torch.optim as optim

#-----------------------------------
# Show some of the training images.
def imshow(img):
    img = img / 2 + 0.5
    npimg = img.numpy()
    plt.imshow(np.transpose(npimg, (1, 2, 0)))
    plt.show()

#----------------------------------------
# Define a Convolutional Neural Network
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

if __name__ == '__main__':
    # -----------------------------------
    # Download the CIFAR10 dataset
    # In this dataset we have 60000 images,
    # in which 50000 images are training set and 10000 images are test set
    ssl._create_default_https_context = ssl._create_unverified_context
    transform = transforms.Compose(
        [transforms.ToTensor(),
         transforms.Normalize((0.5, 0.5, 0.5), (0.5, 0.5, 0.5))]
    )

    batch_size = 8

    trainset = torchvision.datasets.CIFAR10(root='F:\CNN\data', train=True, download=True, transform=transform)
    trainloader = torch.utils.data.DataLoader(trainset, batch_size=batch_size, shuffle=True, num_workers=2)
    testset = torchvision.datasets.CIFAR10(root='F:\CNN\data', train=False, download=True, transform=transform)
    testloader = torch.utils.data.DataLoader(testset, batch_size=batch_size, shuffle=False, num_workers=2)

    classes = ('plane', 'car', 'bird', 'cat', 'deer', 'dog', 'frog', 'horse', 'ship', 'truck')

    # # -----------------------------------
    # # Show some of the training images.
    # dataiter = iter(trainloader)  # get some random training images
    # images, labels = dataiter.next()
    # print(images.size())
    # imshow(torchvision.utils.make_grid(images))
    # print(' '.join('%5s' % classes[labels[j]] for j in range(batch_size)))

    # ----------------------------------------
    # Define a Convolutional Neural Network
    net = Net()
    print(net)
    device = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")
    net.to(device)
    print(device)
    #--------------------------------------
    #Define a Loss function and optimizer
    criterion = nn.CrossEntropyLoss()
    optimizer = optim.SGD(net.parameters(), lr=0.001, momentum=0.9)

    #------------------
    #Train the network
    Loss_temp = []
    Train_times = 50
    for epoch in range(Train_times):  # loop over the dataset multiple times
        running_loss = 0.0
        for i, data in enumerate(trainloader, 0):
            # get the inputs; data is a list of [inputs, labels]
            inputs, labels = data[0].to(device), data[1].to(device)

            # zero the parameter gradients
            optimizer.zero_grad()

            # forward + backward + optimize
            outputs = net(inputs)
            loss = criterion(outputs, labels)
            loss.backward()
            optimizer.step()

            # print statistics
            running_loss += loss.item()
            if i % 1000 == 999:    # print every 2000 mini-batches
                print('[%d, %5d]' % (epoch + 1, i + 1))
        Loss_temp.append(running_loss / 6250)

    # Draw a line chart
    x = [i for i in range(1, Train_times + 1)]
    plt.plot(x, Loss_temp, 'o-', color='g', label="损失函数变化曲线")  # o-:圆形
    plt.xlabel("epoch")  # 横坐标名字
    plt.ylabel("LOSS")  # 纵坐标名字
    plt.savefig('F:\CNN\LossFunction.jpg')
    plt.show()


    PATH = 'F:\CNN\cifar_net.pth'
    torch.save(net.state_dict(), PATH)
    print('Finished Training')

