#pragma once
#include <string>
#include <vector>
using namespace std;

// 날짜 별 섭취한 영양분 양
// 사용자로부터 날짜, 먹은 음식 입력 받으면 food_info.txt에서
// 해당 음식의 영양분을 찾아서 추가함
class DatePerNutrition
{
public:
	DatePerNutrition(string date, double carbo, double protein,
		double fat, double calorie);
	
	string getDate() const { return date; }
	double getCarbo() const { return carbo; }
	double getProtein() const { return protein; }
	double getFat() const { return fat; }
	double getCalorie() const { return calorie; }

	void addCarbo(double carbo) { this->carbo += carbo; }
	void addProtein(double protein) { this->protein += protein; }
	void addFat(double fat) { this->fat += fat; }
	void addCalorie(double calorie) { this->calorie += calorie; }

private:
	string date;
	double carbo;
	double protein;
	double fat;
	double calorie;
};

class Dates_Nutritions
{
public:
//	Dates_Nutritions();
	void addData(string date, double carbo, double protein,
		double fat, double calorie);

private:
	vector<DatePerNutrition> datas;
	// 각 날짜 별로 탄, 단, 지, 칼로리 저장된 벡터
};
