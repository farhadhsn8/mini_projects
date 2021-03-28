#ifndef OBJECTT_H
#define OBJECTT_H
#include "Vectorr.h"
namespace AL
{
	class objectt
	{
	private:
		Vectorr position;
	public:
		objectt();
		Vectorr getposition();
		void setPosition(Vectorr);
		virtual void draw();
		virtual bool satisfy(Vectorr) = 0;
	};
}


#endif // OBJECTT_H


