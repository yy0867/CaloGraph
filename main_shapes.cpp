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
	//for commit[주석만 지워주셈]//
	system(" mode  con lines=50   cols=130 ");

	init_calo_ui();

	while (1) {
		print_edge();

		print_main_menu();
	}
	return 0;
}