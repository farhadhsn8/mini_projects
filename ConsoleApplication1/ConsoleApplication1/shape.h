#ifndef SHAPE_H
#define SHAPE_H
#include <string>
using std::string;

#include "screen.h"
class shape :
	public screen
{
public:
	shape(string ="shekll",string ="blue",string ="white",short=10,float=0.5);
	shape();
	~shape();
	virtual void draw(string &, string &, short &, float &) const;
protected:
	string name;
	string fill; //rang shekl
	string strock; //rang hashie
	short stroke_width; // zekhamat hashie
	float opacity;//shaffafiat shekl 1>opacity>0
};
#endif
