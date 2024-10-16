#pragma once
#include <stdbool.h>

void setLength(int input, int *length);
void setWidth(int input, int *width);
int getPerimeter(int *length, int *width);
int getArea(int *length, int *width);
void printWelcomeMenu();
void printOptions();
int getIntInput(char message[]);


// Declare test
bool getPerimeterTest(int* length, int* width, int expected);
bool getAreaTest(int* length, int* width, int expected);
bool setLengthTest(int input, int* length); 
bool setWidthTest(int input, int* width);