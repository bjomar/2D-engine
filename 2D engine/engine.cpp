/*Copyright © Björn Marx
*
*for details look COPYRIGHT.txt
*
**/

#include "engine.h"

engine_2D::engine::engine(const char* titel, int x, int y, int w, int h, Uint32 windowflags) : event(_event)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);

	win = SDL_CreateWindow(titel, x, y, w, h, windowflags);
	r = rendering::render(*win, SDL_RENDERER_ACCELERATED);
}

engine_2D::engine::~engine()
{

	SDL_Quit();
}

engine_2D::rendering::render& engine_2D::engine::engine_renderer()
{
	return r;
}

engine_2D::eventHandler & engine_2D::engine::engine_event()
{
	return this->event;
}

bool& engine_2D::engine::quit()
{
	return this->_quit;
}