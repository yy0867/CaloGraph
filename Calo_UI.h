#ifndef __CALO_UI_H__
#define __CALO_UI_H__

#include <Windows.h>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

#define EDGE_WIDTH 100
#define EDGE_HEIGHT 30

const string TOP_LEFT = "┌";
const string TOP_RIGHT = "┐";
const string BOTTOM_LEFT = "└";
const string BOTTOM_RIGHT = "┘";
const string VERTICAL = "│";
const string HORIZONTAL = "─";

//Move Cursor to (x, y)
void gotoxy(int x, int y)
{
	COORD pos = { x,y };
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
	pair<int, int> menu_1 = make_pair(40, 20);
	pair<int, int> menu_2 = make_pair(40, 22);
	pair<int, int> menu_3 = make_pair(40, 24);

	gotoxy(menu_1.first, menu_1.second);
	cout << "1. 사용자 생성" << endl;

	gotoxy(menu_2.first, menu_2.second);
	cout << "2. 사용자 선택" << endl;

	gotoxy(menu_3.first, menu_3.second);
	cout << "3. 사용자 삭제" << endl;
}

void cursor()
{

}

#endif