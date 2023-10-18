#include "GameFont.h"
#include "SDL_ttf.h"
#include "Logger.h"
#include "WindowManager.h"

extern Logger *logger;

GameFont::GameFont(void)
{
	color.r = 255;
	color.g = 255;
	color.b = 255;
	color.a = 0;

	renderer = WindowManager::GetRenderer();
}

GameFont::~GameFont(void)
{
}

bool GameFont::Init()
{
	bool success = true;

	if(TTF_Init() == -1)
	{
		success = false;
	}

	return success;
}

void GameFont::Shutdown()
{	
	FreeFont();
	TTF_Quit();
}

void GameFont::OpenFont(char* file, int ptsize)
{
	_font = TTF_OpenFont(file, ptsize);
	if(!_font)
	{
		logger->info("GameFont::OpenFont() FAILED");
		exit(-1);
	}
}

void GameFont::FreeFont()
{
	if(_font)
	{
		TTF_CloseFont(_font);
	}
}

SDL_Texture* GameFont::RenderText(std::string text)
{	
	const char *cstr = text.c_str();
	SDL_Surface *surf = TTF_RenderText_Solid(_font, cstr, color);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer,surf);
	SDL_FreeSurface(surf);

	return texture;
}