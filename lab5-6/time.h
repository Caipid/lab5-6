#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Time1 {
public:
	   int current_error;
	   string type_error;
	   string update;
public:

	Time1(int h,string t, string u)
		: current_error(h),type_error(t), update(u){}

};
	

class Time {
public:int hour = NULL;
	  int minutes = NULL;
	  int seconds = NULL;
public:
	void getData(void){
		cout << "Введите часы,минуты,секунды:";
		cin >> hour >> minutes >> seconds;
	}

	void diskOut(ofstream& fout) {
		fout << this->hour << endl;
		fout << this->minutes << endl;
		fout << this ->seconds << endl;
		cout << "Ваши значения: ";
		cout << hour;
		cout << ":";
		cout << minutes;
		cout << ":";
		cout << seconds << endl;
	}

	void diskIn(ifstream& fin){
		fin >> this -> hour;
		fin >> this -> minutes;
		fin >> this -> seconds;
		}

	int times(int hour, int minutes, int seconds) {
			if (0 <= hour && hour <= 24){
				if (0 <= minutes && minutes <= 60) {
					if (0 <= seconds && seconds <= 60) {
						int fullt = 0;
						fullt = hour * 3600 + minutes * 60 + seconds;
						return fullt;
					}
					else throw Time1(seconds, "Введите значения от 0 до 60 включительно!", "Неверное значение - ");
				}
				else throw Time1(minutes, "Введите значения от 0 до 60 включительно!", "Неверное значение - ");
			}
			else throw Time1(hour, "Введите значения от 0 до 24 включительно!", "Неверное значение - ");

		}
	void result(int fullt, int nighttime) {
		if (fullt == 0 || fullt == 24 * 60) {
			cout << "Сейчас полночь";
		}
		else {
		int a = nighttime - fullt;
				int min = a / 60 % 60;
				int hour = a / 3600;
				int sec = a % 60;
				std::cout << "Осталось до получночи  " << "часов:" << hour << " минут:" << min << " секунд:" << sec << std::endl;
		}
	}
	void plustime(int fullt, int hour, int min, int sec) {
		
		fullt += hour * 3600 + min * 60 + sec;
		int min1 = fullt / 60 % 60 % 60;
		int hour1 = fullt / 3600 % 24;
		int sec1 = fullt % 60 % 60;
		std::cout << "Время через " << "часов:" << hour << " минут:" << min << " секунд:" << sec << std::endl;
		std::cout << hour1 << " - часов " << min1 << " - минут " << sec1 << " - секунд" << std::endl;
	}
	
};
	
