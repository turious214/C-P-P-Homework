#define _CRT_SECURE_NO_WARNINGS 1
#include "Header.h"

int main() {
	//quesiton 1
	switch (money mymoney=yuan10)
	{
	case fen1:
		break;
	case fen2:
		break;
	case fen5:
		break;
	case jiao1:
		break;
	case jiao2:
		break;
	case jiao5:
		break;
	case yuan1:
		break;
	case yuan2:
		break;
	case yuan5:
		break;
	case yuan10:
		break;
	case yuan50:
		break;
	case yuan100:
		break;
	default:
		break;
	}
	
	//question2
	rectangle rec = { 20,10 };
	int perimeter = Perimeter(rec);
	int area = Area(rec);
	printf("rectangle's perimeter is %dcm, area is %dcm\n", perimeter, area);


	system("pause");
	return EXIT_SUCCESS;
}
