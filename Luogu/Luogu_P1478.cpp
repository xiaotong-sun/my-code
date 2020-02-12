#include <stdio.h>

int main() {
    int n, s;                               // n:number of apple  s: strength
    int a, b;                              // a: height of chair  b: max hight can reach
    int x[5000], y[5000];         // x[i]: height of each apple  y[i]: strength of each apple need
    int total = 0, temp;
    scanf("%d%d", &n, &s);
    scanf("%d%d", &a, &b);
    for(int i = 0; i < n; i ++) {
        scanf("%d", &x[i]);
        scanf("%d", &y[i]);
    }
    /*input data*/
    for(int i = 0; i < n - 1; i ++) {
        for(int j = i + 1; j < n; j ++) {
            if(y[i] > y[j]) {                // sort in strength!!!!!!
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
                temp = y[i];
                y[i] = y[j];
                y[j] = temp;
            }
        }
    }
    for(int j = 0; j < n; j ++) {
        if( ( b >= x[j] && s >= y[j] ) || ( a + b >= x[j] && s >= y[j] ) ) {
            total ++;
            s -= y[j];
        }
    }
    printf("%d", total);
    /*deal with data*/
    return 0;
}