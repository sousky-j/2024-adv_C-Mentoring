#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    char a[5][21];//2차원 배열 선언
    int max = 0;
    int lenth = 0;

    for (int i = 0; i < 5; i++) {
        scanf("%s", a[i]);//5개의 배열에 입력
    }

    for (int i = 0; i < 5; i++) {//5개의 배열 중에서
        lenth = strlen(a[i]);
        if (max < lenth) {
            max = lenth;//가장 길이가 긴 배열의 길이를 max에 담음
        }
    }

    for (int i = 0; i < max; i++) {//max번 반복
        for (int j = 0; j < 5; j++) {
            if (i < strlen(a[j])) {//i가 문자열 길이보다 작을때만 출력
                printf("%c", a[j][i]);
            }
        }
    }

}
