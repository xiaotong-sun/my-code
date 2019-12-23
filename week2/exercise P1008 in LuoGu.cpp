#include <stdio.h>

int isvalid(int Double, int Triple, int Flag);

int main()
{
	int Num, Double, Triple, Flag=0;
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			if (i == j) {
				continue;
			} else {
				for (int k = 1; k < 10; k++) {
					if (i == k || j == k) {
						continue;
					} else {
						Num = i * 100 + j * 10 + k; // Get a three-digit number that is different for each digit.
						Double = Num * 2;
						Triple = Num * 3;             // Get three numbers in the ratio of 1:2:3
						Flag=isvalid(Double, Triple, Flag);
						if (Flag == 0) {
							continue;
						} else {
							// Output everything in ascending order.
							printf("%d %d %d\n", Num, Double, Triple);
						}
					}
				}
			}
		}
	}
	return 0;
 } 
 
 int isvalid(int Double, int Triple, int Flag)
 {
 	if (Double % 10 == Double / 10 % 10 
		|| Double / 100 == Double / 10 % 10 
		|| Double % 10 ==  Double / 100
		|| Triple % 10 == Triple / 10 % 10 
		|| Triple / 100 == Triple / 10 % 10 
		|| Triple % 10 ==  Triple / 100
		|| Triple >= 1000) {
		return 0;
	} else {
		return 1;
	}
 }
