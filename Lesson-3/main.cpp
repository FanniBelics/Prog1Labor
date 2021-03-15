#include "Graph.h"
#include "Simple_window.h"

int main ()
{
	int max_width = 600;
	int max_height = 400;

	Simple_window win(Point {100,100}, max_width, max_height, "Window");

	Rectangle r (Point {100,100},400,200);

	Ellipse e (Point{150,200},50,30);
	e.set_fill_color(Color::blue);

	win.attach(r);
	win.attach(e);

	win.wait_for_button();

	e.move(10,10);

	win.wait_for_button();

}