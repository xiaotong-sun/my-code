#include <stdio.h> 
int Not (float score[],int n);
void Datescore(float score[],int n);
int main()
{
	float score[40];
	int n,i,a;
	printf("please input the number of the students(n<=40):");
	scanf("%d",&n);
	printf("please input the score of the students:\n");
	for (i=0;i<n;i++)
	{
		scanf("%f",&score[i]);
	}
	a=Not (score,n);
	printf("不及格的人数为：%d\n",a);
	Datescore(score,n);
	for (i=0;i<n;i++)
	{
		printf("%.1f\n",score[i]);
	}
	return 0;
} 
int Not (float score[],int n)
{
	int i,k=0;
	for (i=0;i<n;i++)
	{
		if (score[i]<60)
		{
			k+=1;
		}
	}
	return k;
}
void Datescore(float score[],int n)
{
	int j,i,k,temp;
	for (i=0;i<n-1;i++)
	{
		k=i;
		for (j=i+1;j<n;j++)
		{
			if (score[k]<score[j])
			{
				k=j;
			}
		}
		if (k!=i)
		{
			temp=score[k];
			score[k]=score[i];
			score[i]=temp;
		}
	}
}






