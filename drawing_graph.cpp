#include "drawing_graph.h"
#include <iostream>
#include <cstdlib>

OneDay::OneDay(string one_line)
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

	date = info[0];
	carbo = stod(info[1]);
	protein = stod(info[2]);
	fat = stod(info[3]);
	calorie = stod(info[4]);
}

string OneDay::get_one_info()
{
	string line = date;
	line += " " + to_string((int)carbo);
	line += " " + to_string((int)protein);
	line += " " + to_string((int)fat);
	line += " " + to_string((int)calorie);

	return line;
}

Person_info::Person_info(string filename)
{
	path = filename;
	ifstream ifs(filename);
	string temp;
	if (ifs.is_open())
	{
		while (!ifs.eof())
		{
			char buf[256];
			ifs.getline(buf, 256);

			temp = buf;
			OneDay prs(temp);
			person.push_back(prs);
		}
	}
	else cout << "file doesn't exist";

	ifs.close();
}

void Person_info::add_day(OneDay source)
{
	person.push_back(source);

	fstream ofs(path, fstream::out | fstream::app);
	if (ofs.is_open())
	{
		ofs << "\n" + source.get_one_info();
	}
	else cout << "file doesn't exist";

	ofs.close();
}

string Person_info::getName()
{
	if (path.empty())
		return "";
	string name="";
	int i = 0;
	while (path[i] != '.') {
		name += path[i++];
	}
	return name;
}

Drawing::Drawing(Point tl, int width, int height, string name)
{
	win = new Simple_window(tl, width, height, name);
}

Drawing::~Drawing()
{
	delete win;
}

void Drawing::attachAxis(int x, int y,string kind,int numOfDate,vector<string> dates)
{
	Axis xa(Axis::x, Point(x, y), AXIS_WIDTH, numOfDate-1, "");
	Axis ya(Axis::y, Point(x, y), AXIS_HEIGHT, 0, kind);
	xa.set_color(Color::black);
	ya.set_color(Color::black);
	xa.draw();
	ya.draw();
	win->attach(xa);
	win->attach(ya);

	Vector_ref <Text> t;
	int unit = (double)AXIS_WIDTH / (numOfDate-1);
	for (int i = 0; i < numOfDate; ++i)
	{
		t.push_back(new Text(Point(x + i * unit, y+20), dates[i]));
		t[i].set_color(Color::black);
		t[i].draw();
		win->attach(t[i]);
	}
	//win->wait_for_button();
}

void Drawing::drawPersonInfo(Drawing draw,Person_info pinfo,int gender)
{
	double extension;
	double downize;
	vector<string> dates;
	for (int i = 0; i < pinfo.numOfDate(); ++i)
		dates.push_back(pinfo.getOneDay(i).get_date());

	Text title(Point(70, 70), "Information of "+pinfo.getName()); title.set_color(Color::black); 
	title.set_font_size(50); title.draw(); win->attach(title);

	draw.attachAxis(LEFT_GRAPH_XPOS, UP_GRAPH_YPOS, "carbo", pinfo.numOfDate(), dates);
	draw.attachAxis(RIGHT_GRAPH_XPOS, UP_GRAPH_YPOS, "protein", pinfo.numOfDate(), dates);
	draw.attachAxis(LEFT_GRAPH_XPOS, DOWN_GRAPH_YPOS, "fat", pinfo.numOfDate(), dates);
	draw.attachAxis(RIGHT_GRAPH_XPOS, DOWN_GRAPH_YPOS, "calorie", pinfo.numOfDate(), dates);
	double today, tomorrow;
	double unit = (double)AXIS_WIDTH / (pinfo.numOfDate() - 1);

	//average values
	int c, p, f, cal;
	switch (gender)
	{
	case MAN:
		c = MAN_AVERAGE_CAR; p = MAN_AVERAGE_PRO;
		f = MAN_AVERAGE_FAT; cal = MAN_AVERAGE_CAL;
		break;
	case WOMAN:
		c = WOMAN_AVERAGE_CAR; p = WOMAN_AVERAGE_PRO;
		f = WOMAN_AVERAGE_FAT; cal = WOMAN_AVERAGE_CAL;
		break;
	}

	//carbo
	extension = 1.2; downize = 150;
	//carbo average line
	Line line1(Point(LEFT_GRAPH_XPOS, UP_GRAPH_YPOS - (c * extension - downize)), Point(LEFT_GRAPH_XPOS + AXIS_WIDTH, UP_GRAPH_YPOS - (c * extension - downize)));
	line1.set_color(Color::dark_green); line1.draw(); win->attach(line1);
	Text txt1(Point(LEFT_GRAPH_XPOS-35, UP_GRAPH_YPOS - (c * extension - downize)), to_string(c));
	txt1.set_color(Color::black); txt1.draw(); win->attach(txt1);
	//

	for (int i = 0; i < pinfo.numOfDate() - 1; ++i)
	{
		today = pinfo.getOneDay(i).get_carbo()*extension-downize;
		tomorrow = pinfo.getOneDay(i + 1).get_carbo()*extension-downize;

		Line line(Point(LEFT_GRAPH_XPOS + (unit * i), UP_GRAPH_YPOS - today), Point(LEFT_GRAPH_XPOS + (unit * (i + 1)), UP_GRAPH_YPOS - tomorrow));
		line.set_color(Color::red);
		line.draw();
		win->attach(line);
	}
	for (int i = 0; i < pinfo.numOfDate(); ++i)
	{
		today = pinfo.getOneDay(i).get_carbo() * extension-downize;
		Text txt(Point(LEFT_GRAPH_XPOS + (unit * i), UP_GRAPH_YPOS - today), to_string((int)pinfo.getOneDay(i).get_carbo()));
		txt.set_color(Color::black);
		txt.draw();
		win->attach(txt);
	}
	//protein
	extension = 4; downize = 120;
	//protein average line
	Line line2(Point(RIGHT_GRAPH_XPOS, UP_GRAPH_YPOS - (p * extension - downize)), Point(RIGHT_GRAPH_XPOS + AXIS_WIDTH, UP_GRAPH_YPOS - (p * extension - downize)));
	line2.set_color(Color::dark_green); line2.draw(); win->attach(line2);
	Text txt2(Point(RIGHT_GRAPH_XPOS - 35, UP_GRAPH_YPOS - (p * extension - downize)), to_string(p));
	txt2.set_color(Color::black); txt2.draw(); win->attach(txt2);
	//
	for (int i = 0; i < pinfo.numOfDate() - 1; ++i)
	{
		today = pinfo.getOneDay(i).get_protein() * extension-downize;
		tomorrow = pinfo.getOneDay(i + 1).get_protein() * extension-downize;

		Line line(Point(RIGHT_GRAPH_XPOS + (unit * i), UP_GRAPH_YPOS - today), Point(RIGHT_GRAPH_XPOS + (unit * (i + 1)), UP_GRAPH_YPOS - tomorrow));
		line.set_color(Color::red);
		line.draw();
		win->attach(line);
	}
	for (int i = 0; i < pinfo.numOfDate(); ++i)
	{
		today = pinfo.getOneDay(i).get_protein() * extension-downize;
		
		Text txt(Point(RIGHT_GRAPH_XPOS + (unit * i), UP_GRAPH_YPOS - today), to_string((int)pinfo.getOneDay(i).get_protein()));
		txt.set_color(Color::black);
		txt.draw();
		win->attach(txt);
	}
	//fat
	//fat average line
	Line line3(Point(LEFT_GRAPH_XPOS, DOWN_GRAPH_YPOS - (f * extension - downize)), Point(LEFT_GRAPH_XPOS + AXIS_WIDTH, DOWN_GRAPH_YPOS - (f * extension - downize)));
	line3.set_color(Color::dark_green); line3.draw(); win->attach(line3);
	Text txt3(Point(LEFT_GRAPH_XPOS - 35, DOWN_GRAPH_YPOS - (f * extension - downize)), to_string(f));
	txt3.set_color(Color::black); txt3.draw(); win->attach(txt3);
	//
	for (int i = 0; i < pinfo.numOfDate() - 1; ++i)
	{
		today = pinfo.getOneDay(i).get_fat() * extension-downize;
		tomorrow = pinfo.getOneDay(i + 1).get_fat() * extension-downize;

		Line line(Point(LEFT_GRAPH_XPOS + (unit * i), DOWN_GRAPH_YPOS - today), Point(LEFT_GRAPH_XPOS + (unit * (i + 1)), DOWN_GRAPH_YPOS - tomorrow));
		line.set_color(Color::red);
		line.draw();
		win->attach(line);
	}
	for (int i = 0; i < pinfo.numOfDate(); ++i)
	{
		today = pinfo.getOneDay(i).get_fat() * extension-downize;
		
		Text txt(Point(LEFT_GRAPH_XPOS + (unit * i), DOWN_GRAPH_YPOS - today), to_string((int)pinfo.getOneDay(i).get_fat()));
		txt.set_color(Color::black);
		txt.draw();
		win->attach(txt);
	}
	//calorie
	if (gender == MAN) {
		extension = 0.25; downize = 450;
	}
	else if (gender == WOMAN) {
		extension = 0.3; downize = 400;
	}
	//calorie average line
	Line line4(Point(RIGHT_GRAPH_XPOS, DOWN_GRAPH_YPOS - (cal * extension - downize)), Point(RIGHT_GRAPH_XPOS + AXIS_WIDTH, DOWN_GRAPH_YPOS - (cal * extension - downize)));
	line4.set_color(Color::dark_green); line4.draw(); win->attach(line4);
	Text txt4(Point(RIGHT_GRAPH_XPOS - 35, DOWN_GRAPH_YPOS - (cal * extension - downize)), to_string(cal));
	txt4.set_color(Color::black); txt4.draw(); win->attach(txt4);
	//
	for (int i = 0; i < pinfo.numOfDate() - 1; ++i)
	{
		today = pinfo.getOneDay(i).get_calorie() * extension-downize;
		tomorrow = pinfo.getOneDay(i + 1).get_calorie() * extension-downize;

		Line line(Point(RIGHT_GRAPH_XPOS + (unit * i), DOWN_GRAPH_YPOS - today), Point(RIGHT_GRAPH_XPOS + (unit * (i + 1)), DOWN_GRAPH_YPOS - tomorrow));
		line.set_color(Color::red);
		line.draw();
		win->attach(line);
	}
	for (int i = 0; i < pinfo.numOfDate(); ++i)
	{
		today = pinfo.getOneDay(i).get_calorie() * extension-downize;

		Text txt(Point(RIGHT_GRAPH_XPOS + (unit * i), DOWN_GRAPH_YPOS - today), to_string((int)pinfo.getOneDay(i).get_calorie()));
		txt.set_color(Color::black);
		txt.draw();
		win->attach(txt);
	}
	win->wait_for_button();
}

void Person_info::print_person_info()
{
	for (int i = 0; i < person.size(); ++i)
	{
		cout << person[i].get_one_info() << endl;
	}
}

void Drawing::setWindow(Point tl, int width, int height, string name)
{
	win = new Simple_window(tl, width, height, name);
}