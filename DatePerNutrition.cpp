#include "DatePerNutrition.h"
#include "food_information.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <locale>
using namespace std;

//void loadFoodList(vector<Food>& foodList)
//{
//	wcout.imbue(locale("ko_KR.UTF-8"));
//	wcin.imbue(locale("ko_KR.UTF-8"));
//	locale::global(locale("ko_KR.UTF-8"));
//
//	wifstream foodFile("foodlist.txt");
//	if (!foodFile.is_open()) {
//		perror("foodlist.txt open() error!");
//		exit(-1);
//	}
//
//	wstring w_food_name;
//	string food_name;
//	double carbo, protein, fat, calorie;
//	while (!foodFile.eof()) {
//		foodFile >> w_food_name;
//		foodFile >> carbo >> protein >> fat >> calorie;
//		
//		food_name.assign(w_food_name.begin(), w_food_name.end());
//		Food f(food_name, carbo, protein, fat, calorie);
//		foodList.push_back(f);
//	}
//	
//	/*wstring food, ignore;
//	while (!foodFile.eof()) {
//		getline(foodFile, food);
//		for (int i = 0; i < food.length(); i++) {
//			if (food[i] == L' ') {
//				food = food.substr(0, i);
//				foodList.push_back(food);
//			}
//		}
//	}*/
//
//	foodFile.close();
//}

DatePerNutrition::DatePerNutrition(string date,
	double carbo, double protein, double fat, double calorie)
	: date(date), carbo(carbo), protein(protein),
	fat(fat), calorie(calorie) {}

Dates_Nutritions::Dates_Nutritions() {}

void Dates_Nutritions::addData(string date,
	double carbo, double protein, double fat, double calorie)
{
	for (size_t i = 0; i < datas.size(); i++) {
		// datas 벡터에 같은 날짜의 객체가 있으면, 그 객체에 더해줌
		if (datas[i].getDate() == date) {
			datas[i].addCarbo(carbo);
			datas[i].addProtein(protein);
			datas[i].addFat(fat);
			datas[i].addCalorie(calorie);
			return;
		}
	}

	// datas 벡터에 같은 날짜의 객체가 없으면,
	// 객체를 생성해서 벡터에 push
	datas.push_back(DatePerNutrition(date,
		carbo, protein, fat, calorie));
}