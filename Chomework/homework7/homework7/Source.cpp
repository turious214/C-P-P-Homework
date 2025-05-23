#define _CRT_SECURE_NO_WARNINGS 1
#include "Header.h"

int main() {
	//question 16
	char str[20] = "Hello World!";
	FILE* fp = fopen("test1.txt", "w");
	fwrite(str, sizeof(str[0]), strlen(str), fp);
	fclose(fp);

	fp = fopen("test1.txt", "r");
	for (int i = 1; i <= strlen(str); i++)
	{
		fseek(fp, -i, 2);
		printf("%c", fgetc(fp));
	}
	fclose(fp);
	printf("\n");
	
	system("pause");
	return EXIT_SUCCESS;
}
