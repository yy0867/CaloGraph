#include "drawing_graph.h"
#include "food_information.h"
#include "Information.h"
<<<<<<< HEAD
#include "DatePerNutrition.h"
=======
#include "Calo_UI.h"
#include "drawing_graph.h"
>>>>>>> main
#include <iostream>
#include <vector>

using namespace std;

void print()
{
	cout << "now print graph" << endl;
}

<<<<<<< HEAD
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
=======
int main() {
>>>>>>> main
	system(" mode  con lines=50   cols=130 ");

	init_calo_ui();

	while (1) {
		print_edge();

		print_main_menu();
	}
<<<<<<< HEAD
	*/

=======
>>>>>>> main
	return 0;
}