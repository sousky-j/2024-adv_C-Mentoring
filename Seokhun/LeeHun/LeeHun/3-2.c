#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
int sort_Ascending(char** dictionary, int count);
int sort_Descending(char** dictionary, int count);
int write_result_to_file(char** dictionary, FILE* fp, int count);
int print_result(char** dictionary, int count);
int main() {
    int i = 0;
    FILE* fp = fopen("words.txt", "r");
    char** data = (char**)malloc(sizeof(char*) * 5);
    char** dictionary = (char**)malloc(sizeof(char*) * 20);
    while (!feof(fp)) {
        char line[1001];
        fgets(line, 1001, fp);
        data[i] = (char*)malloc(sizeof(char) * (strlen(line) + 1));
        strcpy(data[i], line);
        i++;
    }
    int index = 0;
    i = 0;
    int len = 0;
    int d_len = -1;
    while (1) {
        if (index == 19) {
            break;
        }
        char word[101];
        d_len++;
        if (data[i][len + d_len] != '|' && data[i][len + d_len] != '\n') {
            word[d_len] = data[i][len + d_len];
        }
        else {
            len += d_len + 1;
            word[d_len] = '\0';
            d_len = -1;
            if (strcmp(word, "\0") != 0) {
                int w_len = strlen(word);
                dictionary[index] = (char*)malloc(sizeof(char) * (w_len + 1));
                strcpy(dictionary[index], word);
                index++;
            }
            if (data[i][len + d_len] == '\n') {
                i++;
                len = 0;
                d_len = -1;
            }
            memset(word, 0, sizeof(word));
        }
    }
    sort_Descending(dictionary, index);
    print_result(dictionary, index);
    write_result_to_file(dictionary, "Result_Descending.txt", index);
    sort_Ascending(dictionary, index);
    print_result(dictionary, index);
    write_result_to_file(dictionary, "Result_Ascending.txt", index);
    for (int i = 0; i < 5; i++) {
        free(data[i]);
    }
    for (int i = 0; i < 20; i++) {
        free(dictionary[i]);
    }
    free(dictionary);
    free(data);
    fclose(fp);
    return 0;
}
int sort_Ascending(char** dictionary, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(dictionary[i], dictionary[j]) > 0) {
                char* p = dictionary[i];
                dictionary[i] = dictionary[j];
                dictionary[j] = p;
            }
        }
    }
    return 0;
}
int sort_Descending(char** dictionary, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(dictionary[i], dictionary[j]) < 0) {
                char* p = dictionary[i];
                dictionary[i] = dictionary[j];
                dictionary[j] = p;
            }
        }
    }
    return 0;
}
int write_result_to_file(char** dictionary, char* name, int count) {
    FILE* fp = fopen(name, "w");
    fprintf(fp, "========sorting Result========\n");
    for (int i = 0; i < count; i++) {
        fprintf(fp, "[");
        for (int j = 0; j < (9 - strlen(dictionary[i])); j++) {
            fprintf(fp, " ");
        }
        fprintf(fp, "%s]\n", dictionary[i]);
    }
    fclose(fp);
    return 0;
}
int print_result(char** dictionary, int count) {
    printf("========sorting Result========\n");
    for (int i = 0; i < count; i++) {
        printf("[");
        for (int j = 0; j < (9 - strlen(dictionary[i])); j++) {
            printf(" ");
        }
        printf("%s]\n", dictionary[i]);
    }
    return 0;
}