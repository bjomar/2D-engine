#include "main.hpp"
#include "engine.h"
#include "music.h"
#include "animation.h"
#include <iostream>

/*
*	Description: little 2D engine based on SDL
*	License: GPL V2 -> more info: LICENSE.txt
*	copyright © Björn marx 2016
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
using engine::helpers::keyboard;
using engine::helpers::mouse;
using engine::helpers::other;

#undef main

int main(int argc, char** argv)
{
	engine::engine e("test", 50, 50, 1024, 768);

	rectangle rect(100, 100, 100, 100);
	color white(255, 255, 255);

	point p(200, 200);

	const float movmentspeed = 100;
	float tick;

	try
	{
		while (!e.quit())
		{
			tick = SDL_GetTicks() / 15000.f;

			e->generateFrame();
			e->backgroundcolor(color(255, 255, 255));
			e->addDot(100, p, color(30, 90, 40));

			if (e())
			{
				if (e(other::QUIT))
					e.quit() = true;

				if (e(keyboard::ESCAPE))
					e.quit() = true;

				if (e(keyboard::A))
					p.x -= (int)(movmentspeed * tick);
				if (e(keyboard::D))
					p.x += (int)(movmentspeed * tick);
				if (e(keyboard::S))
					p.y += (int)(movmentspeed * tick);
				if (e(keyboard::W))
					p.y -= (int)(movmentspeed * tick);
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