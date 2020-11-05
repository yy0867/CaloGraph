//#include "Graph.h"
//#include "Simple_window.h"
#include "Information.h"
#include "Calo_UI.h"
#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

void print()
{
	cout << "now print graph" << endl;
}

int main() {
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

	return 0;
}