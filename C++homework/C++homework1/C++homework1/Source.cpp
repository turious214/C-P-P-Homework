#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

inline int square(int num) {
	return num * num;
}

inline bool isPrime(int num) {
	if (num <= 1) {
		return false;
	}

	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			return false;
		}
	}

		return true;
}

inline void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void printNum(int num) {
	cout << num << endl;
	cout << "int类型重载" << endl;
}

void printNum(double num) {
	cout << num << endl;
	cout << "double类型重载" << endl;
}

void printNum(float num) {
	cout << num << endl;
	cout << "float类型重载" << endl;
}

inline void multiply(int a, int b = 1) {
	cout << a * b << endl;
}

int getLength(const string str) {
	return str.length();
}

string getLongerString(string str1, string str2) {
	if (str1.length() > str2.length()) {
		return str1;
	}
	else {
		return str2;
	}
}


int main() {
	// q7
	//int num;
	//cin >> num;
	//cout << square(num) << endl;

	// q8
	//int num;
	//cin >> num;
	//cout << isPrime(num) << endl;

	// q16
	//int a = 10;
	//int b = 20;
	//
	//cout << "Before swapping: " << a << " " << b << endl;
	//swap(a, b);
	//cout << "After swapping: " << a << " " << b << endl;

	// q9
	//int num = 2.3;
	//printNum((int)num);
	//printNum((double)num);
	//printNum((float)num);

	// q14
	//multiply(20);

	// q10
	//cout << getLength("Hello World") << endl;
	

	// q30
	//cout << getLongerString("Hello", "World") << endl;

	return 0;

}
