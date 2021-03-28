#include "stdafx.h"
#include "dfaedge.h"
using namespace AL;
bool dfaedge::satisfy(Vectorr)
{
	return true;
}
char dfaedge::getdweight()
{
	return dweight;
}
void dfaedge::setdweight(char c)
{
	dweight = c;
}
void dfaedge::setfrom(dfavertex * f)
{
	from = f;
}
dfavertex* dfaedge::getfrom()
{
	return from;
}
void dfaedge::setto(dfavertex * t)
{
	to = t;
}
dfavertex* dfaedge::getto()
{
	return to;
}
