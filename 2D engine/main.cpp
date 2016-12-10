#include "main.hpp"
#include "engine.h"
#include "animation.h"
#include <Windows.h>

/*
*	Description: little 2D engine based on SDL
*	License: GPL V2 -> mor info: LICENSE.txt
*
*	todo:
*		-implement texture generator
*		-implement sound engine
*
**/

using engine_2D::helpers::rendering::format::rectangle;
using engine_2D::helpers::rendering::format::line;
using engine_2D::helpers::creating::color;
using engine_2D::helpers::creating::texture;

int main(int argc, char** argv)
{
	engine_2D::engine e("test", 100, 100, 1024, 768, SDL_WINDOW_SHOWN);

	try
	{
		while (!e.quit())
		{
			e.engine_renderer().generateFrame();

			if (e.engine_event().generalType(SDL_QUIT))
				e.quit() = true;
		}

		return 0;
	}
	catch (const std::exception& e)
	{
		MessageBoxA(NULL, e.what(), "error", MB_OK);

		return 0;
	}
}