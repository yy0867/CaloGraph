#pragma once
#include <vector>
#include <string>
using namespace std;
//음식 탐색, 목록 추가, 목록에서 제거 필요
class Foods {
public:
	Foods(string one_line);
	string get_one_info();		// name car pro fat cal 한줄 반환

	string get_name() const { return food_name; }
	double get_carbo() const { return carbo; }
	double get_protein() const { return protein; }
	double get_fat() const { return fat; }
	double get_calorie() const { return calorie; }

private:
	string food_name;
	double carbo;
	double protein;
	double fat;
	double calorie;
};

class Foods_info {
public:
	Foods_info();
	void add_food(Foods source);
	void print_foods_info();

	void read_from_file();

private:
	vector<Foods> foods;
};
