#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, a[100];
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) {
        scanf("%d", &a[i]);
    }
    int min = a[0];
    for(int i = 0; i < n; i ++) {
        if(min > a[i]) {
            min = a[i];
        }
    }
    printf("%d", min);
    system("pause");
    return 0;
}