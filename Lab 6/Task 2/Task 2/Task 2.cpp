#include <iostream>
#include <locale>
#include "Windows.h"
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	
	int next = 0;
	double x = 1, sum = 0, item, eps = 1, iteration = 0;

	std::cout << "Будь ласка введіть значення x (|x| < 1) " << endl;
	cin >> x;
	while (!(fabs(x) < 1)) {
		std::cout << "Невірне значення аргументу" << endl;
		cin >> x;
	}
	

	item = ((log((1 + x) / (1 - x))) / 2);
	
	std::cout << "Значення функції = " << setprecision(8) << item << endl;


	for (int i = 0; i < 5; i++) {
		sum += (pow(x, ((2 * i) + 1)) / ((2 * i) + 1));
		}

	std::cout <<  "Сума перших 5 членів рядку = " << setprecision(8) << sum << endl;

	std::cout << "Чи бажаєте ви розрахувати з точністю епсілон, якщо так, то введіть 1, ящо ні - 2" << endl;

	while (!(next == 1 || next == 2)) {
		cin >> next;
	}

	if (next == 1) {
		std::cout << "Будь ласка введіть точність " << endl;
		cin >> eps;
		while (eps < 0.0000000000000001) {
			std::cout << "епсілон занадто мале, будь ласка введіть інше значення" << endl;
			cin >> eps;
		}
		
	}

	if (next == 2) {
		return 0;
	}

	sum = 0;

	for (int i = 0; fabs(item - sum) > eps; i++) {
		sum += (pow(x, ((2 * i) + 1)) / ((2 * i) + 1));
		iteration++;
	}

	std::cout << "Сума рядку = " << setprecision(16) << sum << "\t кількість ітеацій = " << iteration << endl;

	system("PAUSE");
	return 0;
}