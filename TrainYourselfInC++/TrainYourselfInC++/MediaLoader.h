#pragma once
#include "SDL.h"

class MediaLoader
{
public:
	MediaLoader();
	~MediaLoader(void);

	SDL_Texture* LoadImage(char*);
	SDL_Texture* _screenSurface;

	static  MediaLoader* getInstance();
	static MediaLoader* instance;
	void Set_SDLRenderer();
private: 
	SDL_Renderer *_renderer;
};
