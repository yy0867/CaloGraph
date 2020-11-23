#include "drawing_graph.h"
#include "food_information.h"
#include "Information.h"
#include "Calo_UI.h"
#include "drawing_graph.h"
#include <iostream>
#include <vector>

using namespace std;

void print()
{
	cout << "now print graph" << endl;
}

int main()
{
	Drawing draw;
	
	draw.setWindow(Point(150, 150), 1000, 800, "calo");
	Person_info pinfo("man.txt");
	draw.drawPersonInfo(draw, pinfo, MAN);
	return 0;
}