/*Copyright © Björn Marx
*
*for details look COPYRIGHT.txt
*
**/

#include "animation.h"

engine_2D::helpers::rendering::animation::animation(std::vector<SDL_Texture*> _frames)
{
	frames = _frames;
}

SDL_Texture* engine_2D::helpers::rendering::animation::nextFrame()
{
	if (animationFrame > frames.size())
		animationFrame = 0;

	return frames.at((animationFrame++ - 1));
}

void engine_2D::helpers::rendering::animation::appendTextureToFrames(SDL_Texture* tex)
{
	frames.push_back(tex);
}