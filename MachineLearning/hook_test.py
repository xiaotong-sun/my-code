import torch
import torch.nn as nn
import torch.nn.functional as F
import matplotlib.pyplot as plt
from torchvision import transforms



class LeNet(nn.Module):
    def __init__(self):
        super(LeNet, self).__init__()
        self.conv1 = nn.Conv2d(3, 6, 5)
        self.conv2 = nn.Conv2d(6, 16, 5)
        self.fc1 = nn.Linear(16 * 5 * 5, 120)
        self.fc2 = nn.Linear(120, 84)
        self.fc3 = nn.Linear(84, 10)

    def forward(self, x):
        out = F.relu(self.conv1(x))  # 1
        out = F.max_pool2d(out, 2)  # 2
        out = F.relu(self.conv2(out))  # 3
        out = F.max_pool2d(out, 2)
        out = out.view(out.size(0), -1)
        out = F.relu(self.fc1(out))
        out = F.relu(self.fc2(out))
        out = self.fc3(out)
        return out


features = []


def hook(module, input, output):
    # module: model.conv2
    # input :in forward function  [#2]
    # output:is  [#3 self.conv2(out)]
    features.append(output.clone().detach())
    # output is saved  in a list


net = LeNet()  ## 模型实例化
x = torch.randn(1, 3, 32, 32)  ## input
handle = net.conv2.register_forward_hook(hook)  ## 获取整个Lenet模型 conv2的中间结果
y = net(x)  ## 获取的是 关于 input x 的 conv2 结果


toPIL = transforms.ToPILImage() #这个函数可以将张量转为PIL图片，由小数转为0-255之间的像素值
img = features[0][0][1]
plt.imshow(toPIL(img))
plt.show()
# plt.imshow(features[0].detach().numpy(), cmap='hot')
print(features[0].size())  # 即 [#3 self.conv2(out)]
handle.remove()  ## hook删除