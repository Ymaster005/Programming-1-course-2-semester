#include <iostream>
#include <fstream>
#include <iomanip>
#include <locale>
#include "Windows.h"
#include <string.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	const int n = 81;
	int outputflag = 0;
	char* reader = new char[n];
	char* longestword = new char[n];
	char outputfilename[256];
	char inputfilepath[256];
	std::ofstream outputfile;
	std::ifstream inputfile;


	std::cout << "Введіть повний шлях до файлу з якого зчитують без лапок" << std::endl;
	std::cin.getline(inputfilepath, 256);
	inputfile.open(inputfilepath);
	//std::cout << "inputfilepath = " << inputfilepath << std::endl;
	if (!inputfile) {
		std::cout << "Невірний шлях до файлу, файл не відкрит";
		return 1;
	}

	while (outputflag != 1 && outputflag != 2) {
		std::cout << "Введіть:\n1 - якщо хочете вивести дані у файл\n2 - якщо хочете вивести дані у консоль\n";
		std::cin >> outputflag;
		std::cin.ignore();
	}

	int  wordcounter = 0, wordlength = 0, startindex = 0, endindex = 0;
	while (!inputfile.eof()) {
		inputfile.getline(reader, n);

		startindex = 0, endindex = 0;
		//int cyclecounter = 0;

		for (int i = 0; i < n; i++) {

			//если строка меньше 80 символов
			if (reader[i] == '\0' || reader[i] == 'Н') {
				break;
			}
			//если символ строки пробел
			if (reader[i] == ' ' || reader[i] == '.') {
				//если одинаковое количество букв в самых длинных словах
				boolean sameword = false;
				if ((endindex - startindex + 1) == wordlength && wordlength > 0) {
					for (int j = 0; j < wordlength; j++) {
						sameword = true;
						//std::cout << "longestword = " << longestword << std::endl;
						if (longestword[j] != reader[startindex + j]) {
							sameword = false;
						}
					}
					if (sameword) {
						wordcounter++;
						//std::cout << "счётчик +1" << std::endl;
					}
				}
				//если слово длинне предыдущего
				if ((endindex - startindex + 1) > wordlength && endindex != 0) {
					wordlength = endindex - startindex + 1;
					wordcounter = 0;
					//std::cout << "счётчик обнулился " << std::endl;
					for (int j = 0; j < n; j++) {
						longestword[j] = 0;
					}
					for (int j = 0; j < wordlength; j++) {
						longestword[j] = reader[startindex + j];
					}
				}


			}
			//считыватель букв
			else {
				if (i > 0) {
					if (reader[i - 1] == ' ') {
						//std::cout << "startindex changed to " << i << std::endl;
						startindex = i;
					}
				}
				else {
					startindex = i;
				}
				if (i < n) {
					if (reader[i + 1] == ' ' || reader[i + 1] == '.') {
						//std::cout << "endindex changed to " << i << std::endl;
						endindex = i;
					}
				}
			}
			//cyclecounter++;
		}


		/*std::cout << "startindex = " << startindex << std::endl;
		std::cout << "endindex = " << endindex << std::endl;
		std::cout << "cyclecounter = " << cyclecounter << std::endl;
		std::cout << "wordlength = " << wordlength << std::endl;
		std::cout << std::setw(20) << reader << std::endl;
		for (int i = 0; i < n; i++) {
			std::cout << reader[i];
		}
		std::cout << std::endl;

		for (int i = 0; i < n; i++) {
			reader[i] = 0;
		}*/

	}
	

	if (outputflag == 1) {
		int startindex = 0, endindex = 0, flag = 0;
		for (int i = 255; i > 0; i--) {
			if (inputfilepath[i] == '.' && flag == 0) {
				endindex = i - 1;
				flag = 1;
			}
			if (inputfilepath[i] == '\\') {
				startindex = i + 1;
				break;
			}
		}
		if (endindex - startindex < 2) {
			for (int i = 0; i < (endindex - startindex + 1); i++) {
				outputfilename[i] = inputfilepath[startindex];
			}
		}
		else {
			for (int i = 0; i < 3; i++) {
				outputfilename[i] = inputfilepath[startindex + i];
			}
		}
		char out[9] = {'_', 'o', 'u', 't', '.', 'd', 'a', 't', '\0'};
		for (int i = 0; i < 4; i++) {
			if (outputfilename[i] == 'М') {
				for (int j = i, k = 0; j < i + 9; j++, k++) {
					outputfilename[j] = out[k];
				}
				break;
			}
		}
		//std::cout << "outputfilename end = " << outputfilename << std::endl;
		outputfile.open(outputfilename, std::ios::out);
		inputfile.close();
		inputfile.open(inputfilepath);
		while (!inputfile.eof()) {
			inputfile.getline(reader, n);
			outputfile << std::setw(20) << reader << std::endl;
		}
		outputfile << std::setw(20) << "Найдовше слово у файлі = " << longestword << std::endl;
		outputfile << std::setw(20) << "Кількість повторень цього слова = " << wordcounter << std::endl;
	}

	else {
		std::cout << std::setw(20) << "Найдовше слово у файлі = " << longestword << std::endl;
		std::cout << std::setw(20) << "Кількість повторень цього слова = " << wordcounter << std::endl;
	}



	system("PAUSE");
	return 0;
}