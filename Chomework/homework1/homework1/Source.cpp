#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>

int main(){
	const int a = 1;
	const short b = 2;
	const long c = 3;
	const long long d = 4;
	const char e = 'a';
	const char f[100] = {'a','b','c'};
	const float g = 1.1;
	const double h = 1.2;

	printf("item: %d, size: %d\n", a, sizeof(a));
	printf("item: %i, size: %d\n", b, sizeof(b));
	printf("item: %i, size: %d\n", c, sizeof(c));
	printf("item: %i, size: %d\n", d, sizeof(d));
	printf("item: %c, size: %d\n", e, sizeof(e));
	printf("item: %s, size: %d\n", f, sizeof(f));
	printf("item: %f, size: %d\n", g, sizeof(g));
	printf("item: %lf, size: %d\n", h, sizeof(h));

	printf("int:%i  char:%i  short:%i  long:%i  float:%i  double:%i\n",
		sizeof(int), sizeof(char), sizeof(short), sizeof(long), sizeof(float), sizeof(double)
	);

	printf("a=%d\n", a);

	int value = 100;
	printf("%o\t%d\t%x\n", value, value, value);

	int value2 = 0b11;
	printf("%o\n", value2);

	printf("Please type your name: ");
	char name[10];
	scanf("%s", &name);
	printf("\nWelcome %s!", name);

	char ch = getchar();
	putchar(ch);
	char str[100];
	gets_s(str);
	puts(str);
	char c2 = getch();
	putch(c2);


return 0;
}