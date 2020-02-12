#include <stdio.h>

#define A 100000

int main() {
	long n;
	long long total = 0;
	long a[A];
	scanf("%d", &n);
	for(int i = 0; i < n; i ++) {
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n - 1; i ++) {
		if(a[i] > a[i + 1]) {
			total += a[i];
		} else {
			total += a[i +1];
		}
	}
	printf("%lld", total);
	return 0;
}
