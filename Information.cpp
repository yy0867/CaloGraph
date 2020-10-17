#include "Information.h"
#include <iostream>
#include <string>

using namespace std;

Information::Information(string name, bool gender, int age, int height, int weight)
{
	set_information(name, gender, age, height, weight);
}

int Information::save_information(Information info)
{
	ifstream read_file;
	read_file.open("information.txt");

	return 0;
}

void Information::input_information()
{
	string name;
	bool gender;
	int gender_input = -1, age, height, weight;
	cout << "이름을 입력하세요. >> ";
	cin >> name;
	cout << "성별을 골라주세요. \n1. 남자    2. 여자 >> ";
	
	while (1) {
		cin >> gender_input;
		if (gender_input == 1) {
			gender = true;
			break;
		}
		else if (gender_input == 2) {
			gender = false;
			break;
		}
		cout << "1과 2중 선택해주세요. \n1. 남자    2. 여자 >> ";
	}

	cout << "나이가 어떻게 되시나요? (0 ~ 99세) >> ";
	
	while (1) {
		cin >> age;
		if (0 < age && age < 100) break;
		cout << "0세부터 99세까지 입력할 수 있습니다. >> ";
	}

	cout << "키와 몸무게를 입력해주세요. " << endl;
	cout << "키 >> ";
	cin >> height;
	cout << "몸무게 >> ";
	cin >> weight;

	this->set_information(name, gender, age, height, weight);

	system("cls");
}

void Information::set_information(string name, bool gender, int age, int height, int weight)
{
	set_name(name);
	set_gender(gender);
	set_age(age);
	set_height(height);
	set_weight(weight);
}

