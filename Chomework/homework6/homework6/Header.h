#pragma once
#include <stdlib.h>
#include <stdio.h>

//question1
enum money
{
	fen1,fen2,fen5,jiao1,jiao2,jiao5,yuan1,yuan2,yuan5,yuan10,yuan50,yuan100
};

//question2
typedef struct{
	int length;
	int width;
}rectangle;

int Perimeter(rectangle rectangle) {
	int result = rectangle.length * 2 + rectangle.width * 2;
	return result;
}

int Area(rectangle rectangle) {
	int result = rectangle.length * rectangle.width;
	return result;
}