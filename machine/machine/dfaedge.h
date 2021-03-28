#ifndef DFAEDGE_H
#define DFAEDGE_H
#include "edge.h"
#include "dfavertex.h"
namespace AL
{
class dfavertex;
class dfaedge : public edge
{
public:
    dfaedge();
    void setfrom (dfavertex *);
    dfavertex * getfrom ();
    void setto (dfavertex *);
    dfavertex * getto ();
    void setdweight(char='0');
    char getdweight();
    bool satisfy(Vectorr);
private:
    char dweight;
    dfavertex * from;
    dfavertex * to;
};
}
#endif // DFAEDGE_H
