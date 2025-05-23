#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

char* dynamicStr(int size) {
	char* str = (char*)malloc(sizeof(char) * (size + 1));
	return str;
}

void countChar(char* str, int size, \
	int* letters, int* digits, int* spaces, int* others) {
	for (size_t i = 0; i < size; i++)
	{
		char cchar = *(str + i);

		if (isalpha(cchar)){
			(*letters)++;
		} else if (isdigit(cchar)){
			(*digits)++;
		} else if (isspace(cchar)) {
			(*spaces)++;
		} else{
			(*others)++;
		}
	}
}