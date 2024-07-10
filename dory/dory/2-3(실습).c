#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#pragma warning (disable:6031)

int main(void) {

	char* str[10] = { 0 };
	for (int i = 0; i < 10; i++) {
		char string[101] = { 0 };
		scanf("%s", string);
		str[i] = (char*)malloc(sizeof(char) * strlen(string));
		strcpy(str[i], string);
	}
	char tmp[101] = { 0 };
	for (int i = 0; i < 9; i++) {
		for (int j = i; j < 10; j++) {
			if (*str[i] > *str[j]) {
				strcpy(tmp, str[i]);
				strcpy(str[i], str[j]);
				strcpy(str[j], tmp);
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		printf("%s\n", str[i]);
	}

	return 0;
}