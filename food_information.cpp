#include "food_information.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <locale>
using namespace std;

Nutrition::Nutrition()
	: carbo(0), protein(0), fat(0), calorie(0) {}

Nutrition::Nutrition(int carbo, int protein,
	int fat, int calorie)
	: carbo(carbo), protein(protein), fat(fat), calorie(calorie) {}

Food::Food(wstring name, int carbo, int protein,
	int fat, int calorie)
	: food_name(name)
{
	nutrition.setCarbo(carbo);
	nutrition.setProtein(protein);
	nutrition.setFat(fat);
	nutrition.setCalorie(calorie);
}

Food::Food(wstring one_line)
{
	wstring info[5];
	int count = 0;
	for (int i = 0; i < one_line.size(); ++i)
	{
		if (one_line[i] == ' ')
			count++;

		switch (count)
		{
		case 0: info[0] += one_line[i]; break;
		case 1: info[1] += one_line[i]; break;
		case 2: info[2] += one_line[i]; break;
		case 3: info[3] += one_line[i]; break;
		case 4: info[4] += one_line[i]; break;
		}
	}

	food_name = info[0];
	nutrition.setCarbo(stoi(info[1]));
	nutrition.setProtein(stoi(info[2]));
	nutrition.setFat(stoi(info[3]));
	nutrition.setCalorie(stoi(info[4]));
}

wstring cut_int(wstring s)
{
	wstring out = L"";
	for (int i = 0; i < s.length(); i++) {
		out += s[i];
		if (s[i] == '.') {
			out += s[i + 1];
			break;
		}
	}

	return out;
}

wstring Food::get_one_info()
{
	wstring line = food_name;
	line += L" " + to_wstring(nutrition.getCarbo());
	line += L" " + to_wstring(nutrition.getProtein());
	line += L" " + to_wstring(nutrition.getFat());
	line += L" " + to_wstring(nutrition.getCalorie());
	return line;
}

Foods_info::Foods_info()
{
	read_from_file();
}

void Foods_info::read_from_file()
{
	wcout.imbue(locale("ko_KR.UTF-8"));
	wcin.imbue(locale("ko_KR.UTF-8"));
	locale::global(locale("ko_KR.UTF-8"));

	wifstream foodFile("foodlist.txt");
	if (!foodFile.is_open()) {
		perror("foodlist.txt open() error!");
		exit(-1);
	}

	wstring food_name;
	int carbo, protein, fat, calorie;
	while (!foodFile.eof()) {
		foodFile >> food_name;
		foodFile >> carbo >> protein >> fat >> calorie;

		Food f(food_name, carbo, protein, fat, calorie);
		foods.push_back(f);
	}

	foodFile.close();
}

void Foods_info::add_food(Food source)
{
	foods.push_back(source);

	wofstream foodFile("foodlist.txt", ofstream::out | ofstream::app);
	if (!foodFile.is_open()) {
		perror("foodlist.txt open() error!");
		exit(-1);
	}
	foodFile << "\n" << source.get_one_info();

	foodFile.close();
}

void Foods_info::print_foods_info()
{
	for (int i = 0; i < foods.size(); ++i)
		wcout << foods[i].get_one_info() << endl;
}