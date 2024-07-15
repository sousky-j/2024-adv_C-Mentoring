#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#pragma warning(disable:6031)

int main(void) {

	int n;
	scanf("%d", &n);
	int arr[10][10] = { 0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >=  0; j--) {
			printf("%d ", arr[j][i]);
		}
		printf("\n");
	}

	return 0;
}