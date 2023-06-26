#include <iostream>
#include <locale>
#include "Windows.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	const int size = 32;
	int counter = 0;
	char massive[size];

	std::cout << "Будь ласка введіть ваш текст( . - кінець речення)" << std::endl;
	std::cin.getline(massive, size, '.');
	std::cout << massive << std::endl;


	for (int i = 0; i < size; i++) {
		if (massive[i] == ' ') {
			continue;
		}
		if (massive[i] == '\0') {
			break;
		}
		for (int j = 0; j < size; j++) {
			if (massive[i] == massive[j] && i != j) {
				counter++;
				massive[j] = ' ';
			}
		}
		if (counter != 0) {
			std::cout << "кількість повторень символу " << massive[i] << " = " << counter + 1 << std::endl;
		}
		else {
			std::cout << "кількість повторень символу " << massive[i] << " = " << counter << std::endl;
		}
		counter = 0;
	}

	system("PAUSE");
	return 0;
}