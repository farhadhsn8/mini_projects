#ifndef VECTOR_H
#define VECTOR_H
#include <cmath>
#include <string>
namespace AL
{

class Vectorr
{
public:
     Vectorr(double x = 0, double y = 0) : x(x), y(y) {}
     double getx();
     double gety();
     void setx(double);
     void sety(double);
     Vectorr neg();
     Vectorr operator-();
     double size();
     Vectorr sub(Vectorr);
     Vectorr operator-(Vectorr);
     bool isZero();
     std::string toString();
private:
  double x;
  double y;

};
} // namespace AL

#endif // VECTOR_H
