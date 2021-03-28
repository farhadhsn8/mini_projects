#include "stdafx.h"
#include "edge.h"
#include <iostream>
#include <string>
using namespace std;
using namespace AL;
void edge::setfrom(vertex * f)
{
	from = f;
}
vertex* edge::getfrom()
{
	return from;
}
void edge::setto(vertex * t)
{
	to = t;
}
vertex* edge::getto()
{
	return to;
}
void edge::draw()
{

}

