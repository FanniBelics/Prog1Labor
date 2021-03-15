/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{	
	int max_width=600, max_height=400;
    Simple_window win {Point {100,100},max_width,max_height,"Canvas"};

    Line l (Point {200,200}, Point {300,300});

    Lines lines = {
    	{100, 100}, {200,100}, {150,50}, {150,150}
    };

    lines.add(Point{400,340}, Point{450,250});
    lines.set_color(Color::red);

    win.attach(lines);

    win.wait_for_button();
}
