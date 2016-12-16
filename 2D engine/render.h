/*Copyright © Björn Marx
*
*for details look COPYRIGHT.txt
*
**/

#ifndef RENDER
#define RENDER

#include "main.hpp"
#include "helpers.h"

namespace engine
{
	namespace rendering
	{
		class __declspec(dllexport) render
		{
		public:
			render() {}
			render(SDL_Window* win, int w, int h, Uint32 renderer_flags = SDL_RENDERER_ACCELERATED);
			~render();

			//renders the picture
			void generateFrame();

			//adds a speciifik line to the renderer
			void addLine(helpers::rendering::format::line l, helpers::creating::color c);

			void addDot(int diameter, helpers::point p, helpers::creating::color c);
			
			//put rect with color c filled or not filled
			void addRectangle(helpers::rendering::format::rectangle rect, helpers::creating::color c, bool fill);
			void addRectangle(helpers::rendering::format::rectangle rect, helpers::creating::color c, double angle, bool fill);

			//put whole texture to the whole screen
			void addTexture(SDL_Texture* tex);
			//put whole texture @ dstRect
			void addTexture(SDL_Texture* tex, helpers::rendering::format::rectangle dstRect);
			//put texture rotated by angle @ dstRect
			void addTexture(SDL_Texture* tex, helpers::rendering::format::rectangle dstRect, double angle);
			//put srcRect of texture rotated by angle @ dstRect
			void addTexture(SDL_Texture* tex, helpers::rendering::format::rectangle srcRect, helpers::rendering::format::rectangle dstRect, double angle);
			//put texture rotated by angle rotated around p_center @ dstRect
			void addTexture(SDL_Texture* tex, helpers::rendering::format::rectangle dstRect, helpers::point p_center, double angle);
			//put srcRect of texture rotated by angle rotated around p_center @ dstRect
			void addTexture(SDL_Texture* tex, helpers::rendering::format::rectangle srcRect, helpers::rendering::format::rectangle dstRect, helpers::point p_center, double angle);
			//put srcRect of texture @ dstrect
			void addTexture(SDL_Texture* tex, helpers::rendering::format::rectangle srcRect, helpers::rendering::format::rectangle dstRect);

			//sets the backgroundcolor
			void backgroundcolor(helpers::creating::color c);

			//clears the renderer, will generate a black picture
			void clear();

			SDL_Renderer* renderer();
			operator SDL_Renderer*();

		private:

			SDL_Renderer* _renderer = nullptr;
			SDL_Texture* scene = nullptr;
			SDL_Texture* bufTex = nullptr;
		};
	}
}
#endif // !RENDER