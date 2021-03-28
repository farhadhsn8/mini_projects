#include "dfam.h"
using namespace std;
using namespace AL;

void dfam::setinputs(string s)
{
    inputs=s;
}

string dfam::getinputs()
{
    return inputs;
}

void dfam::setstart(dfavertex * v)
{
    for (auto verr : dvertexes)
        {
          if (verr->getmood()==1)
          {
            verr->setmood(0);
          }
        }
        v->setmood(1);
}

dfavertex * dfam::getstart()
{
    for (auto verr : dvertexes)
        {
          if (verr->getmood()==1)
          {
            return verr;
          }
        }
}

void dfam::add_dedge()
{
    dfaedge * a =new dfaedge();
    dedges.push_back(a);
    a->draw();
}

void dfam::add_dvertex()
{
    dfavertex * a =new dfavertex();
    dvertexes.push_back(a);
    a->draw();
}

void dfam::delete_dedge(dfaedge * a)
{
    for (int i=0; i<dedges.size();i++)
    {
        if (dedges[i]==a)
        {
            dedges[i]->deleteobj();
            dedges[i]=NULL;
        }
    }
}

void dfam::delete_dvertex(dfavertex * c)
{
    for (int i=0;i<dvertexes.size();i++)
    {
        if (dvertexes[i]==c)
        {
            dvertexes[i]->deleteobj();
            dvertexes[i]=NULL;
        }
    }
}

bool dfam::getresult()
{
    string s=dfam::getinputs();
    dfavertex * v = dfam::getstart();
    dfaedge * e;

    for (int i=0;i<s.size();i++)
    {
        bool changestate=0;
        if (s[i]==v->getto0()->getdweight())
        {
            e=v->getto0();
            v=e->getto();
            changestate=1;
        }
        if (s[i]==v->getto1()->getdweight() && changestate==0)
        {
            e=v->getto1();
            v=e->getto();
            changestate=1;
        }
        if (changestate ==0)
            return 0;
        if(changestate==1 && (i==(s.size()-1)))
        {
            if (v->getmood()==2)
                return 1;
            if (v->getmood()!=2)
                return 0;
        }
    }
}


















