#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#pragma warning(disable:6031)

char str1[21];
char str2[21];
char str3[21];
char str4[21];
char str5[21];
char result[101];

int main(void) {

	int num = 0;

	scanf("%s", str1);
	scanf("%s", str2);
	scanf("%s", str3);
	scanf("%s", str4);
	scanf("%s", str5);

	for (int i = 0; i < 20; i++) {
		if (str1[i] != 0) {
			result[num] = str1[i];
			num++;
		}
		if (str2[i] != 0) {
			result[num] = str2[i];
			num++;
		}
		if (str3[i] != 0) {
			result[num] = str3[i];
			num++;
		}
		if (str4[i] != 0) {
			result[num] = str4[i];
			num++;
		}
		if (str5[i] != 0) {
			result[num] = str5[i];
			num++;
		}
	}
	printf("%s", result);
	return 0;
}