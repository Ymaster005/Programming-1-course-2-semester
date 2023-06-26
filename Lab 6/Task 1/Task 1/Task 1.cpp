#include <iostream>
#include <locale>
#include "Windows.h"
#include <math.h>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	long double xlast, y, x0, interval;
	
	if (argc == 4) {
		x0 = atof(argv[1]);
		xlast = atof(argv[2]);
		interval = atof(argv[3]);
	}
	
	else {
		cout << "Введіть через пробіл нижню границю, верхню границю та інтервал обчислень х " << endl;
		cin >> x0 >> xlast >> interval;
	}
	
	if (x0 > xlast || interval <= 0) {
		cout << "Невірно введені значення х або інтервалу обчислень";
		return 0;
	}

	while (x0 <= xlast) {

		if (x0 > 8 && x0 <= 10)
		{
			y = ((1 / (2 + exp(-x0))) * log(sqrt(abs(2 - x0)) + 1.2)) + (cbrt(2 / x0));
			cout << setw(10) << "x = " << x0 << setw(30) << "F(x) = " << y << endl;
		}
		else
		{
			if (x0 >= -5 && x0 <= 5)
			{
				if (x0 > -0.00001 && x0 < 0.00001) {
					cout << setw(10) << "x = " << x0 << setw(30) << "F(x) = " << "Немає значення" << endl;
				}
				else {
					y = pow(x0, -25);
					cout << setw(10) << "x = " << x0 << setw(30) << "F(x) = " << y << endl;
				}
				
			}

			else
			{
				y = pow(x0, -100);
				cout << setw(10) << "x = " << x0 << setw(30) << "F(x) = " << y << endl;
			}
		}

		x0 = x0 + interval;

	}
	system("PAUSE");
	return 0;
}