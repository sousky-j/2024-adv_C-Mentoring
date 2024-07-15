#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
int main() {
    int N, n;
    int ten = 1;
    int index = 0;
    int score[4] = { 0 };
    char nine[5] = "IXCM";
    char save[7] = "DCLXVI";
    int len;
    char* result;
    result = (char*)malloc(sizeof(char) * index);
    printf("변환 수 입력 : ");
    scanf("%d", &N);
    n = N;
    for (int i = 3; i >= 0; i--) {
        score[i] = N % 10;
        N = N / 10;
    }
    printf("%d=", n);
    for (int i = 0; i < 4; i++) {
        for (int j = i; j < 3; j++) ten = ten * 10;
        printf("%d", score[i] * ten);
        ten = 1;
        if (i < 3) printf("+");
        if (i == 3) printf("=");
        len = index;
    }
    if (score[0] == 1) {
        index += 1;
        result = (char*)realloc(result, sizeof(char) * index);
        result[0] = 'M';
        len = index;
    }
    for (int t = 0; t < 3; t++) {
        if (score[t + 1] == 9) {
            index += 2;
            result = (char*)realloc(result, sizeof(char) * index);
            result[len] = nine[2 - t];
            result[len + 1] = nine[3 - t];
            len = index;
        }
        else if (score[t + 1] < 9 && score[t + 1] >= 5) {
            index += score[t + 1] - 4;
            result = (char*)realloc(result, sizeof(char) * index);
            result[len] = save[2 * t];
            for (int i = 0; i < score[t + 1] - 5; i++) result[len + i + 1] = save[(2 * t) + 1];
            len = index;
        }
        else if (score[t + 1] == 4) {
            index += 2;
            result = (char*)realloc(result, sizeof(char) * index);
            result[len] = save[(2 * t) + 1];
            result[len + 1] = save[2 * t];
            len = index;
        }
        else if (score[t + 1] < 4 && score[t + 1] >= 1) {
            index += score[t + 1];
            result = (char*)realloc(result, sizeof(char) * index);
            for (int i = 0; i < score[t + 1]; i++) result[len + i] = save[(2 * t) + 1];
            len = index;
        }
    }
    for (int i = 0; i < len; i++) printf("%c", result[i]);
    return 0;
}

