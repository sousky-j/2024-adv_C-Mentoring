#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* roma(int num);

void main() {
	int num,num1=0;
	int count=0;
	int a, b, c = 0;
	scanf("%d", &num);

	if (num > 1000) {
		printf("잘못입력");
	}

	char* arr = roma(num);
	count = strlen(arr);

	a = (num / 100);
	num1 = num - a*100;
	b = num1 / 10;
	c =num-a*100-b*10;
	

	printf("%d =%d + %d + %d = %s , %d", num,a*100,b*10,c, arr, count);

	free(arr);

}

char* roma(int num) {
	
	char* roma[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	int b[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	int size = sizeof(b)/sizeof(b[0]);
	
	char* arr = (char*)malloc(sizeof(char) * 20);
	
	arr[0] = '\0';

	for (int i = 0; i < size; i++) {
		while (num >= b[i]) {
			strcat(arr, roma[i]);
			num -= b[i];
		
		}
	
	}


	
	return arr;
}