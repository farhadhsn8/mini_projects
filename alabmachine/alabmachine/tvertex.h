#pragma once
#ifndef TVERTEX_H
#define TVERTEX_H
#include "vertex.h"
#include <vector>
#include "tedge.h"
namespace AL
{
	class tedge;
	class tvertex : public vertex
	{
	public:
		tvertex()
		{

		}
		void settoedges(tedge *);
		std::vector < tedge * > toedges;
	


	};
}
#endif // TVERTEX_H

