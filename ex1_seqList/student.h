#pragma once
#include<iostream>
#include<iomanip>
using namespace std;
struct student {
	string name = "Admin";
	int ID = 1001;
	string sex = "male";
	int classroom = 0;
	string tel = "10100000000";

	friend ostream& operator<<(ostream& out, student s);
};


