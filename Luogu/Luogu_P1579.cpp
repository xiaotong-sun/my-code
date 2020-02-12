#include <stdio.h>
#include <math.h>

int is_prime(int i);

int main() {
    int n, a, b, c;
    scanf("%d", &n);
    for(int i = 2; i < n; i ++ ) {
        if(is_prime(i)) {
            for(int j = 2; j < n; j ++) {
                if(is_prime(j)) {
                    for(int k = 2; k < n; k ++) {
                        if(is_prime(k)) {
                            if(i + j + k == n) {
                                printf("%d %d %d", i, j, k);
                                goto Flag;
                            }
                        }
                    }
                }
            }
        }
    }
    Flag: ;
    return 0;
}

int is_prime(int i) {
    if(i == 2) {
        return 1;
    }
    for(int j = 2; j <= fabs(sqrt(i)); j ++) {
        if(i % j == 0) {
            return 0;
        }
    }
    return 1;
}