/*Copyright © Björn Marx
*
*for details look COPYRIGHT.txt
*
**/

#ifndef ANIMATION_CLASS
#define ANIMATION_CLASS

#include "main.hpp"

namespace engine_2D
{
	namespace helpers
	{
		namespace rendering
		{
			class __declspec(dllexport) animation
			{
			public:
				animation()
				{}
				animation(std::vector<SDL_Texture*> _frames);
				~animation()
				{}

				SDL_Texture*  nextFrame();

				void appendTextureToFrames(SDL_Texture* tex);

			private:
				int animationFrame = 0;
				std::vector<SDL_Texture*> frames;
			};
		}
	}
}
#endif // !ANIMATION_CLASS