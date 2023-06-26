#include <iostream>
#include <locale>
#include "Windows.h"
#include <string.h>
#include <stdlib.h>

int mystrlen(char[], int);
double mystrtod(char[]);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	const int size = 32;
	char massive[size];
	char* ptrEnd;

	std::cout << "Будь ласка введіть ваш текст(; - це кінець тексту)" << std::endl;
	std::cin.getline(massive, size, ';');
	std::cout << massive << std::endl;

	int symbolsnum = mystrlen(massive, size);
	std::cout << "(моя функція) кількість символів в рядку - " << symbolsnum << std::endl;
	std::cout << "(функція с++) кількість символів в рядку - " << strlen(massive) << std::endl;

	double number = mystrtod(massive);
	std::cout << "(моя функція) Число типу double = " << number << std::endl;
	std::cout << "(функція с++) Число типу double = " << strtod(massive, &ptrEnd) << std::endl;

	system("PAUSE");
	return 0;
} 

int mystrlen(char *massive, int size) {
	int counter = 0;
	for (int i = 0; i < size; i++) {
		if (massive[i] == '\0') {
			break;
		}
		counter++;
	}
	return counter;
}
double mystrtod(char* massive) {
	double number = atof(massive);
	return number;
}