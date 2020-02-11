#include <stdio.h>
#include <math.h>

#define A 10000

int Is_prime(long sum);

int main() {
    int n, k, t = -1, total = 0;
    long x[20];
    long sum[A];
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i ++) {
        scanf("%ld", &x[i]);
    }
    for(int i = 0; i < k - 2; i ++) {
        for(int j = i + 1; j < k - 1; k ++ ) {
            for(int m = j + 1; m < k; m ++ ) {
                t ++;
                sum[t] = x[i] + x[j] + x[m];
            }
        }
    }
    for(int i = 0; i < t; i ++) {
        if(Is_prime(sum[i])) {
            total ++;
        }
    }
    printf("%d", total);
    return 0;
}

int Is_prime(long sum) {
    for(int a = 2; a <= fabs(sqrt(sum)); a ++) {
        if(sum % a == 0) {
            return 0;       
        }
    }
    return 1;
}
