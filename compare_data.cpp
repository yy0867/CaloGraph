#include <iostream>
#include <fstream>
#include "compare_data.h"
dates::dates()
{
	this->date = date;
	this->carbo = carbo;
	this->protein = protein;
	this->fat = fat;
	this->calorie = calorie;
}

//dates::dates(string date, double carbo, double protein, double fat, double calorie)
//	: date(date), carbo(carbo), protein(protein), fat(fat), calorie(calorie) {}

void dates::OpenFile(string username)
{
	ifstream file;
	string line;
	vector<string> info;

	username += ".txt";
	file.open(username);
	if (file.is_open()) {
		while (!file.eof()) {
			int count = 0;
			getline(file, line, ' ');
			info.push_back(line);
		}
	}
		cout << info[4] << " ";
	file.close();
}