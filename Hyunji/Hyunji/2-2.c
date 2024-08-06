// Day2 HW 2. Dictionary Sort
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>

int count = 0;

void input_word(char** arr);
void sort_word(char** arr);
void print_word(char** arr);

int main() {
	char* arr = (char*)malloc(sizeof(char*) * 1);
	
	input_word(arr);

	for (int i = 0; i < count; i++) {
		free(arr[i]);
	}
	free(arr);
}

void input_word(char** arr) {
	while (1) {
		char tmp[100];
		gets(tmp);
		if (tmp[0] ==0)
			break;
		else{
			count++;
			arr = (char**)realloc(arr, sizeof(char*) * count);
			arr[count - 1] = (char*)malloc(sizeof(char) * (strlen(tmp)+1));
			strcpy(arr[count - 1],tmp);
		}
	}

	sort_word(arr);
}

void sort_word(char** arr) {
	char* tmp;

	for (int i = 0; i < count; i++) {
		for (int j = i; j < count; j++) {
			if (strcmp(arr[i], arr[j]) > 0) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	print_word(arr);
}

void print_word(char** arr) {
	for (int i = 0; i < count; i++) {
		printf("%s\n", arr[i]);
	}
}