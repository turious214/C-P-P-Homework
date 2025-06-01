#include <stdio.h>  
#include <stdlib.h>  
#include <string>  
#include <iostream>  

using namespace std;

template <typename T>
class Array {
private:
	T* space;
	int size;

public:
	Array(int size): size(size) {
		if (size <= 0) {
			throw invalid_argument("Size must be greater than 0");
		}
		space = new T[size];
	}

	Array(const Array& other) : size(other.size) {
		if (size <= 0) {
			throw invalid_argument("Size must be greater than 0");
		}
		space = new T[size];
		for (int i = 0; i < size; ++i) {
			space[i] = other.space[i];
		}
	}

	~Array() {
		delete[] space;
	}

	Array& operator=(const Array& other) {
		if (this != &other) {
			if (other.size <= 0) {
				throw invalid_argument("Size must be greater than 0");
			}

			delete[] space;
			this->size = other.size;
			space = new T[size];
			for (int i = 0; i < size; ++i) {
				space[i] = other.space[i];
			}
		}
		return *this;
	}

	T& operator[](int index) {
		if (index < 0 || index >= size) {
			throw out_of_range("Index out of range");
		}

		return space[index];
	}

	//int getSize() {
	//	return size;
	//}

	template <typename T>
	friend ostream& operator<<(ostream& out, Array<T>& arr);
};

template <typename T>  
ostream& operator<<(ostream& out, Array<T>& arr) {  
   for (int i = 0; i < arr.size; ++i) {  
       out << arr.space[i];  
       if (i < arr.size - 1) {  
           out << ", ";  
       }
   }  
   return out;  
}

int main() {
	srand((unsigned)time(NULL));
	Array<int> arr(10);
	for (int i = 0; i < 10; ++i) {
		arr[i] = rand() % 10000;
	}
	Array<int> arr2(arr); // Copy constructor
	//for (int i = 0; i < 10; ++i) {
	//	arr2[i] = rand() % 10000;
	//}
	Array<int> arr3(5);
	for (int i = 0; i < 5; ++i) {
		arr3[i] = rand() % 10000;
	}
	
	//arr3 = arr2; // Assignment operator
	//for (int i = 0; i < 10; ++i) {
	//	arr3[i] = rand() % 10000;
	//}

	cout << arr << "\n" << arr3 << "\n" << arr2 << endl;

	return 0;
}