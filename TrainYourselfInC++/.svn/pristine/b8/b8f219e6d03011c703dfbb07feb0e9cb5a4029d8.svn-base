#include "HUD.h"
#include <string>
#include <sstream>

char* HUD::scoreText = "Score :";

HUD::HUD(int x, int y):Sprite(x,y)
{
	player = Player::getInstance();
	fontSys = new GameFont();	
	InitFontSystem();
}

HUD::~HUD(void)
{
}

SDL_Texture* HUD::RenderText(std::string text)
{
	std::string scoreString = ConvertIntToString(player->score);
	std::string txt = text + " " + scoreString;
	this->surface = fontSys->RenderText(txt);
	this->Set_SpriteDimensions();
	return surface;
}


void HUD::InitFontSystem()
{
	fontSys->Init();
	fontSys->OpenFont("resources/fonts/Roboto-Bold.ttf",24);
	this->RenderText("Score: ");
}

void HUD::ReleaseFontSystem()
{
	fontSys->Shutdown();
}

void HUD::Update()
{	if(surface)
	{
		SDL_DestroyTexture(surface);
	}
	surface = RenderText(scoreText);
}

std::string HUD::ConvertIntToString(int score)
{	
	std::string s;
	std::ostringstream out;
	out << score;
	s = out.str();
	return s;
}