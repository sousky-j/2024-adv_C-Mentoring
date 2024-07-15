#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//
// Created by HolyChan on 2024. 7. 15..
//

int main(){

    int string_len = 0;
    int index = 0;
    char **string = (char **)malloc(sizeof(char *) * string_len);

    // 입력
    while(1){

        char input[100];

        fgets(input, sizeof(input), stdin);

        int input_len = strlen(input) - 1;

        // 빈 줄이면 입력 중단
        if(input_len == 0) break;

        string = (char **)realloc(string, sizeof(char *) * (string_len + 1));

        string[index] = (char*) malloc(sizeof(char) * input_len);
        strncpy(string[index], input, input_len);

        index++;
        string_len++;

    }

    for(int i = 0; i < string_len; i++){
        for(int j = i; j < string_len; j++){
            if(strcmp(string[i], string[j]) > 0){
                char *temp = string[i];
                string[i] = string[j];
                string[j] = temp;
            }
        }
    }

    for(int i = 0; i < string_len; i++){
        printf("%s\n", string[i]);
    }

    for (int i = 0; i < string_len; i++) {
        free(string[i]);
    }
    free(string);




    return 0;
}
