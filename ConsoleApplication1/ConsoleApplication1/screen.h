#pragma once
#ifndef SCREEN_H
#define SCREEN_H

class screen
{
public:
	screen(  int=600,int=600,short =0);
	void set_screen_x (int);
	void set_screen_y (int);
	void counter_shape(bool);
	~screen();
protected:
	int screen_x;
	int screen_y;
	static short shape_count ;
	
	
};
#endif

