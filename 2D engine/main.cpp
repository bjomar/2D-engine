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
	
	srand((int)"penis");

	try
	{
		for (size_t i = 0; i < 1024; i += 50)
		{
			for (size_t j = 0; j < 768; j += 50)
			{
				e->addRectangle(rectangle(i, j, 10, 10), color(rand(), rand(), rand()), true);
				//e->addDot(10, point(i, j), color(rand(), rand(), rand()));
			}
		}

		while (!e.quit())
		{
			e->generateFrame();

			if (e())
			{
				if (e(other::QUIT))
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