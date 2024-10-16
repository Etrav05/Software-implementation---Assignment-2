#include <stdio.h>
#include "main.h"

bool getPerimeterTest(int* length, int* width, int expected) {

	int result = getPerimeter(length, width);

	if (result == expected)
		return true;
	else
		return false;
}

bool getAreaTest(int* length, int* width, int expected) {

	int result = getArea(length, width);

	if (result == expected)
		return true;
	else
		return false;
}

bool setLengthTest(int* input, int expected) {
	int length = 0;

	setLength(input, &length);

	if (length == expected)
		return true;
	else
		return false;
}

bool setWidthTest(int* input, int expected) {
	int width = 0;

	setWidth(input, &width);

	if (width == expected)
		return true;
	else
		return false;
}