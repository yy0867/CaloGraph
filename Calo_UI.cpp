#include "Calo_UI.h"

void gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void goto_origin() { gotoxy(0, 0); }

void init()
{
	vector<pair<int, int>> menu_coord;

	menu_coord.push_back(menu_1);
	menu_coord.push_back(menu_2);
	menu_coord.push_back(menu_3);
}

void print_edge()
{
	system("cls");

	goto_origin();
	for (int i = 1; i <= EDGE_HEIGHT; i++) {
		for (int j = 1; j <= EDGE_WIDTH; j++) {
			if (i == 1 && j == 1) cout << TOP_LEFT;
			else if (i == 1 && j == EDGE_WIDTH) cout << TOP_RIGHT;
			else if (i == EDGE_HEIGHT && j == 1) cout << BOTTOM_LEFT;
			else if (i == EDGE_HEIGHT && j == EDGE_WIDTH) cout << BOTTOM_RIGHT;
			else if (i == 1 || i == EDGE_HEIGHT) cout << HORIZONTAL;
			else if (j == 1 || j == EDGE_WIDTH) cout << VERTICAL;
			else cout << " ";
		}
		cout << endl;
	}
}

void print_main_menu()
{
	for (int i = 0; i < 3; i++) {

		cout << main_menu_sel[i] << endl;
	}
}