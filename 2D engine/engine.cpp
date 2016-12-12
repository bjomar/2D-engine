/*Copyright © Björn Marx
*
*for details look COPYRIGHT.txt
*
**/

#include "engine.h"

engine::engine::engine(const char* titel, int x, int y, int w, int h, uint32_t windowflags)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_ALL);
	Mix_Init(MIX_ALL);

	win = SDL_CreateWindow(titel, x, y, w, h, windowflags);
	r = rendering::render(win, w, h);
}

engine::engine::~engine()
{
	SDL_DestroyRenderer(r);
	SDL_DestroyWindow(win);

	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}

engine::rendering::render& engine::engine::renderer()
{
	return this->r;
}

engine::eventHandler& engine::engine::event()
{
	return this->_event;
}

bool& engine::engine::quit()
{
	return this->_quit;
}