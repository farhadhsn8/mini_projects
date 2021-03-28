#pragma once
#ifndef VERTEX_H
#define VERTEX_H
#include "objectt.h"
#include <string>
#include "vectorr.h"
#include <vector>


namespace AL
{
	class vertex : public objectt
	{
	public:
		vertex()
		{

		}

		virtual void draw();
		virtual void deleteobj();
		void setname(std::string);
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

