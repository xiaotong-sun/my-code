 #include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, c;
    int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    scanf("%d %d", &a, &b);
    if((a % 4 == 0 && a % 100 != 0) || a % 400 == 0) {
        if(b == 2) {
            c = day[1] + 1;
        } else {
            c = day[b -1];
        }
    } else {
        c = day[b - 1];
    }
    printf("%d", c);
    system("pause");
    return 0;
}