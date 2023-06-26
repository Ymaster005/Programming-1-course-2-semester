#include <iostream>
#include <locale>
#include "Windows.h"
#include <iomanip>
#include <fstream>

void showmatrix(int, int, int**);
void task2and3(int n, int m, int** matrixA, int** matrixB, int** newmatrixA, int** newmatrixB, int max);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	char inputfilepath[256];
	std::ofstream outputfile;
	std::ifstream inputfile;

	int n, m, flag1 = 0, flag2 = 0;
	while (flag1 != 1 && flag1 != 2) {
		std::cout << "Виберіть тип вводу\n1 - вручну\n2 - з файлу" << std::endl;
		std::cin >> flag1;
		std::cin.ignore();
	}
	if (flag1 == 2) {
		std::cout << "Введіть повний шлях до файлу з якого зчитують без лапок" << std::endl;
		std::cin.getline(inputfilepath, 256);
		inputfile.open(inputfilepath);
		if (!inputfile) {
			std::cout << "Невірний шлях до файлу, файл не відкрит";
			return 1;
		}
	}

	while (flag2 != 1 && flag2 != 2) {
		std::cout << "Виберіть тип виводу\n1 - у консоль\n2 - у файл" << std::endl;
		std::cin >> flag2;
	}
	if (flag2 == 2) {
		outputfile.open("output.txt", std::ios::out);
	}

	if (flag1 == 1) {
		std::cout << "Введіть розмір матриці n и m(n, m >= 6, n - строки, m - стовпці) ";
		std::cin >> n >> m;
	}
	else {
		inputfile >> n >> m;
	}
	
	int** newmatrixA = new int* [n];
	for (int i = 0; i < n; i++)
	{
		newmatrixA[i] = new int[m];
	}
	int** newmatrixB = new int* [n];
	for (int i = 0; i < n; i++)
	{
		newmatrixB[i] = new int[m];
	}
	int** matrixA = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matrixA[i] = new int[m];
	}
	int** matrixB = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matrixB[i] = new int[m];
	}
	int** matrixSum = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matrixSum[i] = new int[m];
	}


	int input;
	if (flag1 == 1) {
		std::cout << "введіть матрицю A" << std::endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				std::cin >> input;
				matrixA[i][j] = input;
			}
		}
		std::cout << "введіть матрицю B" << std::endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				std::cin >> input;
				matrixB[i][j] = input;
			}
		}
	}
	else {
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				inputfile >> input;
				matrixA[i][j] = input;
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				inputfile >> input;
				matrixB[i][j] = input;
			}
		}
	}

	//часть 1
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrixSum[i][j] = matrixA[i][j] + matrixB[i][j];
		}
	}
	//часть 1 конец

	//часть 2 и 3
	int max = matrixA[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (matrixA[i][j] > max) {
				max = matrixA[i][j];
			}
		}
	}
	//std::cout << "max = " << max;
	if (max > 0) {
		task2and3(n, m, matrixA, matrixB, newmatrixA, newmatrixB, max);
	}

	if (flag2 == 1) {
		std::cout << "\nматриця A\n";
		showmatrix(n, m, matrixA);
		std::cout << "\nматриця B\n";
		showmatrix(n, m, matrixB);
		std::cout << "\nсума матриць A и B\n";
		showmatrix(n, m, matrixSum);
		if (max <= 0) {
			std::cout << "в матриці A немає додатніх елементів більше нуля";
		}
		else {
			std::cout << "\nнова матриця B\n";
			showmatrix(n, m, newmatrixB);
			std::cout << "\nнова матриця A\n";
			showmatrix(n, m, newmatrixA);
		}
	}
	else {
		outputfile << "\nматриця A\n";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				outputfile << std::setw(4) << matrixA[i][j];
			}
			outputfile << std::endl;
		}
		outputfile << "\nматриця B\n";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				outputfile << std::setw(4) << matrixB[i][j];
			}
			outputfile << std::endl;
		}
		outputfile << "\nсума матриць A и B\n";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				outputfile << std::setw(4) << matrixSum[i][j];
			}
			outputfile << std::endl;
		}
		if (max <= 0) {
			outputfile << "в матриці A немає додатніх елементів більше нуля";
		}
		else {
			outputfile << "\nнова матриця B\n";
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					outputfile << std::setw(4) << newmatrixB[i][j];
				}
				outputfile << std::endl;
			}
			outputfile << "\nнова матриця A\n";
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					outputfile << std::setw(4) << newmatrixA[i][j];
				}
				outputfile << std::endl;
			}
		}
	}
	

	for (int i = 0; i < n; i++)
	{
		delete matrixA[i];
	}
	delete[] matrixA;

	for (int i = 0; i < n; i++)
	{
		delete matrixB[i];
	}
	delete[] matrixB;

	for (int i = 0; i < n; i++)
	{
		delete newmatrixA[i];
	}
	delete[] newmatrixA;

	for (int i = 0; i < n; i++)
	{
		delete newmatrixB[i];
	}
	delete[] newmatrixB;

	for (int i = 0; i < n; i++)
	{
		delete matrixSum[i];
	}
	delete[] matrixSum;

	system("PAUSE");
	return 0;
}

void showmatrix(int n, int m, int** matrix) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cout << std::setw(4) << matrix[i][j];
		}
		std::cout << std::endl;
	}
}

void task2and3(int n, int m, int** matrixA, int** matrixB, int** newmatrixA, int** newmatrixB, int max) {
	if (max > 0) {
		int min = max;
		int rowindex;
		int a;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (matrixA[i][j] > 0 && matrixA[i][j] < min) {
					min = matrixA[i][j];
					rowindex = i;
					a = j;
				}
			}
		}
		std::cout << "min = " << min << std::endl;
		std::cout << "стовпчик = " << a + 1 << " рядок = " << rowindex + 1 << std::endl;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				newmatrixB[i][j] = matrixB[i][j];
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (newmatrixB[i][j] < 0) {
					newmatrixB[i][j] = min;
				}
			}
		}

		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				newmatrixA[i][j] = matrixA[i][j];
			}
		}
		int temp;
		for (int i = 0; i < m; i++)
		{
			for (int j = 1; j < m; j++)
			{
				if (newmatrixA[rowindex][j] < newmatrixA[rowindex][j - 1]) {
					temp = newmatrixA[rowindex][j];
					newmatrixA[rowindex][j] = newmatrixA[rowindex][j - 1];
					newmatrixA[rowindex][j - 1] = temp;
				}
			}
		}

	}
}