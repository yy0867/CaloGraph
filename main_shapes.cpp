#include "drawing_graph.h"
#include "food_information.h"
#include "Information.h"
#include "Calo_UI.h"
#include "compare_data.h"
#include "drawing_graph.h"
#include <iostream>
#include <vector>
#include <atlstr.h>
#include <locale>

using namespace std;

void print()
{
	cout << "now print graph" << endl;
}

int main()
{
	system(" mode  con lines=50   cols=130 ");
	init_calo_ui();

	while (1) {
		print_edge();
		print_main_menu();
	}

	USES_CONVERSION;
	// string, cout, cin으로 한글 안나오면 추가해줄 것 

	/*
	Foods_info xaeha;

	Food new_food(L"������", 100, 100, 100, 100);
	xaeha.add_food(new_food);

	xaeha.print_foods_info();
	cout << endl << endl << endl;

	cout << "xaeha 등장 위치: " << xaeha.is_exist(L"이재하");
	*/
	return 0;
}