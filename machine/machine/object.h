#ifndef OBJECT_H
#define OBJECT_H
#include "Vectorr.h"
namespace AL
{
class object
{
private:
    Vectorr position;
public:
    object();
    Vectorr getposition();
    void setPosition(Vectorr);
    virtual void draw();
    virtual void deleteobj();
    virtual bool satisfy (Vectorr) = 0;
};
}


#endif // OBJECT_H
