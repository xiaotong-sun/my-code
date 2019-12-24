#include <stdio.h>

int is_valid_hundreds_digit(int num);
int is_hundreds(int num);
int has_different_digits(int num);

int main()
{
	int num, _double, triple;
	for (int ones = 1; ones < 10; ones++) {
		for (int tens = 1; tens < 10; tens++) {
			if (ones == tens) {
				continue;
			} else {
				for (int hundreds = 1; hundreds < 10; hundreds++) {
					if (ones == hundreds || tens == hundreds) {
						continue;
					} else {
						num = ones * 100 + tens * 10 + hundreds; // Get a three-digit number that is different for each digit.
						_double = num * 2;
						triple = num * 3;             // Get three numbers in the ratio of 1:2:3
						if (is_valid_hundreds_digit(_double) && is_valid_hundreds_digit(triple)) {
							// Output everything in ascending order.
							printf("%d %d %d\n", num, _double, triple);
						} else {
							continue;
						}
					}
				}
			}
		}
	}
	return 0;
 } 
 
 int is_valid_hundreds_digit(int num)
 {
 	if (is_hundreds(num) && has_different_digits(num)) {
 		return 1;
	}
	return 0;
 }
 
 int is_hundreds(int num)
 {
 	if (num < 1000) {
 		return 1;
	}
	return 0;
 }
 
 int has_different_digits(int num)
 {
 	if (num % 10 != num / 10 % 10
		&& num % 10 != num / 100
		&& num / 10 % 10 != num / 100) {
		return 1;
	}
	return 0;
 }
