/*Copyright © Björn Marx
*
*for details look COPYRIGHT.txt
*
**/

#ifndef ENGINE
#define ENGINE

#include "main.hpp"
#include "helpers.h"
#include "render.h"
#include "eventHandler.h"


namespace engine_2D
{
	class __declspec(dllexport) engine
	{
	public:
		engine(const char* titel, int x, int y, int w, int h, Uint32 windowflags);
		~engine();

		rendering::render& engine_renderer();
		eventHandler& engine_event();

		bool& quit();

	private:
		SDL_Window* win = nullptr;
		SDL_Event _event;
		
		rendering::render r;
		eventHandler event;


		bool _quit = false;
	};
}
#endif