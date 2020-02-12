#include <stdio.h>
#include <math.h>

#define A 10000

int Is_prime(long sum);
void deal_with_data(long sum[A], long x[20]);

int main() {
    int n, k, t = -1, total = 0;
    long x[20];
    long sum[A];
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i ++) {
        scanf("%ld", &x[i]);
    }
    deal_with_data(sum, x);
    for(int i = 0; i < t; i ++) {
        if(Is_prime(sum[i])) {
            total ++;
        }
    }
    printf("%d", total);
    return 0;
}

void deal_with_data(long sum[A], long x[20]) {
	
}

int Is_prime(long sum) {
    for(int a = 2; a <= fabs(sqrt(sum)); a ++) {
        if(sum % a == 0) {
            return 0;       
        }
    }
    return 1;
}
