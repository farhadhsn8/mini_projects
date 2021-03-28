#ifndef VERTEX_H
#define VERTEX_H
#include "objectt.h"
#include <string>
#include "Vectorr.h"
#include <vector>
#include "edge.h"

namespace AL
{
	class vertex : public objectt
	{
	public:
		vertex(std::string = " ", int = 0);

		void draw();
		void setname(std::string);
		std::string getname();
		void setmood();
		int getmood();
		bool satisfy(Vectorr);
	private:
		std::string name;
		int mood;//0 is normal ,1 start ,2 final
		std::vector <int> toedge;

	};
}
#endif // VERTEX_H

