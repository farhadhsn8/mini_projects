#pragma once
#ifndef EDGE_H
#define EDGE_H
#include "objectt.h"
#include "vertex.h"
namespace AL
{
	class vertex;
	class edge : public objectt
	{
	public:
		edge()
		{

		}

		virtual void draw();
		virtual void deleteobj();
		virtual bool satisfy(Vectorr)
		{
			return 1;
		}
	private:


	};
}
#endif // EDGE_H

