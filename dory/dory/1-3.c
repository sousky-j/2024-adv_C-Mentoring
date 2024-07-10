#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#pragma warning (disable : 6031)
int main(void) {

	char str1[1001] = { 0 };
	char str2[1001] = { 0 };
	int cnt = 0;
	scanf("%s", str1);
	scanf("%s", str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for (int i = 0; i < len1 - len2 + 1; i++) {
		int count = 0;
		int k = i;
		for (int j = 0; j < len2; j++) {
			if (str1[k] == str2[j]) {
				k++;
				count++;
			}
		}
		if (count % len2 == 0 && count != 0) {
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}