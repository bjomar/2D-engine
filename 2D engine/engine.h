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

namespace engine
{
	class __declspec(dllexport) engine
	{
	public:
		engine(const char* titel, int x, int y, int w, int h, const char* iconFile = NULL, uint32_t windowflags = SDL_WINDOW_SHOWN, uint32_t rendererFlags = SDL_RENDERER_ACCELERATED);
		~engine();

		rendering::render* operator->();

		bool operator()(helpers::keyboard k, bool up = false);
		bool operator()(helpers::mouse b, bool up = false);
		bool operator()(helpers::other o);
		bool operator()();

		bool& quit();
		
	private:
		SDL_Window* win = nullptr;
		eventHandler _event;
		rendering::render r;

		bool _quit = false;
	};
}
#endif //!engine