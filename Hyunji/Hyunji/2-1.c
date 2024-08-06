// Day2 HW 1. Numeri Romani
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int main() {
	int num;
	scanf("%d", &num);
	int num_save = num;
	// malloc first rom[]
	char* rom = (char*)malloc(sizeof(char) * 2);
	int num_count[3];
	char ten, five, one;
	int N = 100;
	int count = 1;
	int rc = 0;
	// 100, 10, 1 print
	for (int i = 0; i <= 2; i++) {
		num_count[i] = num - (num % N);
		// give rom each number 
		if (N == 100) { ten = 'M'; five = 'D'; one = 'C'; }
		else if (N == 10) { ten = 'C'; five = 'L'; one = 'X'; }
		else { ten = 'X'; five = 'V'; one = 'I'; }
		// realloc, special number (9,5,4)
		if (num >= (9 * N)) {
			count += 2;
			rom = (char*)realloc(rom, sizeof(char) * count);
			rom[rc++] = one;
			rom[rc++] = ten;
			num %= (9 * N);
		}
		else if (num >= (5 * N)) {
			count += 1;
			rom = (char*)realloc(rom, sizeof(char) * count);
			rom[rc++] = five;
			num %= (5 * N);
		}
		else if (num >= (4 * N)) {
			count += 2;
			rom = (char*)realloc(rom, sizeof(char) * count);
			rom[rc++] = one;
			rom[rc++] = five;
			num %= (4 * N);
		}
		// remainder
		if (num >= N) {
			count += (int)(num / (1 * N));
			rom = (char*)realloc(rom, sizeof(char) * count);
			for (int k = 0; k < (int)(num / (1 * N)); k++) {
				rom[rc++] = one;
			}
			num %= N;
		}
		N /= 10;
	}
	// null rext, print
	rom[count - 1] = '\0';
	printf("%d=%d+%d+%d=%s, %d", num_save, num_count[0], num_count[1], num_count[2], rom, count - 1);
	free(rom);
}