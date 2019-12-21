#include <stdio.h> 
#include <math.h>
#include <conio.h>

#define EPS 1e-1

int main()
{
	while (1) { 
		float a, b, c;
		printf("请输入三角形的三边长：");
		scanf("%f%f%f", &a, &b, &c);
		if (a + b > c && a + c > b && b + c > a)
			{
				if(fabs(a * a + b * b - c * c) <= EPS
				 || fabs(a * a + c * c - b * b) <= EPS
				 || fabs(b * b + c * c - a * a) <= EPS)
					printf("三角形为直角三角形\n");
				else if (fabs(a - b) <= EPS
				       || fabs(a - c) <= EPS
				       || fabs(b - c) <= EPS)
					printf("三角形为等腰三角形\n");
				else 
					printf("三角形为一般三角形\n");
			}
		else 
			printf("不构成三角形\n"); 
		getch();
	}
	
	return 0; 
}
