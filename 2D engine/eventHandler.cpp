/*Copyright © Björn Marx
*
*for details look COPYRIGHT.txt
*
**/

#include "eventHandler.h"

bool engine::eventHandler::event_avaliable()
{
	return SDL_PollEvent(&e);
}

bool engine::eventHandler::generalType(Uint32 type)
{
	return e.type == type;
}

bool engine::eventHandler::key(Uint32 key, bool up)
{
	if (up)
		return e.type == SDL_KEYUP && e.key.keysym.sym == key;
	else
		return e.type == SDL_KEYDOWN && e.key.keysym.sym == key;
}

bool engine::eventHandler::mouseButton(Uint32 button, bool up)
{
	if (up)
		return e.type == SDL_MOUSEBUTTONUP && e.button.button == button;
	else
		return e.type == SDL_MOUSEBUTTONDOWN && e.button.button == button;
}
