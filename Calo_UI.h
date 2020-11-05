#ifndef __CALO_UI_H__
#define __CALO_UI_H__

#include <Windows.h>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

#define EDGE_WIDTH 100
#define EDGE_HEIGHT 30

enum class UI { MAIN_MENU, USR_CREAT, USR_SEL, USR_DEL, FOOD_FIND, FOOD_INS, FOOD_DEL };

const string TOP_LEFT = "┌";
const string TOP_RIGHT = "┐";
const string BOTTOM_LEFT = "└";
const string BOTTOM_RIGHT = "┘";
const string VERTICAL = "│";
const string HORIZONTAL = "─";

const pair<int, int> menu_1 = make_pair(40, 20);
const pair<int, int> menu_2 = make_pair(40, 22);
const pair<int, int> menu_3 = make_pair(40, 24);

//Move Cursor to (x, y)
void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void goto_origin() { gotoxy(0, 0); }

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

void print_menu()
{
	gotoxy(menu_1.first, menu_1.second);
	cout << "1. 사용자 생성" << endl;

	gotoxy(menu_2.first, menu_2.second);
	cout << "2. 사용자 선택" << endl;

	gotoxy(menu_3.first, menu_3.second);
	cout << "3. 사용자 삭제" << endl;
}


//UI { MAIN_MENU, USR_CREAT, USR_SEL, USR_DEL, FOOD_FIND, FOOD_INS, FOOD_DEL };
void c_main_menu();
void c_usr_creat();
void c_usr_sel();
void c_usr_del();
void c_food_find();
void c_food_ins();
void c_food_del();

void cursor(UI ui)
{
	switch (ui) {
	case UI::MAIN_MENU:
		c_main_menu();
		break;
	case UI::USR_CREAT:
		c_usr_creat();
		break;
	case UI::USR_SEL:
		c_usr_sel();
		break;
	case UI::USR_DEL:
		c_usr_del();
		break;
	case UI::FOOD_FIND:
		c_food_find();
		break;
	case UI::FOOD_INS:
		c_food_ins();
		break;
	case UI::FOOD_DEL:
		c_food_del();
		break;
	}
}

#endif