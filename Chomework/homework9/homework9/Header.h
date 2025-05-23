#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int id;
	char name[20];
	double mark;
} student;

student classRoom[10] = {
	{1,"kevin", 100},
	{8,"Alice", 45.23},
	{3,"Bob", 13.88},
	{9,"Charlie", 78.12},
	{6,"Daisy", 59.41},
	{10,"Edward", 90.57},
	{2,"Fiona", 23.68},
	{4,"George", 10.45},
	{7,"Hannah", 99.12},
	{5,"Ivy", 67.34}
};

student classRoom1[10] = {
	{1,"kevin", 100},
	{8,"Alice", 45.23},
	{3,"Bob", 13.88},
	{9,"Charlie", 78.12},
	{6,"Daisy", 59.41},
	{10,"Edward", 90.57},
	{2,"Fiona", 23.68},
	{4,"George", 10.45},
	{7,"Hannah", 99.12},
	{5,"Ivy", 67.34}
};

student classRoom2[10] = {
	{1,"kevin", 100},
	{8,"Alice", 45.23},
	{3,"Bob", 13.88},
	{9,"Charlie", 78.12},
	{6,"Daisy", 59.41},
	{10,"Edward", 90.57},
	{2,"Fiona", 23.68},
	{4,"George", 10.45},
	{7,"Hannah", 99.12},
	{5,"Ivy", 67.34}
};

student classRoom3[10] = {
	{1,"kevin", 100},
	{8,"Alice", 45.23},
	{3,"Bob", 13.88},
	{9,"Charlie", 78.12},
	{6,"Daisy", 59.41},
	{10,"Edward", 90.57},
	{2,"Fiona", 23.68},
	{4,"George", 10.45},
	{7,"Hannah", 99.12},
	{5,"Ivy", 67.34}
};

student classRoom4[10] = {
	{1,"kevin", 100},
	{8,"Alice", 45.23},
	{3,"Bob", 13.88},
	{9,"Charlie", 78.12},
	{6,"Daisy", 59.41},
	{10,"Edward", 90.57},
	{2,"Fiona", 23.68},
	{4,"George", 10.45},
	{7,"Hannah", 99.12},
	{5,"Ivy", 67.34}
};

void bubbleSortAsc(student* classroom1, int size) {
	student temp;
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - 1 - i; j++)
		{
			if ((classRoom1 + j)->mark > (classRoom1 + (j + 1))->mark)
			{
				temp = *(classRoom1 + j);
				*(classRoom1 + j) = *(classRoom1 + (j + 1));
				*(classRoom1 + (j + 1)) = temp;
			}
		}
	}
}

void bubbleSortDesc(student* classroom2, int size) {
	student temp;
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - 1 - i; j++)
		{
			if ((classRoom2 + j)->mark < (classRoom2 + (j + 1))->mark)
			{
				temp = *(classRoom2 + j);
				*(classRoom2 + j) = *(classRoom2 + (j + 1));
				*(classRoom2 + (j + 1)) = temp;
			}
		}
	}
}

void selectionSortAsc(student* classroom3, int size) {
	for (size_t i = 0; i < size; i++)
	{
		student* min = (classRoom3 + i);
		for (size_t j = i + 1; j < size - 1; j++)
		{
			if (min->mark > (classRoom3 + j)->mark) {
				min = (classRoom3 + j);
			}
		}
		student temp = *(classRoom3 + i);
		*(classroom3 + i) = *min;
		*min = temp;
	}
}

void selectionSortDesc(student* classroom4, int size) {
	for (size_t i = 0; i < size; i++)
	{
		student* max = (classRoom4 + i);
		for (size_t j = i + 1; j < size - 1; j++)
		{
			if (max->mark < (classRoom4 + j)->mark) {
				max = (classRoom4 + j);
			}
		}
		student temp = *(classRoom4 + i);
		*(classroom4 + i) = *max;
		*max = temp;
	}
}

int binarySearch(student* classRoom4, int size, double score, int mode) {
	int right = size - 1, left = 0;
	int mid;
	bool notFind = true;

	while (notFind) {
		mid = (left + right) / 2;

		if ((classRoom4 + mid)->mark == score)
		{
			notFind = false;
		}
		else
		{
			if ((classRoom4 + mid)->mark > score)
			{
				if (mode == 0)
				{
					right = mid--;
				}
				else
				{
					left = mid++;
				}
			}
			else
			{
				if (mode = 0)
				{
					left = mid++;
				}
				else
				{
					right = mid--;
				}
				
			}
		}
	}

	return mid;
}