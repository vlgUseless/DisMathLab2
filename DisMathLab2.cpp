#include "functions.h"
#include <iostream>

using namespace std;


int main()
{
	setlocale(0, "Russian");
	Table tab;
	CalculateSDNFf(&tab);
	CalculateSKNFf(&tab);
	CalculatePoly(&tab);

	cout << "Исходная функция задана вектором (1100011001011111)." << endl << endl;
	while (true)
	{
		string str;
		cout << "Выберите действие:" << endl;
		cout << "(1) Вывод таблицы истинности для заданной функции" << endl;
		cout << "(2) Вывод СДНФ для заданной функции" << endl;
		cout << "(3) Вывод СКНФ для заданной функции" << endl;
		cout << "(4) Вывод полинома Жегалкина для заданной функции" << endl;
		cout << "(5) Вывод БДР для заданной функции" << endl;
		cout << "(6) Поиск минимального БДР для заданной функции" << endl;
		cout <<
			"(7) Вывод СДНФ и БДР для определенных переменных заданной функции"
			<< endl;
		cout << "(8) Выход " << endl << endl;

		cin >> str;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (str[0] == '8' and str.size() == 1)
		{
			break;
		}
		cout << endl;
		InputProcessing(&tab, str);
		cout << endl;
	}
}
