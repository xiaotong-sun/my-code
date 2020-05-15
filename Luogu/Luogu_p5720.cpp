#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, count = 1;
    scanf("%d", &a);
    while(a != 1) {
        a /= 2;
        count ++;
    }
    printf("%d", count);
    system("pause");
}