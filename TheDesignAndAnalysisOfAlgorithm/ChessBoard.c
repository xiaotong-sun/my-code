/*
这是一个关于“棋盘覆盖”问题的算法
*/
#include <stdio.h>

void ChessBoard(int tr, int tc, int dr, int dc, int size, int *title, int Board[][8]) {
    if (size == 1) {
        return;
    }
    int t = (*title) ++;
    int s = size / 2;
    // 覆盖左上角棋盘
    if (dr < tr + s && dc < tc + s) {   // 特殊方格在其中
        ChessBoard(tr, tc, dr, dc, s, title, Board);
    } else {
        Board[tr + s -1][tc + s - 1] = t; //特殊方格不在其中，将右下角补为特殊方格
        ChessBoard(tr,tc, tr + s - 1, tc + s - 1, s, title, Board);
    }
    // 覆盖右上角棋盘
    if (dr < tr + s && dc >= tc + s) {  // 特殊方格在其中
        ChessBoard(tr, tc + s, dr, dc, s, title, Board);
    } else {
        Board[tr + s -1][tc + s] = t; //特殊方格不在其中，将左下角补为特殊方格
        ChessBoard(tr, tc + s, tr + s - 1, tc + s, s, title, Board);
    }
    // 覆盖左下角棋盘
    if (dr >= tr + s && dc < tc + s) {  // 特殊方格在其中
        ChessBoard(tr + s, tc, dr, dc, s, title, Board);
    } else {
        Board[tr + s][tc + s - 1] = t; //特殊方格不在其中，将右上角补为特殊方格
        ChessBoard(tr + s, tc, tr + s, tc + s - 1, s, title, Board);
    }
    // 覆盖右下角棋盘
    if (dr >= tr + s && dc >= tc + s) { // 特殊方格在其中
        ChessBoard(tr + s, tc + s, dr, dc, s, title, Board);
    } else {
        Board[tr + s][tc + s] = t; //特殊方格不在其中，将左上角补为特殊方格
        ChessBoard(tr + s, tc + s, tr + s, tc + s, s, title, Board);
    }
}

int main() {
    int title = 1;
    int Board[8][8] = {0};
    int dr = 0; //特殊方格的位置
    int dc = 1;
    ChessBoard(0, 0, dr, dc, 8, &title, Board);
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            printf("%d\t", Board[i][j]);
        }
        printf("\n");
    }
    return 0;
}
