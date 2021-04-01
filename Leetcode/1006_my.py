def clumsy(N):
    array = []
    for i in range(N, 0, -1):
        array.append(i)
    left = N % 4
    total = 0
    totalArray = []
    for k in range(N // 4):
        a = array[0]
        b = array[1]
        c = array[2]
        d = array[3]
        if k == 0:
            total = a * b // c + d
        else:
            total = a * b // c - d
        totalArray.append(total)
        for i in range(4):
            array.pop(0)
    if len(array) == 3:
        a = array[0]
        b = array[1]
        c = array[2]
        total = a * b // c
        totalArray.append(total)
    elif len(array) == 2:
        a = array[0]
        b = array[1]
        total = a * b
        totalArray.append(total)
    elif len(array) == 1:
        totalArray.append(array[0])
    total = totalArray[0]
    for i in range(1, len(totalArray)):
        total = total - totalArray[i]
    return total


clumsy(4)