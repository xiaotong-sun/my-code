# 输入数据
def read(majorNum, list0, list1, majorList):
    for i in range(majorNum):
        major = input('专业：')
        majorList.append(major)
        studentNum = int(input('人数：'))
        list0.append(studentNum)
        for j in range(studentNum):
            studentID = int(input("学号："))
            name = input("姓名：")
            treeNum = int(input("植树数量："))
            list2 = [major, studentID, name, treeNum]
            list1.append(list2)


def output1(majorNum, list0, list1, majorList):
    temp = 0
    for i in range(majorNum):
        print(majorList[i] + ":")
        for j in range(list0[i]):
            print(str(list1[temp + j][1]) + "\t" + list1[temp + j][2] + "\t" + str(list1[temp + j][3]))
        temp += list0[i]


def output2(list0, list1):
    temp = 0
    for i in list0:
        temp += i
    for j in range(temp):
        print(list1[j][0] + "\t" + str(list1[j][1]) + "\t" + list1[j][2] + "\t" + str(list1[j][3]))


def MergeSort(lists):
    if len(lists) <= 1:
        return lists
    num = int(len(lists) / 2)
    left = MergeSort(lists[:num])
    right = MergeSort(lists[num:])
    return Merge(left, right)


def Merge(left, right):
    r, l = 0, 0
    result = []
    while l < len(left) and r < len(right):
        if left[l][3] <= right[r][3]:
            result.append(left[l])
            l += 1
        else:
            result.append(right[r])
            r += 1
    result += left[l:]
    result += right[r:]
    return result


def main():
    list0 = []  # 记录每个专业的学生人数
    list1 = []  # 存放汇总出来的总表
    majorList = []  # 记录每个专业的名字
    majorNum = int(input("专业数："))
    read(majorNum, list0, list1, majorList)
    print("未排序前：")
    output1(majorNum, list0, list1, majorList)
    result = MergeSort(list1)
    print("排序后的输出：")
    print("专业\t\t学号\t姓名\t植树数量")
    output2(list0, result)


main()
