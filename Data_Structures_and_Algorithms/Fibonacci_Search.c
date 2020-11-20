// Fibonacci_Search.c

#include <stdio.h>

#define MAX_SIZE 20
#define MAX 100

// ----构造斐波那契数列-----
void Fibonacci(int *F) {
    F[0] = 0;
    F[1] = 1;
    for (int i = 2; i < MAX_SIZE; ++i) {
        F[i] = F[i - 1] + F[i - 2];
    }
}

//----斐波那契查找算法------
int Fibonacci_Search(int *a, int n, int key) {     //a为需要查找的数组，n为a的长度，key为要查找的数
    int F[MAX_SIZE];
    Fibonacci(F);
    int u = 0;
    while (n > F[u]) {						//计算n位于斐波那契数列的位置
        u ++;
    }
    for (int i = n; i < F[u] - 1; ++i) {	//如果n < F[u] - 1,则用数组最后一个数补位，直到n = F[u] -1
        a[i + 1] = a[i];
    }
    int low = 1;
    int high = n;
    while (low <= high) {
        int mid = low + F[u - 1] - 1;
        if (mid > n && a[n] == key) {		//若mid>=n则说明是扩展的数值,返回n
            return n;
        } else if (mid > n){
            return -2;						//查找的数据不存在
        }
        if (key == a[mid]) {
            return mid;
        } else if (key > a[mid]) {
            low = mid + 1;
            u -= 2;
        } else if (key < a[mid]) {
            high = mid - 1;
            u--;
        }
    }
    return -2; 								//查找的数据不存在
}

int main() {
    int F[MAX_SIZE];
    Fibonacci(F);
    int a[MAX];
    int n;
    printf("请输入数据的个数：");
    scanf("%d", &n);
    printf("请输入数据：\n");
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    int key;
    printf("请输入要查找的数据：");
    scanf("%d", &key);
    int answer = Fibonacci_Search(a, n, key);
    printf("数据位于第%d项\n", answer);
    return 0;
}