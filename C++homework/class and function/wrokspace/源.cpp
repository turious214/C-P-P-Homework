#include <stdio.h>  
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

template <typename T>
class MyArray {
private:
	T* data;
	size_t capacity;
	int length;

	void expend() {
		capacity *= 2;
		T* newData = new T[capacity];
		for (size_t i = 0; i < length; i++) {
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
	}

public:
	MyArray(size_t size) {
		capacity = size;
		data = new T[capacity];
		length = 0;
	}

	MyArray(const MyArray& arr) {
		capacity = arr.capacity;
		data = new T[capacity];
		for (size_t i; i < capacity; i++) {
			data[i] = arr.data[i];
		}
	}

	MyArray& operator=(const MyArray& arr) {
		if (this != &arr) {
			delete[] data;
			capacity = arr.capacity;
			data = new T[capacity];
			for (size_t i = 0; i < capacity; i++)
			{
				data[i] = arr.data[i];
			}
		}
		return *this;
	}

	~MyArray() {
		delete[] data;
	}

	void append(T value) {
		if (length == capacity) {
			expend();
		}

		*(data + length) = value;
		length++;
	}

	void insert(int index, T value) {
		if (length == capacity) {
			expend();
		}

		if (index >= length) {
			cout << "invalid value" << endl;
		}

		for (size_t i = length; i > index; i--) {
			*(data + i) = *(data + i - 1);
		}

		*(data + index) = value;
		length++;
	}

	auto at(int index) {
		return *(data + index);
	}

	void removeAt(int index) {
		if (index >= length) {
			cout << "invalid value" << endl;
		}

		for (size_t i = index; i < length - 1; i++) {
			*(data + i) = *(data + i + 1);
		}

		length--;
	}

	int indexOf(T value) {
		int index = -1;

		for (size_t i = 0; i < length; i++) {
			if (*(data + i) == value) {
				index = i;
				break;
			}
		}

		return index;
	}

	void print() {
		for (size_t i = 0; i < length; i++) {
			cout << *(data + i) << " ";
		}
		cout << endl;
	}

	void replace(int index, T value) {
		if (index >= length) {
			cout << "invalid value" << endl;
		}

		*(data + index) = value;
	}

	int getLength() {
		return length;
	}

};

int main() {
	MyArray<int> arr(5);
	arr.append(1); // 1
	arr.append(2); // 1 2
	arr.append(3); // 1 2 3

	arr.insert(1, 4); // 1 4 2 3
	arr.insert(2, 5); // 1 4 5 2 3

	cout << arr.at(2) << endl; // 5

	arr.removeAt(1); // 1 5 2 3
	
	cout << arr.indexOf(5) << endl; // 1

	arr.replace(1, 2); // 1 2 2 3

	cout << arr.getLength() << endl; // 4

	arr.print(); // 1 2 2 3


	return 0;
}