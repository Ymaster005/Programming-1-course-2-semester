#include <iostream>
#include <locale>
#include "Windows.h"
#include <Math.h>

void showmassive(int[], int[], int, int);
int *task1(int[], int[], int[], int, int, int);
void task2(int[], int);
void task3(int[], int[], int, int);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	//инициализация массивов
	int Asize, Bsize;
	std::cout << "Будь ласка введіть кілкість елементів массиву A\n";
	std::cin >> Asize;
	std::cout << "Будь ласка введіть кілкість елементів массиву B\n";
	std::cin >> Bsize;
	int* A = new int[Asize];
	int* B = new int[Bsize];
	int Csize = Asize + Bsize;
	int* C = new int[Csize];

	//вывести размер массива C
	//std::cout << "\nразмер массива C = " << Csize << "\n";

	std::cout << "Будь ласка введіть значення елементів массиву A\n";
	for (int i = 0; i < Asize; i++) {
		std::cin >> A[i];
	}
	std::cout << "Будь ласка введіть значення елементів массиву B\n";
	for (int i = 0; i < Bsize; i++) {
		std::cin >> B[i];
	}

	//выведение массивов
	showmassive(A, B, Asize, Bsize);

	//часть 1: массив C
	task1(A, B, C, Asize, Bsize, Csize);
	
	//часть 2: нахождение суммы
	task2(A, Asize);
	
	//часть 3: нахождение произведения
	task3(A, B, Asize, Bsize);

	delete[] A;
	delete[] B;
	delete[] C;

	return 0;
}

void showmassive(int *A, int *B, int Asize, int Bsize) {
	std::cout << "Массив A: ";
	for (int i = 0; i < Asize; i++) {
		std::cout << A[i] << " ";
	}
	std::cout << "\nМассив B: ";
	for (int i = 0; i < Bsize; i++) {
		std::cout << B[i] << " ";
	}
}

int *task1(int *A, int *B, int *C, int Asize, int Bsize, int Csize) {
	//заполнение массива C
	for (int i = 0; i < Asize; i++) {
		if (A[i] % 2 == 0) {
			if (A[i] != 0) {
				C[i] = i + 1;
			}
			else {
				C[i] = 0;
			}
		}
		else {
			C[i] = A[i];
		}
	}
	for (int i = 0; i < Bsize; i++) {
		if (B[i] % 2 == 0) {
			if (B[i] != 0) {
				C[i + Asize] = i + 1;
			}
			else {
				C[i + Asize] = 0;
			}
		}
		else {
			C[i + Asize] = B[i];
		}
	}

	//пузырьковая сортировка
	int temp;
	for (int i = 0; i < Csize; i++) {
		for (int j = 0; j < Csize; j++) {
			if (C[j] < C[j - 1]) {
				temp = C[j];
				C[j] = C[j - 1];
				C[j - 1] = temp;
			}
		}
	}

	//выведение массива C
	std::cout << "\nМассив C: ";
	for (int i = 0; i < Csize; i++) {
		std::cout << C[i] << " ";
	}
	return C;
}

void task2(int *A, int Asize) {
	bool oneNegativeNumbers = false;
	bool twoNegativeNumbers = false;
	int firstNegativeIndex;
	int lastNegativeIndex;
	int sum = 0;
	//поиск отрицательных значений
	for (int i = 0; i < Asize; i++) {
		if (A[i] < 0) {
			oneNegativeNumbers = true;
			firstNegativeIndex = i;
			break;
		}
	}

	if (oneNegativeNumbers == true) {
		for (int i = Asize - 1; i > 0; i--) {
			if (A[i] < 0 && i != firstNegativeIndex) {
				lastNegativeIndex = i;
				twoNegativeNumbers = true;
				break;
			}
		}
	}

	//вывод суммы
	if (oneNegativeNumbers == false) {
		std::cout << "\nУ массиві A немає від'ємних елементів\n";
	}
	else {
		if (twoNegativeNumbers == false) {
			std::cout << "\nУ массиві A тільки один від'ємний елемент\n";
		}
		else {
			for (int i = firstNegativeIndex + 1; i < lastNegativeIndex; i++) {
				sum += A[i];
			}
			std::cout << "\nsum = " << sum << "\n";
		}
	}
}

void task3(int *A, int *B, int Asize, int Bsize) {
	int Amin = abs(A[0]), Bmin = abs(B[0]);
	int AminIndex = 0, BminIndex = 0;
	double productA = 1, productB = 1;
	double productFinal;
	//поиск минимальнго элемента в массивах
	for (int i = 0; i < Asize; i++) {
		if (abs(A[i]) < Amin) {
			Amin = abs(A[i]);
			AminIndex = i;
		}
	}
	for (int i = 0; i < Bsize; i++) {
		if (abs(B[i]) < Bmin) {
			Bmin = abs(B[i]);
			BminIndex = i;
		}
	}

	//показать индекс минимального элемента
	//std::cout << "\nAminIndex = " << AminIndex << "\tBminIndex = " << BminIndex << "\n";

	//вычисление произведения для каждого массива
	for (int i = AminIndex + 1; i < Asize; i++) {
		productA = productA * abs(A[i]);
	}
	for (int i = BminIndex + 1; i < Bsize; i++) {
		productB = productB * abs(B[i]);
	}

	//показать произведение членов массива после минимального элемента для массивов A и B
	//std::cout << "\nproductA = " << productA << "\tproductB = " << productB << "\n";

	//вычисление общего произведения и вывод его
	productFinal = productA * productB;
	std::cout << "Добуток product = " << productFinal << "\n";
}