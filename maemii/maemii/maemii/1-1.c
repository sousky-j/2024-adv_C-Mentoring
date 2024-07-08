#include <stdio.h>
#include <string.h>

void func_print(char str[101], int len) {
    for (int i = 0; i < len; i++)
        printf("%c", str[i]);
}

void func_sort(char str[101], int num) {
    int tmp;
    int len = strlen(str);
    if (num == 1) {
        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j < len; j++) {
                if (str[i] > str[j]) {
                    tmp = str[i];
                    str[i] = str[j];
                    str[j] = tmp;
                }
            }
        }
    }
    else {
        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j < len; j++) {
                if (str[i] < str[j]) {
                    tmp = str[i];
                    str[i] = str[j];
                    str[j] = tmp;
                }
            }
        }
    }
    func_print(str, len);
}

void input_char(char str[101]) {
    char sortingMethod[20];
    scanf("%s", str);
    scanf("%s", sortingMethod);

    if (strcmp(sortingMethod, "내림차순"))
        func_sort(str, 1);
    else
        func_sort(str, -1);
}
int main() {
    char str[101];
    input_char(str);
    return 0;
}