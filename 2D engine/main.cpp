#include "main.hpp"
#include "engine.h"
#include "music.h"
#include "animation.h"
#include <iostream>

/*
*	Description: little 2D engine based on SDL
*	License: GPL V2 -> mor info: LICENSE.txt
*
*	todo:
*		-implement texture generator
*		-implement sound engine
*
**/

using engine::helpers::rendering::format::rectangle;
using engine::helpers::rendering::format::line;
using engine::helpers::creating::color;
using engine::helpers::creating::texture;
using engine::sound::music;
using engine::helpers::point;

#undef main

int main(int argc, char** argv)
{
	engine::engine e("test", 100, 100, 1024, 768, SDL_WINDOW_SHOWN);

	rectangle rect(0, 0, 100, 100);
	color white(255, 255, 255), black(0, 0, 0);

	try
	{
		e.renderer().addRectangle(rect, white, true);

		while(!e.quit())
		{
			e.renderer().generateFrame();

			if (e.event().event_avaliable())
				if (e.event().generalType(SDL_QUIT))
					e.quit() = true;
		}

		return 0;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();

		return 0;
	}
}