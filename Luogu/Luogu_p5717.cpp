#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(a + b <= c || a + c <= b || b + c <= a) {
        printf("Not triangle\n");
    } else {
        if(a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) {
            printf("Right triangle\n");
        } else if(a * a + b * b > c * c && a * a + c * c > b * b && b * b + c * c > a * a) {
            printf("Acute triangle\n");
        } else {
            printf("Obtuse triangle\n");
        }
        if(a == b || b == c || a == c) {
            printf("Isosceles triangle\n");
        }
        if(a == b && a == c) {
            printf("Equilateral triangle\n");
        }
    }
    system("pause");
    return 0;
}