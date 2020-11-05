#include "Calo_UI.h"
#include <Windows.h>

void textcolor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void c_main_menu()
{
	gotoxy(menu_1.first, menu_1.second);

	textcolor(BLACK, LIGHTGRAY);
	
}

void c_usr_creat() 
{

}

void c_usr_sel()
{

}

void c_usr_del()
{

}

void c_food_find()
{

}

void c_food_ins()
{

}

void c_food_del()
{

}
