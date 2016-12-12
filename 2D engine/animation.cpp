/*Copyright © Björn Marx
*
*for details look COPYRIGHT.txt
*
**/

#include "animation.h"

engine::helpers::rendering::animation::animation(std::vector<SDL_Texture*> _frames)
{
	frames = _frames;
}

SDL_Texture* engine::helpers::rendering::animation::nextFrame()
{
	if (animationFrame > frames.size())
		animationFrame = 0;

	return frames.at((animationFrame++ - 1));
}

void engine::helpers::rendering::animation::appendTextureToFrames(SDL_Texture* tex)
{
	frames.push_back(tex);
}