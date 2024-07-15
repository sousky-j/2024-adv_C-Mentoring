#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decmpNum(int num) {
	int hundred = (num / 100) * 100;
	int ten = ((num - hundred) / 10) * 10;
	int one = (num - hundred - ten);

	int huhhuh[3] = {hundred, ten, one };
	for (int i = 0; i < 3; i++) {
		if (huhhuh[0] == 1000) {
			printf("1000");
			break;
		}
		if (huhhuh[i] != 0) {
			printf("%d", huhhuh[i]);
			if (huhhuh[i + 1] != 0 && i<2)
				printf(" + ");
		}
	}
	printf(", ");
}
void ArabicToRoman(int num) {
	int arabic[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	char* roman[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

	int k = 2;
	char* romanNum = (char*)malloc(sizeof(char) * k);
	romanNum[0] = '\0';

	for (int i = 0; i < 13; i++) {
		while (num >= arabic[i]) {
			int need_size = strlen(romanNum) + strlen(roman[i]) + 1;
			if (need_size > k) {
				k *= 2;
				romanNum = (char*)realloc(romanNum, sizeof(char) * k);
			}
			strcat(romanNum, roman[i]);
			num -= arabic[i];
		}
	}
	printf("%s, %d", romanNum, strlen(romanNum));
	free(romanNum);
}
int main() {
	int num;
	scanf("%d", &num);
	
	printf("%d = ", num);
	decmpNum(num);
	ArabicToRoman(num);

	return 0;
}