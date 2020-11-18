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

	Drawing draw(Point(150,150),1000,800,"window");
	draw.attachAxis(200, 200);
	draw.winp()->wait_for_button();

	/*
	system(" mode  con lines=50   cols=130 ");

	init_calo_ui();

	while (1) {
		print_edge();
<<<<<<< HEAD
		
		t = _getch();
<<<<<<< HEAD
		if (t == 27) break;
	}
	
=======
		if (t == 27) break; //ESC

=======
>>>>>>> origin/main
		print_main_menu();
	}
<<<<<<< HEAD
>>>>>>> origin/main
*/
	return 0;
}