#include "tedge.h"
using namespace AL;
bool satisfy()
{
    return true;
}

char tedge::getc1()
{
    return c1;
}

char tedge::getc2()
{
    return c2;
}

char tedge::getc3()
{
    return c3;
}

void tedge::setc1(char a)
{
    c1=a;
}

void tedge::setc2(char a)
{
    c2=a;
}

void tedge::setc3(char a)
{
    if (a=='R'|| a=='r' ||a=='L' ||a=='l' )
        c3=a;
}
void tedge::setfrom(tvertex * f)
{
    from=f;
}
tvertex* tedge::getfrom()
{
    return from;
}
void tedge::setto(tvertex * t)
{
    to =t;
}
tvertex* tedge::getto()
{
    return to;
}
