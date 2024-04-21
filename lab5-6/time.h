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
		cout << "������� ����,������,�������:";
		cin >> hour >> minutes >> seconds;
	}

	void diskOut(ofstream& fout) {
		fout << this->hour << endl;
		fout << this->minutes << endl;
		fout << this ->seconds << endl;
		cout << "���� ��������: ";
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
					else throw Time1(seconds, "������� �������� �� 0 �� 60 ������������!", "�������� �������� - ");
				}
				else throw Time1(minutes, "������� �������� �� 0 �� 60 ������������!", "�������� �������� - ");
			}
			else throw Time1(hour, "������� �������� �� 0 �� 24 ������������!", "�������� �������� - ");

		}
	void result(int fullt, int nighttime) {
		if (fullt == 0 || fullt == 24 * 60) {
			cout << "������ �������";
		}
		else {
		int a = nighttime - fullt;
				int min = a / 60 % 60;
				int hour = a / 3600;
				int sec = a % 60;
				std::cout << "�������� �� ���������  " << "�����:" << hour << " �����:" << min << " ������:" << sec << std::endl;
		}
	}
	void plustime(int fullt, int hour, int min, int sec) {
		
		fullt += hour * 3600 + min * 60 + sec;
		int min1 = fullt / 60 % 60 % 60;
		int hour1 = fullt / 3600 % 24;
		int sec1 = fullt % 60 % 60;
		std::cout << "����� ����� " << "�����:" << hour << " �����:" << min << " ������:" << sec << std::endl;
		std::cout << hour1 << " - ����� " << min1 << " - ����� " << sec1 << " - ������" << std::endl;
	}
	
};
	
