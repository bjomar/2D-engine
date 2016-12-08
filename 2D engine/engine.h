#ifndef ENGINE
#define ENGINE

#include "main.hpp"

class engine
{
public:
	engine();
	~engine();

	int run();
	void exit();

	SDL_Renderer* engine_renderer();
	SDL_Window* engine_window();
	void currentEvent(SDL_Event&);

private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	SDL_Event event;

	struct 
	{
		int x = 100, y = 100;
	}rect;

	bool quit =  false;
};

#endif