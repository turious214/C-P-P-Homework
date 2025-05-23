#include "Header.h"



int main() {
	int size = (sizeof(classRoom) / sizeof(classRoom[0]));
	bubbleSortAsc(classRoom1, size);
	bubbleSortDesc(classRoom2, size);
	selectionSortAsc(classRoom3, size);
	selectionSortDesc(classRoom4, size);

	for (size_t i = 0; i < size; i++)
	{
		printf("%lf\t", ((classRoom1 + i)->mark));
	}
	printf("\n");

	for (size_t i = 0; i < size; i++)
	{
		printf("%lf\t", ((classRoom2 + i)->mark));
	}
	printf("\n");

	for (size_t i = 0; i < size; i++)
	{
		printf("%lf\t", ((classRoom3 + i)->mark));
	}
	printf("\n");

	for (size_t i = 0; i < size; i++)
	{
		printf("%lf\t", ((classRoom4 + i)->mark));
	}
	printf("\n");

	printf("100ÔÚµÚ%d¸ö\n", (binarySearch(classRoom4, size, 100, 1) + 1));

	system("pause");
	return EXIT_SUCCESS;
}