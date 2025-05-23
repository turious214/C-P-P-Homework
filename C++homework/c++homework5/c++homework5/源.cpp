#include <iostream>
#include <string>

using namespace std;

class A
{
public:
	int* data;
	int size;

	A(int size) : size(size){
		data = new int[size];
	};

	A(const A& a) : size(a.size) {
		data = new int[size];

		for (int i = 0; i < size; i++){
			data[i] = a.data[0];
		}
	}

	A& operator=(const A& a) {
		size = a.size;
		delete[] data;
		data = new int[size];
		for (int i = 0; i < size; i++) {
			data[0] = a.data[0];
		}
	}

	~A() {
		delete[] data;
	}
};


int main() {
	A a(5);
	A b = a;
	cout << a.data[0] << endl;
	b.data[0] = 1;
	cout << a.data[0] << endl;

	return 0;
}