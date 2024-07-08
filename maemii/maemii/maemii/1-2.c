#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_arr(char arr[5][21], int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 5; j++) {
            if (arr[j][i] != '\0')
                printf("%c", arr[j][i]);
        }
    }
    printf("\n");
}
int input_num(char arr[5][21]) {
    for (int i = 0; i < 5; i++)
        scanf("%s", arr[i]);
    int longlen = strlen(arr[0]);
    for (int i = 1; i < 5; i++) {
        if (longlen < strlen(arr[i]))
            longlen = strlen(arr[i]);
    }
    return longlen;

}
int main() {
    char arr[5][21];
    int len = input_num(arr);
    print_arr(arr, len);
    return 0;
}