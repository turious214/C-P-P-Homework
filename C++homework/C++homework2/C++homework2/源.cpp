#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct {
	string firstName;
	string lastName;
	string name;
} name;

inline void addName(name* nameptr) {
	nameptr->firstName;
	nameptr->lastName;
	nameptr->name = nameptr->firstName + " " + nameptr->lastName;
	
}

inline void addptr(int** intptr) {
	++(**intptr);
}

inline void clearptr(int** intptr) {
	**intptr = 0;
}

inline void swapName(name* nameptr) {
	string temp = nameptr->firstName;
	nameptr->firstName = nameptr->lastName;
	nameptr->lastName = temp;
}

int main() {
	// q3
	//name* nameptr = new name;
	//name nameInstance;
	//nameInstance.firstName = "Jane";
	//nameInstance.lastName = "Doe";
	//name* nameptr = &nameInstance;
	//addName(nameptr);
	//cout << nameptr->name << endl;

	// q4
	//int num = 0;
	//int* intptr = &num;
	//int** intptrptr = &intptr;
	//addptr(intptrptr);
	//cout << num << endl;

	// q5
	//int* arr = new int[10];
	//delete []arr;

	// q7
	//name nameInstance;
	//nameInstance.firstName = "Jane";
	//nameInstance.lastName = "Doe";
	//name * nameptr = &nameInstance;
	//swapName(nameptr);
	//addName(nameptr);
	//cout << nameptr->name << endl;

	// q8
	//int num = 100;
	//int* intptr = &num;
	//int** intptrptr = &intptr;
	//clearptr(intptrptr);
	//cout << num << endl;

	// q10
	//float* ptr = new float[10];
	//delete[] ptr;

	return 0;
}