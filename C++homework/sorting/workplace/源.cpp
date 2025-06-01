#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

//template<size_t N> // 修复模板参数为非类型模板参数
//void bubbleSort(int(&arr)[N]) {
//    int len = sizeof(arr) / sizeof(int);
//    for (int i = 0; i < len; ++i) {
//        for (int j = 0; j < len - 1 - i; ++j) {
//            if (arr[j] > arr[j + 1]) {
//				// 交换元素
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//            }
//        }
//    }
//}
//
//template <size_t N>
//void selectionSort(int(&arr)[N]) {
//	int minIndex;
//    int len = sizeof(arr) / sizeof(int);
//    for (int i = 0; i < len - 1; ++i)
//    {
//        minIndex = i;
//        for (int j = i; j < len; ++j) {
//			if (arr[j] < arr[minIndex]) {
//                minIndex = j;
//			}
//        }
//
//        if (minIndex != i) {
//            swap(arr[minIndex], arr[i]);
//        }
//    }
//}
//
//template <size_t N>
//void insertionSort(int(&arr)[N]) {
//    int len = sizeof(arr) / sizeof(int);
//    int key;
//    for (int i = 1; i < len; ++i) {
//        key = arr[i];
//		  int j = i - 1;
//        while (j >= 0 && arr[j] > key) {
//			arr[j + 1] = arr[j];
//			--j;
//        }
//
//        arr[j + 1] = key;
//    }
//}
//
////template <size_t N >
//void shellSort(int(&arr)[N]) {
//    int len = sizeof(arr) / sizeof(int);
//    for (int gap = len / 2; gap > 0; gap /= 2) {
//        for (int i = gap; i < len; ++i) {
//            int key = arr[i];
//            int j = i - 1;
//            for (j = i; j >= gap && arr[j - gap] > key; j -= gap) {
//                arr[j] = arr[j - gap];
//            }
//
//            arr[j] = key;
//        }
//    }
//}
//
//template <size_t N>
//void quickSort(int(&arr)[N], int left, int right) {
//    if (left < right) {
//        int value = arr[left];
//        int cLeft = left + 1;
//        int cRight = right;
//
//        while (true) {
//            while (cLeft <= cRight && arr[cLeft] <= value) {
//                ++cLeft;
//            }
//
//            while (cRight >= cLeft && arr[cRight] >= value) {
//                --cRight;
//            }
//
//            if (cLeft > cRight) {
//                break;
//            }
//            swap(arr[cLeft], arr[cRight]);
//        }
//
//		  swap(arr[left], arr[cRight]);
//
//        quickSort(arr, left, cRight - 1);
//        quickSort(arr, cRight + 1, right);
//    }
//}

//template <size_t N>
//void radixSort(int(&arr)[N]) {
//    int len = sizeof(arr) / sizeof(int);
//    int maxVal = arr[0];
//    for (int i = 1; i < len; ++i){
//        if (maxVal < arr[i]) {
//            maxVal = arr[i];
//        }
//    }
//
//    for (int exp = 1; maxVal / exp > 0 ; exp *= 10){
//        int result[N];
//        int count[10]{};
//        for (int i = 0; i < len; ++i) {
//            ++count[(arr[i] / exp) % 10];
//        }
//
//        for (int i = 1; i < 10; ++i) {
//            count[i] += count[i - 1];
//        }
//
//        for (int i = len - 1; i >= 0; --i) {
//            result[count[(arr[i] / exp) % 10] - 1] = arr[i];
//            --count[(arr[i] / exp) % 10];
//        }
//
//        for (int i = 0; i < len; ++i) {
//            arr[i] = result[i];
//        }
//    }
//}

//template <size_t N>
//void mergeSort(int(&arr)[N], int left, int right) {
//    if (left < right) {
//        int mid = left + (right - left) / 2;
//
//        mergeSort(arr, left, mid);
//        mergeSort(arr, mid + 1, right);
//        int leftSize = mid - left + 1;
//        int rightSize = right - mid;
//
//		int* leftArr = new int[leftSize];
//        int* rightArr = new int[rightSize];
//        for (int i = 0; i < leftSize; ++i) {
//            leftArr[i] = arr[left + i];
//        }
//        for (int i = 0; i < rightSize; ++i) {
//            rightArr[i] = arr[mid + 1 + i];
//        }
//
//		int i = 0, j = 0, k = left;
//        while (i < leftSize && j < rightSize) {
//            if (leftArr[i] <= rightArr[j]) {
//				arr[k] = leftArr[i];
//                ++i;
//            }
//            else {
//                arr[k] = rightArr[j];
//                ++j;
//            }
//            ++k;
//        }
//
//        while (i < leftSize) {
//            arr[k] = leftArr[i];
//            ++i;
//            ++k;
//        }
//        while (j < rightSize) {
//            arr[k] = rightArr[j];
//            ++j;
//            ++k;
//        }
//    }
//}

template <size_t N>
void bubbleSort(int(&arr)[N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template <size_t N>
void selectionSort(int(&arr)[N]) {
    for (int i = 0; i < N - 1; ++i) {
        int minIndex = i;
        for (int j = i; j < N; ++j) {
            if (arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swap(arr[minIndex], arr[i]);
        }
    }
}

template <size_t N>
void insertionSort(int(&arr)[N]) {
    for (int i = 1; i < N; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

template <size_t N>
void shellSort(int(&arr)[N]) {
    for (int gap = N / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < N; ++i) {
            int key = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > key; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = key;
        }
    }
}

template <size_t N>
void quickSort(int(&arr)[N], int left, int right) {
    if (left < right) {
        int value = arr[left];
        int cLeft = left + 1;
        int cRight = right;
        while (true) {
            while (cLeft <= cRight && arr[cLeft] <= value) {
                ++cLeft;
            }
            while (cRight >= cLeft && arr[cRight] >= value) {
                --cRight;
            }
            if (cLeft > cRight) {
				break;
            }
            swap(arr[cLeft], arr[cRight]);
        }
        swap(arr[left], arr[cRight]);
        quickSort(arr, left, cRight - 1);
        quickSort(arr, cRight + 1, right);
    }
}

template <size_t N>
void radixSort(int(&arr)[N]) {
    int maxVal = arr[0];
    for (int i = 1; i < N; ++i) {
        if (maxVal < arr[i]) {
            maxVal = arr[i];
        }
    }
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        int result[N];
        int count[10]{};
        for (int i = 0; i < N; ++i) {
            ++count[(arr[i] / exp) % 10];
        }
        for (int i = 1; i < 10; ++i) {
            count[i] += count[i - 1];
        }
        for (int i = N - 1; i >= 0; --i) {
            result[count[(arr[i] / exp) % 10] - 1] = arr[i];
            --count[(arr[i] / exp) % 10];
        }
        for (int i = 0; i < N; ++i) {
            arr[i] = result[i];
        }
    }
}

template <size_t N>
void mergeSort(int(&arr)[N], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        int leftSize = mid - left + 1;
        int rightSize = right - mid;
        int* leftArr = new int[leftSize];
        int* rightArr = new int[rightSize];
        for (int i = 0; i < leftSize; ++i) {
            leftArr[i] = arr[left + i];
        }
        for (int i = 0; i < rightSize; ++i) {
            rightArr[i] = arr[mid + 1 + i];
        }
        int i = 0, j = 0, k = left;
        while (i < leftSize && j < rightSize) {
            if (leftArr[i] < rightArr[j]) {
                arr[k] = leftArr[i];
                ++i;
            }
            else {
                arr[k] = rightArr[j];
                ++j;
            }
            ++k;
        }
        while (i < leftSize) {
            arr[k] = leftArr[i];
            ++i;
            ++k;
        }
        while (j < rightSize) {
            arr[k] = rightArr[j];
            ++j;
            ++k;
        }
    }
}

int main() {
   int arr[10] = { 12, 59, 38, 27, 16, 55, 64, 83, 42, 21 };

   cout << "Before sorting: ";
   for (int i = 0; i < 10; ++i) {
	   cout << arr[i] << "  ";
   }
   cout << endl;

   cout << "After bubble sorting: ";
   bubbleSort(arr);
   for (int i = 0; i < 10; ++i) {
       cout << arr[i] << "  ";
   }
   cout << endl;

   int arr2[10] = { 12, 59, 38, 27, 16, 55, 64, 83, 42, 21 };
   cout << "After selection sorting: ";
   selectionSort(arr2);
   for (int i = 0; i < 10; ++i) {
       cout << arr2[i] << "  ";
   }
   cout << endl;

   int arr3[10] = { 12, 59, 38, 27, 16, 55, 64, 83, 42, 21 };
   cout << "After insertion sorting: ";
   insertionSort(arr3);
   for (int i = 0; i < 10; ++i) {
       cout << arr3[i] << "  ";
   }
   cout << endl;

   int arr4[11] = { 12, 59, 38, 27, 16, 55, 64, 83, 42, 21, 22};
   cout << "After shell sorting: ";
   shellSort(arr4);
   for (int i = 0; i < 11; ++i) {
       cout << arr4[i] << "  ";
   }
   cout << endl;

   int arr5[10] = { 12, 59, 38, 27, 16, 55, 64, 83, 42, 21 };
   cout << "After quick sorting: ";
   quickSort(arr5, 0, 9);
   for (int i = 0; i < 10; ++i) {
       cout << arr5[i] << "  ";
   }
   cout << endl;

   int arr6[10] = { 12, 5, 88, 276, 86, 6666, 64, 823, 62, 21 };
   cout << "After radix sorting: ";
   radixSort(arr6);
   for (int i = 0; i < 10; ++i) {
       cout << arr6[i] << "  ";
   }
   cout << endl;

   int arr7[10] = { 12, 5, 38, 276, 66666, 9999, 64, 888, 62, 21 };
   cout << "After merge sorting: ";
   mergeSort(arr7, 0, 9);
   for (int i = 0; i < 10; ++i) {
       cout << arr7[i] << "  ";
   }
   cout << endl;

   return 0;
}