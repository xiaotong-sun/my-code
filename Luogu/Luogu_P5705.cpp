#include <stdio.h>

int main() {
    float a;
    int b[4];
    scanf("%f", &a);
    a = a * 10;
    for(int i = 0; i < 4; i ++) {
        b[i] = (int)a % 10;
        a = a / 10;
    }
    printf("%d.", b[0]);
    for(int i = 1; i < 4; i ++) {
        printf("%d", b[i]); 
    }
    return 0;
}
