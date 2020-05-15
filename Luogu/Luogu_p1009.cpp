#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i ,j;
    unsigned long long S = 0;
    scanf("%lld", &n);
    if(n == 0) {
        printf("1");
    } else {
        for(i = 1; i <= n; i ++) {
        unsigned long long sum = 1;
        for(j = 1; j <= i; j ++) {
            sum *= j;
        }
            S += sum;
        }
        printf("%lld", S); 
    }
    system("pause");
}