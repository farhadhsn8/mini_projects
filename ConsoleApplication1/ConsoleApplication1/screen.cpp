#include "stdafx.h"
#include "screen.h"


screen::screen(int sx,int sy ,short shape_number)
{
	set_screen_x(sx);
	set_screen_y(sy);
}
void screen::set_screen_x(int x)
{
	screen_x = x;
}
void screen::set_screen_y(int y)
{
	screen_y = y;
}
void screen::counter_shape(bool add_or_deduct)
{
	if (add_or_deduct==0) shape_count --;
	if (add_or_deduct == 1) shape_count++;

}


screen::~screen()
{
}
