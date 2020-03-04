#include <stdio.h>

int main() {
    int s, x;
    float total = 7, first = 7;
    scanf("%d %d", &s, &x);
    while (total <= s - x) {
        first *= 0.98;
        total += first;
    }
    if (total == 7) {
        if (total > s + x) {
            printf("n");
        } else {
            printf("y");
        }
    } else {
        if(total + first * 0.98 > s + x ) {
            printf("n");
        } else {
        printf("y");
        }
    }
    return 0;
}