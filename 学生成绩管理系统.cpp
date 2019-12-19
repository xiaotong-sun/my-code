#include <stdio.h>
 
int get_failed_student_count(float score[], int n);
void put_score_in_order(float score[], int n);
void exchange_score(float score[], int k, int i);

int main()
{
	float score[40];
	int n, i, a;
	printf("please input the number of the students(n<=40):");
	scanf("%d",&n);
	printf("please input the score of the students:\n");
	for (i=0; i<n; i++)
	{
		scanf("%f",&score[i]);
	}
	a = get_failed_student_count(score, n);
	printf("不及格的人数为：%d\n", a);
	put_score_in_order(score, n);
	for (i=0; i<n; i++)
	{
		printf("%.1f\n", score[i]);
	}
	return 0;
} 

int get_failed_student_count(float score[], int n)
{
	int i, failed_student_count=0;
	for (i=0; i<n; i++)
	{
		if (score[i] < 60)
		{
			failed_student_count += 1;
		}
	}
	return failed_student_count;
}

void put_score_in_order(float score[], int n)
{
	int k;
	for (int i=0; i<n-1; i++)
	{
		k = i;
		for (int j=i+1; j<n; j++)
		{
			if (score[k] < score[j])
			{
				k = j;
			}
		}
		if (k != i)
		{
			exchange_score(score, k, i);
		}
	}
}

void exchange_score(float score[], int k, int i)
{
	int temp;
	temp = score[k];
	score[k] = score[i];
	score[i] = temp;
}
