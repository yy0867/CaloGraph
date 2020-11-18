#include "Information.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

Information::Information(string name, bool gender, int age, int height, int weight)
{
	set_information(name, gender, age, height, weight);
}

void Information::save_information(vector<Information> info)
{
	ofstream write_file;
	write_file.open("information.txt", fstream::out | fstream::app); //***test: information.txt*** | ***Release: ../information.txt***

	if (write_file.is_open()) {
		Information target = *this;
		if (find(info.begin(), info.end(), target) == info.end()) {
			string temp = convert_string();
			const char* write_string = temp.c_str();
			write_file.write(write_string, strlen(write_string));
		}
	}

	write_file.close();
}

//Read Information from Console
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

//Save Information to this Class
void Information::set_information(string name, bool gender, int age, int height, int weight)
{
	set_name(name);
	set_gender(gender);
	set_age(age);
	set_height(height);
	set_weight(weight);
}

void save_to_txt(vector<Information> infos) 
{
	ofstream write;
	write.open("Information.txt");

	if (write.is_open()) {
		for (Information info : infos) {
			string temp = info.convert_string();
			const char* str = temp.c_str();

			write.write(str, strlen(str));
		}
	}

	write.close();
}

void del_information(Information target) 
{
	vector<Information> infos = get_information();
	vector<Information>::iterator itr;
	
	for (itr = infos.begin(); itr != infos.end(); ++itr) {
		if (*itr == target) break;
	}

	infos.erase(itr);

	save_to_txt(infos);
}