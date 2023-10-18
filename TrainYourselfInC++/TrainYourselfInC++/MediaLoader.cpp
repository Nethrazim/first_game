#include "MediaLoader.h"
#include "SDL_image.h"
#include "WindowManager.h"
#include "Logger.h"

extern Logger* logger;

MediaLoader* MediaLoader::instance = NULL;

MediaLoader::MediaLoader()
{	
	logger->info("OBJ-MediaLoader");
	MediaLoader::instance = this;
}

MediaLoader::~MediaLoader(void)
{
}

void MediaLoader::Set_SDLRenderer(void)
{
	this->_renderer = WindowManager::GetRenderer();
}

SDL_Texture* MediaLoader::LoadImage(char* path)
{	
	Logger::getInstance()->info(path);

	SDL_Surface* loadedSurface = IMG_Load(path);

	if(loadedSurface == NULL)
	{
		return false;
	}
	SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, loadedSurface);
	SDL_FreeSurface(loadedSurface);

	return texture;
}

MediaLoader* MediaLoader::getInstance()
{
	return MediaLoader::instance;
}