#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void checkVaildInput11() {
	
}

int main() {
	//Question 11
//	printf("Please give any numebr in range 1~4\n");
//	printf("Type -1 to stop\n");
//	int intArray[4] = {0};
//	int num;
//	
//	do
//	{
//		scanf("%d", &num);
//		switch (num)
//		{
//		case 1:
//			intArray[0]++;
//			break;
//		case 2:
//			intArray[1]++;
//			break;
//		case 3:
//			intArray[2]++;
//			break;
//		case 4:
//			intArray[3]++;
//			break;
//		case -1:
//			break;
//		default:
//			printf("Invalid input!\n");
//			break;
//		}	
//
//	} while (num != -1);
//	printf("1 displays %d times\n\
//2 displays %d times\n\
//3 displays %d times\n\
//4 displays %d times\n\
//		", intArray[0], intArray[1], intArray[2], intArray[3]);

	//Question 12
	//Option 1
	//char str1[6][10] = { "hello ","world ","how ","are ","you ","!" };
	//char str2[50] = "\0";

	//for (int i = 0; i < 6; i++) {
	//	strcat(str2, str1[i]);
	//}

	//printf("%s", str2);

	//Option 2
	char str1[6][10] = { "hello ","world ","how ","are ","you ","!" };
	char str2[50] = "\0";

	int index = 0;
	for (int i = 0; i < 6; i++) {
		for (int k = 0; k < 10; k++)
		{
			if (str1[i][k] != '\0') {
				str2[index++] = str1[i][k];
			}
		}
	}

	puts(str2);
}

