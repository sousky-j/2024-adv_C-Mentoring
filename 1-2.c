// 1주차 과제 2. 세로드립
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char str[5][20];
	
	// 각 행 문자열 받기
	for (int i = 0; i < 5; i++) {
		scanf("%s", *(str + i));
	}

	// A~z 사이라면 출력하기 (아스키코드)
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 5; j++) {
			if (str[j][i] >= 'A' && str[j][i] <= 'z') {
				printf("%c", str[j][i]);
			}
		}
	}
}