// 3주차 과제2. 단어 오름차순, 내림차순 정렬 프로그램
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void sort_Ascending(char** word);
void sort_Descending(char** word);
void write_result_to_file(char** word);
void print_result();

int main() {
	FILE* data = fopen("data.txt", "r");
	
	char A[5][100];
	char B[20][10];
	int count_word=0;
	int count_b=0;

	for (int i = 0; i < 5; i++) {
		fgets(A[i], 100, data);
		for (int j = 0; j < 100; j++) {
			if (A[i][j] >= 'A' && A[i][j] <= 'z') {
				B[count_b][count_word++] = A[i][j];
			}
			else if (A[i][j] == '|') {
				B[count_b++][count_word] = '\0';
				count_word = 0;
			}
		}
	}
	B[count_b][count_word] = '\0';

	write_result_to_file(B);

	print_result();

	fclose(data);
}

void write_result_to_file(char** word) {
	FILE* as = fopen("ascend.txt", "w");
	FILE* des = fopen("descend.txt", "w");

	sort_Ascending(word);
	fwrite(word, sizeof(char) * 10, 20, as);

	sort_Descending(word);
	fwrite(word, sizeof(char) * 10, 20, des);

	fclose(as);
	fclose(des);
}

void sort_Ascending(char** word) {
	char* tmp;
	for (int j = 0; j < 19; j++) {
		for (int k = j; k < 19; k++) {
			if (strcmp(word[j], word[k]) > 0) {
				tmp = word[k];
				word[k] = word[j];
				word[j] = tmp;
			}
		}
	}
}

void sort_Descending(char** word) {
	char* tmp;
	for (int j = 0; j < 19; j++) {
		for (int k = j; k < 19; k++) {
			if (strcmp(word[j], word[k]) < 0) {
				tmp = word[k];
				word[k] = word[j];
				word[j] = tmp;
			}
		}
	}
}

void print_result() {
	FILE* as = fopen("ascend.txt", "r");
	FILE* des = fopen("descend.txt", "r");
	
	char word[10];

	printf("========sorting Result========");
	for (int i = 0; i < 19; i++) {
		fscanf(as, "%s", word);
		printf("[%10s]", word);
	}

	fclose(as);
	fclose(des);
}