#ifndef MUSIC
#define MUSIC

#include "main.hpp"

namespace engine
{
	namespace sound
	{
		class music
		{
		public:
			music(const char* file);
			~music();

			void play(int loops = -1);
			void stop();
			void resume();
			void halt();

			bool musicPaused();

			operator Mix_Music* ();

		private:
			Mix_Music* _music;
		};
	}
}
#endif // !MUSIC