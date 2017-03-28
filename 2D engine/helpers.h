/*Copyright © Björn Marx
*
*for details look COPYRIGHT.txt
*
**/

#ifndef HELPERS
#define HELPERS

#include "main.hpp"

namespace engine
{
	namespace helpers
	{
		enum keyboard
		{
			W = SDLK_w,
			A = SDLK_a,
			S = SDLK_s,
			D = SDLK_d,
			ESCAPE = SDLK_ESCAPE,
			ARROW_UP = SDLK_UP,
			ARROW_LEFT = SDLK_LEFT,
			ARROW_DOWN = SDLK_DOWN,
			ARROW_RIGHT = SDLK_RIGHT

			
		};

		enum other
		{
			QUIT = SDL_QUIT
		};

		enum mouse
		{
			BUTTON_LEFT = SDL_BUTTON_LEFT,
			BUTTON_RIGHT = SDL_BUTTON_RIGHT,
			BUTTON_MITTDLE = SDL_BUTTON_MIDDLE
		};

		struct point : SDL_Point
		{
		public:
			point(int x, int y);
			point(){}
		};

		namespace creating
		{
			struct __declspec(dllexport) color
			{
			public:
				color(int _r, int _g, int _b);

				int r, g, b, a = 255;
			};
		}
		namespace rendering
		{
			namespace format
			{
				struct __declspec(dllexport) line
				{
					line() {}
					line(int _x1, int _y1, int _x2, int _y2);

					int x1, y1, x2, y2;

				};

				struct __declspec(dllexport) rectangle : SDL_Rect
				{
				public:
					rectangle() {}
					rectangle(int x, int y, int width, int height);
				};
			}
		}

		namespace creating
		{
			struct __declspec(dllexport) texture
			{
			public:
				texture(const char* file, SDL_Renderer* r);

				operator SDL_Texture* ();

			private:
				SDL_Texture* tex;
			};
		}
	}
}
#endif // !HELPERS