#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//
// Created by HolyChan on 2024. 7. 10..
//

//string 함수 선언, 정의는 main 아래에 정의 후 구현
int my_strlen(char *arr1);
int my_strcmp(char *arr1, char *arr2);
void my_strcpy(char *arr1, char *arr2);
void my_strcat(char *arr1, char *arr2);

int main() {
    char arr1[50], arr2[50];

    scanf("%s", arr1);
    scanf("%s", arr2);

	int result_strlen = my_strlen(arr1);
	int result_strcmp = my_strcmp(arr1, arr2);

	printf("check my_strlen method: %d\n", result_strlen);
	printf("check my_strcmp method: %d\n", result_strcmp);

	my_strcpy(arr1, arr2);
	printf("check my_strcpy method, arr1: %s\n", arr1);
	printf("check my_strcpy method, arr2: %s\n", arr2);
	printf("check my_strcmp method: %d\n", my_strcmp(arr1, arr2));

	my_strcat(arr1, arr2);
	printf("check my_strcat method: %s", arr1);


    return 0;
}

int my_strlen(char *arr){
	int length = 0;

	while(1){
		if(*(arr + length) == '\0'){
			break;
		}

		length++;
	}

	return length;
}

int my_strcmp(char *arr1, char *arr2){
	int arr1_aski = 0;
	int arr2_aski = 0;
	int index = 0;
	int isEnd_arr1 = 1;
	int isEnd_arr2 = 1;
	while(isEnd_arr1 || isEnd_arr2){
		if(*(arr1 + index) != '\0'){
			arr1_aski += *(arr1 + index);
		}
		if(*(arr1 + index) == '\0'){
			isEnd_arr1 = 0;
		}

		if(*(arr2 + index) != '\0'){
			arr2_aski += *(arr2 + index);
		}
		if(*(arr2 + index) == '\0'){
			isEnd_arr2 = 0;
		}
		index++;
	}

	return arr1_aski - arr2_aski;
}

void my_strcpy(char *arr1, char *arr2){
	for(int i = 0; i < 50; i++){
		*(arr1 + i) = *(arr2 + i);
	}
}

void my_strcat(char *arr1, char *arr2){
	int start_index = my_strlen(arr1);
	for(int i = 0; i < my_strlen(arr2); i++){
		*(arr1 + i + start_index) = *(arr2 + i);
	}
	*(arr1 + start_index + my_strlen(arr2)) = '\0';
}