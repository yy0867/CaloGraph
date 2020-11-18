#include "Calo_UI.h"
#include <conio.h>

vector<pair<int, int>> menu_coord;
vector<string> main_menu_sel;

void gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void gotoxy(pair<int, int> coord)
{
	COORD pos = { coord.first, coord.second };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void goto_origin() { gotoxy(0, 0); }

void set_color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void init_calo_ui()
{
	menu_coord.push_back(menu_1);
	menu_coord.push_back(menu_2);
	menu_coord.push_back(menu_3);

	main_menu_sel.push_back("1. Select User");
	main_menu_sel.push_back("2. Create User");
	main_menu_sel.push_back("3. Delete User");
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

void print_textbox(pair<int, int> lu, string msg)
{
	const int edge_h = 3;
	const int edge_w = msg.length() + 3;

	for (int i = 1; i <= edge_h; i++) {
		gotoxy(lu.first, lu.second + i);
		for (int j = 1; j <= edge_w; j++) {
			if (i == 1 && j == 1) cout << TOP_LEFT;
			else if (i == 1 && j == edge_w) cout << TOP_RIGHT;
			else if (i == edge_h && j == 1) cout << BOTTOM_LEFT;
			else if (i == edge_h && j == edge_w) cout << BOTTOM_RIGHT;
			else if (i == 1 || i == edge_h) cout << HORIZONTAL;
			else if (j == 1 || j == edge_w) cout << VERTICAL;
			else cout << " ";
		}
	}

	gotoxy(lu.first + 2, lu.second + 2);
	cout << msg;
}

void print_main_menu()
{
	for (int i = 0; i < 3; i++) {
		print_textbox(menu_coord[i], main_menu_sel[i]);
	}
	cursor(menu_coord, main_menu_sel);
}

void cursor(vector<pair<int, int>> sels, vector<string> msgs)
{
	while (1) {
		gotoxy(0, 32);
		char t = _getch();
		if (t == 27) break; //ESC
	}
}