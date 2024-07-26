#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
struct menu {
    char name[101];
    int price;
    int quantity;
    int order;
};
int check_ID();
int reset_drink_menu(int index, struct menu** information);
int reset_snack_menu(int index, struct menu** information);
int reset_gmarket(int index, struct menu** information);
int reset_coupang(int index, struct menu** information);
int service_mode(int sign, int d_index, int s_index, struct menu* information);
int printf_receipt(int d_index, int s_index, struct menu* d_information, struct menu* s_information);
int admin_mode(int total, int d_index, int s_index, int g_index, int c_index, struct menu* d_information, struct menu* s_information, struct menu* g_information, struct menu* c_information);
int order_printf(int g_index, int c_index, struct menu* g_information, struct menu* c_information);
int main() {
    int total = 0;
    int TOTAL = 0;
    struct menu* d_information = NULL;
    struct menu* s_information = NULL;
    struct menu* c_information = NULL;
    struct menu* g_information = NULL;
    int drink_num = -1;
    int snack_num = -1;
    int g_num = -1;
    int c_num = -1;
    while (1) {
        int mode = check_ID();
        if (mode == 1) {
            drink_num = reset_drink_menu(drink_num, &d_information);
            snack_num = reset_snack_menu(snack_num, &s_information);
            while (1) {
                int menu;
                printf("주문하실 음식을 선택해주세요(1번: 음료수, 2번: 스낵, 3번: 주문종료) : ");
                scanf("%d", &menu);
                if (menu == 1) {
                    service_mode(1, drink_num, snack_num, d_information, s_information);
                }
                else if (menu == 2) {
                    service_mode(2, drink_num, snack_num, d_information, s_information);
                }
                else if (menu == 3) {
                    service_mode(3, drink_num, snack_num, d_information, s_information);
                    break;
                }
                else {
                    printf("Error : Worng Input\n");
                }
            }
            total = printf_receipt(drink_num, snack_num, d_information, s_information);
            TOTAL += total;
        }
        if (mode == -1) {
            g_num = reset_gmarket(g_num, &g_information);
            c_num = reset_coupang(c_num, &c_information);
            admin_mode(TOTAL, drink_num, snack_num, g_num, c_num, d_information, s_information, g_information, c_information);
            order_printf(g_num, c_num, g_information, c_information);
        }
    }
    free(d_information);
    free(s_information);
    free(c_information);
    free(g_information);
    return 0;
}
int check_ID() {
    char mode[101];
    while (1) {
        printf("Mode Select (admin or user) : ");
        scanf("%s", mode);
        if (strcmp(mode, "user") == 0) {
            printf("user mode\n");
            return 1;
        }
        else if (strcmp(mode, "admin") == 0) {
            printf("admin mode\n");
            return -1;
        }
        else if (strcmp(mode, "exit") == 0) {
            printf("Exit the Program\n");
            return 0;
        }
        else {
            printf("Error : Worng Input\n");
        }
    }
}
int reset_drink_menu(int index, struct menu** information) {
    if ((*information)[0].name != NULL) {
        for (int i = 1; i < index; i++) {
            (*information)[i].order = 0;
        }
        return index;
    }
    else {
        FILE* fp = fopen("drink2.txt", "r");
        while (!feof(fp)) {
            index++;
            if (index == 0) {
                *information = (struct menu*)malloc(sizeof(struct menu));
            }
            else {
                *information = (struct menu*)realloc(*information, sizeof(struct menu) * (index + 1));
            }
            char p[101], q[101];
            fscanf(fp, "%s\t%s\t%s", (*information)[index].name, p, q);
            sscanf(p, "%d", &(*information)[index].price);
            sscanf(q, "%d", &(*information)[index].quantity);
            (*information)[index].order = 0;
        }
        fclose(fp);
        return index + 1;
    }
}
int reset_snack_menu(int index, struct menu** information) {
    if ((*information)[0].name != NULL) {
        for (int i = 1; i < index; i++) {
            (*information)[i].order = 0;
        }
        return index;
    }
    else {
        FILE* fp = fopen("snack2.txt", "r");
        while (!feof(fp)) {
            index++;
            if (index == 0) {
                (*information) = (struct menu*)malloc(sizeof(struct menu));
            }
            else {
                *information = (struct menu*)realloc(*information, sizeof(struct menu) * (index + 1));
            }
            char p[101], q[101];
            fscanf(fp, "%s\t%s\t%s\n", (*information)[index].name, p, q);
            sscanf(p, "%d", &(*information)[index].price);
            sscanf(q, "%d", &(*information)[index].quantity);
            (*information)[index].order = 0;
        }
        fclose(fp);
        return index + 1;
    }
}
int service_mode(int sign, int d_index, int s_index, struct menu* d_information, struct menu* s_information) {
    if (sign == 1) {
        for (int i = 0; i < d_index; i++) {
            if (i == 0) {
                printf("번호 메뉴 이름\n");
            }
            else {
                printf("%d %s %d\n", i, d_information[i].name, d_information[i].price);
            }
        }
        int Number;
        printf("주문하실 메뉴 번호를 입력해주세요 : ");
        scanf("%d", &Number);
        if (Number >= 1 && Number <= d_index - 1) {
            if (d_information[Number].quantity >= 1) {
                d_information[Number].order++;
                d_information[Number].quantity--;
            }
            else {
                printf("%s 재료가 모두 소진되었습니다. 다른 메뉴를 선택해주세요.\n", d_information[Number].name);
            }
        }
        else {
            printf("존재하지 않는 메뉴 번호입니다. 다른 메뉴를 선택해주세요.\n");
        }
    }
    if (sign == 2) {
        for (int i = 0; i < s_index; i++) {
            if (i == 0) {
                printf("번호 메뉴 이름\n");
            }
            else {
                printf("%d %s %d\n", i, s_information[i].name, s_information[i].price);
            }
        }
        int Number;
        printf("주문하실 메뉴 번호를 입력해주세요 : ");
        scanf("%d", &Number);
        if (Number >= 1 && Number <= s_index - 1) {
            if (s_information[Number].quantity >= 1) {
                s_information[Number].order++;
                s_information[Number].quantity--;
            }
            else {
                printf("%s 재료가 모두 소진되었습니다. 다른 메뉴를 선택해주세요.\n", s_information[Number].name);
            }
        }
        else {
            printf("존재하지 않는 메뉴 번호입니다. 다른 메뉴를 선택해주세요.\n");
        }
    }
    else if (sign == 3) {
        int total = 0;
        printf("======주문 내역======\n");
        for (int i = 1; i < d_index; i++) {
            if (d_information[i].order > 0) {
                printf("%s %d x%d\n", d_information[i].name, d_information[i].price, d_information[i].order);
                total += d_information[i].price * d_information[i].order;
            }
        }
        for (int i = 1; i < s_index; i++) {
            int t = i - 1;
            if (s_information[i].order > 0) {
                printf("%s %d x%d\n", s_information[i].name, s_information[i].price, s_information[i].order);
                total += s_information[i].price * s_information[i].order;
            }
        }
        printf("=====================\n총 합계 금액: %d원\n", total);
    }
    return 0;
}
int printf_receipt(int d_index, int s_index, struct menu* d_information, struct menu* s_information) {
    FILE* fp = fopen("receipt.txt", "w");
    fprintf(fp, "======주문 내역======\n");
    int total = 0;
    for (int i = 1; i < d_index; i++) {
        if (d_information[i].order > 0) {
            fprintf(fp, "%s %d x%d\n", d_information[i].name, d_information[i].price, d_information[i].order);
            total += d_information[i].price * d_information[i].order;
        }
    }
    for (int i = 1; i < s_index; i++) {
        int t = i - 1;
        if (s_information[i].order > 0) {
            fprintf(fp, "%s %d x%d\n", d_information[i].name, d_information[i].price, s_information[i].order);
            total += s_information[i].price * s_information[i].order;
        }
    }
    fprintf(fp, "=====================\n총 합계 금액: %d원\n", total);
    fclose(fp);
    return total;
}
int admin_mode(int total, int d_index, int s_index, int g_index, int c_index, struct menu* d_information, struct menu* s_information, struct menu* g_information, struct menu* c_information) {
    int inventory = 0;
    char data[101];
    int finance;
    FILE* fp = fopen("asset.txt", "r");
    fscanf(fp, "%s", data);
    sscanf(data, "%d", &finance);
    finance += total;
    fclose(fp);
    for (int i = 1; i < d_index; i++) {
        if (d_information[i].quantity == 0) {
            inventory++;
        }
    }
    for (int i = 1; i < s_index; i++) {
        if (s_information[i].quantity == 0) {
            inventory++;
        }
    }
    if (inventory >= 3) {
        int g_price, c_price, g_quantity, c_quantity, t;
        for (int i = 1; i < d_index; i++) {
            if (d_information[i].quantity == 0) {
                printf("=====================\n");
                printf("재고량 0인 항목 : %s\n", d_information[i].name);
                for (int j = 1; j < g_index; j++) {
                    if (strcmp(g_information[j].name, d_information[i].name) == 0) {
                        g_price = g_information[j].price;
                        g_quantity = g_information[j].quantity;
                        t = j;
                        break;
                    }
                    else {
                        g_price = 0;
                        g_quantity = 0;
                    }
                }
                for (int j = 1; j < c_index; j++) {
                    if (strcmp(g_information[j].name, d_information[i].name) == 0) {
                        c_price = c_information[j].price;
                        c_quantity = c_information[j].quantity;
                        t = j;
                        break;
                    }
                    else {
                        c_price = 0;
                        c_quantity = 0;
                    }
                }
                if (g_quantity >= 5 && c_quantity >= 5) {
                    if (c_price >= g_price) {
                        printf("개당 가격 : %d\n", g_information[t].price);
                        printf("현재 자산 : %d\n현재 gmarket 재고량 : %d\n재고 주문수를 입력해주세요(5개 단위로 입력) : ", finance, g_quantity);
                        scanf("%d", &g_information[t].order);
                        if (finance - (g_information[t].order * g_price) > 0) {
                            finance -= g_information[t].order * g_price;
                            g_information[t].quantity -= g_information[t].order;
                        }
                        else {
                            int num = 0;
                            while (finance - (num + 5) * g_price > 0) {
                                num += 5;
                            }
                            finance -= num * g_price;
                            g_information[t].order = num;
                            g_information[t].quantity -= g_information[t].order;
                            printf("금액이 부족하여 주문 가능한 만큼 주문합니다. 주문량 :%d\n", num);
                        }
                    }
                    else {
                        printf("개당 가격 : %d\n", c_information[t].price);
                        printf("현재 자산 : %d\n현재 coupang 재고량 : %d\n재고 주문수를 입력해주세요(5개 단위로 입력) : ", finance, c_quantity);
                        scanf("%d", &c_information[t].order);
                        if (finance - (c_information[t].order * c_price) > 0) {
                            finance -= c_information[t].order * c_price;
                            c_information[t].quantity -= c_information[t].order;
                        }
                        else {
                            int num = 0;
                            while (finance - (num + 5) * c_price > 0) {
                                num += 5;
                            }
                            finance -= num * c_price;
                            c_information[t].order = num;
                            c_information[t].quantity -= c_information[t].order;
                            printf("금액이 부족하여 주문 가능한 만큼 주문합니다. 주문량 :%d\n", num);
                        }
                    }
                }
                else if (g_quantity < 5 && c_quantity >= 5) {
                    printf("개당 가격 : %d\n", c_information[t].price);
                    printf("현재 자산 : %d\n현재 coupang 재고량 : %d\n재고 주문수를 입력해주세요(5개 단위로 입력) : ", finance, c_quantity);
                    scanf("%d", &c_information[t].order);
                    if (finance - (c_information[t].order * c_price) > 0) {
                        finance -= c_information[t].order * c_price;
                        c_information[t].quantity -= c_information[t].order;
                    }
                    else {
                        int num = 0;
                        while (finance - (num + 5) * c_price > 0) {
                            num += 5;
                        }
                        finance -= num * c_price;
                        c_information[t].order = num;
                        c_information[t].quantity -= c_information[t].order;
                        printf("금액이 부족하여 주문 가능한 만큼 주문합니다. 주문량 :%d\n", num);
                    }
                }
                else if (g_quantity >= 5 && c_quantity < 5) {
                    printf("개당 가격 : %d\n", g_information[t].price);
                    printf("현재 자산 : %d\n현재 gmarket 재고량 : %d\n재고 주문수를 입력해주세요(5개 단위로 입력) : ", finance, g_quantity);
                    scanf("%d", &g_information[t].order);
                    if (finance - (g_information[t].order * g_price) > 0) {
                        finance -= g_information[t].order * g_price;
                        g_information[t].quantity -= g_information[t].order;
                    }
                    else {
                        int num = 0;
                        while (finance - (num + 5) * g_price > 0) {
                            num += 5;
                        }
                        finance -= num * g_price;
                        g_information[t].order = num;
                        g_information[t].quantity -= g_information[t].order;
                        printf("금액이 부족하여 주문 가능한 만큼 주문합니다. 주문량 :%d\n", num);
                    }
                }
                else if (g_quantity < 5 && c_quantity < 5) {
                    printf("재고가 부족하여 재고 주문을 할 수 없습니다.\n");
                }
            }
        }
        for (int i = 1; i < s_index; i++) {
            if (s_information[i].quantity == 0) {
                printf("=====================\n");
                printf("재고량 0인 항목 : %s\n", s_information[i].name);
                for (int j = 1; j < g_index; j++) {
                    if (strcmp(g_information[j].name, s_information[i].name) == 0) {
                        g_price = g_information[j].price;
                        g_quantity = g_information[j].quantity;
                        t = j;
                        break;
                    }
                    else {
                        g_price = 0;
                        g_quantity = 0;
                    }
                }
                for (int j = 1; j < c_index; j++) {
                    if (strcmp(g_information[j].name, s_information[i].name) == 0) {
                        c_price = c_information[j].price;
                        c_quantity = c_information[j].quantity;
                        t = j;
                        break;
                    }
                    else {
                        c_price = 0;
                        c_quantity = 0;
                    }
                }
                if (g_quantity >= 5 && c_quantity >= 5) {
                    if (c_price >= g_price) {
                        printf("개당 가격 : %d\n", g_information[t].price);
                        printf("현재 자산 : %d\n현재 gmarket 재고량 : %d\n재고 주문수를 입력해주세요(5개 단위로 입력) : ", finance, g_quantity);
                        scanf("%d", &g_information[t].order);
                        if (finance - (g_information[t].order * g_price) > 0) {
                            finance -= g_information[t].order * g_price;
                            g_information[t].quantity -= g_information[t].order;
                        }
                        else {
                            int num = 0;
                            while (finance - (num + 5) * g_price > 0) {
                                num += 5;
                            }
                            finance -= num * g_price;
                            g_information[t].order = num;
                            g_information[t].quantity -= g_information[t].order;
                            printf("금액이 부족하여 주문 가능한 만큼 주문합니다. 주문량 :%d\n", num);
                        }
                    }
                    else {
                        printf("개당 가격 : %d\n", c_information[t].price);
                        printf("현재 자산 : %d\n현재 coupang 재고량 : %d\n재고 주문수를 입력해주세요(5개 단위로 입력) : ", finance, c_quantity);
                        scanf("%d", &c_information[t].order);
                        if (finance - (c_information[t].order * c_price) > 0) {
                            finance -= c_information[t].order * c_price;
                            c_information[t].quantity -= c_information[t].order;
                        }
                        else {
                            int num = 0;
                            while (finance - (num + 5) * c_price > 0) {
                                num += 5;
                            }
                            finance -= num * c_price;
                            c_information[t].order = num;
                            c_information[t].quantity -= c_information[t].order;
                            printf("금액이 부족하여 주문 가능한 만큼 주문합니다. 주문량 :%d\n", num);
                        }
                    }
                }
                else if (g_quantity < 5 && c_quantity >= 5) {
                    printf("개당 가격 : %d\n", c_information[t].price);
                    printf("현재 자산 : %d\n현재 coupang 재고량 : %d\n재고 주문수를 입력해주세요(5개 단위로 입력) : ", finance, c_quantity);
                    scanf("%d", &c_information[t].order);
                    if (finance - (c_information[t].order * c_price) > 0) {
                        finance -= c_information[t].order * c_price;
                        c_information[t].quantity -= c_information[t].order;
                    }
                    else {
                        int num = 0;
                        while (finance - (num + 5) * c_price > 0) {
                            num += 5;
                        }
                        finance -= num * c_price;
                        c_information[t].order = num;
                        c_information[t].quantity -= c_information[t].order;
                        printf("금액이 부족하여 주문 가능한 만큼 주문합니다. 주문량 :%d\n", num);
                    }
                }
                else if (g_quantity >= 5 && c_quantity < 5) {
                    printf("개당 가격 : %d\n", g_information[t].price);
                    printf("현재 자산 : %d\n현재 gmarket 재고량 : %d\n재고 주문수를 입력해주세요(5개 단위로 입력) : ", finance, g_quantity);
                    scanf("%d", &g_information[t].order);
                    if (finance - (g_information[t].order * g_price) > 0) {
                        finance -= g_information[t].order * g_price;
                        g_information[t].quantity -= g_information[t].order;
                    }
                    else {
                        int num = 0;
                        while (finance - (num + 5) * g_price > 0) {
                            num += 5;
                        }
                        finance -= num * g_price;
                        g_information[t].order = num;
                        g_information[t].quantity -= g_information[t].order;
                        printf("금액이 부족하여 주문 가능한 만큼 주문합니다. 주문량 :%d\n", num);
                    }
                }
                else if (g_quantity < 5 && c_quantity < 5) {
                    printf("재고가 부족하여 재고 주문을 할 수 없습니다.\n");
                }
            }
        }
    }
    else {
        printf("재고량이 0인 메뉴가 3개 이상일때 재고 주문을 할 수 있습니다.\n");
    }
    fp = fopen("asset.txt", "w");
    fprintf(fp, "%d\n", finance);
    fclose(fp);
    return 0;
}
int order_printf(int g_index, int c_index, struct menu* g_information, struct menu* c_information) {
    int total, finance;
    total = 0;
    char f[101];
    FILE* fp = fopen("asset.txt", "r");
    fscanf(fp, "%s", f);
    sscanf(f, "%d", &finance);
    fclose(fp);
    printf("======주문 내역======\n");
    for (int i = 1; i < g_index; i++) {
        if (g_information[i].order > 0) {
            printf("%s %d x%d\n", g_information[i].name, g_information[i].price, g_information[i].order);
            total += g_information[i].price * g_information[i].order;
        }
    }
    for (int i = 1; i < c_index; i++) {
        int t = i - 1;
        if (c_information[i].order > 0) {
            printf("%s %d x%d\n", c_information[i].name, c_information[i].price, c_information[i].order);
            total += c_information[i].price * c_information[i].order;
        }
    }
    printf("=====================\n\t\t %d원\n\t\t-%d원\n=====================\n\t\t %d원\n", total + finance, total, finance);
    return 0;
}
int reset_gmarket(int index, struct menu** information) {
    if ((*information)[0].name != NULL) {
        for (int i = 1; i < index; i++) {
            (*information)[i].order = 0;
        }
        return index;
    }
    else {
        FILE* fp = fopen("gmarket.txt", "r");
        while (!feof(fp)) {
            index++;
            if (index == 0) {
                *information = (struct menu*)malloc(sizeof(struct menu));
            }
            else {
                *information = (struct menu*)realloc(*information, sizeof(struct menu) * (index + 1));
            }
            char p[101], q[101];
            fscanf(fp, "%s\t%s\t%s", (*information)[index].name, p, q);
            sscanf(p, "%d", &(*information)[index].price);
            sscanf(q, "%d", &(*information)[index].quantity);
            (*information)[index].order = 0;
        }
        fclose(fp);
        return index + 1;
    }
}
int reset_coupang(int index, struct menu** information) {
    if ((*information)[0].name != NULL) {
        for (int i = 1; i < index; i++) {
            (*information)[i].order = 0;
        }
        return index;
    }
    else {
        FILE* fp = fopen("coupang.txt", "r");
        while (!feof(fp)) {
            index++;
            if (index == 0) {
                *information = (struct menu*)malloc(sizeof(struct menu));
            }
            else {
                *information = (struct menu*)realloc(*information, sizeof(struct menu) * (index + 1));
            }
            char p[101], q[101];
            fscanf(fp, "%s\t%s\t%s", (*information)[index].name, p, q);
            sscanf(p, "%d", &(*information)[index].price);
            sscanf(q, "%d", &(*information)[index].quantity);
            (*information)[index].order = 0;
        }
        fclose(fp);
        return index + 1;
    }
}
