#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap_values(int* ptr1,int* ptr2);

int main()
{
	int num1 = 10;
	int num2 = 20;
	int* ptr1 = &num1;
	int* ptr2 = &num2;
	printf("교환 이전: num1 = %d, num2 = %d\n", num1, num2);
	swap_values(ptr1,ptr2);
	printf("교환 이후: num1 = %d, num2 = %d\n", num1, num2);
	return 0;
}
void swap_values(int* ptr1,int* ptr2)
{
	int** dptr1 = &ptr1;
	int** dptr2 = &ptr2;
	int tmp;
	tmp = **dptr1;
	**dptr1 = **dptr2;
	**dptr2 = tmp;
}