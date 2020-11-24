#include "Calo_UI.h"
#include "Information.h"
#include <locale>
#include <atlstr.h>
#include <shellapi.h>
#include <Windows.h>

vector<pair<int, int>> menu_coord;
vector<pair<int, int>> user_choice_coord;
vector<pair<int, int>> food_list_coord;
vector<string> main_menu_sel;
vector<string> user_sel_sel;
vector<string> user_del_sel;
vector<string> user_create_sel;
vector<string> user_sel_choice;

Drawing draw;

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
	draw.setWindow(Point(150, 150), 1000, 800, "CaloGraph");
	draw.winp()->color(Color::white);
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
	name += ".txt";

	Person_info pinfo(name);
	draw.drawPersonInfo(draw, pinfo, gender);
}

wstring str2wstr(string str)
{
	string message_a = str;
	wstring message_w;
	message_w.assign(message_a.begin(), message_a.end());
	return message_w;
}

string wstr2str(wstring wstr) 
{
	std::wstring message_w = wstr;
	std::string message_a;
	message_a.assign(message_w.begin(), message_w.end());
	return message_a;
}

Food input_food_info(wstring food_name)
{
	print_edge();
	gotoxy(5, 3);
	wcout << "Input information about " << food_name;

	int carbo, pro, fat, cal;
	gotoxy(5, 5);
	cout << "Input carbohydrate[탄수화물] content >> ";
	cin >> carbo;

	gotoxy(5, 7);
	cout << "Input protein[단백질] content >> ";
	cin >> pro;

	gotoxy(5, 9);
	cout << "Input fat[지방] content >> ";
	cin >> fat;

	gotoxy(5, 11);
	cout << "Input Calories[칼로리] content >> ";
	cin >> cal;

	return Food(food_name, carbo, pro, fat, cal);
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
		Person_info pinfo(person_name + ".txt");
		Foods_info food_infos;
		wstring food;
		string date;

		USES_CONVERSION;

		print_edge();
		gotoxy(3, 2);
		cout << "Input what you eat! >> ";
		wcin >> food;

		gotoxy(3, 5);
		cout << "When did you eat? [mm/dd] >> ";

		while (1) {
			int i;
			cin >> date;
			for (i = 0; i < date.length(); i++) {
				if (date[i] == '/') continue;
				if (!isdigit(date[i])) {
					gotoxy(3, 7);
					cout << "Please input form [mm/dd] >> ";
					break;
				}
			}
			if (i == date.length()) break;
		}
		
		int res = food_infos.is_exist(food);
		if (res == -1) {
			gotoxy(6, 7);
			cout << "Press any key to open URL / ESC to exit";
			char t = _getch();
			if (t == 27) return;

			wstring link = L"https://www.myfitnesspal.com/ko/food/search?page=1&search=";
			link += food;

			ShellExecute(0, 0, link.c_str(), 0, 0, SW_SHOW);

			Food f = input_food_info(food);

			int dateIndex = pinfo.dateExist(date);
			if (dateIndex != -1)
			{
				int ncar, npro, nfat, ncal, ocar, opro, ofat, ocal;	//new,old
				ocar = pinfo[dateIndex].get_carbo(); opro = pinfo[dateIndex].get_protein();
				ofat = pinfo[dateIndex].get_fat(); ocal = pinfo[dateIndex].get_calorie();

				ncar = f.getCarbo() + ocar; npro = f.getProtein() + opro;
				nfat = f.getFat() + ofat; ncal = f.getCalorie() + ocal;

				string newInfo = date + " " + to_string(ncar) + " " + to_string(npro) + " " + to_string(nfat) + " " + to_string(ncal);
				pinfo.setOneDay(dateIndex, OneDay(newInfo));
				pinfo.write_on_file(person_name + ".txt");
			}
			else
			{
				string newInfo = "";
				newInfo = date + " " + to_string(f.getCarbo()) + " " + to_string(f.getProtein()) + " " + to_string(f.getFat()) + " " + to_string(f.getCalorie());
				pinfo.add_day(OneDay(newInfo));
			}
		}
		else {
			Food f = food_infos[res];
			int dateIndex=pinfo.dateExist(date);
			if (dateIndex!=-1)
			{
				int ncar, npro, nfat, ncal, ocar, opro, ofat, ocal;	//new,old
				ocar = pinfo[dateIndex].get_carbo(); opro = pinfo[dateIndex].get_protein();
				ofat = pinfo[dateIndex].get_fat(); ocal = pinfo[dateIndex].get_calorie();

				ncar = f.getCarbo() + ocar; npro = f.getProtein() + opro;
				nfat = f.getFat() + ofat; ncal = f.getCalorie() + ocal;

				string newInfo = date + " " + to_string(ncar) + " " + to_string(npro) + " " + to_string(nfat) + " " + to_string(ncal);
				pinfo.setOneDay(dateIndex, OneDay(newInfo));
				pinfo.write_on_file(person_name+".txt");
			}
			else
			{
				string newInfo = "";
				newInfo = date + " " + to_string(f.getCarbo()) + " " + to_string(f.getProtein()) + " " + to_string(f.getFat()) + " " + to_string(f.getCalorie());
				pinfo.add_day(OneDay(newInfo));
			}
		}
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
