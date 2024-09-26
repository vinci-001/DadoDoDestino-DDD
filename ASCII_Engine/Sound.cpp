#include "Sound.hpp"
#include <sstream>
#include <fstream>

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

Sound::~Sound()
{
	if (isplaying())
		stop();
}

//nao funciona se soundName tiver espacos
bool Sound::play(unsigned times)
{
	return false;
}


bool Sound::playloop() 
{
	return play(0);
}


bool Sound::stop()
{
	return false;
}

bool Sound::pause()
{
	return false;
}

bool Sound::unpause()
{
	return false;
}


bool Sound::isplaying() const 
{
	return false;
}