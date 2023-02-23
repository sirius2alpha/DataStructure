#pragma once
#include<iostream>
#include<iomanip>
struct time_a {
	int year = 2020;
	int month = 1;
	int day = 1;
	int hour = 12;
	int min = 0;
	int sec = 0;
	friend ostream& operator<<(ostream& out, const time_a& t);
	friend istream& operator>>(istream& in,  time_a& t);
};

