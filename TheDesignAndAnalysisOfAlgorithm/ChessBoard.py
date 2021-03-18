def ChessBoard(tr, tc, dr, dc, size, Board):
    if size == 1:
        return
    s = size // 2
    # 覆盖左上角棋盘
    if dr < tr + s and dc < tc + s:
        ChessBoard(tr, tc, dr, dc, s, Board)
    # 如果特殊棋盘不在左上角而在右下角，则将子棋盘的右下角设为4号
    elif dr >= tr + s and dc >= tc + s:
        Board[tr + s - 1][tc + s - 1] = 4
        ChessBoard(tr, tc, tr + s - 1, tc + s - 1, s, Board)
    # 如果特殊棋盘不在左上角且不在右下角，则将子棋盘的右下角设为0
    else:
        Board[tr + s - 1][tc + s - 1] = 0
        ChessBoard(tr, tc, tr + s - 1, tc + s - 1, s, Board)
    # 覆盖右上角棋盘
    if dr < tr + s and dc >= tc + s:
        ChessBoard(tr, tc + s, dr, dc, s, Board)
    # 如果特殊棋盘不在右上角而在左下角，则将子棋盘的左下角设为2号
    elif dr >= tr + s and dc < tc + s:
        Board[tr + s - 1][tc + s] = 2
        ChessBoard(tr, tc + s, tr + s - 1, tc + s, s, Board)
    # 如果特殊棋盘不在右上角且不在左下角，则将子棋盘的右下角设为0
    else:
        Board[tr + s - 1][tc + s] = 0
        ChessBoard(tr, tc + s, tr + s - 1, tc + s, s, Board)
    # 覆盖左下角棋盘
    if dr >= tr + s and dc < tc + s:
        ChessBoard(tr + s, tc, dr, dc, s, Board)
    # 如果特殊棋盘不在左下角而在右上角，则将子棋盘的右上角设为1号
    elif dr < tr + s and dc >= tc + s:
        Board[tr + s][tc + s - 1] = 1
        ChessBoard(tr + s, tc, tr + s, tc + s - 1, s, Board)
    # 如果特殊棋盘不在左上角且不在右下角，则将子棋盘的右下角设为0
    else:
        Board[tr + s][tc + s - 1] = 0
        ChessBoard(tr + s, tc, tr + s, tc + s - 1, s, Board)
    # 覆盖右下角棋盘
    if dr >= tr + s and dc >= tc + s:
        ChessBoard(tr + s, tc + s, dr, dc, s, Board)
    # 如果特殊棋盘不在右下角而在左上角，则将子棋盘的左上角设为3号
    elif dr < tr + s and dc < tc + s:
        Board[tr + s][tc + s] = 3
        ChessBoard(tr + s, tc + s, tr + s, tc + s, s, Board)
    # 如果特殊棋盘不在左上角且不在右下角，则将子棋盘的右下角设为0
    else:
        Board[tr + s][tc + s] = 0
        ChessBoard(tr + s, tc + s, tr + s, tc + s, s, Board)


def InitBoard(k, dr, dc, Board):
    for i in range(2 ** k):
        a = []
        for j in range(2 ** k):
            a.append(0)
        Board.append(a)
    Board[dr][dc] = 'A'


def PrintBoard(k, Board):
    for i in range(2 ** k):
        for j in range(2 ** k):
            if Board[i][j] != 0 and Board[i][j] != 'A':
                print('{}\t{}\t{}' .format(i, j, Board[i][j]))


def main():
    Board = []
    k = int(input())
    dr = int(input())
    dc = int(input())
    InitBoard(k, dr, dc, Board)
    ChessBoard(0, 0, dr, dc, 2 ** k, Board)
    PrintBoard(k, Board)


main()