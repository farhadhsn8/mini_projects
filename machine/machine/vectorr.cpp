#include "Vectorr.h"
#include <iostream>
using namespace AL;
using namespace std;

double Vectorr::getx()
{
    return x;
}
double Vectorr::gety()
{
    return y;
}

void Vectorr::setx(double xx)
{
    x = xx;
}

void Vectorr::sety(double yy)
{
    y = yy;
}
Vectorr Vectorr::neg()
{
    return Vectorr(-x, -y);
}
Vectorr Vectorr::operator-()
{
    return Vectorr(-x, -y);
}

double Vectorr::size()
{
    return sqrt(x * x + y * y);
}


Vectorr Vectorr::sub(Vectorr u)
{
    return Vectorr (x-u.x,y-u.y);
}

Vectorr Vectorr::operator-(Vectorr u)
{
    return sub(u);
}
bool Vectorr::isZero()
{
    return size() < 0.001;
}

std::string Vectorr::toString()
{
  std::string result =
      "(" + std::to_string(x) + "," + std::to_string(y) + ")";
  return result;
}

