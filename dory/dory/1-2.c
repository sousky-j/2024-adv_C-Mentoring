#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#pragma warning (disable : 6031)
int at(int n, int* arr);

int main(void) {

	int n;
	int arr[1001];
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		arr[i] = i;
	}
	at(n, arr);

	for (int i = 1; i < n; i++) {
		if (arr[i] != 0) {
			printf("%d ", arr[i]);
		}
	}
	return 0;
}

int at(int n, int* arr) {
	arr[1] = 0;

	for (int i = 2; i <= n; i++) {
		int m = 2;
		if (arr[i] != 0) {
			while ((i * m) < n) {
				arr[i * m] = 0;
				m++;
			}
		}
	}
	return 0;
}

