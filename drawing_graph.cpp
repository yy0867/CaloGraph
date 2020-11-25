#include "drawing_graph.h"
#include "compare_data.h"
#include <iostream>
#include <cstdlib>

OneDay::OneDay(string one_line)
{
	string info[5];
	int count = 0;
	for (int i = 0; i < one_line.size(); ++i)
	{
		if (one_line[i] == ' ')count++;
		else {
			switch (count)
			{
			case 0: info[0] += one_line[i]; break;
			case 1: info[1] += one_line[i]; break;
			case 2: info[2] += one_line[i]; break;
			case 3: info[3] += one_line[i]; break;
			case 4: info[4] += one_line[i]; break;
			}
		}
	}

	date = info[0];
	carbo = stoi(info[1]);
	protein = stoi(info[2]);
	fat = stoi(info[3]);
	calorie = stoi(info[4]);
}

string OneDay::get_one_info()
{
	string line = date;
	line += " " + to_string(carbo);
	line += " " + to_string(protein);
	line += " " + to_string(fat);
	line += " " + to_string(calorie);

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
void Person_info::setOneDay(int index,OneDay source)
{
	person[index] = source;
}
int Person_info::dateExist(string date)
{
	for (int i = 0; i < numOfDate(); ++i)
	{
		if (person[i].get_date() == date)
			return i;
	}
	
	return -1;
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

void Person_info::write_on_file(string filename)
{
	ofstream ofs(filename);
	if (ofs.is_open())
	{
		for (int i = 0; i < numOfDate(); ++i)
		{
			if (i == numOfDate() - 1) {
				ofs << person[i].get_one_info();
			}
			else {
				ofs << person[i].get_one_info() + "\n";
			}
		}
	}
	else cout << "file doesn't exist";

	ofs.close();
}

Drawing::Drawing(Point tl, int width, int height, string name)
{
	win = new Simple_window(tl, width, height, name);
}

void Drawing::drawPersonInfo(Drawing draw,Person_info pinfo,int gender)
{
	double extension;
	double downize;
	vector<string> dates;
	Vector_ref<Line> lines1;	Vector_ref<Text> txts1;
	Vector_ref<Line> lines2;	Vector_ref<Text> txts2;
	Vector_ref<Line> lines3;	Vector_ref<Text> txts3;
	Vector_ref<Line> lines4;	Vector_ref<Text> txts4;

	for (int i = 0; i < pinfo.numOfDate(); ++i)
		dates.push_back(pinfo.getOneDay(i).get_date());

	Text title(Point(70, 70), "Information of "+pinfo.getName()); title.set_color(Color::black); 
	title.set_font_size(50); title.draw(); win->attach(title);
	//Axis
	Vector_ref<Axis> axis;
	axis.push_back(new Axis(Axis::x, Point(LEFT_GRAPH_XPOS, UP_GRAPH_YPOS), AXIS_WIDTH,pinfo.numOfDate()-1, ""));
	axis.push_back(new Axis(Axis::y, Point(LEFT_GRAPH_XPOS,UP_GRAPH_YPOS), AXIS_HEIGHT, 0, "carbo"));
	axis.push_back(new Axis(Axis::x, Point(RIGHT_GRAPH_XPOS, UP_GRAPH_YPOS), AXIS_WIDTH, pinfo.numOfDate() - 1, ""));
	axis.push_back(new Axis(Axis::y, Point(RIGHT_GRAPH_XPOS, UP_GRAPH_YPOS), AXIS_HEIGHT, 0, "protein"));
	axis.push_back(new Axis(Axis::x, Point(LEFT_GRAPH_XPOS, DOWN_GRAPH_YPOS), AXIS_WIDTH, pinfo.numOfDate() - 1, ""));
	axis.push_back(new Axis(Axis::y, Point(LEFT_GRAPH_XPOS, DOWN_GRAPH_YPOS), AXIS_HEIGHT, 0, "fat"));
	axis.push_back(new Axis(Axis::x, Point(RIGHT_GRAPH_XPOS, DOWN_GRAPH_YPOS), AXIS_WIDTH, pinfo.numOfDate() - 1, ""));
	axis.push_back(new Axis(Axis::y, Point(RIGHT_GRAPH_XPOS, DOWN_GRAPH_YPOS), AXIS_HEIGHT, 0, "calorie"));
	for (int i = 0; i < axis.size(); ++i)
	{
		axis[i].set_color(Color::black);
		axis[i].draw();
		win->attach(axis[i]);
	}

	Vector_ref <Text> t;
	double unit = (double)AXIS_WIDTH / (pinfo.numOfDate() - 1);
	for (int i = 0; i < pinfo.numOfDate(); ++i)
	{
		t.push_back(new Text(Point(LEFT_GRAPH_XPOS + i * unit, UP_GRAPH_YPOS + 20), dates[i]));
		t.push_back(new Text(Point(RIGHT_GRAPH_XPOS + i * unit, UP_GRAPH_YPOS + 20), dates[i]));
		t.push_back(new Text(Point(LEFT_GRAPH_XPOS + i * unit, DOWN_GRAPH_YPOS + 20), dates[i]));
		t.push_back(new Text(Point(RIGHT_GRAPH_XPOS+ i * unit, DOWN_GRAPH_YPOS + 20), dates[i]));
	}
	for (int i = 0; i < t.size(); ++i)
	{
		t[i].set_color(Color::black);
		t[i].draw();
		win->attach(t[i]);
	}
	
	double today, tomorrow;
	
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

		lines1.push_back(new Line(Point(LEFT_GRAPH_XPOS + (unit * i), UP_GRAPH_YPOS - today), Point(LEFT_GRAPH_XPOS + (unit * (i + 1)), UP_GRAPH_YPOS - tomorrow)));
		lines1[i].set_color(Color::red);
		lines1[i].draw();
		win->attach(lines1[i]);
	}
	for (int i = 0; i < pinfo.numOfDate(); ++i)
	{
		today = pinfo.getOneDay(i).get_carbo() * extension-downize;
		txts1.push_back(new Text(Point(LEFT_GRAPH_XPOS + (unit * i), UP_GRAPH_YPOS - today), to_string((int)pinfo.getOneDay(i).get_carbo())));
		txts1[i].set_color(Color::black);
		txts1[i].draw();
		win->attach(txts1[i]);
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

		lines2.push_back(new Line(Point(RIGHT_GRAPH_XPOS + (unit * i), UP_GRAPH_YPOS - today), Point(RIGHT_GRAPH_XPOS + (unit * (i + 1)), UP_GRAPH_YPOS - tomorrow)));
		lines2[i].set_color(Color::red);
		lines2[i].draw();
		win->attach(lines2[i]);
	}
	for (int i = 0; i < pinfo.numOfDate(); ++i)
	{
		today = pinfo.getOneDay(i).get_protein() * extension-downize;
		
		txts2.push_back(new Text(Point(RIGHT_GRAPH_XPOS + (unit * i), UP_GRAPH_YPOS - today), to_string((int)pinfo.getOneDay(i).get_protein())));
		txts2[i].set_color(Color::black);
		txts2[i].draw();
		win->attach(txts2[i]);
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

		lines3.push_back(new Line(Point(LEFT_GRAPH_XPOS + (unit * i), DOWN_GRAPH_YPOS - today), Point(LEFT_GRAPH_XPOS + (unit * (i + 1)), DOWN_GRAPH_YPOS - tomorrow)));
		lines3[i].set_color(Color::red);
		lines3[i].draw();
		win->attach(lines3[i]);
	}
	for (int i = 0; i < pinfo.numOfDate(); ++i)
	{
		today = pinfo.getOneDay(i).get_fat() * extension-downize;
		
		txts3.push_back(new Text(Point(LEFT_GRAPH_XPOS + (unit * i), DOWN_GRAPH_YPOS - today), to_string((int)pinfo.getOneDay(i).get_fat())));
		txts3[i].set_color(Color::black);
		txts3[i].draw();
		win->attach(txts3[i]);
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

		lines4.push_back(new Line(Point(RIGHT_GRAPH_XPOS + (unit * i), DOWN_GRAPH_YPOS - today), Point(RIGHT_GRAPH_XPOS + (unit * (i + 1)), DOWN_GRAPH_YPOS - tomorrow)));
		lines4[i].set_color(Color::red);
		lines4[i].draw();
		win->attach(lines4[i]);
	}
	for (int i = 0; i < pinfo.numOfDate(); ++i)
	{
		today = pinfo.getOneDay(i).get_calorie() * extension-downize;

		txts4.push_back(new Text(Point(RIGHT_GRAPH_XPOS + (unit * i), DOWN_GRAPH_YPOS - today), to_string((int)pinfo.getOneDay(i).get_calorie())));
		txts4[i].set_color(Color::black);
		txts4[i].draw();
		win->attach(txts4[i]);
	}

	//comment
	Text comment1(Point(50, 750), compare_average_nutrition(pinfo.getPath(), gender));
	comment1.set_color(Color::magenta); comment1.draw(); win->attach(comment1);

	Text comment2(Point(50, 770), compare_recent_nutrition(pinfo.getPath(), gender));
	comment2.set_color(Color::dark_cyan); comment2.draw(); win->attach(comment2);
	

	win->wait_for_button();
	win->detach(title); win->detach(line1); win->detach(line2); win->detach(line3); win->detach(line4);
	win->detach(txt1); win->detach(txt2); win->detach(txt3); win->detach(txt4); win->detach(comment1); win->detach(comment2);
	for (int i = 0; i < lines1.size(); ++i)
	{
		win->detach(lines1[i]); win->detach(lines2[i]); win->detach(lines3[i]); win->detach(lines4[i]);
	}
	for (int i = 0; i < txts1.size(); ++i)
	{
		win->detach(txts1[i]); win->detach(txts2[i]); win->detach(txts3[i]); win->detach(txts4[i]);
	}
	for (int i = 0; i < t.size(); ++i){	win->detach(t[i]);}
	for (int i = 0; i < axis.size(); ++i) { win->detach(axis[i]); }
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