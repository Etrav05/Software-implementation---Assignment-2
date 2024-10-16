#include <stdio.h>
#include <stdbool.h>
#include "main.h"

#define RUN_TESTS // Turn this line off and on by making it a comment, its used to run the tests

#ifndef RUN_TESTS 

void main() {
	int length = 1;
	int width = 1;
	bool continueProgram = true;
	while (continueProgram) {
		printWelcomeMenu();
		printOptions();

		int menuInput;
		menuInput = getIntInput("Enter menu option number:");

		switch (menuInput)
		{
			case 1:
			{
				printf("\nThe Rectangle has a length of %i and a width of %i\n\n", length, width);
				break;
			}
			case 2:
			{
				int input = getIntInput("Please enter the length of the rectangle:");
				setLength(input, &length);
				break;
			}
			case 3:
			{
				int input = getIntInput("Please enter the width of the rectangle:");
				setWidth(input, &width);
				break;
			}
			case 4:
			{
				printf("\nThe Rectangle has a perimeter of %i\n\n", getPerimeter(&length, &width));
				break;
			}
			case 5:
			{
				printf("\nThe Rectangle has an area of %i\n\n", getArea(&length, &width));
				break;
			}
			case 6:
			{
				continueProgram = false;
				break;
			}
			default:
			{
				printf("\nInvalid value entered.\n\n");
				break;
			}
		}
	}
}

#else

int main() {
	int length, width;  // define the variables used

	printf("test 01 - Perimeter:\n");

	length = 10;
	width = 5;
	int expectedPerimeter = 30;
	int expectedArea = 50;

	if (getPerimeterTest(&length, &width, expectedPerimeter))
		printf("\n===== passed =====\n");
	else
		printf("\n===== fail =====\n");

	printf("\n\ntest 02 - Area:\n");

	if (getAreaTest(&length, &width, expectedArea))
		printf("\n===== passed =====\n");
	else
		printf("\n===== fail =====\n");


	int validLength = 10;

	printf("\n\ntest 03a - Length:\n");

	setLength(validLength, &length);

	if (length == validLength)
		printf("\n===== passed =====\n");
	else
		printf("\n===== fail =====\n");

	int boundaryLength = 100;

	printf("\n\ntest 03b - Length:\n");

	setLength(boundaryLength, &length);

	if (length == boundaryLength)
		printf("\n===== fail =====\n");
	else
		printf("\n===== passed =====\n");

	int invalidLength = 0;

	printf("\n\ntest 03c - Length:\n");

	setLength(invalidLength, &length);

	if (length == invalidLength)
		printf("\n===== fail =====\n");
	else
		printf("\n===== passed =====\n");


	int validWidth = 5;

	printf("\n\ntest 04a - Width:\n");

	setWidth(validWidth, &width);

	if (width == validWidth)
		printf("\n===== passed =====\n");
	else
		printf("\n===== fail =====\n");

	int boundaryWidth = 100;

	printf("\n\ntest 04b - Width:\n");

	setWidth(boundaryWidth, &width);

	if (width == boundaryWidth)
		printf("\n===== fail =====\n");
	else
		printf("\n===== passed =====\n");

	int invalidWidth = 0;

	printf("\n\ntest 04c - Width:\n");

	setWidth(invalidWidth, &width);

	if (width == invalidWidth)
		printf("\n===== fail =====\n");
	else
		printf("\n===== passed =====\n");
}
#endif  // end the test case and dont run the rest of the program

int getIntInput(char message[]) {
	int input;
	int scannedValues;
	do {
		printf("\n%s\n",message);
		scannedValues = scanf_s("%i", &input);
		int buf;
		while ((buf = getchar()) != '\n' && buf != EOF);
	} while (scannedValues != 1);
	return input;
}

void setLength(int input, int *length) {
	if (input > 0 && input < 100) {
		*length = input;
	}
}

void setWidth(int input, int *width) {
	if (input > 0 && input < 100) {
		*width = input;
	}
}

int getPerimeter(int *length, int *width) {
	int perimeter = *length + *length + *width + *width;
	return perimeter;
}

int getArea(int *length, int *width) {
	int area = *length * *width;
	return area;
}

void printWelcomeMenu() {
	printf(" **********************\n");
	printf("**     Welcome to     **\n");
	printf("**    Assignment 02   **\n");
	printf(" **********************\n");
}

void printOptions() {
	printf("1. Get Rectange Length & Width\n");
	printf("2. Change Rectangle Length\n");
	printf("3. Change Rectangle Width\n");
	printf("4. Get Rectangle Perimeter\n");
	printf("5. Get Rectangle Area\n");
	printf("6. Exit\n");
}