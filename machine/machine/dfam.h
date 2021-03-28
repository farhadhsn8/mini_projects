#ifndef DFAM_H
#define DFAM_H
#include <string>
#include <vector>
#include "dfaedge.h"
#include "dfavertex.h"
#include <iostream>
namespace AL
{
class dfam
{

public:
    dfam()
    {
        std::cout << "dfam created !"<<std::endl;
    }
    void setinputs(std::string);
    std::string getinputs ();
    bool getresult();
    void setstart(dfavertex *);
    dfavertex * getstart ();
    void add_dedge ();
    void delete_dedge (dfaedge *);
    void add_dvertex ();
    void delete_dvertex (dfavertex *);
private:
    std::string inputs;
    bool result;
    dfavertex * start;
    std::vector <dfaedge * > dedges;
    std::vector <dfavertex *> dvertexes;
};
}
#endif // DFAM_H
