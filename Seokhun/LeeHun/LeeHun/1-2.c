#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <malloc.h>
int main() {
	char [1001] = { 0 };
	int len[5], max, all, t;
	max = 0;
	all = 0;
	t = 0;
	char** str = (char**)malloc(sizeof(char*) * 5);
	for (int i = 0; i < 5; i++) {
		scanf("%s", arr);
		len[i] = strlen(arr);
		str[i] = (char*)malloc(sizeof(char) * (len[i] + 1));
		strcpy(str[i], arr);
		all += len[i];
		if (max < len[i]) {
			max = len[i];
		}
	}
	char* result = (char*)malloc(sizeof(char) * (all + 1));
	for (int i = 0; i < all + 1; i++) {
		result[i] = '\0';
	}
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < 5; j++) {
			if (i < len[j]) {
				if (str[j][i] != '\0') {
					result[t] = str[j][i];
					t++;
				}
			}
		}
	}
	printf("\n");
	for (int i = 0; i < strlen(result); i++) {
		printf("%c", result[i]);
	}
	for (int i = 0; i < 5; i++) {
		free(str[i]);
	}
	free(str);
	free(result);
	return 0;
}