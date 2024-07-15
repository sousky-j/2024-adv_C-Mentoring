#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#pragma warning(disable:6031)

int main(void) {

	int n,q,x,y;
	
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d", &q);
	int* result = (int*)malloc(sizeof(int) * q);

	for (int i = 0; i < q; i++) {
		result[i] = 0;
		x = 0;
		y = 0;
		scanf("%d %d", &x, &y);
		for (int j = x - 1; j < y; j++) {
			result[i] += arr[j];
		}
	}
	for (int k = 0; k < q; k++) {
		printf("%d\n", result[k]);
	}
	free(arr);
	free(result);
}