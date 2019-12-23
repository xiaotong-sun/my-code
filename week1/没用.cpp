#include <stdio.h> 
int main()
{
	int num1, num2, num3;
	for(int i = 1; i < 10; i++) {
		for(int j = 1; j < 10; j++) {
			if(i == j) {
				continue;
			} else {
				for(int k = 1; k < 10; k++) {
					if(i == k || j == k) {
						continue;
					} else {
						num1 = i * 100 + j * 10 + k; // Get a three-digit number that is different for each digit.
						num2 = num1 * 2;
						num3 = num1 * 3;             // Get three numbers in the ratio of 1:2:3
						if(num2 % 10 == num2 / 10 % 10 
						|| num2 / 100 == num2 / 10 % 10 
						|| num2 % 10 ==  num2 / 100
						|| num3 % 10 == num3 / 10 % 10 
						|| num3 / 100 == num3 / 10 % 10 
						|| num3 % 10 ==  num3 / 100
						|| num3 >= 1000) {
							continue;
						} else {
							printf("%d %d %d\n", num1, num2, num3); // Output everything in ascending order.
						}
					}
				}
			}
		}
	}
	return 0;
 } 
