
#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;

    Point tl {100, 100};
    Simple_window win {tl, 1200, 800, "My Window"};

    Axis xa{Axis::x, Point {100,300},600,10,"x axis"};
    xa.set_color(Color::blue);
    xa.label.set_color(Color::dark_blue);
    Axis ya{Axis::y, Point {100,300}, 600, 10, "y axis"};
    ya.set_color(Color::red);
    ya.label.set_color(Color::dark_red);

    Function sine(sin,0,100,Point {20,150},1000,100,100);

    Polygon poly;
    poly.add(Point {600, 700});
    poly.add(Point {650, 600});
    poly.add(Point {700, 700});
    poly.set_color(Color::cyan);
    poly.set_style(Line_style::dot);
    poly.set_style(Line_style(Line_style::dot,4));

    Rectangle r {Point {200, 200}, 200, 50};
    r.set_fill_color(Color::yellow);

    Closed_polyline poly_rect;
    poly_rect.add(Point {100, 50});
    poly_rect.add(Point {200, 50});
    poly_rect.add(Point {200, 100});
    poly_rect.add(Point {100, 100});
    poly_rect.add(Point {50, 75});
    poly_rect.set_style(Line_style(Line_style::dashdot,3));

    Text t {Point {150, 150}, "Hello, graphical world!"};
    t.set_font(Graph_lib::Font::courier);
    t.set_font_size(30);
    t.set_color(Color::dark_green);

    Image ii {Point {0,40}, "image.jpg"};

    Circle c {Point {600, 400},210};
    c.set_fill_color(Color::green);
    Ellipse e {Point {100,200}, 75, 25};
    e.set_color(Color::dark_red);
    Mark m {Point {100,200}, '+'};

    win.attach(ii);
    win.attach(xa);
    win.attach(ya);
    win.attach(sine);
    win.attach(poly);
    win.attach(r);
    win.attach(poly_rect);
    win.attach(t);
    win.attach(e);
    win.attach(c);
    win.attach(m);

    win.wait_for_button();
    ii.move(10,20);

    win.wait_for_button();
}