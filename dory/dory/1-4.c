#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#pragma warning(disable:6031)

void input_char(char* str,char* method);
void func_sort(char* str,char* method);
void func_print(char* str);
int main(void) {

	char str[101];
	char method[10];
	input_char(str,method); 
	func_sort(str,method);
	func_print(str);

	return 0;
}

void input_char(char* str,char* method) {

	printf("문자열 입력(최대 100자) : ");
	scanf("%s", str);
	printf("정렬 방식 입력 : ");
	scanf("%s", method);
}

void func_sort(char* str, char* method) {
	char tmp;
	if (strcmp(method, "오름차순") == 0) {
		for (int i = 0; i < strlen(str) - 1; i++) {
			if (str[i] > str[i + 1]) {
				tmp = str[i];
				str[i] = str[i + 1];
				str[i + 1] = tmp;
			}
		}
	}
	else if (strcmp(method, "내림차순") == 0) {
		for (int i = 0; i < strlen(str) - 1; i++) {
			if (str[i] < str[i + 1]) {
				tmp = str[i];
				str[i] = str[i + 1];
				str[i + 1] = tmp;
			}
		}
	}
}

void func_print(char* str) {
	printf("%s", str);
}