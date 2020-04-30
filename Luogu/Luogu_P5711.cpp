#include <stdio.h>

int main() {
    int m;
    scanf("%d", &m);
    if(m % 4 == 0 && m % 100 != 0) {
        printf("1");
    } else if(m % 400 == 0) {
        printf("1");
    } else {
        printf("0");
    }
    return 0;
}