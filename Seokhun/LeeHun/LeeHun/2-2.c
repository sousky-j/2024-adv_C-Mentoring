#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <malloc.h>
int main() {
	char str[101];
	int count, len;
	count = 0;
	char** dictionary = (char**)malloc(sizeof(char*));
	while (1) {
		fgets(str, 101, stdin);
		len = strlen(str);
		if (strcmp(str,"\n")==0) {
			break;
		}
		else {
			count++;
			dictionary=(char**)realloc(dictionary, count * sizeof(char*));
			dictionary[count - 1] = (char*)malloc(sizeof(char) * (len + 1));
			strcpy(dictionary[count - 1], str);
		}
	}
	for (int i = 0; i < count - 1; i++) {
		for (int j = i + 1; j < count; j++) {
			if (strcmp(dictionary[i], dictionary[j]) > 0) {
				char* p = dictionary[i];
				dictionary[i] = dictionary[j];
				dictionary[j] = p;
			}
		}
	}
	for (int i = 0; i < count; i++) {
		printf("%s", dictionary[i]);
	}
	for (int i = 0; i < count; i++) {
		free(dictionary[i]);
	}
	free(dictionary);
	return 0;
}