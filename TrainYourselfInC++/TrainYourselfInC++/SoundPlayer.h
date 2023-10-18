#pragma once
#include "SDL_mixer.h"

class SoundPlayer
{
public:
	~SoundPlayer(void);

	static int audio_rate;
	static Uint16 audio_format;
	static int audio_channels;
	static int audio_buffers;
	static bool OpenAudio();
	static void CloseAudio();
	static void LoadSounds();
	static void PlayShoot();
private:
	SoundPlayer(void);
	static Mix_Chunk *shoot;
};
