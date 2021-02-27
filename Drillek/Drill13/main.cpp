#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{
	Point beginning {100,100};
	int win_x=800, win_y=1000;

	Simple_window win (beginning,win_x,win_y,"Drill 13");

	int grid_x=100;
	int grid_y=100;

	Lines grid;

	for(int x=grid_x;x<win_x;x+=grid_x)
	{
		grid.add(Point{x,0},Point(x,win_y-200));
	}

	for(int y=grid_y;y<win_y;y+=grid_y)
	{
		grid.add(Point{0,y},Point(win_x,y));
	}	


	win.attach(grid);
	win.wait_for_button();
}