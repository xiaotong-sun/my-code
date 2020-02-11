#include <stdio.h>

void deal_with_data(int i, char a[51], int n);

int main() {
    int n;
    char before[51];
    scanf("%d", &n);
    scanf("%s", before);
    for(int i = 0; before[i] != '\0'; i ++) {
        deal_with_data(i, before, n);
    }
    printf("%s", before);
    return 0;
}

void deal_with_data(int i, char a[51], int n) {
    if(a[i] + n <= 122) {
        a[i] = a[i] + n;
    } else {
        a[i] = a[i] + n - 26;
       while(a[i] >122) {
            a[i] = a[i] -26;
        }
    }
}