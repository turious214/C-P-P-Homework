#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>

int main() {
	printf("Please give three numbers\n");

	double num1, num2, num3;
	scanf("%lf %lf %lf", &num1, &num2, &num3);

	printf("%lf\n", num1 > num2 ? num1 > num3 ? num1 : num3 : num2 == num3 ? num2 : num2 > num3\
	? num2 : num3);
	

	return 0;
}