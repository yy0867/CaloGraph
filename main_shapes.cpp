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

int main() {
<<<<<<< HEAD
	Drawing draw(Point(150,150),1000,800,"CaloGraph");
	Person_info pinfo("man.txt");
	draw.drawPersonInfo(draw,pinfo,MAN);
	/*
=======
>>>>>>> 44d97339e256c5ad07bcf5908c9cb2c9796e0767
	system(" mode  con lines=50   cols=130 ");

	init_calo_ui();

	while (1) {
		print_edge();

		print_main_menu();
	}
	return 0;
}