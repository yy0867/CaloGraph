#ifndef __INFORMATION_H__
#define __INFORMATION_H__

#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Information
{
public:
	Information(string name = " ", bool gender = true, int age = 20, int height = 170, int weight = 70);

	int save_information(Information info);
	void input_information();
	void set_information(string name, bool gender, int age, int height, int weight);

	void set_name(string name) { this->name = name; }
	void set_gender(bool gender) { this->gender = gender; }
	void set_age(int age) { this->age = age; }
	void set_height(int height) { this->height = height; }
	void set_weight(int weight) { this->weight = weight; }

	string get_name()	{ return name; }
	bool get_gender()	{ return gender; }
	int get_age() { return age; }
	int get_height() { return height; }
	int get_weight() { return weight; }

private:
	string name;
	bool gender; // true -> male, false -> female
	int age;
	int height, weight;
};


static Information sep_space(string s)
{
	Information info;
	string t = "";
	int order = 0;

	for (int i = 0; i < s.length(); i++) {
		t += s[i];
		if (s[i] == ' ') {
			if (order == 0) info.set_name(t);
			else if (order == 1) info.set_gender((bool)(stoi(t)));
			else if (order == 2) info.set_age(stoi(t));
			else if (order == 3) info.set_height(stoi(t));
			else if (order == 4) info.set_weight(stoi(t));

			t = "";
			order++;
		}
	}

	return info;
}

static vector<Information> get_information()
{
	vector<Information> infos;

	ifstream read_file;
	read_file.open("information.txt");
	if (read_file.is_open()) {
		while (!read_file.eof()) {
			char input[sizeof(Information) + 1];
			read_file.getline(input, sizeof(Information));

			infos.push_back(sep_space(input));
		}
	}

	return infos;
}

#endif