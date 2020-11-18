#include "drawing_graph.h"
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

}