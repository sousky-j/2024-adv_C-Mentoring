#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void input_char(char* a, char* b);//입력 받는 함수
void func_print(char* a, char* b);//변환함수
void func_sort(char* a);//출력 함수

int main() {
    char a[101];//최대 100개의 문자열이니까 \0 포함 101개
    char b[10];//내림,오름 입력 문자열

    input_char(a, b);
    func_print(a, b);
    func_sort(a);

    return 0;
}

void input_char(char* a, char* b) {
    scanf("%s", a);//실행할 문자열 입력
    scanf("%s", b);//오름, 내림 입력

}
void func_print(char* a, char* b) {
    int lenth = strlen(a);//입력받은 문자열 길이
    char c;//변환할 변수
    for (int i = 0; i < lenth - 1; i++) {//첫번째 문자부터 반복
        for (int j = i + 1; j < lenth; j++) {//두번째 문자부터 비교
            if (strcmp(b, "오름차순") == 0 && a[i] > a[j]) {//b에서 받은 문자가 오름차순이면서 앞 글자가 더 크면
                char c = a[i];//자리 바꿈
                a[i] = a[j];
                a[j] = c;
            }
            else if (strcmp(b, "내림차순") == 0 && a[i] < a[j]) {//b에서 받은 문자가 내림차순이면서 앞글자가 더 작으면
                char c = a[i];//자리 바꿈
                a[i] = a[j];
                a[j] = c;
            }
        }
    }
}
void func_sort(char* a) {
    printf("%s", a);//바뀐 문자열 출력
}
