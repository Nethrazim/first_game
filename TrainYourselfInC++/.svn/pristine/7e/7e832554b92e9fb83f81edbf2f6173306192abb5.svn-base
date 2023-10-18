#pragma once
#include <string>
#include "SDL.h"
#include "SDL_ttf.h"

class GameFont
{
public:
	GameFont(void);
	~GameFont(void);
	
	bool Init();
	void OpenFont(char*, int);
	void Shutdown();
	SDL_Texture* RenderText(std::string);

private:
	TTF_Font *_font;
	SDL_Color color;
	void FreeFont();
	SDL_Renderer *renderer;
};
