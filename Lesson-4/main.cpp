/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{	
	int max_width=1920, max_height=1080;
    Simple_window win {Point {100,100},max_width,max_height,"Canvas"};

    Vector_ref<Rectangle> vr;

    for(int i=0; i<8; i++)
    {
        vr.push_back(new Rectangle(Point{i*100,i*100},100,100));
        vr[i].set_fill_color(Color::dark_magenta);
        //win.attach(vr[i]);
    }

    Marks mpl ("prog1");
    mpl.add{100,150};
    mpl.add{200,100};
    mpl.add{300,350};
    mpl.add{400,100};
    win.attach(mpl); 


    win.wait_for_button();
}
