#include "drawing.h"
#include <iostream>
#include <cstdlib>

Drawing::Drawing(Point tl, int width, int height, string name)
{
	win = new Simple_window(tl, width, height, name);
}

Drawing::~Drawing()
{
	delete win;
}

void Drawing::attachAxis(int x, int y)
{
	fl_line(x, y, x + AXIS_WIDTH, y + AXIS_WIDTH);
}