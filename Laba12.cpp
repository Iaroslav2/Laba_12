#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include "Laba12.h"

DataAndTime::DataAndTime() {
	time_t t = time(NULL);
	tm* date = gmtime(&t);

	day = date->tm_mday;
	month = date->tm_mon + 1;
	year = date->tm_year + 1900;
	hour = date->tm_hour + 3;
	min = date->tm_min;
	sec = date->tm_sec;
	if (year % 4 == 0) {//если год делится на 4 без остатка
		flag_year = true;
	}
	else {
		flag_year = false;
	}
}
DataAndTime::~DataAndTime() {
}
DataAndTime::DataAndTime(const DataAndTime& different) {
	year = different.year;
	month = different.month;
	day = different.day;
	hour = different.hour;
	min = different.min;
	sec = different.sec;
}

DataAndTime& DataAndTime::operator=(const DataAndTime& different) {

	if (&different == this){
		return *this;
	}
	year = different.year;
	month = different.month;
	day = different.day;
	hour = different.hour;
	min = different.min;
	sec = different.sec;
	return *this;
}
DataAndTime& DataAndTime::operator+(const DataAndTime& different){
	year = year + different.year;
	month = month + different.month;
	day = day + (different.day / 2);
	hour = hour + different.hour;
	min = min + different.min;
	sec = sec + different.sec;
	return *this; 
}
DataAndTime& DataAndTime::operator-(const DataAndTime& different) {
	year = year - different.year;
	month = month - different.month;
	day = day - (different.day / 2);
	hour = hour - different.hour;
	min = min - different.min;
	sec = sec - different.sec;
	return *this;
}

void DataAndTime::SetYear(int value) {
		year = value;
}
void DataAndTime::SetMonth(int value) {
	if (year % 4 == 0) {//если год делится на 4 без остатка
		flag_year = true;
	}
	else {
		flag_year = false;
	}

	while (value <= 0) {
		value += 12;
	}

	month = value % 13;
}
void DataAndTime::SetDay(int value) {

	while (value <= 0) { //прибавляю модуль, пока не станет нормальным числом
		value += month_array[month - 1] - 1;
	}

	if (month == 2 && flag_year) {	//если месяц февраль и год високосный
		day = (value) % (month_array[month - 1] + 1);	//берем по модулю 29
		if (day == 0) { //если день стал == 0
			day += month_array[month - 1];
		}
	}
	else {
		day = (value + 1 ) % month_array[month - 1];	//берем по модулю месяца
		if (day == 0) { //если день стал == 0
			day += month_array[month - 1] - 1;
		}
	}
}
void DataAndTime::SetHour(int value) {
	while (value < 0) {
		value += 24;
	}
	hour = value % 24;
}
void DataAndTime::SetMin(int value) {
	while (value < 0) {
		value += 60;
	}
	min = value % 60;
}

void DataAndTime::SetSec(int value) {
	while (value < 0) {
		value += 60;
	}
	sec = value % 60;
}
void DataAndTime::Checking(){
	int value = month;
	if (year % 4 == 0) {//если год делится на 4 без остатка
		flag_year = true;
	}
	else {
		flag_year = false;
	}

	while (value <= 0) {
		value += 12;
	}

	month = value % 13;
	int value1 = day;
	while (value1 <= 0) { //прибавляю модуль, пока не станет нормальным числом
		value1 += month_array[month - 1] - 1;
	}

	if (month == 2 && flag_year) {	//если месяц февраль и год високосный
		day = (value1 + 1) % (month_array[month - 1] + 1);	//берем по модулю 29
		if (day == 0) { //если день стал == 0
			day += month_array[month - 1];
		}
	}
	else {
		day = (value1) % month_array[month - 1];	//берем по модулю месяца
		if (day == 0) { //если день стал == 0
			day += month_array[month - 1] - 1;
		}
	}
	int value2 = hour;
	while (value2 < 0) {
		value2 += 24;
	}
	hour = value2 % 24;
	int value3 = min;
	while (value3 < 0) {
		value3 += 60;
	}
	min = value3 % 60;
	int value4 = sec;
	while (value4 < 0) {
		value4 += 60;
	}
	sec = value4 % 60;
}


int DataAndTime::GetYear() const{
	return year;
}
int DataAndTime::GetMonth() const{
	return month;
}
int DataAndTime::GetDay() const{
	return day;
}
int DataAndTime::GetHour() const{
	return hour;
}
int DataAndTime::GetMin() const{
	return min;
}
int DataAndTime::GetSec() const{
	return sec;
}


int DataAndTime::Input() {
	int year;
	int month;
	int day;
	int hour;
	int min;
	int sec;
	switch (k) {
	case 0:
		std::cout << "Input year -  ";
		std::cin >> year;
		k++;
		return year;
	case 1:
		std::cout << "Input month - ";
		std::cin >> month;
		k++;
		return  month;
	case 2:
		std::cout << "Input day -  ";
		std::cin >> day;
		k++;
			return day;
	case 3:
		std::cout << "Input hour - ";
		std::cin >> hour;
		k++;
		return hour;
	case 4:
		std::cout << "Input min - ";
		std::cin >> min;
		k++;
			return min;
	case 5:
		std::cout << "Input sec - ";
		std::cin >> sec;
		std::cout << "\n";
			return sec;
	}
}
void DataAndTime::output() {

	std::cout << "Year: " << GetYear() << std::endl;
	std::cout << "Month: " << GetMonth() << std::endl;
	std::cout << "Day: " << GetDay() << std::endl;
	std::cout << "Hour:" << GetHour() << ::std::endl;
	std::cout << "Min:" << GetMin() << ::std::endl;
	std::cout << "Sec:" << GetSec() << "\n" << ::std::endl;
}