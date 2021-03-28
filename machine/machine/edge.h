#ifndef EDGE_H
#define EDGE_H
#include "object.h"
#include "vertex.h"
namespace AL
{
class vertex;
class edge : public object
{
public:
    edge()
    {

    }

    virtual void draw();
    virtual void deleteobj();
    virtual bool satisfy (Vectorr) = 0;
private:


};
}
#endif // EDGE_H
