#ifndef EDGE_H
#define EDGE_H
#include "objectt.h"
#include "vertex.h"
namespace AL
{
	class edge : public objectt
	{
	public:
		edge()
		{
			from = NULL;
			to = NULL;
		}
		void setfrom(vertex *);
		vertex * getfrom();
		void setto(vertex *);
		vertex * getto();
		virtual void draw();
		virtual bool satisfy(Vectorr) = 0;
		vertex * from;
		vertex * to;
	private:
	};
}
#endif // EDGE_H

