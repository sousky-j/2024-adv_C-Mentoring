// 3���� no1. �л� ���� ��� ���α׷�(fscanf)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main() {
	FILE* stu = fopen("students.txt","r");

	int count = 0;
	char** name = (char**)malloc(sizeof(char*) * 1);
	char** course = (char**)malloc(sizeof(char*) * 1);
	float* score_name = (float*)malloc(sizeof(float) * 1);
	float* score_course=(float*)malloc(sizeof(float) * 1);

	// ���� �Է� �ޱ�
	while (1) {
		if (feof(stu))
			break;
		count++;
		char f_name[100];
		char f_course[100];
		char f_score[10];
		name = (char**)realloc(name, sizeof(char*) * count);
		course = (char**)realloc(course, sizeof(char*) * count);
		score_name = (float*)realloc(score_name, sizeof(float) * count);
		score_course = (float*)realloc(score_course, sizeof(float) * count);
		fscanf(stu, "%*d%*c%[^:]s", f_name);
		name[count - 1] = (char*)malloc(sizeof(char) * (strlen(f_name) + 1));
		strcpy(name[count - 1], f_name);
		fscanf(stu, "%*c%[^:]s", f_course);
		course[count - 1] = (char*)malloc(sizeof(char) * (strlen(f_course) + 1));
		strcpy(course[count - 1], f_course);
		fscanf(stu,"%*c%[^\n]s",f_score);
		score_name[count - 1] = ((f_score[0] - '0') * 10) + (f_score[1] - '0');
		score_course[count - 1] = score_name[count - 1];
	}

	// ���� �̸�, ���� ���� �������� �����ֱ�
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			if (strcmp(name[i], name[j])==0&&i!=j) {
				score_name[i] += score_name[j];
			}
			if (strcmp(course[i], course[j]) == 0 && i != j) {
				score_course[i] += score_course[j];
			}
		}
	}

	// ���� �̸� ����, ���� ���� ���� ���� ������ (��� ����)
	int count_name;
	int count_course;
	for (int i = 0; i < count; i++) {
		count_name = 0;
		count_course = 0;
		for (int j = 0; j <count; j++) {
			if (strcmp(name[i], name[j])==0){
				count_name++;
			}
			if (strcmp(course[i], course[j]) == 0) {
				count_course++;
			}
		}
		score_name[i] /= count_name;
		score_course[i] /= count_course;
	}

	// ���
	printf("�л��� ��� ����:\n");
	for (int i = 0; i < count; i++) {
		count_name = 0;
		for (int j = i; j >= 0; j--) {
			if (strcmp(name[i], name[j]) == 0)
				count_name++;
		}
		if (count_name == 1) {
			printf("%s: %.2f\n", name[i], score_name[i]);
		}
	}
	printf("\n������ ��� ����:\n");
	for (int i = 0; i < count; i++) {
		count_course = 0;
		for (int j = i; j >= 0; j--) {
			if (strcmp(course[i], course[j]) == 0)
				count_course++;
		}
		if (count_course == 1) {
			printf("%s: %.2f\n", course[i], score_course[i]);
		}
	}
	
	// free, fclose
	for (int i = 0; i < count; i++) {
		free(name[i]);
		free(course[i]);
	}
	free(name);
	free(course);
	free(score_name);
	free(score_course);
	fclose(stu);

	return 0;
}