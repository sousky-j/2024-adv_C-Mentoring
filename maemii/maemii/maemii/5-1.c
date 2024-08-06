#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct library {
    int id;
    char name[50];
    int num;
}Library;

typedef struct borrow {
    int id;
    char name[50];
}Borrow;

void initial_booklist();

void manage_booklist();

void print_booklist();

int main() {
    FILE* fp;
    fp = fopen("book.txt", "r");

    Library* book = (Library*)malloc(sizeof(Library) * 21);
    Borrow* borrowbook = (Borrow*)malloc(sizeof(Borrow) * 63);

    int huhhuh = 0;

    initial_booklist(book, fp);
    while (1) {
        int id;
        print_booklist(book);
        printf("빌릴 책의 ID를 입력해주세요. (0 입력 시 종료) : ");
        scanf("%d", &id);

        if (id == 0)
            break;
        else if (id < 0 || id>21)
            printf("존재하지 않는 책입니다. 다시 입력해 주십시오. \n\n");
        else {
            if (book[id - 1].num > 0) {
                book[id - 1].num--;
                printf("책을 대출했습니다!\n\n", huhhuh);
                manage_booklist(book, borrowbook, fp, id, huhhuh);
                huhhuh++;
            }
            else
                printf("재고가 소진된 책입니다.\n\n");
        }
    }

    free(borrowbook);
    free(book);
    fclose(fp);
    return 0;
}

void initial_booklist(Library* book, FILE* fp) {
    for (int i = 0; i < 21; i++) {
        book[i].id = i + 1;
        fgets(book[i].name, 50, fp);
        book[i].num = 3;
    }
}

void manage_booklist(Library* book, Borrow* borrowbook, FILE* fp, int id, int huhhuh) {
    strcpy(borrowbook[huhhuh].name, book[id - 1].name);
    borrowbook[huhhuh].id = book[id - 1].id;

    printf("========= Borrowed Book List =========\n");

    for (int i = 0; i < huhhuh + 1; i++)
        printf("%d : %s", borrowbook[i].id, borrowbook[i].name);

    printf("======================================\n\n");
}

void print_booklist(Library* book) {
    printf("=============== Book List ===============\n");

    for (int i = 0; i < 21; i++)
        printf("%d : %s\n", book[i].id, book[i].name);

    printf("========================================\n\n");
}