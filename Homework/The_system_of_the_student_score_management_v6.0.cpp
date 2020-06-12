#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct record
{
	long student_id;
	char name[20];
	long score[6];
	int total2 = 0;
	float average2 = 0;
}RECORD;

void menu();
void input_record(RECORD data[], char subject[][20], int n, int m);
void calculate_of_subject(int n, int m, RECORD data[], long total[], float average[]);
void calculate_of_student(int n, int m, RECORD data[]);
void print_total_and_average_of_each_subject(int m, char subject[][20], long total[], float average[]);
void print_total_and_average_of_each_student(int n, RECORD data[]);
void selection_sort(RECORD data[], int n, int m, int (*compare)(long a, long b));
int rank_by_grade_in_descending_order(long a, long b);
int rank_by_grade_in_ascending_order(long a, long b);
void print_score(RECORD data[], char subject[][20], int n, int m);
void rank_by_student_id_in_ascending_order(RECORD data[], int n, int m);
void rank_by_student_name(RECORD data[], int n, int m);
int search_student_rank_and_grade_by_student_id(RECORD data[], char subject[][20], int n, int m);
int search_student_rank_and_grade_by_student_name(RECORD data[], char subject[][20], int n, int m);
void count_the_percentage_of_the_each_category(RECORD data[], char subject[][20], int n, int m);
void WritetoFile(RECORD data[], char subject[][20], int n, int m);
void ReadfromFile(RECORD data[], char subject[][20], int *n, int *m);

int main()
{
	RECORD data[30];
	char subject[6][20];
	int n, m, choice;
	long total1[30] = {0};                           // total1 and average1 are for each subject
	float average1[30] = {0};                    // total2 and average2 are for each student
	menu();
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
			input_record(data, subject, n, m);
			calculate_of_student(n, m, data);
			calculate_of_subject(n, m, data, total1, average1);
			break;
		case 2:
			print_total_and_average_of_each_subject(m, subject, total1, average1);
			break;
		case 3:
			print_total_and_average_of_each_student(n, data);
			break;
		case 4:
			selection_sort(data, n, m, rank_by_grade_in_descending_order);
			printf("Rank by grade in descending order\n");
			print_score(data, subject, n, m);
			break;
		case 5:
			selection_sort(data, n, m, rank_by_grade_in_ascending_order);
			printf("Rank by grade in ascending order\n");
			print_score(data, subject, n, m);
			break;
		case 6:
			rank_by_student_id_in_ascending_order(data, n, m);
			printf("rank by student number in ascending order\n");
			print_score(data, subject, n, m);
			break;
		case 7:
			rank_by_student_name(data, n, m);
			printf("rank by student name\n");
			print_score(data, subject, n, m);
			break;
		case 8:
			search_student_rank_and_grade_by_student_id(data, subject, n, m);
			break;
		case 9:
			search_student_rank_and_grade_by_student_name(data, subject, n, m);
			break;
		case 10:
			count_the_percentage_of_the_each_category(data, subject, n, m);
			break;
		case 11:
			rank_by_student_id_in_ascending_order(data, n, m);
			print_score(data, subject, n, m);
			print_total_and_average_of_each_student(n, data);
			print_total_and_average_of_each_subject(m, subject, total1, average1);
			break;
		case 12:
			rank_by_student_id_in_ascending_order(data, n, m);
			WritetoFile(data, subject, n, m);
			break;
		case 13:
			ReadfromFile(data, subject, &n, &m);
			calculate_of_student(n, m, data);
			calculate_of_subject(n, m, data, total1, average1);
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

/*打印菜单*/
void menu() {
	printf("***************| MENU |***************\n\n");
	printf("1.  Input record\n");
	printf("2.  Caculate total and average score of every course\n");
	printf("3.  Caculate total and average score of every student\n");
	printf("4.  Sort in descending order by total score of every student\n");
	printf("5.  Sort in ascending order by total score of every student\n");
	printf("6.  Sort in ascending order by number");
	printf("7.  Sort in dictionary order by name\n");
	printf("8.  Search by number\n");
	printf("9.  Search by name\n");
	printf("10. Statistic analysis for every course\n");
	printf("11. List record\n");
	printf("12. Write to a file\n");
	printf("13. Read from a file\n\n");
	printf("0.  Exit\n\n");
	printf("**************************************\n");
}

/*录入学生的学号，姓名，学科，各科成绩*/
void input_record(RECORD data[], char subject[][20], int n, int m) {
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
			scanf("%ld %s", &data[i].student_id, data[i].name);
			for (int j = 0; j < m; j++) {
				scanf("%ld", &data[i].score[j]);
			}
		}
	}
}

/* 计算各科的总成绩以及平均分*/
void calculate_of_subject(int n, int m, RECORD data[], long total[], float average[]) {
	for(int i = 0; i < m; i ++) {
		total[i] = 0;
		average[i] = 0;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			total[i] += data[j].score[i];
		}
		average[i] = total[i] / (float)n;
	}
}

/*输出各科的总成绩以及平均分*/
void print_total_and_average_of_each_subject(int m, char subject[][20], long total[], float average[]) {
	for (int i = 0; i < m; i++) {
	printf("%s: total = %d\taverage = %.2f\n", subject[i], total[i], average[i]);	
	}
	printf("\n");
}

/*计算学生的总成绩以及平均分*/
void calculate_of_student(int n, int m, RECORD data[]) {
	for(int i = 0; i < n; i ++) {
		data[i].total2 = 0;
		data[i].average2 = 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			data[i].total2 += data[i].score[j];
		}
		data[i].average2 = data[i].total2 / (float)m;
	}
}

/*输出学生的总成绩和平均分*/
void print_total_and_average_of_each_student(int n, RECORD data[]) {
	for (int i = 0; i < n; i++) {
	printf("%s: total = %d\taverage = %.2f\n", data[i].name, data[i].total2, data[i].average2);
	}
	printf("\n");
} 

/*排序：按成绩升序或降序*/
void selection_sort(RECORD data[], int n, int m, int (*compare)(long a, long b)) {
	int k;
	RECORD temp;
	for (int i = 0; i < n - 1; i++) {
		k = i;
		for (int j = i + 1; j < n; j++) {
			if ((*compare)(data[k].total2, data[j].total2)) {
				k = j;
			}
		}
		if (k != i) {
			temp = data[i];
			data[i] = data[k];
			data[k] = temp;
		}
	}
}

int rank_by_grade_in_descending_order(long a, long b) {
	return a < b;
}

int rank_by_grade_in_ascending_order(long a, long b) {
	return a > b;
}

/*输出每个学生的学号，姓名，各科成绩*/
void print_score(RECORD data[], char subject[][20], int n, int m) {
	printf("ID-number\tStudent-name\t");
	for (int i = 0; i < m; i++) {
		printf("%-3s\t", subject[i]);
	}
	printf("total\t");
	printf("\n");
	for (int i = 0; i < n; i++) {
		printf("%-10ld\t%-12s\t", data[i].student_id, data[i].name);
		for (int j = 0; j < m; j++) {
			printf("%-4ld\t", data[i].score[j]);
		}
		printf("%d\t", data[i].total2);
		printf("\n");
	}
}

/*按学号升序排列*/
void rank_by_student_id_in_ascending_order(RECORD data[], int n, int m) {
	int k;
	RECORD temp;
	for (int i = 0; i < n - 1; i++) {
		k = i;
		for (int j = i + 1; j < n; j++) {
			if (data[k].student_id > data[j].student_id) {
				k = j;
			}
		}
		if (k != i) {
			temp = data[i];
			data[i] = data[k];
			data[k] = temp;
		}
	}
}

/*按姓名排序*/
void rank_by_student_name(RECORD data[], int n, int m) {
	int k;
	RECORD temp;
	for (int i = 0; i < n - 1; i++) {
		k = i;
		for (int j = i + 1; j < n; j++) {
			if (strcmp(data[k].name, data[j].name) > 0) {
				k = j;
			}
		}
		if (k != i) {
			temp = data[i];
			data[i] = data[k];
			data[k] = temp;
		}
	}
}

/*按学号索引学生排名及成绩*/
int search_student_rank_and_grade_by_student_id(RECORD data[], char subject[][20], int n, int m) {
	long num;
	selection_sort(data, n, m, rank_by_grade_in_descending_order);
	printf("please input the student number:");
	scanf("%ld", &num);
	for (int i = 0; i < n; i++) {
		if (num == data[i].student_id) {
			printf("The student's name is %s\n", data[i].name);
			printf("The student's ranking is %d\n", i + 1);
			for (int j = 0; j < m; j ++) {
				printf("%s: %ld\n", subject[j], data[i].score[j]);
			}
			printf("total = %d\n", data[i].total2);
			printf("\n");
			return 0;
		}
	}
	printf("Not existence\n");
	return 0;
}

/*按姓名索引学生排名及成绩*/
int search_student_rank_and_grade_by_student_name(RECORD data[], char subject[][20], int n, int m) {
	char na[20];
	selection_sort(data, n, m, rank_by_grade_in_descending_order);
	printf("please input the student name:");
	scanf("%s", na);
	for (int i = 0; i < n; i ++) {
		if (strcmp(na, data[i].name) == 0) {
			printf("The student's ID is %ld\n", data[i].student_id);
			printf("The student's ranking is %d\n", i + 1);
			for (int j = 0; j < m; j ++) {
				printf("%s: %ld\n", subject[j], data[i].score[j]);
			}
			printf("total = %d\n", data[i].total2);
			printf("\n");
			return 0;
		}
	}
	printf("Not existence\n");
	return 0;
}

/*统计各科优秀，良好，中等，及格，不及格比例*/
void count_the_percentage_of_the_each_category(RECORD data[], char subject[][20], int n, int m) {
	int excellent, good, medium, pass, fail;
	float excellent_avg, good_avg, medium_avg, pass_avg, fail_avg;
	for (int i = 0; i < m; i++) {
		excellent = 0, good = 0, medium = 0, pass = 0, fail = 0;
		for (int j = 0; j < n; j++) {
			if (data[j].score[i] <= 100 && data[j].score[i] >= 90) {
				excellent++;
			}
			else if (data[j].score[i] < 90 && data[j].score[i] >= 80) {
				good++;
			}
			else if (data[j].score[i] < 80 && data[j].score[i] >= 70) {
				medium++;
			}
			else if (data[j].score[i] < 70 && data[j].score[i] >= 60) {
				pass++;
			}
			else if (data[j].score[i] < 60) {
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

void WritetoFile(RECORD data[],char subject[][20], int n, int m) {
	FILE *fp;
	if((fp = fopen("student.txt", "w")) == NULL) {
		printf("Failure to open student.txt!\n");
		exit(0);
	}
	fprintf(fp, "Total number of students: %d\nTotal number of subjects: %d\n", n, m);
	for(int i = 0; i < m; i ++) {
		fprintf(fp, "%s\n", subject[i]);
	}
	for(int i = 0; i < n; i ++) {
		fprintf(fp, "%-10ld\t%-12s\t", data[i].student_id, data[i].name);
		for(int j = 0; j < m; j ++) {
			fprintf(fp, "%-4ld\t", data[i].score[j]);
		}
		fprintf(fp, "%-4d\t%-4.2f\n", data[i].total2, data[i].average2);
	}
	fclose(fp);
}

void ReadfromFile(RECORD data[], char subject[][20], int *n, int *m) {
	FILE *fp;
	if((fp = fopen("student.txt", "r")) == NULL) {
		printf("Failure to open student.txt!\n");
		exit(0);
	}
	fscanf(fp, "Total number of students: %d\nTotal number of subjects: %d\n", n, m);
	for(int i = 0; i < *m; i ++) {
		fscanf(fp, "%s", subject[i]);
	}
	for(int i = 0; i < *n; i ++) {
		fscanf(fp, "%10ld\t%12s\t", &data[i].student_id, data[i].name);
		for(int j = 0; j < *m; j ++) {
			fscanf(fp, "%4ld\t", &data[i].score[j]);
		}
		fscanf(fp, "%4d\t%f", &data[i].total2, &data[i].average2);
	}
}