#include "engine.h"

engine::engine()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	this->window = SDL_CreateWindow("test", 60, 60, 640, 480, SDL_WINDOW_SHOWN);
	if (!this->window)
		throw std::exception(SDL_GetError());

	this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
	if (!this->renderer)
		throw std::exception(SDL_GetError());
}

engine::~engine()
{
	SDL_DestroyRenderer(this->renderer);
	SDL_DestroyWindow(this->window);
	IMG_Quit();
	SDL_Quit();
}

int engine::run()
{
	while (!quit)
	{
		
	}

	return 0;
}

void engine::exit()
{
	this->quit = true;
}

SDL_Renderer * engine::engine_renderer()
{
	return this->renderer;
}

SDL_Window * engine::engine_window()
{
	return this->window;
}

void engine::currentEvent(SDL_Event& e)
{
	SDL_PollEvent(&e);
}
