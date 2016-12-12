#include "main.hpp"
#include "engine.h"
#include "music.h"
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

using engine::helpers::rendering::format::rectangle;
using engine::helpers::rendering::format::line;
using engine::helpers::creating::color;
using engine::helpers::creating::texture;
using engine::sound::music;

#undef main

int main(int argc, char** argv)
{
	engine::engine e("test", 100, 100, 1024, 768, SDL_WINDOW_SHOWN);

	music m("music.mp3");

	m.play();

	try
	{
		while (!e.quit())
		{
			if (e.event().event_avaliable())
				if (e.event().key(SDLK_1))
					if (m.musicPaused())
						m.resume();
					else
						m.stop();

			if (e.event().generalType(SDL_QUIT))
			{
				m.halt();
				e.quit() = true;
			}
		}

		return 0;
	}
	catch (const std::exception& e)
	{
		MessageBoxA(NULL, e.what(), "error", MB_OK);

		return 0;
	}
}