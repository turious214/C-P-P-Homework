#pragma once
#include <string>

using namespace std;

class student
{
	string name;
	int age;
	double score;

public:
	inline student(string name, int age, double score) {
		this->name = name;
		this->age = age;
		this->score = score;
	}

	inline string getName() {
		return this->name;
	}

	inline int getAge() {
		return this->age;
	}

	inline double getScore() {
		return this->score;
	}
};

