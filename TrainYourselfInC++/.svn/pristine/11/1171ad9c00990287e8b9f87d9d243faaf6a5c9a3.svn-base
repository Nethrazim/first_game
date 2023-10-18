#pragma once
#include "SDL.h"
#include "Sprite.h"
#include "Player.h"
#include "GameFont.h"

class HUD : public Sprite
{
public:
	HUD(int, int);
	~HUD(void);
	
	static char* scoreText;

	GameFont* fontSys;
	
	SDL_Texture* RenderText(std::string); 
	void InitFontSystem();
	void ReleaseFontSystem();
	Player *player;
	void Update();
private:
	std::string ConvertIntToString(int);
};
