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
		engine(const char* titel, int x, int y, int w, int h, uint32_t windowflags);
		~engine();

		rendering::render& renderer();
		eventHandler& event();

		bool& quit();
		
	private:
		SDL_Window* win = nullptr;
		eventHandler _event;
		rendering::render r;

		bool _quit = false;
	};
}
#endif //!engine