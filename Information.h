#ifndef __INFORMATION_H__
#define __INFORMATION_H__

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Information //Contains Name, Gender, Age, Height, Weight
{
public:
	Information(string name = " ", bool gender = true, int age = 20, int height = 170, int weight = 70);

	vector<Information> save_information(vector<Information> info); //Save Information to txt File
	void input_information();				//Input Information from User, using Console
	void set_information(string name, bool gender, int age, int height, int weight); //Save Information to this class

	//Setter
	void set_name(string name) { this->name = name; }
	void set_gender(bool gender) { this->gender = gender; }
	void set_age(int age) { this->age = age; }
	void set_height(int height) { this->height = height; }
	void set_weight(int weight) { this->weight = weight; }

	//Getter
	string get_name()	{ return name; }
	bool get_gender()	{ return gender; }
	int get_age() { return age; }
	int get_height() { return height; }
	int get_weight() { return weight; }

	string convert_string() {
		return name + " " + (gender ? "1 " : "0 ") + to_string(age) + " " + to_string(height) + " " + to_string(weight) + "\n";
	}

	bool operator==(Information cmp) {
		return convert_string() == cmp.convert_string();
	}

private:
	string name;
	bool gender; // true -> male, false -> female
	int age;
	int height, weight;
};

//*** Read Information from txt file *** [sep_space, get_information]
static Information sep_space(string s)
{
	Information info;
	string t = "";
	int order = 0;

	for (int i = 0; i < s.length(); i++) {
		t += s[i];
		if (s[i] == ' ') {
			if (order == 0) {
				t.erase(find(t.begin(), t.end(), ' '));
				info.set_name(t);
			}
			else if (order == 1) info.set_gender((bool)(stoi(t)));
			else if (order == 2) info.set_age(stoi(t));
			else if (order == 3) info.set_height(stoi(t));

			t = "";
			order++;
		}
	}
	info.set_weight(stoi(t));

	return info;
}

static vector<Information> get_information()
{
	vector<Information> infos;

	ifstream read_file;
	read_file.open("information.txt"); //***test: information.txt*** | ***Release: ../information.txt***
	if (read_file.is_open()) {
		while (!read_file.eof()) {
			char input[sizeof(Information) + 1];
			read_file.getline(input, sizeof(Information));

			if(input[0] != '\0') infos.push_back(sep_space(input));
		}
	}
	read_file.close();

	return infos;
}
//*** Read Information from txt file ***//

void save_to_txt(vector<Information> infos);
void del_information(Information target);	//Delete Information from txt file

#endif