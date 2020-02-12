#include <stdio.h>

int main() {
	int n, temp, total = 0;
	int N[10000];
	scanf("%d", &n);
	for(int i = 0; i < n; i ++) {
		scanf("%d", &N[i]);
	}
	for(int i = 0; i < n - 1; i ++) {
		for(int j = i + 1; j < n; j ++) {
			if(N[j] < N[i]) {
				temp = N[j];
				N[j] = N[i];
				N[i] = temp;
				total ++;
			}
		}
	}
	printf("%d", total);
	return 0;
} 
