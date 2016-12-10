/*Copyright © Björn Marx
*
*for details look COPYRIGHT.txt
*
**/

#ifndef EVENTHANDLER
#define EVENTHANDLER

#include "main.hpp"

namespace engine_2D
{
	class __declspec(dllexport) eventHandler
	{
	public:
		eventHandler(SDL_Event& _e);

		bool generalType(Uint32 type);
		bool key(Uint32 key, bool up = false);
		bool mouseButton(Uint32 button, bool up = false);

	private:
		SDL_Event e;
	};
}
#endif // !EVENTHANDLER