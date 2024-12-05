#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
//#include<string.h>
#include<stdio.h>
//#include<conio.h>

int main() {
	
	//Question 9
	//int a = 0;
	//while (1)
	//{
	//	scanf("%d", &a);
	//	if (a >= 0 && a <= 10)
	//	{
	//		continue;
	//	}
	//	else
	//	{
	//		break;
	//	}
	//}

	//Question 10
	//int row, column;
	//for (row = 1; row < 10; row++) {
	//	for (column = 1; column <= row; column++) {
	//		printf("%d*%d=%d\t", row, column, row*column);
	//	}
	//	printf("\n");
	//}

	//Question 11
	int num;
	
	printf("Please give a number: ");
	scanf("%d", &num);

	if (num <= 1) {
		printf("This is not a prime number\n");

	}
	else {
		int remainder;

		for (int i = 2; i < num; i++) {
			remainder = num % i;

			if (remainder == 0) {
				goto NotPrimeNumber;
			}
		}
		printf("This is a prime number\n");
		return EXIT_SUCCESS;
	}

NotPrimeNumber:
	printf("This is not a prime number\n");

	system("pause");
	return EXIT_SUCCESS;
}