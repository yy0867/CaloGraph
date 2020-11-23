#include "Calo_UI.h"
#include "Information.h"

vector<pair<int, int>> menu_coord;
vector<pair<int, int>> user_choice_coord;
vector<string> main_menu_sel;
vector<string> user_sel_sel;
vector<string> user_del_sel;
vector<string> user_create_sel;
vector<string> user_sel_choice;

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

	user_choice_coord.push_back(make_pair(5, 3));
	user_choice_coord.push_back(make_pair(5, 7));

	user_sel_choice.push_back("1. Analyze");
	user_sel_choice.push_back("2. Add Information");
}

void print_edge(int height, int width)
{
	system("cls");

	goto_origin();
	for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= width; j++) {
			if (i == 1 && j == 1) cout << TOP_LEFT;
			else if (i == 1 && j == width) cout << TOP_RIGHT;
			else if (i == height && j == 1) cout << BOTTOM_LEFT;
			else if (i == height && j == width) cout << BOTTOM_RIGHT;
			else if (i == 1 || i == height) cout << HORIZONTAL;
			else if (j == 1 || j == width) cout << VERTICAL;
			else cout << " ";
		}
		cout << endl;
	}

	cout << endl << "Press ESC to previous menu / EXIT";
}

void print_textbox(pair<int, int> lu, string msg)
{
	const int edge_h = 3;
	const int edge_w = msg.length() + 3;

	for (int i = 1; i <= edge_h; i++) {
		gotoxy(lu.first, lu.second + i - 2);
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

	gotoxy(lu.first + 2, lu.second);
	cout << msg;
}

void print_main_menu()
{
	for (int i = 0; i < 3; i++) {
		print_textbox(menu_coord[i], main_menu_sel[i]);
	}
	int res = cursor(menu_coord);

	switch (res) {
	case -1:
		system("cls");
		print_edge();
		gotoxy(3, 5);
		cout << "Exit Program!";
		exit(1);
	case 0:
		print_user_sel();
		break;
	case 1:
		print_user_create();
		break;
	case 2:
		print_user_del();
		break;
	}
}

int cursor(vector<pair<int, int>> sels)
{
	int i = 0;
	KEY key;
	while (1) {
		pair<int, int> t = make_pair(sels[i].first - 2, sels[i].second);
		gotoxy(t);

		cout << ">";

		key = get_key();
		if (key == KEY::ESC) {
			gotoxy(0, 32);
			return -1;
		}
		else if (key == KEY::ENTER) return i;
		
		switch(key) {
		case KEY::UP:
			gotoxy(t);
			cout << " ";
			i -= 1;
			if (i < 0) i = sels.size() - 1;
			break;
		case KEY::DOWN:
			gotoxy(t);
			cout << " ";
			i = (i + 1) % sels.size();
			break;
		}
	}

	return -1;
}

vector<string> name_to_vector(vector<Information> infos)
{
	vector<string> names;
	for (Information info : infos) {
		names.push_back(info.get_name());
	}

	return names;
}

void draw_graph(string name, bool gender)
{
	Drawing draw(Point(150, 150), 1000, 800, "CaloGraph");
	name += ".txt";

	Person_info pinfo(name);
	draw.drawPersonInfo(draw, pinfo, gender);
}

void print_user_choice(string person_name, bool gender)
{
	system("cls");
	print_edge();

	for (int i = 0; i < user_sel_choice.size(); i++) {
		gotoxy(user_choice_coord[i].first, user_choice_coord[i].second);
		cout << user_sel_choice[i];
	}

	int res;
	if((res = cursor(user_choice_coord)) == -1) return;
	else if (res == 0) {
		draw_graph(person_name, gender);
	}
	else if (res == 1) {
		
	}
}

void print_user_sel() 
{
	system("cls");

	int i = 0;
	vector<Information> infos;
	infos = get_information();

	print_edge(infos.size() * 2 + 4);

	vector<string> names;
	vector<pair<int, int>> coords;

	for (Information info : infos) {
		gotoxy(5, (++i) * 2);
		coords.push_back(make_pair(4, i * 2));
		cout << info.get_name() << endl;
	}

	int res;
	if ((res = cursor(coords)) == -1) return;
	
	print_user_choice(infos[res].get_name(), infos[res].get_gender());
}

void print_user_create()
{
	system("cls");
	print_edge();

	Information info;
	info.input_information();

	vector<Information> infos;
	infos = get_information();
	infos = info.save_information(infos);

	save_to_txt(infos);
}

void print_user_del()
{
	system("cls");

	int i = 0;
	vector<Information> infos;
	infos = get_information();

	print_edge(infos.size() * 2 + 4);

	vector<string> names;
	vector<pair<int, int>> coords;

	for (Information info : infos) {
		gotoxy(5, (++i) * 2);
		coords.push_back(make_pair(4, i * 2));
		cout << info.get_name() << endl;
	}

	int index = cursor(coords);
	infos.erase(infos.begin() + index);

	save_to_txt(infos);
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
	return KEY::NONE;
}
