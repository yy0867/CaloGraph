#include "Information.h"

using namespace std;

Information::Information(string name, bool gender, int age, int height, int weight)
{
	set_information(name, gender, age, height, weight);
}

vector<Information> Information::save_information(vector<Information> info)
{
	Information target = *this;
	if (find(info.begin(), info.end(), target) == info.end()) {
		info.push_back(target);
	}

	return info;
}

//Read Information from Console
void Information::input_information() 
{
	string name;
	bool gender;
	int gender_input = -1, age, height, weight;
	int y = 2;

	gotoxy(3, y);
	y += 3;
	cout << "이름을 입력하세요. >> ";
	cin >> name;

	gotoxy(3, y);
	y += 1;
	cout << "성별을 골라주세요.";
	gotoxy(3, y);
	y += 3;
	cout << "1. 남자    2. 여자 >> ";
	
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
		gotoxy(3, y);
		y += 3;
		cout << "1과 2중 선택해주세요. \n1. 남자    2. 여자 >> ";
	}

	gotoxy(3, y);
	y += 3;
	cout << "나이가 어떻게 되시나요? (0 ~ 99세) >> ";
	
	while (1) {
		cin >> age;
		if (0 < age && age < 100) break;
		gotoxy(3, y);
		y += 3;
		cout << "0세부터 99세까지 입력할 수 있습니다. >> ";
	}

	gotoxy(3, y);
	cout << "키와 몸무게를 입력해주세요. " << endl;
	gotoxy(3, y + 1);
	cout << "키 >> ";
	cin >> height;
	gotoxy(3, y + 2);
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
	write.open("information.txt");

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
