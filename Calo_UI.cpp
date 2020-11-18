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

int cursor(vector<pair<int, int>> sels, vector<string> msgs)
{
	int i = 0;
	KEY key;
	while (1) {
		pair<int, int> t = make_pair(menu_coord[i].first - 2, menu_coord[i].second + 2);
		gotoxy(t);

		cout << "¢º";

		key = get_key();
		if (key == KEY::ESC) exit(1);
		else if (key == KEY::ENTER) return i;
		
		switch(key) {
		case KEY::UP:
			gotoxy(t);
			cout << " ";
			i -= 1;
			if (i < 0) i = 2;
			break;
		case KEY::DOWN:
			gotoxy(t);
			cout << " ";
			i = (i + 1) % 3;
			break;
		}
	}

	return -1;
}

KEY get_key()
{
	char t = _getch();
	switch (t) {
	case 72:
		return KEY::UP;
	case 80:
		return KEY::DOWN;
	case 75:
		return KEY::LEFT;
	case 77:
		return KEY::RIGHT;
	case 13:
		return KEY::ENTER;
	case 27:
		return KEY::ESC;
	}
<<<<<<< HEAD
=======

	return KEY::NONE;
>>>>>>> 1bd59d1e1cd265e90410edaec58524c1a98a4e4a
}
