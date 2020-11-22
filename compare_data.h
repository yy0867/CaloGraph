#pragma once
#include <string>
#include <vector>
using namespace std;

class dates {
public:
	/*dates(string date, double carbo, double protein, double fat, double calorie);*/
	dates();
	//void OpenFile(string username, vector<dates>& value);
	void OpenFile(string username);
private:
	string date;
	double carbo;
	double protein;
	double fat;
	double calorie;
};