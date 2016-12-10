/*Copyright © Björn Marx
*
*for details look COPYRIGHT.txt
*
**/

#include "render.h"

engine_2D::rendering::render::render(SDL_Window& win, Uint32 renderer_flags)
{
	this->renderer = SDL_CreateRenderer(&win, -1, renderer_flags);
}

engine_2D::rendering::render::~render()
{

}

void engine_2D::rendering::render::generateFrame()
{
	SDL_RenderPresent(renderer);
}

void engine_2D::rendering::render::addLine(helpers::rendering::format::line & l, helpers::creating::color & c)
{
	SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);

	SDL_RenderDrawLine(this->renderer, l.x1, l.y1, l.x2, l.y2);
}

void engine_2D::rendering::render::addLines(helpers::rendering::format::line l[], int count, helpers::creating::color & c)
{
	SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);

	for (size_t i = 0; i < count; i++)
	{
		this->addLine(l[i], c);
	}
}

void engine_2D::rendering::render::addRectangle(helpers::rendering::format::rectangle& rect, helpers::creating::color& c, bool fill)
{
	SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);

	if (fill)
		SDL_RenderFillRect(this->renderer, &rect);
	else
		SDL_RenderDrawRect(this->renderer, &rect);
}

void engine_2D::rendering::render::addRectangles(helpers::rendering::format::rectangle rect[], int count, helpers::creating::color & c, bool fill)
{
	SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);

	for (size_t i = 0; i < count; i++)
	{
		this->addRectangle(rect[i], c, fill);
	}
}

void engine_2D::rendering::render::addTexture(SDL_Texture* tex)
{
	if (SDL_RenderCopy(this->renderer, tex, NULL, NULL) == -1)
		throw std::exception(SDL_GetError());
}

void engine_2D::rendering::render::addTexture(SDL_Texture* tex, helpers::rendering::format::rectangle& dstRect)
{
	if (SDL_RenderCopy(this->renderer, tex, NULL, &dstRect) == -1)
		throw std::exception(SDL_GetError());
}

void engine_2D::rendering::render::addTexture(SDL_Texture* tex, helpers::rendering::format::rectangle& srcRect, helpers::rendering::format::rectangle& dstRect)
{
	if (SDL_RenderCopy(this->renderer, tex, &srcRect, &dstRect) == -1)
		throw std::exception(SDL_GetError());
}

void engine_2D::rendering::render::backgroundcolor(helpers::creating::color& c)
{
	SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);

	SDL_RenderFillRect(renderer, NULL);
}

void engine_2D::rendering::render::render::clear()
{
	SDL_RenderClear(renderer);
}

engine_2D::rendering::render::operator SDL_Renderer*()
{
	return this->renderer;
}