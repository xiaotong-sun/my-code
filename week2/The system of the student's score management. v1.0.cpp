#include <stdio.h>

void readscore(int n, long student_number[], int score[]);
void print_total_and_average(int n, int score[]);
void rank_by_grade_in_descending_order(int n, long student_number[], int score[]);
void print_score(int n, long student_number[], int score[]);
void rank_by_student_number_in_ascending_order(int n, long student_number[], int score[]);
int search_student_rank_and_grade_by_student_number(int n, long student_number[], int score[]);
void count_the_percentage_of_the_each_category(int n, long student_number[], int score[]);

int main()
{
	long student_number[30];
	int score[30], n, _switch;
	printf("1.Input record\n2.Caculate total and average score of course\n3.Sort in descending order by score\n");
	printf("4.Sort in ascending order by number\n5.search by number\n6.Statistic analysis\n0.Exit\n\n");
	do {
		printf("Please enter your choice:");
		scanf_s("%d", &_switch);
		switch (_switch)
		{
			case 1:
				printf("Please input the number of the students:");
				scanf_s("%d", &n);
				readscore(n, student_number, score);
				break;
			case 2:
				print_total_and_average(n, score);
				break;
			case 3:
				rank_by_grade_in_descending_order(n, student_number, score);
				printf("Rank by grade in descending order\n");
				print_score(n, student_number, score);
				break;
			case 4:
				rank_by_student_number_in_ascending_order(n, student_number, score);
				printf("rank by student number in ascending order\n");
				print_score(n, student_number, score);
				break;
			case 5:
				search_student_rank_and_grade_by_student_number(n, student_number, score);
				break;
			case 6:
				count_the_percentage_of_the_each_category(n, student_number, score);
				break;
			case 0:
				break;
		}
	} while (_switch != 0);
	return 0;
}

void readscore(int n, long student_number[], int score[]) {
	printf("Please input the student's number and his score\n");
	for (int i = 0; i < n; i++) {
		scanf_s("%ld %d", &student_number[i], &score[i]);
	}
}

void print_total_and_average(int n, int score[]) {
	int total = 0;
	float average;
	for (int i = 0; i < n; i++) {
		total += score[i];
	}
	average = total / (float)n;
	printf("total = %d\taverage = %.2f\n", total, average);
	printf("\n");
}

void rank_by_grade_in_descending_order(int n, long student_number[], int score[]) {
	int temp, k;
	for (int i = 0; i < n - 1; i++) {
		k = i;
		for (int j = i + 1; j < n; j++) {
			if (score[k] < score[j]){
				k = j;
			}
		}
		if (k != i) {
			temp = score[i];
			score[i] = score[k];
			score[k] = temp;
			temp = student_number[i];
			student_number[i] = student_number[k];
			student_number[k] = temp;
		}
	}
}

void print_score(int n, long student_number[], int score[]) {
	for (int i = 0; i < n; i++) {
		printf("%ld\t%d\n", student_number[i], score[i]);
	}
	printf("\n");
}

void rank_by_student_number_in_ascending_order(int n, long student_number[], int score[]) {
	int temp, k;
	for (int i = 0; i < n - 1; i++) {
		k = i;
		for (int j = i + 1; j < n; j++) {
			if (student_number[k] > student_number[j]) {
				k = j;
			}
		}
		if (k != i) {
			temp = score[i];
			score[i] = score[k];
			score[k] = temp;
			temp = student_number[i];
			student_number[i] = student_number[k];
			student_number[k] = temp;
		}
	}
}
int search_student_rank_and_grade_by_student_number(int n, long student_number[], int score[]) {
	long num;
	rank_by_grade_in_descending_order(n, student_number, score);
	printf("please input the student number:");
	scanf_s("%ld", &num);
	for (int i = 0; i < n; i++) {
		if (num == student_number[i]) {
			printf("The student's ranking is %d\n", i + 1);
			printf("The student's score is %d\n\n", score[i]);
			return 0;
		}
	}
	printf("Not existence\n");
	return 0;
}

void count_the_percentage_of_the_each_category(int n, long student_number[], int score[]) {
	int excellent = 0, good = 0, medium = 0, pass = 0, fail = 0;
	float _excellent, _good, _medium, _pass, _fail;
	for (int i = 0; i < n; i++) {
		if (score[i] <= 100 && score[i] >= 90) {
			excellent++;
		}
		else if (score[i] < 90 && score[i] >= 80) {
			good++;
		}
		else if (score[i] < 80 && score[i] >= 70) {
			medium++;
		}
		else if (score[i] < 70 && score[i] >= 60) {
			pass++;
		}
		else if (score[i] < 60) {
			fail++;
		}
	}
	_excellent = excellent / (float)n;
	_good = good / (float)n;
	_medium = medium / (float)n;
	_pass = pass / (float)n;
	_fail = fail / (float)n;
	printf("Excellent account for %.2f\n", _excellent);
	printf("Good account for %.2f\n", _good);
	printf("Medium account for %.2f\n", _medium);
	printf("Pass account for %.2f\n", _pass);
	printf("Fail account for %.2f\n", _fail);
}