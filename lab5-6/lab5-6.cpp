#include <iostream>
#include <locale>
#include "time.h"
#include <string>
#include <fstream>
#include <string>

using namespace std;
int main() {	
	setlocale(LC_ALL, "ru");
	cout << "         Cправочная информация:" << endl;
	cout << "Ключ - 0: Завершение программы" << endl;
	cout << "Ключ - 1: Ввод временных значений" << endl;
	cout << "Ключ - 2: Запись значений в файл" << endl;
	cout << "Ключ - 3: Получение значений из файла" << endl;
	cout << "Ключ - 4: Перевод времени в общее количество секунд" << endl;
	cout << "Ключ - 5: Количество времени оставшиешся до полуночи" << endl;
	cout << "Ключ - 6: Время через 100 минут" << endl;
	int hour, minutes, seconds,fullt, nighttime;
	int key = 1;
	Time day1;
	while (key != 0) {
		cout << "Введите новый ключ:";
		cin >> key;
	switch (key)
		{
	case 1: {
		day1.getData(); 
		break;
	}
	case 2: {
		ofstream fout("T.txt");
		day1.diskOut(fout);
		break;
	}
	case 3: {
		ifstream fin("T.txt");
		day1.diskIn(fin);
		cout << "Получены значения из файла";
		break;
	}
	case 4: {
		if (day1.hour == NULL || day1.minutes == NULL || day1.seconds == NULL) {
			cout << "Сначала укажите время!" << endl;
			day1.getData();
		}
		else {
			try {
				fullt = day1.times(day1.hour,day1.minutes,day1.seconds);
			}
			catch (const Time1 e) {
				cout << e.type_error << endl;
				cout << e.update;
				cout << e.current_error << endl;
			}
			cout << "Введы коретные значения" << endl;
			cout << "Время в секундах:" << fullt;
			break;
		}
	}
	case 5: {
		if (day1.hour == NULL || day1.minutes == NULL || day1.seconds == NULL) {
			cout << "Сначала укажите время!" << endl;
			day1.getData();
			try {
				fullt = day1.times(day1.hour, day1.minutes, day1.seconds);
			}
			catch (const Time1 e) {
				cout << e.type_error << endl;
				cout << e.update;
				cout << e.current_error << endl;
			}
			cout << "Введы коретные значения" << endl;
			cout << "Время в секундах:" << fullt << endl;
			Time night;
			nighttime = night.times(24, 0, 0);
			day1.result(fullt, nighttime);
			break;
		}
		else {
			try {
				fullt = day1.times(day1.hour, day1.minutes, day1.seconds);
			}
			catch (const Time1 e) {
				cout << e.type_error << endl;
				cout << e.update;
				cout << e.current_error << endl;
			}
			cout << "Введы коретные значения" << endl;
			cout << "Время в секундах:" << fullt << endl;
			Time night;
			nighttime = night.times(24, 0, 0);
			day1.result(fullt, nighttime);
			break;
		}
	}
	case 6: {
		if (day1.hour == NULL || day1.minutes == NULL || day1.seconds == NULL) {
			cout << "Сначала укажите время!" << endl;
			day1.getData();
			try {
				fullt = day1.times(day1.hour, day1.minutes, day1.seconds);
			}
			catch (const Time1 e) {
				cout << e.type_error << endl;
				cout << e.update;
				cout << e.current_error << endl;
			}
			cout << "Введы коретные значения" << endl;
			cout << "Время в секундах:" << fullt << endl;
			day1.plustime(fullt, 0, 100, 0);
			break;
		}
		else {
			try {
				fullt = day1.times(day1.hour, day1.minutes, day1.seconds);
			}
			catch (const Time1 e) {
				cout << e.type_error << endl;
				cout << e.update;
				cout << e.current_error << endl;
			}
			cout << "Введы коретные значения" << endl;
			cout << "Время в секундах:" << fullt << endl;
			day1.plustime(fullt, 0, 100, 0);
			break;
		}
	}
	case 0:{
		cout << "                                   Спасибо, что воспользовались нашей програмой." << endl;
		cout << "                                   Хорошего вам дня!" << endl;
		cout << "                                                        © NVLCORP ";
		break;
	}
		default:
			cout << "Неправильный кодовый ключ";
			break;
		}
	}
}