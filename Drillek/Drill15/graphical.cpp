#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

double one(double x) {return 1;}
double slope(double x) {return x/2;}
double square(double x){return x*x;}
double cos_slope(double x){return  slope(x)+cos(x);}

int main()
{
	int win_height=600, win_width=600;
	Point origo{win_width/2,win_height/2};

	Simple_window win (Point{100,100},win_width,win_height,"Function graphs");

	int notches=20;

	Axis x_sis (Axis::x, Point{100,300},400,notches,"1==20 pixels");
	x_sis.set_color(Color::red);
	win.attach(x_sis);
	Axis y_sis (Axis::y, Point{300,500},400,notches,"1==20 pixels");
	y_sis.set_color(Color::red);
	win.attach(y_sis);

	int range_min=-10, range_max=11;
	int points=400;
	int x_scaling=20, y_scaling=20;

	Function one_for_all(one,range_min,range_max,origo,points,x_scaling,y_scaling);
	win.attach(one_for_all);
	Function slopp(slope,range_min,range_max,origo,points,x_scaling,y_scaling);
	win.attach(slopp);
	Text label {Point {500,190}, "x/2"};
	win.attach(label);
	Function sqr(square,range_min,range_max,origo,points,x_scaling,y_scaling);
	win.attach(sqr);
	Function cosinus([](double x){return cos(x);},
		range_min, range_max, origo, points, x_scaling, y_scaling);
	cosinus.set_color(Color::blue);
	win.attach(cosinus);
	Function cslope(cos_slope,range_min,range_max,origo,points,x_scaling,y_scaling);
	win.attach(cslope);

	win.wait_for_button();
}