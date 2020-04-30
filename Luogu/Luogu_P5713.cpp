#include <stdio.h>

int main() {
    int m;
    scanf("%d", &m);
    if(5 * m < 11 + 3 * m) {
        printf("Local");
    } else {
            printf("Luogu");
    }
}