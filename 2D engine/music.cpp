#include "music.h"

engine::sound::music::music(const char * file)
{
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	this->_music = Mix_LoadMUS(file);
}

engine::sound::music::~music()
{
	Mix_FreeMusic(_music);
	Mix_CloseAudio();
}

void engine::sound::music::play(int loops)
{
	Mix_PlayMusic(this->_music, loops);
}

void engine::sound::music::stop()
{
	Mix_PauseMusic();
}

void engine::sound::music::resume()
{
	Mix_ResumeMusic();
}

void engine::sound::music::halt()
{
	Mix_HaltMusic();
}

bool engine::sound::music::musicPaused()
{
	return Mix_PausedMusic();
}

engine::sound::music::operator Mix_Music*()
{
	return this->_music;
}