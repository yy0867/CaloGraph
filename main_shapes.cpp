#include "Graph.h"
#include "Simple_window.h"
#include "Information.h"
#include <iostream>
#include <vector>

using namespace std;

void print()
{
	cout << "now print graph" << endl;
}

int main() {
	vector<Information> info;

	info = get_information();

	for (Information i : info) {
		cout << i.get_name() << " " << (i.get_gender() ? "male " : "female ") << i.get_age() << " " << i.get_height() << " " << i.get_weight() << endl;
	}

	return 0;
}