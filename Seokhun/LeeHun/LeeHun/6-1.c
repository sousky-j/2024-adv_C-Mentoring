#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
struct Node {
	int data;
	struct Node* next;
};
struct Queue {
	struct Node* front;
	int count;
	struct Node* back;
};
int enque(int num, struct Queue* queue);
int deque(struct Queue* queue);
int print(struct Queue* queue);
int size(struct Queue* queue);
int empty(struct Queue* queue);
int front(struct Queue* queue);
int back(struct Queue* queue);
int main() {
	struct Queue queue;
	queue.front = NULL;
	queue.count = 0;
	queue.back = NULL;
	while (1) {
		char command[101];
		scanf("%s", command);
		if (strcmp(command, "enqueue") == 0) {
			int num;
			scanf("%d", &num);
			enque(num, &queue);
		}
		else if (strcmp(command, "print") == 0) {
			print(&queue);
		}
		else if (strcmp(command, "size") == 0) {
			size(&queue);
		}
		else if (strcmp(command, "dequeue") == 0) {
			int data = deque(&queue);
			printf("%d\n", data);
		}
		else if (strcmp(command, "empty") == 0) {
			int data = empty(&queue);
			printf("%d\n", data);
		}
		else if (strcmp(command, "front") == 0) {
			int data = front(&queue);
			printf("%d\n", data);
		}
		else if (strcmp(command, "back") == 0) {
			int data = back(&queue);
			printf("%d\n", data);
		}
		else if (strcmp(command, "exit") == 0) {
			printf("Exit the Program\n");
			break;
		}
		else {
			printf("Wrong Command.\n");
		}
	}
	return 0;
}
int enque(int num, struct Queue* queue) {
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = num;
	node->next = NULL;
	if (queue->front == NULL) {
		queue->front = node;
	}
	else {
	 queue->back->next = node;
	}
	queue->back = node;
	queue->count++;
	return 0;
}
int deque(struct Queue* queue) {
	if (queue->count == 0) {
		return -1;
	}
	else {
		struct Node* node = queue->front;
		int num = node->data;
		queue->front = node->next;
		free(node);
		queue->count--;
		return num;
	}
}
int print(struct Queue* queue) {
	if (queue->count>0) {
		struct Node* current = queue->front;
		while (current != NULL) {
			printf("%d ", current->data);
			current = current->next;
		}
	}
	else {
		printf("empty");
	}
	printf("\n");
	return 0;
}
int size(struct Queue* queue) {
	printf("%d\n", queue->count);
}
int empty(struct Queue* queue) {
	if (queue->count == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
int front(struct Queue* queue) {
	if (queue->count == 0) {
		return -1;
	}
	else {
		return queue->front->data;
	}
}
int back(struct Queue* queue) {
	if (queue->count == 0) {
		return -1;
	}
	else {
		return queue->back->data;
	}
}


