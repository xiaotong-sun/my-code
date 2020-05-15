#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, a = 1;
    scanf("%d", &n);
    while(n != 0) {
        for(int i = 1; i <= n; i ++) {
            printf("%02d", a);
            a ++;
        }
        printf("\n");
        n --;
    }
    system("pause");
}
    