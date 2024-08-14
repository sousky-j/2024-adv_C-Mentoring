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
        printf("���� å�� ID�� �Է����ּ���. (0 �Է� �� ����) : ");
        scanf("%d", &id);

        if (id == 0)
            break;
        else if (id < 0 || id>21)
            printf("�������� �ʴ� å�Դϴ�. �ٽ� �Է��� �ֽʽÿ�. \n\n");
        else {
            if (book[id - 1].num > 0) {
                book[id - 1].num--;
                printf("å�� �����߽��ϴ�!\n\n", huhhuh);
                manage_booklist(book, borrowbook, fp, id, huhhuh);
                huhhuh++;
            }
            else
                printf("��� ������ å�Դϴ�.\n\n");
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