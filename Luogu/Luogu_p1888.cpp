#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    long long a, b, c;
    long long max, min;
    scanf("%lld %lld %lld", &a, &b, &c);
    max = a;
    min = a;
    if(max < b) {
        max = b;
    }
    if(max < c) {
        max = c;
    }
    if(min > b) {
        min = b;
    }
    if(min > c) {
        min = c;
    }
    for(int i = 1; i <= sqrt(min); i ++) {
        if(min % i == 0 && max % i == 0) {
            min /= i;
            max /= i;
        }
    }
    printf("%lld/%lld", min, max);
    system("pause");
    return 0;
}