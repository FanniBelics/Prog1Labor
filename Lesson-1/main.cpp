/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

double one (double) {return 1;}
double square (double x){return x*x;}


int main()
{
   using namespace Graph_lib;

   int xmax=1280, ymax=720;
   int x_origo=xmax/2;
   int y_origo=ymax/2;

   int rmin=-11;
   int rmax=11;

   Simple_window win {Point{100,100},xmax,ymax,"Canvas"};

   Point origo {x_origo,y_origo};

   int xlength=xmax-40;
   int ylength=ymax-40;

    int xscale=30;
    int yscale=30;
    int n_points=400;

    Function s(one,rmin,rmax,origo,n_points,xscale,yscale);
    Function sqr(square,rmin,rmax,origo,n_points,xscale,yscale);
    Function cos_f([] (double x) {return cos(x);},rmin,rmax,origo,n_points,xscale,yscale);

   Axis x {Axis::x, Point{20,y_origo}, xlength, xlength/xscale, "x"};
   Axis y {Axis::y, Point{x_origo,ylength+20}, ylength, ylength/yscale, "y"};

   Rectangle r {Point {200,200}, 100, 50};
   r.set_fill_color(Color::yellow);
   r.set_style(Line_style(Line_style::dash, 4));

    Text t{Point{200,400},"Hello World!"};
    t.set_font(Font::courier);
    t.set_font_size(20);

    Image im {Point{100,100}, "badge.jpg"};

    Circle c {Point{400,400},50};

    win.attach(im);
    win.attach(x);
    win.attach(y);
    win.attach(s);
    win.attach(sqr);
    win.attach(cos_f);
    win.attach(r);
    win.attach(t);
    win.attach(c);

    win.wait_for_button();

}
