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

	print_edge();
	print_menu();

	gotoxy(0, 32);
	cout << "press any key to continue...";
	_getch();

	return 0;
}