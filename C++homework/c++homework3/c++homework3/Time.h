#pragma once
#include <iostream>
#include <string>

using namespace std;

class Time
{
	int hour;
	int minutes;
	int second;

public:
	inline string getTime() {
		string curTime = to_string(this->hour) + ":" + to_string(this->minutes)\
			+":" + to_string(this->second);
		
		return curTime;
	}

	inline void setTime(int hour, int minutes, int second) {
		this->hour = hour;
		this->minutes = minutes;
		this->second = second;
	}
};

