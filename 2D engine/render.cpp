/*Copyright © Björn Marx
*
*for details look COPYRIGHT.txt
*
**/

#include "render.h"

engine::rendering::render::render(SDL_Window* win, int w, int h, Uint32 renderer_flags)
{
	this->renderer = SDL_CreateRenderer(win, -1, renderer_flags);
	if (!this->renderer)
		throw std::exception(SDL_GetError());
	this->scene = SDL_CreateTexture(this->renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_TARGET, w, h);
	if (!this->scene)
		throw std::exception(SDL_GetError());
}

engine::rendering::render::~render()
{
}

void engine::rendering::render::generateFrame()
{
	SDL_RenderCopy(this->renderer, this->scene, NULL, NULL);
	SDL_RenderPresent(renderer);
}

void engine::rendering::render::addLine(helpers::rendering::format::line& l, helpers::creating::color & c)
{
	if(SDL_SetRenderTarget(this->renderer, this->scene) < 0)
		throw std::exception(SDL_GetError());

	if(SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a) < 0)
		throw std::exception(SDL_GetError());

	if (SDL_RenderDrawLine(this->renderer, l.x1, l.y1, l.x2, l.y2) < 0)
		throw std::exception(SDL_GetError());

	if (SDL_SetRenderTarget(this->renderer, NULL) < 0)
		throw std::exception(SDL_GetError());
}

void engine::rendering::render::addLines(helpers::rendering::format::line l[], int count, helpers::creating::color & c)
{
	for (size_t i = 0; i < count; i++)
	{
		this->addLine(l[i], c);
	}
}

void engine::rendering::render::addRectangle(helpers::rendering::format::rectangle& rect, helpers::creating::color& c, bool fill)
{
	if (SDL_SetRenderTarget(this->renderer, this->scene) < 0)
		throw std::exception(SDL_GetError());

	if (SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a) < 0)
		throw std::exception(SDL_GetError());

	if (fill)
		if (SDL_RenderFillRect(this->renderer, &rect) < 0)
			throw std::exception(SDL_GetError());
		else
			if (SDL_RenderDrawRect(this->renderer, &rect) < 0)
				throw std::exception(SDL_GetError());

	if (SDL_SetRenderTarget(this->renderer, NULL) < 0)
		throw std::exception(SDL_GetError());
}

void engine::rendering::render::addRectangles(helpers::rendering::format::rectangle rect[], int count, helpers::creating::color& c, bool fill)
{
	for (size_t i = 0; i < count; i++)
	{
		this->addRectangle(rect[i], c, fill);
	}
}

void engine::rendering::render::addTexture(SDL_Texture* tex)
{
	if (SDL_SetRenderTarget(this->renderer, this->scene) < 0)
		throw std::exception(SDL_GetError());

	if (SDL_RenderCopy(this->renderer, tex, NULL, NULL) == -1)
		throw std::exception(SDL_GetError());

	if (SDL_SetRenderTarget(this->renderer, NULL) < 0)
		throw std::exception(SDL_GetError());
}

void engine::rendering::render::addTexture(SDL_Texture* tex, helpers::rendering::format::rectangle& dstRect)
{
	if (SDL_SetRenderTarget(this->renderer, this->scene) < 0)
		throw std::exception(SDL_GetError());

	if (SDL_RenderCopy(this->renderer, tex, NULL, &dstRect) == -1)
		throw std::exception(SDL_GetError());

	if (SDL_SetRenderTarget(this->renderer, NULL) < 0)
		throw std::exception(SDL_GetError());
}

void engine::rendering::render::addTexture(SDL_Texture* tex, helpers::rendering::format::rectangle& srcRect, helpers::rendering::format::rectangle& dstRect)
{
	if (SDL_SetRenderTarget(this->renderer, this->scene) < 0)
		throw std::exception(SDL_GetError());

	if (SDL_RenderCopy(this->renderer, tex, &srcRect, &dstRect) < 0)
		throw std::exception(SDL_GetError());

	if (SDL_SetRenderTarget(this->renderer, NULL) < 0)
		throw std::exception(SDL_GetError());
}

void engine::rendering::render::backgroundcolor(helpers::creating::color& c)
{
	if (SDL_SetRenderTarget(this->renderer, this->scene) < 0)
		throw std::exception(SDL_GetError());

	if (SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a) < 0)
		throw std::exception(SDL_GetError());

	if (SDL_RenderFillRect(renderer, NULL) < 0)
		throw std::exception(SDL_GetError());

	if (SDL_SetRenderTarget(this->renderer, NULL) < 0)
		throw std::exception(SDL_GetError());
}

void engine::rendering::render::render::clear()
{
	if (SDL_RenderClear(renderer) < 0)
		throw std::exception(SDL_GetError());
}

engine::rendering::render::operator SDL_Renderer*()
{
	return this->renderer;
}