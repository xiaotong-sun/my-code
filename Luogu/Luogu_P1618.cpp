#include <stdio.h>

int is_valid_hundreds_digit(int ones, int num, int arry[],int A,int B,int C);
int is_hundreds(int num);
int has_different_digits(int num);
int has_no_zero(int num);
int have_no_repeat_number(int ones, int num, int arry[],int A,int B,int C);

int main()
{
	int num, _double, triple, arry[6];
	int A, B, C;
	int Flag = 1;
	scanf("%d%d%d", &A, &B, &C) ;
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
						arry[0] = ones;
						arry[1] = tens;
						arry[2] = hundreds;
						if(num * B % A != 0) {
							continue;
						} else {
							_double = num * B / A;
						}
						arry[3] = _double % 10;
						arry[4] = _double / 10 % 10;
						arry[5] = _double / 100;
						if(num * C % A != 0) {
							continue;
						} else {
								triple = num * C / A;             // Get three numbers in the ratio of 1:2:3
						}
						if (is_valid_hundreds_digit(num, _double, arry, A, B, C) && is_valid_hundreds_digit(num, triple, arry, A, B, C)) {
							// Output everything in ascending order.
							Flag = 0;
							printf("%d %d %d\n", num, _double, triple);
						} else {
							continue;
						}
					}
				}
			}
		}
	}
	if(Flag) {
		printf("No!!!");
	}
	return 0;
} 

int is_valid_hundreds_digit(int ones, int num, int arry[],int A,int B,int C)
{
 	if (is_hundreds(num) 
	 	&& has_different_digits(num) 
		&& has_no_zero(num) 
		&& have_no_repeat_number(ones, num, arry, A, B, C)) {
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
 
int has_no_zero(int num)
{
	if (num % 10 != 0 && num / 10 % 10 != 0) {
		return 1;
	}
	return 0;
}
 
int have_no_repeat_number(int ones, int num, int arry[],int A,int B,int C)
{
	if (num == B * ones / A) {
		for (int i = 0; i < 3; i++) {
			if (arry[i] == num % 10
				|| arry[i] == num / 10 % 10
				|| arry[i] == num / 100) {
				return 0;
			}
		}
	} else if (num == C * ones / A) {
		for (int i = 0; i < 6; i++) {
			if (arry[i] == num % 10
				|| arry[i] == num / 10 % 10
				|| arry[i] == num / 100) {
				return 0;	
			}
		}
	}
	return 1;
}
