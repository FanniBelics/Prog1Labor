#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
	Lines_window(Point xy, int w, int h, const string& title );
	Open_polyline lines;

	Menu color_menu;

	bool wait_for_button();

	//CallBacks
	static void cb_red(Address, Address pw) {reference_to<Lines_window>(pw).red_pressed();}
	static void cb_blue(Address, Address pw) {reference_to<Lines_window>(pw).blue_pressed();}
	static void cb_black(Address, Address pw){reference_to<Lines_window>(pw).black_pressed();}
	static void cb_white(Address, Address pw){reference_to<Lines_window>(pw).white_pressed();}

private:
	Button next_button;
	Button quit_button;

	In_box next_x;
	In_box next_y;

	Out_box xy_out;

	void next();
	void quit();

	//setting colors
	void change(Color c) {lines.set_color(c);}

	void red_pressed() {change(Color::red);}
	void blue_pressed() {change(Color::blue);}
	void black_pressed(){change(Color::black);}
	void white_pressed(){change(Color::white);}

};