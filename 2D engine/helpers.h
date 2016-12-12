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