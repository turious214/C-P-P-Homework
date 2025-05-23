#include "Header.h"

int main() {
	
	int size;
	printf("输入你想要输入的字符串个数: ");
	scanf("%d", &size);

	char* str = dynamicStr(size);

	printf("输入你想要输入的字符串:\n");
	getchar();
	fgets(str, size, stdin);

	int letters = 0, digits = 0, spaces = 0, others = 0;
	countChar(str, size, &letters, &digits, &spaces, &others);
	
	printf("字母有%d个，数字有%d个，空格%d有个，其他字符%d个\n", \
	letters, digits, spaces, others);

	free(str);
	system("pause");
	return EXIT_SUCCESS;
}