define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <malloc.h>
int input_char();
int func_sort(char* p, int len);
int func_print(char str[101]);
int main() {
	char str[101];
	scanf("%s", str);
	input_char();
	func_sort(&p, strlen(str));
	func_print(str[100]);
	return 0;
}
int input_char() {
	while (1) {
		char str[1001];
		scanf("%s", &str);
		if (strcmp(str,"내림차순") == 1) {
			return 1;
		}
		else if (strcmp(str,"오름차순") == 1) {
			return 0;
		}
		else {
			printf("잘못된 입력 형식입니다.\n");
		}
	}
	return 0;
}
int func_sort(char* p, int len) {
	for (int i = 0; i < len - 1;i++) {
		for (int j = i + 1; j < len - 1;j++) {
			if (*(p + i) > *(p + j)) {
				char tmp;
				tmp = *(p + i);
				*(p + i) = *(p + j);
				*(p + j) = *(p + i);
			}
		}
	}
	return 0;
}
int func_print() {
	printf("%s", str);
	return 0;
}