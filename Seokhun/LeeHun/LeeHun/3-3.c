#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE* fp = fopen("menu.txt", "r");
    char** menu = (char**)malloc(sizeof(char*));
    int* cost = (int*)malloc(sizeof(int));
    int Number = 0;
    int result = 0;
    while (!feof(fp)) {
        char food[101];
        int price;
        fscanf(fp, "%[^:]:%d\n", food, &price);
        menu[Number] = (char*)malloc(sizeof(char) * (strlen(food) + 1));
        strcpy(menu[Number], food);
        menu = (char**)realloc(menu, sizeof(char*) * (Number + 2));
        cost[Number] = price;
        cost = (int*)realloc(cost, sizeof(int) * (Number + 2));
        Number++;
    }
    int* count = (int*)calloc(Number, sizeof(int));
    printf("메뉴 정보\n");
    for (int i = 0; i < Number; i++) {
        printf("%d번 %s 가격:%d원\n", i + 1, menu[i], cost[i]);
    }
    int order;
    while (1) {
        int sign = 0;
        printf("주문하실 메뉴 번호를 입력해주세요.(0번 선택시 주문이 종료됩니다):");
        scanf("%d", &order);
        if (order == 0) {
            printf("주문이 종료되었습니다. 영수증은 receipt.txt에서 확인해주세요");
            break;
        }
        for (int i = 0; i < Number; i++) {
            if (order == i + 1) {
                count[i]++;
                sign++;
                break;
            }
        }
        if (sign == 0) {
            printf("잘못된 메뉴 번호입니다. 다시 입력해주세요.\n");
        }
    }
    fclose(fp);
    FILE* FP = fopen("receipt.txt", "w");
    fprintf(FP, "========결제 내역========\n");
    for (int i = 0; i < Number; i++) {
        if (count[i] > 0) {
            fprintf(FP, "%d번 %s 가격:%d원 x %d\n", i + 1, menu[i], cost[i], count[i]);
            result += cost[i] * count[i];
        }
    }
    fprintf(FP, "총 결제 금액:%d원", result);
    fclose(FP);
    for (int i = 0; i < Number; i++) {
        free(menu[i]);
        free(cost[i]);
        free(count[i]);
    }
    free(menu);
    free(cost);
    free(count);
    return 0;
}
