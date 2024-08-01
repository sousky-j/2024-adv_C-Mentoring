#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
struct data {
	int ID;
	char* name;
	int number;
	int borrow;
};
initial_booklist(struct data** book);
manage_booklist(int index, int t, struct data* book);
int main() {
	struct data* book = (struct data*)malloc(sizeof(struct data));
	int index = initial_booklist(&book);
	while (1) {
		int N;
		printf("========== Book list ==========\n");
		for (int i = 0; i < index; i++) {
			printf("%d : %s", book[i].ID, book[i].name);
		}
		printf("\n===============================\nType the book id to borrow(0 to end) : ");
		scanf("%d", &N);
		if (0 < N && N <= index) {
			int t = N - 1;
			if (book[t].number > 0) {
				printf("Borrow a Book.\n");
				manage_booklist(index, t, book);
			}
			else {
				printf("The Book is out of stock.\n");
			}
		}
		else if (N == 0) {
			break;
		}
		else {
			printf("ID not exist.\n");
		}
	}
	for (int i = 0; i < index; i++) {
		free(book[i].name);
	}
	free(book);
	return 0;
}
initial_booklist(struct data** book) {
	FILE* fp = fopen("book.txt", "r");
	int index = 0;
	while (!feof(fp)) {
		char NAME[101];
		fgets(NAME, 101, fp);
		*book = (struct data*)realloc(*book, sizeof(struct data) * (index + 1));
		(*book)[index].name = (char*)malloc(sizeof(char) * (strlen(NAME) + 1));
		strcpy((*book)[index].name, NAME);
		(*book)[index].number = 3;
		(*book)[index].borrow = 0;
		(*book)[index].ID = index + 1;
		index++;
	}
	fclose(fp);
	return index;
}
manage_booklist(int index, int t, struct data* book) {
	book[t].number--;
	book[t].borrow++;
	printf("==========  Borrow Book list ==========\n");
	for (int i = 0; i < index; i++) {
		if (book[i].borrow > 0) {
			for (int j = 0; j < book[i].borrow; j++) {
				printf("%d : %s", book[i].ID, book[i].name);
			}
		}
	}
	printf("=========================================\n");
	return 0;
}