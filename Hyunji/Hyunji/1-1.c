// 1주차 과제 1. 오름차순 내림차순 구현하기 (문자열)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char str[101];

int input_char(); //문자열, 정렬방식 입력
int func_sort(int n); //정렬
int func_print(); //출력

int main() {
	input_char();
}

int input_char() {
	char sort[20];
	scanf("%s", str);
	scanf(" %s", sort);
	
	//오름차순: 0, 내림차순: -1 들어감
	func_sort(strcmp(sort, "오름차순"));
}

int func_sort(int n) {
	char tmp;
	for (int i = 0; i < strlen(str); i++) {
		for (int j = i; j < strlen(str); j++) {
			// 오름차순일 경우
			if ((str[i] > str[j]) && n==0) {
				tmp = str[i];
				str[i] = str[j];
				str[j] = tmp;
			}
			// 내림차순일 경우
			else if ((str[i] < str[j]) && n == -1) {
				tmp = str[i];
				str[i] = str[j];
				str[j] = tmp;
			}
		}
	}
	func_print();
}

int func_print() {
	printf("%s", str);
}