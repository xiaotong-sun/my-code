#include <stdio.h>

int main() {
    int m;
    scanf("%d", &m);
    if(m == 1 || m == 0) {
        printf("Today, I ate %d apple.", m);
    } else if(m > 1) {
        printf("Today, I ate %d apples.", m);
    }
}