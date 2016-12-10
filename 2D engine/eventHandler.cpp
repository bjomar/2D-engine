/*Copyright © Björn Marx
*
*for details look COPYRIGHT.txt
*
**/

#include "eventHandler.h"

engine_2D::eventHandler::eventHandler(SDL_Event & _e)
{
	this->e = _e;
}

bool engine_2D::eventHandler::generalType(Uint32 type)
{
	SDL_PollEvent(&e);

	if (e.type == type)
		return true;
	else
		return false;
}

bool engine_2D::eventHandler::key(Uint32 key, bool up)
{
	SDL_PollEvent(&e);

	if (!up)
		if (e.type == SDL_KEYDOWN)
			if (e.key.keysym.sym == key)
				return true;
			else
				return false;
		else
			return false;
	else
		if (e.type == SDL_KEYUP)
			if (e.key.keysym.sym == key)
				return true;
			else return false;
		else
			return false;
}

bool engine_2D::eventHandler::mouseButton(Uint32 button, bool up)
{
	SDL_PollEvent(&e);

	if (!up)
		if (e.type == SDL_MOUSEBUTTONDOWN)
			if (e.button.button == button)
				return true;
			else
				return false;
		else
			return false;
	else
		if (e.type == SDL_MOUSEBUTTONUP)
			if (e.button.button == button)
				return true;
			else return false;
		else
			return false;
}
