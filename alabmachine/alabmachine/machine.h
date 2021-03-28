#pragma once
#ifndef MACHINE_H
#define MACHINE_H
#include <iostream>
namespace AL
{


	class machine
	{
	public:
		machine()
		{
			std::cout << "machine was created !!@!!" << std::endl;
		}
		void hello();
	};
}
#endif // MACHINE_H

