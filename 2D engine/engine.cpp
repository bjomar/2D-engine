/*Copyright © Björn Marx
*
*for details look COPYRIGHT.txt
*
**/

#include "engine.h"

engine::engine::engine(const char* titel, int x, int y, int w, int h, const char* iconFile, uint32_t windowflags, uint32_t rendererFlags)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_ALL);
	Mix_Init(MIX_ALL);

	if (iconFile != NULL)
		SDL_SetWindowIcon(this->win, IMG_Load(iconFile));

	win = SDL_CreateWindow(titel, x, y, w, h, windowflags);
	r = rendering::render(win, w, h, rendererFlags);
}

engine::engine::~engine()
{
	SDL_DestroyRenderer(r);
	SDL_DestroyWindow(win);

	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}

engine::rendering::render* engine::engine::operator->()
{
	return &this->r;
}

bool engine::engine::operator()(helpers::keyboard k, bool up)
{
	return this->_event.key(k, up);
}

bool engine::engine::operator()(helpers::mouse b, bool up)
{
	return this->_event.mouseButton(b, up);
}

bool engine::engine::operator()(helpers::other o)
{
	return this->_event.generalType(o);
}

bool engine::engine::operator()()
{
	return this->_event.event_avaliable();
}

bool& engine::engine::quit()
{
	return this->_quit;
}