#include <stdio.h>

int main() {
    unsigned long long n, m;
    scanf("%lld", &n);
    if (n <= 3) {
        printf("0");
    } else {
        m = n * (n-1) / 2 * (n-2) / 3 * (n-3) / 4;
        printf("%lld", m);
    }
    scanf("%lld", &n);
}