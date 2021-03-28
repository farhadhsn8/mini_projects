#pragma once
#ifndef OBJECT_H
#define OBJECT_H
#include "vectorr.h"
namespace AL
{
	class objectt
	{
	private:
		Vectorr position;
	public:
		objectt()
		{
			
		}
		Vectorr getposition();
		void setPosition(Vectorr);
		virtual void draw();
		virtual void deleteobj();
		
	};
}


#endif // OBJECT_H


