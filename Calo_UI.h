#ifndef __CALO_UI_H__
#define __CALO_UI_H__

#include <Windows.h>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define EDGE_WIDTH 100
#define EDGE_HEIGHT 30

#define BLACK 0 
#define BLUE 1 
#define GREEN 2 
#define CYAN 3 
#define RED 4 
#define MAGENTA 5 
#define BROWN 6 
#define LIGHTGRAY 7 
#define DARKGRAY 8 
#define LIGHTBLUE 9 
#define LIGHTGREEN 10 
#define LIGHTCYAN 11 
#define LIGHTRED 12 
#define LIGHTMAGENTA 13 
#define YELLOW 14 
#define WHITE 15 

enum class KEY { UP, DOWN, LEFT, RIGHT, ENTER, ESC, NONE };

const string TOP_LEFT = "¦£";
const string TOP_RIGHT = "¦¤";
const string BOTTOM_LEFT = "¦¦";
const string BOTTOM_RIGHT = "¦¥";
const string VERTICAL = "¦¢";
const string HORIZONTAL = "¦¡";

const pair<int, int> menu_1 = make_pair(40, 17);
const pair<int, int> menu_2 = make_pair(40, 20);
const pair<int, int> menu_3 = make_pair(40, 23);

//Move Cursor to (x, y)
void init_calo_ui();
void gotoxy(int x, int y);
void gotoxy(pair<int, int> coord);
void goto_origin();
void print_edge();
void print_main_menu();
void print_textbox(pair<int, int> lu, string msg); //ru: right up, ld: left down
void cursor(vector<pair<int, int>> sels, vector<string> msgs);
KEY get_key();

#endif