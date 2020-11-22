//#include "Graph.h"
//#include "Simple_window.h"
#include "food_information.h"
#include "Information.h"
#include "Calo_UI.h"
#include "compare_data.h"
#include <iostream>
#include <vector>

using namespace std;

void print()
{
	cout << "now print graph" << endl;
}

int main() {
	/*system(" mode  con lines=50   cols=130 ");

	init_calo_ui();

	while (1) {
		print_edge();
		print_main_menu();
	}*/
	string username;
	cout << "username : ";
	cin >> username;
	dates test;

	test.OpenFile(username);
	return 0;
}