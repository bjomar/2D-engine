#include "main.hpp"
#include "engine.h"
/*
*	Description: this will get a little engine based on SDL
*	License: GPL V2
*
*	todo:
*		-everything
*
**/

int main(int argc, char** argv)
{
	try
	{
		return engine().run();
	}
	catch (const std::exception& e)
	{
		std::fstream f;
		f.open("error.txt", std::ios::app);

		f << e.what();
	}
}