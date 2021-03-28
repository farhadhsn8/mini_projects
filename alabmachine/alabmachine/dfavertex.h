#pragma once
#ifndef DFAVERTEX_H
#define DFAVERTEX_H
#include "vertex.h"
#include "dfaedge.h"
namespace AL
{
	class dfaedge;
	class dfavertex : public vertex
	{
	public:
		dfavertex()
		{

		}

		void setto0(dfaedge *);
		dfaedge * getto0();
		void setto1(dfaedge *);
		dfaedge * getto1();
	private:
		dfaedge * to0;
		dfaedge * to1;
	};
}
#endif // DFAVERTEX_H

