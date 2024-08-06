// 5주차 과제1. 도서관 도서 대여 프로그램
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct Book_list {
	int id;
	char* title;
	int num;
}Book;

int initial_booklist(int count, Book* lib);
int manage_booklist(int count, Book* lib);

int main() {
	// 구조체에 책 목록 읽어오기
	FILE* book = fopen("book.txt", "r");
	int count = 0;
	Book* lib = (Book*)malloc(sizeof(Book) * (count + 1));
	while (1) {
		if (feof(book))
			break;
		lib = (Book*)realloc(lib, sizeof(Book) * (count + 1));
		lib[count].id = count + 1;
		char tmp[50];
		fgets(tmp, 50, book);
		lib[count].title = (char*)malloc(sizeof(char) * (strlen(tmp) + 1));
		tmp[strlen(tmp)-1] = '\0';
		strcpy(lib[count].title, tmp);
		count++;
	}
	fclose(book);
	// 보유 권수 (3권) 초기화
	initial_booklist(count,lib);
	// 대여 프로그램 시작
	manage_booklist(count,lib);

	// free
	for (int i = 0; i < count; i++) {
		free(lib[i].title);
	}
	free(lib);
}

int initial_booklist(int count, Book* lib) {
	for (int i = 0; i < count; i++) {
		lib[i].num = 3;
	}
}

int manage_booklist(int count, Book* lib) {
	int bo_num = 0;
	int* bo_list = (int*)malloc(sizeof(int) * 1);
	int n;
	while (1) {
		// 책 리스트 출력
		printf("========== Book list ==========\n");
		for (int i = 0; i < count; i++) {
			printf("%d : %s\n", lib[i].id, lib[i].title);
		}
		printf("=================================\n");
		// 책 id 입력 받기
		printf("Type the book id to borrow(0 to end) : ");
		scanf("%d", &n);

		// 0 입력시 프로그램 종료
		if (n == 0) {
			printf("Exit the program.\n");
			break;
		}
		// 목록에 없는 책일 경우
		else if (n > count)
			printf("There is no the book on list.\n");
		// 책 재고가 없을 경우
		else if (lib[n - 1].num == 0)
			printf("The Book is out of stock.\n");
		// 책 대여
		else {
			printf("Borrow a Book.\n");
			bo_num++;
			lib[n - 1].num--;
		}

		// 대여 목록 없을 경우 출력 안함
		if (bo_num == 0)
			continue;
		// 대여한 책 목록 출력
		else {
			printf("=========== Borrowed Book List ============\n");
			bo_list = (int*)realloc(bo_list, sizeof(int) * bo_num);
			bo_list[bo_num - 1] = n;
			for (int i = 0; i < bo_num; i++) {
				printf("%d : %s\n", bo_list[i], lib[bo_list[i] - 1].title);
			}
			printf("=====================================\n");
		}
	}
	// free
	free(bo_list);
}