#include "Graph.h"
#include "Simple_window.h"

int main() {
	using namespace Graph_lib;

	Point tl(150, 150);
	Simple_window win(tl, 800, 800, "My window");

	Vector_ref <Box> boxes;
	Vector_ref <Regular_polygon> polys;
	Vector_ref <Star> stars;
	Vector_ref <Rose> roses;
	Vector_ref <Tschirnhausen_cubic> tc;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			boxes.push_back(new Box(Point{50 + 150 * i,50 + 150 * j},50 + 40 * i,50 + 40 * j,10));
			boxes[4 * i + j].set_color(Color{ 4 * i + j });
			boxes[4 * i + j].set_fill_color(Color{ 4 * i + j + 1 });
			boxes[4 * i + j].draw_lines();
			win.attach(boxes[4 * i + j]);
		}
	}
	win.wait_for_button();
	
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			win.detach(boxes[4*i+j]);
			
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			polys.push_back(new Regular_polygon(Point{ 100 + 150 * j,100 + 150 * i }, 4 * i + j + 3, 50));
			polys[4 * i + j].set_color(Color{ 4 * i + j });
			polys[4 * i + j].draw_lines();
			win.attach(polys[4 * i + j]);
		}
	}
	win.wait_for_button();
	
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			win.detach(polys[4 * i + j]);
		
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			stars.push_back(new Star(Point{ 100 + 150 * j,100 + 150 * i },4*i+j+3,30,60));
			stars[4 * i + j].set_color(Color{ 4 * i + j });
			stars[4 * i + j].draw_lines();
			win.attach(stars[4 * i + j]);
		}
	}
	
	win.wait_for_button();
	
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			win.detach(stars[4 * i + j]);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			roses.push_back(new Rose(Point{ 100 + 150 * i,100 + 150 * j },i+1,j+1,60));
			roses[4 * i + j].set_color(Color{ 4 * i + j });
			roses[4 * i + j].draw_lines();
			win.attach(roses[4 * i + j]);
		}
	}

	win.wait_for_button();
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			win.detach(roses[4 * i + j]);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			tc.push_back(new Tschirnhausen_cubic(Point{ 100 + 200 * i,100 + 150 * j },4*i+j+8));
			tc[4 * i + j].set_color(Color{ 4 * i + j });
			tc[4 * i + j].draw_lines();
			win.attach(tc[4 * i + j]);
		}
	}

	win.wait_for_button();
}