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
	engine::engine e("test", 50, 50, 1024, 768);

	double angle = 0.0;

	rectangle rect(100, 100, 100, 100), sweg(0, 0, 100, 100);
	point center_rect((rect.x + rect.w) / 2, (rect.y + rect.h) / 2);
	color white(255, 255, 255), black(0, 0, 0);

	try
	{
		while(!e.quit())
		{
			e.renderer().clear();
			e.renderer().backgroundcolor(black);
			e.renderer().addRectangle(rect, white, angle, true);
			e.renderer().generateFrame();

			if (e.event().event_avaliable())
			{
				if (e.event().key(SDLK_RIGHT))
					angle += 0.2;

				if (e.event().key(SDLK_LEFT))
					angle -= 0.2;

				if (e.event().generalType(SDL_QUIT))
					e.quit() = true;
			}
		}

		return 0;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();

		return 0;
	}
}