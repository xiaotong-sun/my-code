#include <stdio.h>

int main() {
    int m;
    scanf("%d", &m);
    if(m % 2 == 0 && m > 4 && m <= 12) {
        printf("1");
    } else {
        printf("0");
    }
    if(m % 2 == 0 || (m > 4 && m <= 12)) {
        printf(" 1");
    } else {
        printf(" 0");
    }
    if(m % 2 == 0 && (m <= 4 || m > 12)) {
        printf(" 1");
    } else if(m % 2 != 0 && m > 4 && m <= 12) {
        printf(" 1");
    } else {
        printf(" 0");
    }
    if(m % 2 == 0 || (m > 4 && m <= 12)) {
        printf(" 0");
    } else {
        printf(" 1");
    }
    return 0;
}