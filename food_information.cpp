#include "food_information.h"
#include <iostream>
#include <fstream>
using namespace std;

Foods::Foods(string one_line)
{
	string info[5];
	int count = 0;
	for (int i = 0; i < one_line.size(); ++i)
	{
		if (one_line[i] == ' ')count++;

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
	carbo = stod(info[1]);
	protein = stod(info[2]);
	fat = stod(info[3]);
	calorie = stod(info[4]);
}

string cut_double(string s)
{
	string out = "";
	for (int i = 0; i < s.length(); i++) {
		out += s[i];
		if (s[i] == '.') {
			out += s[i + 1];
			break;
		}
	}

	return out;
}

string Foods::get_one_info()
{
	string line = food_name;
	line += " " + cut_double(to_string(carbo));
	line += " " + cut_double(to_string(protein));
	line += " " + cut_double(to_string(fat));
	line += " " + cut_double(to_string(calorie));

	return line;
}

Foods_info::Foods_info()
{
	read_from_file();
}

void Foods_info::read_from_file()
{
	ifstream ifs("food_info.txt");
	string temp;
	if (ifs.is_open())
	{
		while (!ifs.eof())
		{
			char buf[256];
			ifs.getline(buf, 256);

			temp = buf;
			Foods fds(temp);
			foods.push_back(fds);
		}
	}
	else cout << "file doesn't exist";

	ifs.close();
}

void Foods_info::write_on_file()
{
	ofstream ofs("food_info.txt");
	if (ofs.is_open())
	{

	}
	else cout << "file doesn't exist";

	ofs.close();
}

void Foods_info::add_food(Foods source)
{
	foods.push_back(source);
}

void Foods_info::print_foods_info()
{
	for (int i = 0; i < foods.size(); ++i)
	{
		cout << foods[i].get_one_info() << endl;
	}
}
