#ifndef VERTEX_H
#define VERTEX_H
#include "object.h"
#include <string>
#include "Vectorr.h"
#include <vector>


namespace AL
{
class vertex : public object
{
public:
    vertex(std::string=" ",int=0);

    virtual void draw();
    virtual void deleteobj();
    void setname(std :: string );
    std::string getname();
    void setmood(int);
    int getmood();
    bool satisfy(Vectorr);
    private:
    std::string name;
    int mood;//0 is normal ,1 start ,2 final
};
}
#endif // VERTEX_H
