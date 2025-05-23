#pragma once
#include <string>

using namespace std;

class Person
{
	string name;
	int age;

public:
	inline string getName() {
		return name;
	}

	inline int getAge() {
		return age;
	}

	inline void setName(string name) {
		this->name = name;
	}

	inline void setAge(int age) {
		this->age = age;
	}
};

