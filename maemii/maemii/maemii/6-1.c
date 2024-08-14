#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct queue {
    int data;
    struct queue* next;
};

struct queue* tail = NULL;
struct queue* head = NULL;

void enqueue(int data) {
    struct queue* newnode = (struct queue*)malloc(sizeof(struct queue));
    newnode->data = data;
    newnode->next = NULL;

    if (tail == NULL) {
        tail = newnode;
        head = newnode;
    }
    else {
        tail->next = newnode;
        tail = newnode;
    }
}
void dequeue() {
    head = head->next;
    if (head == NULL)
        tail = NULL;
}
void size() {
    int size = 0;
    struct queue* tmp = head;
    while (tmp != NULL) {
        size++;
        tmp = tmp->next;
    }
    printf("%d\n", size);
}
void empty() {
    if (tail != NULL)
        printf("0\n");
    else
        printf("1\n");
}
void front() {
    if (tail != NULL)
        printf("%d\n", head->data);
    else
        printf("-1\n");
}
void back() {
    if (tail != NULL)
        printf("%d\n", tail->data);
    else
        printf("-1\n");
}

void print() {
    struct queue* tmp = head;
    while (1) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
        if (tmp == NULL) {
            printf("\n");
            break;
        }
    }
}
int input() {
    char input[10];
    int n;
    scanf("%s", input);

    if (strcmp(input, "enqueue") == 0) {
        scanf("%d", &n);
        enqueue(n);
    }
    if (strcmp(input, "dequeue") == 0)
        dequeue();
    if (strcmp(input, "size") == 0)
        size();
    if (strcmp(input, "empty") == 0)
        empty();
    if (strcmp(input, "front") == 0)
        front();
    if (strcmp(input, "back") == 0)
        back();
    if (strcmp(input, "print") == 0)
        print();
}
int main() {

    while (1)
        input();

    struct queue* current = head;
    while (current != NULL) {
        struct queue* tmp = current;
        current = current->next;
        free(tmp);
    }
    return 0;
}