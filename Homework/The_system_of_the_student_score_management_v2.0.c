#include <stdio.h>

void input_score(long student_id[], long score[], int n);
void print_total_and_average(int n, long score[]);
void selection_sort(long student_id[], long score[],int n, int (*compare)(long a, long b));
int rank_by_grade_in_descending_order(long a, long b);
int rank_by_grade_in_ascending_order(long a, long b);
void print_score(long student_id[], long score[], int n);
void rank_by_student_id_in_ascending_order(long student_id[], long score[], int n);
int search_student_rank_and_grade_by_student_id(long student_id[], long score[], int n);
void count_the_percentage_of_the_each_category(long student_id[], long score[], int n);
void swap(long *a, long *b);

int main()
{
	long student_id[30], score[30];
	int n, choice;
	printf("1. Input record\n");
	printf("2. Caculate total and average score of course\n");
	printf("3. Sort in descending order by score\n");
	printf("4. Sort in ascending order by score\n");
	printf("5. Sort in ascending order by number\n");
	printf("6. search by number\n");
	printf("7. Statistic analysis\n");
	printf("8. List record\n");
	printf("0. Exit\n\n");
	do {
		printf("Please enter your choice:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Please input the number of the students(n <= 30):");
			scanf("%d", &n);
			input_score(student_id, score, n);
			break;
		case 2:
			print_total_and_average(n, score);
			break;
		case 3:
			selection_sort(student_id, score, n, rank_by_grade_in_descending_order);
			printf("Rank by grade in descending order\n");
			print_score(student_id, score, n);
			break;
		case 4:
			selection_sort(student_id, score, n, rank_by_grade_in_ascending_order);
			printf("Rank by grade in ascending order\n");
			print_score(student_id, score, n);
			break;
		case 5:
			rank_by_student_id_in_ascending_order(student_id, score, n);
			printf("rank by student number in ascending order\n");
			print_score(student_id, score, n);
			break;
		case 6:
			search_student_rank_and_grade_by_student_id(student_id, score, n);
			break;
		case 7:
			count_the_percentage_of_the_each_category(student_id, score, n);
			break;
		case 8:
			rank_by_student_id_in_ascending_order(student_id, score, n);
			print_score(student_id, score, n);
			print_total_and_average(n, score);
			break;
		case 0:
			printf("Exit successfully! \\*_*/\n");
			break;
		default :
			printf("Please input a correct choice.  !!-_-!!\n");
		}
	} while (choice != 0);
	return 0;
}

void input_score(long student_id[], long score[], int n) {
	if (n > 30) {
		printf("The number exceeds limit.\n");
	}
	else {
		printf("Please input the student's number and score\n");
		for (int i = 0; i < n; i++) {
			scanf("%ld %ld", &student_id[i], &score[i]);
		}
	}
}

void print_total_and_average(int n, long score[]) {
	int total = 0;
	float average;
	for (int i = 0; i < n; i++) {
		total += score[i];
	}
	average = total / (float)n;
	printf("total = %d\taverage = %.2f\n", total, average);
	printf("\n");
}

void selection_sort(long student_id[], long score[],int n, int (*compare)(long a, long b)) {
	int k;
	for (int i = 0; i < n - 1; i++) {
		k = i;
		for (int j = i + 1; j < n; j++) {
			if ((*compare)(score [k], score [j])) {
				k = j;
			}
		}
		if (k != i) {
			swap(&score[i], &score[k]);
			swap(&student_id[i], &student_id[k]);
		}
	}
}

void swap(long *a, long *b) {
	long temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int rank_by_grade_in_descending_order(long a, long b) {
	return a < b;
}

int rank_by_grade_in_ascending_order(long a, long b)  {
	return a > b;
}

void print_score(long student_id[], long score[], int n) {
	printf("ID-NUM \t score\n");
	for (int i = 0; i < n; i++) {
		printf("%ld \t %ld\n", student_id[i], score[i]);
	}
	printf("\n");
}

void rank_by_student_id_in_ascending_order(long student_id[], long score[], int n) {
	int k;
	for (int i = 0; i < n - 1; i++) {
		k = i;
		for (int j = i + 1; j < n; j++) {
			if (student_id[k] > student_id[j]) {
				k = j;
			}
		}
		if (k != i) {
			swap(&score[i], &score[k]);
			swap(&student_id[i], &student_id[k]);
		}
	}
}

int search_student_rank_and_grade_by_student_id(long student_id[], long score[], int n) {
	long num;
	selection_sort(student_id, score, n, rank_by_grade_in_descending_order);
	printf("please input the student number:");
	scanf("%ld", &num);
	for (int i = 0; i < n; i++) {
		if (num == student_id[i]) {
			printf("The student's ranking is %d\n", i + 1);
			printf("The student's score is %ld\n\n", score[i]);
			return 0;
		}
	}
	printf("Not existence\n");
	return 0;
}

void count_the_percentage_of_the_each_category(long student_id[], long score[], int n) {
	int excellent = 0, good = 0, medium = 0, pass = 0, fail = 0;
	float excellent_avg, good_avg, medium_avg, pass_avg, fail_avg;
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
	excellent_avg = excellent / (float)n;
	good_avg = good / (float)n;
	medium_avg = medium / (float)n;
	pass_avg = pass / (float)n;
	fail_avg = fail / (float)n;
	printf("Excellent account for %.2f\n", excellent_avg);
	printf("Good account for %.2f\n", good_avg);
	printf("Medium account for %.2f\n", medium_avg);
	printf("Pass account for %.2f\n", pass_avg);
	printf("Fail account for %.2f\n\n", fail_avg);
}