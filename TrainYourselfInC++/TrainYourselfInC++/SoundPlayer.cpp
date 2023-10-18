#include "SoundPlayer.h"
#include "Logger.h"

extern Logger *logger;

int SoundPlayer::audio_rate = 22050;
Uint16 SoundPlayer::audio_format = AUDIO_S16;
int SoundPlayer::audio_channels = 2;
int SoundPlayer::audio_buffers = 4096;
Mix_Chunk* SoundPlayer::shoot = NULL;

SoundPlayer::SoundPlayer(void)
{
}

SoundPlayer::~SoundPlayer(void)
{
}

bool SoundPlayer::OpenAudio()
{	
	Mix_QuerySpec(&audio_rate, &audio_format, &audio_channels);
	if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) != -1)
	{
		return true;
	}	
	logger->info(Mix_GetError());
	return false;
}

void SoundPlayer::LoadSounds()
{
	shoot = Mix_LoadWAV( "resources/sounds/laser.wav" );
}

void SoundPlayer::PlayShoot()
{
	Mix_PlayChannel(-1, shoot, 0);
}

void SoundPlayer::CloseAudio()
{
	Mix_FreeChunk(shoot);
	Mix_CloseAudio();
}
