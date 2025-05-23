#pragma once

class Rectangle
{
	int width;
	int height;

public:
	inline int getArea() {
		return width * height;
	}

	inline void setWidth(int width) {
		this->width = width;
	}

	inline void setHeight(int height) {
		this->height = height;
	}
};

