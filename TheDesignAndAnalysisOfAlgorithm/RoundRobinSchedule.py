def InitBoard(n, Board):
    for i in range(n):
        a = []
        for j in range(n):
            a.append(0)
        Board.append(a)
    for i in range(n):
        Board[0][i] = i + 1


def SplitLeft(a, b, n, Board):
    if n == 0:
        return
    SplitLeft(a, (a + b - 1) // 2, n // 2, Board)
    SplitRight((a + b - 1) // 2 + 1, b, n // 2, Board)
    # 左上角复制到右下角
    for i in range(n):
        for j in range(a, b + 1):
            Board[i + n][j + n - 1] = Board[i][j - 1]


def SplitRight(a, b, n, Board):
    if n == 0:
        return
    SplitLeft(a, (a + b - 1) // 2, n // 2, Board)
    SplitRight((a + b - 1) // 2 + 1, b, n // 2, Board)
    # 右上角复制到左下角
    for i in range(n):
        for j in range(a, b + 1):
            Board[i + n][j - n - 1] = Board[i][j - 1]


def Print(n, Board):
    for i in range(n):
        for j in range(n):
            print(Board[i][j], end="\t")
        print()


def main():
    Board = []
    k = int(input("请输入k:"))
    n = 2 ** k
    InitBoard(n, Board)
    SplitLeft(1, n // 2, n // 2, Board)
    SplitRight(n // 2 + 1, n, n // 2, Board)
    Print(n, Board)


main()
