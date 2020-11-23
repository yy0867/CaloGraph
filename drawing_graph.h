#pragma once
#include <vector>
#include <string>
#include "Graph.h"
#include "Simple_window.h"

#define AXIS_WIDTH 350
#define AXIS_HEIGHT 250
#define LEFT_GRAPH_XPOS 50
#define UP_GRAPH_YPOS 400
#define RIGHT_GRAPH_XPOS 600
#define DOWN_GRAPH_YPOS 700
#define MAN 0 
#define MAN_AVERAGE_CAR 250	//all units : "grams"
#define MAN_AVERAGE_PRO 60
#define MAN_AVERAGE_FAT 60
#define MAN_AVERAGE_CAL 2200
#define WOMAN 1
#define WOMAN_AVERAGE_CAR 200
#define WOMAN_AVERAGE_PRO 50
#define WOMAN_AVERAGE_FAT 50
#define WOMAN_AVERAGE_CAL 1700

using namespace Graph_lib;

class OneDay {
public:
	OneDay(string one_line);
	
	string get_one_info();
	string get_date() const { return date; }
	double get_carbo() const { return carbo; }
	double get_protein() const { return protein; }
	double get_fat() const { return fat; }
	double get_calorie() const { return calorie; }

private:
	string date;
	double carbo;
	double protein;
	double fat;
	double calorie;
};

class Person_info {
public:
	Person_info(string filename);
	void add_day(OneDay source);
	int numOfDate() { return person.size(); }

	void print_person_info();
	OneDay getOneDay(int i) const { return person[i]; }
	string getPath() const { return path; }
	string getName();
private:
	vector<OneDay> person;
	string path;
};

class Drawing {
public:
	Drawing() {}
	Drawing(Point tl,int width,int height,string name);
	~Drawing();

	void setWindow(Point tl, int width, int height, string name);

	void attachAxis(int x, int y,string kind,int numOfDate,vector<string> dates);	//x,y를 원점으로 하는 축 생성
	void drawPersonInfo(Drawing draw,Person_info pinfo,int gender);	//drawing객체, 일별 영양소 파일, 성별 입력

	Simple_window* winp() { return win; };
	void wait_for_button() { win->wait_for_button(); }
private:
	Simple_window* win;
};