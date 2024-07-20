#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main(void) {
    char** mat = (char**)malloc(sizeof(char*));
    char** MAT = (char**)malloc(sizeof(char*));
    int* number = (int*)malloc(sizeof(int));
    int* NUMBER = (int*)malloc(sizeof(int));
    int* score = (int*)malloc(sizeof(int));
    int* SCORE = (int*)malloc(sizeof(int));
    int count = 1;
    int COUNT = 1;
    int len, LEN, sign;
    FILE* fp = fopen("word1.txt", "r");
    int num, cost;
    char name[101], subject[101];
    fscanf(fp, "%d:%[^:]:%[^:]:%d", &num, name, subject, &cost);
    len = strlen(name);
    LEN = strlen(subject);
    mat[0] = (char*)malloc(sizeof(char) * (len + 1));
    MAT[0] = (char*)malloc(sizeof(char) * (LEN + 1));
    strcpy(mat[0], name);
    strcpy(MAT[0], subject);
    number[0] = 1;
    NUMBER[0] = 1;
    score[0] = cost;
    SCORE[0] = cost;
    while (!feof(fp)) {
        fscanf(fp, "%d:%[^:]:%[^:]:%d", &num, name, subject, &cost);
        sign = 0;
        len = strlen(name);
        LEN = strlen(subject);
        for (int i = 0; i < count; i++) {
            if (strcmp(mat[i], name) == 0) {
                number[i]++;
                score[i] += cost;
                sign++;
            }
        }
        if (sign == 0) {
            count++;
            mat = (char**)realloc(mat, sizeof(char*) * count);
            mat[count - 1] = (char*)malloc(sizeof(char) * (len + 1));
            strcpy(mat[count - 1], name);
            score = (int*)realloc(score, sizeof(int) * count);
            number = (int*)realloc(number, sizeof(int) * count);
            number[count - 1] = 1;
            score[count - 1] = cost;
        }
        sign = 0;
        for (int i = 0; i < COUNT; i++) {
            if (strcmp(MAT[i], subject) == 0) {
                NUMBER[i]++;
                SCORE[i] += cost;
                sign++;
            }
        }
        if (sign == 0) {
            COUNT++;
            MAT = (char**)realloc(MAT, sizeof(char*) * COUNT);
            MAT[COUNT - 1] = (char*)malloc(sizeof(char) * (LEN + 1));
            strcpy(MAT[COUNT - 1], subject);
            SCORE = (int*)realloc(SCORE, sizeof(int) * COUNT);
            NUMBER = (int*)realloc(NUMBER, sizeof(int) * COUNT);
            NUMBER[COUNT - 1] = 1;
            SCORE[COUNT - 1] = cost;
        }
    }
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(mat[i], mat[j]) > 0) {
                char* p = mat[i];
                mat[i] = mat[j];
                mat[j] = p;
                int t = score[i];
                score[i] = score[j];
                score[j] = t;
                int k = number[i];
                number[i] = number[j];
                number[j] = k;

            }
        }
    }
    printf("학생별 평균 점수:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %.1f\n", mat[i], (float)score[i] / number[i]);
    }
    for (int i = 0; i < COUNT - 1; i++) {
        for (int j = i + 1; j < COUNT; j++) {
            if (strcmp(MAT[i], MAT[j]) > 0) {
                char* p = MAT[i];
                MAT[i] = MAT[j];
                MAT[j] = p;
                int t = SCORE[i];
                SCORE[i] = SCORE[j];
                SCORE[j] = t;
                int k = NUMBER[i];
                NUMBER[i] = NUMBER[j];
                NUMBER[j] = k;
            }
        }
    }
    printf("과목별 평균 점수:\n");
    for (int i = 0; i < COUNT; i++) {
        printf("%s: %.1f\n", MAT[i], (float)SCORE[i] / NUMBER[i]);
    }
    fclose(fp);
    for (int i = 0; i < count; i++) {
        free(mat[i]);
    }
    free(mat);
    free(number);
    free(score);
    for (int i = 0; i < COUNT; i++) {
        free(MAT[i]);
    }
    free(MAT);
    free(NUMBER);
    free(SCORE);
    return 0;
}