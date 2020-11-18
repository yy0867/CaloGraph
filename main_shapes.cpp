//#include "Graph.h"
//#include "Simple_window.h"
#include "food_information.h"
#include "Information.h"
#include "Calo_UI.h"
#include "food_information.h"
#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

void print()
{
	cout << "now print graph" << endl;
}

int main() {
	Foods_info finfo;

	finfo.print_foods_info();
	
	/*
	system(" mode  con lines=50   cols=130 ");

	char t;

	while (1) {
		print_edge();
		
		t = _getch();
<<<<<<< HEAD
		if (t == 27) break;
	}
	*/
=======
		if (t == 27) break; //ESC

		print_main_menu();
	}
>>>>>>> origin/main
	return 0;
}