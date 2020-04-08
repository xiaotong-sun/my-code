#include <stdio.h>
#include <string.h>

void input_record(long student_id[], char name[][20], char subject[][20], long score[][6], int n, int m);
void print_total_and_average_of_each_subject(int n, int m, char subject[][20], long score[][6], long total[], float average[]);
void print_total_and_average_of_each_student(int n, int m, char name[][20], long score[][6], long total[], float average[]);
void selection_sort(long student_id[], char  name[][20], long score[][6], long total[], int n, int m, int (*compare)(long a, long b));
int rank_by_grade_in_descending_order(long a, long b);
int rank_by_grade_in_ascending_order(long a, long b);
void print_score(long student_id[], char name[][20], char subject[][20], long score[][6], int n, int m);
void rank_by_student_id_in_ascending_order(long student_id[], char name[][20], long total[], long score[][6], int n, int m);
void rank_by_student_name(long student_id[], char name[][20], long total[], long score[][6], int n, int m);
int search_student_rank_and_grade_by_student_id(long student_id[], char name[][20], char subject[][20], long total[], long score[][6], int n, int m);
int search_student_rank_and_grade_by_student_name(long student_id[], char name[][20], char subject[][20], long total[], long score[][6], int n, int m);
void count_the_percentage_of_the_each_category(long student_id[], char subject[][20], long score[][6], int n, int m);
void swap(long* a, long* b);

int main()
{
	char name[30][20], subject[6][20];
	long student_id[30], score[30][6];
	int n, m, choice;
	long total1[30] = {0},total2[30] = {0};                           // total1 and average1 are for each subject
	float average1[30] = {0}, average2[30] = {0};                    // total2 and average2 are for each student
	printf("1. Input record\n");
	printf("2. Caculate total and average score of each subject\n");
	printf("3. Caculate total and average score of each student\n");
	printf("4. Sort in descending order by total score of each student\n");
	printf("5. Sort in ascending order by total score of each student\n");
	printf("6. Sort in ascending order by student-ID\n");
	printf("7. Sort by name\n");
	printf("8. search by student-ID\n");
	printf("9. search by name\n");
	printf("10. Statistic analysis\n");
	printf("11. List record\n");
	printf("0. Exit\n\n");
	do {
		printf("Please enter your choice:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Please input the number of the students(n <= 30):");
			scanf("%d", &n);
			printf("Please input the number of the subject (m <= 6):");
			scanf("%d", &m);
			input_record(student_id, name, subject, score, n, m);
			break;
		case 2:
			print_total_and_average_of_each_subject(n, m, subject, score, total1, average1);
			break;
		case 3:
			print_total_and_average_of_each_student(n, m, name, score, total2, average2);
			break;
		case 4:
			selection_sort(student_id, name, score, total2, n, m, rank_by_grade_in_descending_order);
			printf("Rank by grade in descending order\n");
			print_score(student_id, name, subject, score, n, m);
			break;
		case 5:
			selection_sort(student_id, name, score, total2, n, m, rank_by_grade_in_ascending_order);
			printf("Rank by grade in ascending order\n");
			print_score(student_id, name, subject, score, n, m);
			break;
		case 6:
			rank_by_student_id_in_ascending_order(student_id, name, total2, score, n, m);
			printf("rank by student number in ascending order\n");
			print_score(student_id, name, subject, score, n, m);
			break;
		case 7:
			rank_by_student_name(student_id, name, total2, score, n, m);
			printf("rank by student name\n");
			print_score(student_id, name, subject, score, n, m);
			break;
		case 8:
			search_student_rank_and_grade_by_student_id(student_id, name, subject, total2, score, n, m);
			break;
		case 9:
			search_student_rank_and_grade_by_student_name(student_id, name, subject, total2, score, n, m);
			break;
		case 10:
			count_the_percentage_of_the_each_category(student_id, subject, score, n, m);
			break;
		case 11:
			rank_by_student_id_in_ascending_order(student_id, name, total2, score, n, m);
			print_score(student_id, name, subject, score, n, m);
			print_total_and_average_of_each_student(n, m, name, score, total2, average2);
			print_total_and_average_of_each_subject(n, m, subject, score, total1, average1);
			break;
		case 0:
			printf("Exit successfully! \\*_*/\n");
			break;
		default:
			printf("Please input a correct choice.  !!-_-!!\n");
		}
	} while (choice != 0);
	return 0;
}

void input_record(long student_id[], char name[][20], char subject[][20], long score[][6], int n, int m) {
	if (n > 30 || m > 6) {
		printf("The number exceeds limit.\n");
	}
	else {
		printf("Please input the subject name\n");
		for (int i = 0; i < m; i++) {
			scanf("%s", subject[i]);
		}
		printf("Please input the student's number, name and each-subject-score\n");
		for (int i = 0; i < n; i++) {
			scanf("%ld %s", &student_id[i], name[i]);
			for (int j = 0; j < m; j++) {
				scanf("%ld", &score[i][j]);
			}
		}
	}
}

void print_total_and_average_of_each_subject(int n, int m, char subject[][20], long score[][6], long total[], float average[]) {
	for(int i = 0; i < m; i ++) {
		total[i] = 0;
		average[i] = 0;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			total[i] += score[j][i];
		}
		average[i] = total[i] / (float)n;
	}
	for (int i = 0; i < m; i++) {
	printf("%s: total = %d\taverage = %.2f\n", subject[i], total[i], average[i]);	
	}
	printf("\n");
}

void print_total_and_average_of_each_student(int n, int m, char name[][20], long score[][6], long total[], float average[]) {
	for(int i = 0; i < n; i ++) {
		total[i] = 0;
		average[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			total[i] += score[i][j];
		}
		average[i] = total[i] / (float)n;
	}
	for (int i = 0; i < n; i++) {
	printf("%s: total = %d\taverage = %.2f\n", name[i], total[i], average[i]);
	}
	printf("\n");
}

void selection_sort(long student_id[], char  name[][20], long score[][6], long total[], int n, int m, int (*compare)(long a, long b)) {
	int k;
	char temp[20];
	for (int i = 0; i < n - 1; i++) {
		k = i;
		for (int j = i + 1; j < n; j++) {
			if ((*compare)(total[k], total[j])) {
				k = j;
			}
		}
		if (k != i) {
			strcpy(temp, name[i]);
			strcpy(name[i], name[k]);
			strcpy(name[k], temp);
			swap(&total[i], &total[k]);
			for (int a = 0; a < n; a++) {
				swap(&score[i][a], &score[k][a]);
			}
			swap(&student_id[i], &student_id[k]);
		}
	}
}

void swap(long* a, long* b) {
	long temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int rank_by_grade_in_descending_order(long a, long b) {
	return a < b;
}

int rank_by_grade_in_ascending_order(long a, long b) {
	return a > b;
}

void print_score(long student_id[], char name[][20], char subject[][20], long score[][6], int n, int m) {
	printf("ID-number\tStudent-name\t");
	for (int i = 0; i < m; i++) {
		printf("%s\t", subject[i]);
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
		printf("%ld\t%s\t", student_id[i], name[i]);
		for (int j = 0; j < m; j++) {
			printf("%ld\t", score[i][j]);
		}
		printf("\n");
	}
}

void rank_by_student_id_in_ascending_order(long student_id[], char name[][20], long total[], long score[][6], int n, int m) {
	int k;
	char temp[20];
	for (int i = 0; i < n - 1; i++) {
		k = i;
		for (int j = i + 1; j < n; j++) {
			if (student_id[k] > student_id[j]) {
				k = j;
			}
		}
		if (k != i) {
			strcpy(temp, name[i]);
			strcpy(name[i], name[k]);
			strcpy(name[k], temp);
			swap(&total[i], &total[k]);
			for (int a = 0; a < n; a++) {
				swap(&score[i][a], &score[k][a]);
			}
			swap(&student_id[i], &student_id[k]);
		}
	}
}

void rank_by_student_name(long student_id[], char name[][20], long total[], long score[][6], int n, int m) {
	int k;
	char temp[20];
	for (int i = 0; i < n - 1; i++) {
		k = i;
		for (int j = i + 1; j < n; j++) {
			if (strcmp(name[k], name[j]) > 0) {
				k = j;
			}
		}
		if (k != i) {
			strcpy(temp, name[i]);
			strcpy(name[i], name[k]);
			strcpy(name[k], temp);
			swap(&total[i], &total[k]);
			for (int a = 0; a < m; a++) {
				swap(&score[i][a], &score[k][a]);
			}
			swap(&student_id[i], &student_id[k]);
		}
	}
}

int search_student_rank_and_grade_by_student_id(long student_id[], char name[][20], char subject[][20], long total[], long score[][6], int n, int m) {
	long num;
	selection_sort(student_id, name, score, total, n, m, rank_by_grade_in_descending_order);
	printf("please input the student number:");
	scanf("%ld", &num);
	for (int i = 0; i < n; i++) {
		if (num == student_id[i]) {
			printf("The student's name is %s\n", name[i]);
			printf("The student's ranking is %d\n", i + 1);
			for (int j = 0; j < m; j ++) {
				printf("%s: %ld\n", subject[j], score[i][j]);
			}
			printf("\n");
			return 0;
		}
	}
	printf("Not existence\n");
	return 0;
}

int search_student_rank_and_grade_by_student_name(long student_id[], char name[][20], char subject[][20], long total[], long score[][6], int n, int m) {
	char na[20];
	selection_sort(student_id, name, score, total, n, m, rank_by_grade_in_descending_order);
	printf("please input the student name:");
	scanf("%s", na);
	for (int i = 0; i < n; i ++) {
		if (strcmp(na, name[i]) == 0) {
			printf("The student's ID is %ld\n", student_id[i]);
			printf("The student's ranking is %d\n", i + 1);
			for (int j = 0; j < m; j ++) {
				printf("%s: %ld\n", subject[j], score[i][j]);
			}
			printf("\n");
			return 0;
		}
	}
	printf("Not existence\n");
	return 0;
}

void count_the_percentage_of_the_each_category(long student_id[], char subject[][20], long score[][6], int n, int m) {
	int excellent, good, medium, pass, fail;
	float excellent_avg, good_avg, medium_avg, pass_avg, fail_avg;
	for (int i = 0; i < m; i++) {
		excellent = 0, good = 0, medium = 0, pass = 0, fail = 0;
		for (int j = 0; j < n; j++) {
			if (score[j][i] <= 100 && score[j][i] >= 90) {
				excellent++;
			}
			else if (score[j][i] < 90 && score[j][i] >= 80) {
				good++;
			}
			else if (score[j][i] < 80 && score[j][i] >= 70) {
				medium++;
			}
			else if (score[j][i] < 70 && score[j][i] >= 60) {
				pass++;
			}
			else if (score[j][i] < 60) {
				fail++;
			}
		}
		excellent_avg = excellent / (float)n;
		good_avg = good / (float)n;
		medium_avg = medium / (float)n;
		pass_avg = pass / (float)n;
		fail_avg = fail / (float)n;
		printf("%s:\n", subject[i]);
		printf("Excellent account for %.2f\n", excellent_avg);
		printf("Good account for %.2f\n", good_avg);
		printf("Medium account for %.2f\n", medium_avg);
		printf("Pass account for %.2f\n", pass_avg);
		printf("Fail account for %.2f\n\n", fail_avg);
	}
}
