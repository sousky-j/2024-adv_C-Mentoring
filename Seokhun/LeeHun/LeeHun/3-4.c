#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
int make_dictionary(char** dictionary, int count);
int my_strcmp(char* a, char* b);
int main() {
    int t = 0;
    int count = 0;
    int len;
    FILE* fp = fopen("words.txt", "r");
    char** dictionary = (char**)malloc(sizeof(char*));
    char word[101];
    while (!feof(fp)) {
        char token = fgetc(fp);
        if (token != ',' && token != ';' && token != ' ' && token != '|' && token != '\n' && token != '\t') {
            word[t] = token;
            t++;
        }
        else {
            word[t] = '\0';
            len = strlen(word);
            if (len != 0) {
                dictionary[count] = (char*)malloc(sizeof(char) * (len + 1));
                strcpy(dictionary[count], word);
                memset(word, 0, sizeof(word));
                count++;
                dictionary = (char**)realloc(dictionary, sizeof(char*) * (count + 1));
                t = 0;
            }
        }
    }
    make_dictionary(dictionary, count);
    for (int i = 0; i < count; i++) {
        free(dictionary[i]);
    }
    free(dictionary);
    fclose(fp);
    return 0;
}
int make_dictionary(char** dictionary, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (my_strcmp(dictionary[i], dictionary[j]) > 0) {
                char* p = dictionary[i];
                dictionary[i] = dictionary[j];
                dictionary[j] = p;
            }
        }
    }
    FILE* fp = fopen("dictionary.txt", "w");
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s\n", dictionary[i]);
    }
    fclose(fp);
    return 0;
}
int my_strcmp(char* arr1, char* arr2) {
    int first, end;
    int len = strlen(arr1);
    if (strlen(arr2) < len) {
        len = strlen(arr2);
    }
    for (int i = 0; i < len + 1; i++) {
        first = arr1[i];
        end = arr2[i];
        if (first >= 97 && first <= 122) {
            first = first - 32;
        }
        if (end >= 97 && end <= 122) {
            end = end - 32;
        }
        if (first - end != 0) {
            return first - end;
        }
        else {
            continue;
        }
    }
    return 0;
}