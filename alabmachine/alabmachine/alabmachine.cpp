// alabmachine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "vectorr.h"
#include <string>
#include <iostream>
#include "objectt.h"
#include "vertex.h"
#include "edge.h"
#include "tedge.h"
#include "tvertex.h"
#include "dfaedge.h"
#include "dfavertex.h"
#include "machine.h"
using namespace std;
using namespace AL;
int main()
{
	Vectorr v;
	v.setx(2.4);
	v.sety(v.getx() * 2);
	cout << v.getx() << endl << v.gety() << endl;
	objectt obj;
	obj.setPosition(v);
	cout<<"obj(x) = "<<obj.getposition().getx()<<endl;
	edge e;
	e.setPosition(v);
	cout << "e(y): " << e.getposition().gety() << endl;
	vertex vtx;
	vtx.setmood(2);
	cout << "vtx (mood) = " << vtx.getmood() << endl;
	tedge te;
	te.setc2('z');
	cout <<"te(c2) = "<< te.getc2() << endl;
	tvertex tv;
	tv.setname("ali");
	cout << "tv(name) = " << tv.getname() << endl;
	dfaedge dfae;
	dfae.setdweight('m');
	cout << "dfae(weight) = " << dfae.getdweight() << endl;
	dfavertex dfav;
	dfav.setmood(1);
	cout << "dfav (mood) = " << dfav.getmood() << endl;
	machine mac;
	mac.hello();
    return 0;
}

