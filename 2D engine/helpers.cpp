/*Copyright © Björn Marx
*
*for details look COPYRIGHT.txt
*
**/

#include "helpers.h"

engine_2D::helpers::creating::color::color(int _r, int _g, int _b)
{
	r = _r;
	g = _g;
	b = _b;
}

engine_2D::helpers::rendering::format::rectangle::rectangle(int x, int y, int width, int height)
{
	this->x = x;
	this->y = y;
	this->w = width;
	this->h = height;
}

engine_2D::helpers::rendering::format::line::line(int _x1, int _y1, int _x2, int _y2)
{
	x1 = _x1;
	x2 = _x2;
	y1 = _y1;
	y2 = _y2;
}

engine_2D::helpers::creating::texture::texture(const char * file, SDL_Renderer * r)
{
	this->tex = IMG_LoadTexture(r, file);
}

engine_2D::helpers::creating::texture::operator SDL_Texture*()
{
	return this->tex;
}