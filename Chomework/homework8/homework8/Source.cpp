#include "Header.h"

int main() {
	
	int size;
	printf("��������Ҫ������ַ�������: ");
	scanf("%d", &size);

	char* str = dynamicStr(size);

	printf("��������Ҫ������ַ���:\n");
	getchar();
	fgets(str, size, stdin);

	int letters = 0, digits = 0, spaces = 0, others = 0;
	countChar(str, size, &letters, &digits, &spaces, &others);
	
	printf("��ĸ��%d����������%d�����ո�%d�и��������ַ�%d��\n", \
	letters, digits, spaces, others);

	free(str);
	system("pause");
	return EXIT_SUCCESS;
}