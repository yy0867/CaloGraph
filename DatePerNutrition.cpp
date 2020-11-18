#include "DatePerNutrition.h"
#include <iostream>
#include <cstdlib>
using namespace std;

DatePerNutrition::DatePerNutrition(string date,
	double carbo, double protein, double fat, double calorie)
	: date(date), carbo(carbo), protein(protein),
	fat(fat), calorie(calorie) {}

//Dates_Nutritions::Dates_Nutritions()
//{
//
//}

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