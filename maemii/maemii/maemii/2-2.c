#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort_arr(char** arr, int cnt) {
	char* tmp;
	for (int i = 0; i < cnt - 1; i++) {
		for (int j = i + 1; j < cnt; j++) {

			if (strcmp(arr[i], arr[j]) > 0) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	for (int i = 0; i < cnt; i++)
		printf("%s\n", arr[i]);
}

int main() {
	int cnt = 0;
	char input[101];
	char** arr = (char**)malloc(sizeof(char*));

	while (1) {
		gets_s(input, 101);
		if (input[0] == '\0')
			break;

		arr = (char**)realloc(arr, sizeof(char*) * (cnt + 1));
		arr[cnt] = (char*)malloc(sizeof(char) * (sizeof(input) + 1));

		strcpy(arr[cnt], input);
		cnt++;
	}

	sort_arr(arr, cnt);

	for (int i = 0; i < cnt; i++)
		free(arr[i]);
	free(arr);

	return 0;
}