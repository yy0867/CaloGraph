#include "drawing_graph.h"
#include "food_information.h"
#include "Information.h"
#include "Calo_UI.h"
#include "compare_data.h"
#include "drawing_graph.h"
#include <iostream>
#include <vector>

using namespace std;

void print()
{
	cout << "now print graph" << endl;
}

int main() {
	Foods_info xaeha;

	Food new_food(L"ÀÌÀçÇÏ", 100, 100, 100, 100);
	xaeha.add_food(new_food);

	xaeha.print_foods_info();

	return 0;
}