//#include "Graph.h"
//#include "Simple_window.h"
#include "food_information.h"
#include "Information.h"
#include "DatePerNutrition.h"
#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

void print()
{
	cout << "now print graph" << endl;
}

int main()
{
	/*wcout.imbue(locale("ko_KR.UTF-8"));
	wcin.imbue(locale("ko_KR.UTF-8"));
	locale::global(locale("ko_KR.UTF-8"));*/

	/*vector<Food> foodList(150);
	loadFoodList(foodList);
	cout << foodList.size();

	for (int i = 0; i < foodList.size(); i++) {
		cout << foodList[i].get_name() << " ";
		cout << foodList[i].getCarbo() << " ";
		cout << foodList[i].getProtein() << " ";
		cout << foodList[i].getFat() << " ";
		cout << foodList[i].getCalorie() << endl;
	}*/

	Foods_info xaeha;
	xaeha.print_foods_info();
	/*
	system(" mode  con lines=50   cols=130 ");

	char t;

	while (1) {
		print_edge();
		print_menu();

		//Press ESC to Exit
		gotoxy(0, 32);
		cout << "Press ESC to exit..." << endl;
		t = _getch();
		if (t == 27) break;
	}
	*/

	return 0;
}