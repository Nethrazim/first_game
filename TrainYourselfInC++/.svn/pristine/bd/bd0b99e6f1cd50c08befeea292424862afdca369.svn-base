#pragma once
#include "SDL.h"
#include "MediaLoader.h"

class Assets
{
public:
	~Assets(void);
	
	static SDL_Texture* player_front;
	static SDL_Texture* player_left;
	static SDL_Texture* player_right;
	static SDL_Texture* player_dead;
	static SDL_Texture* player_shield;

	static SDL_Texture* bullet1;
	static SDL_Texture* bullet2;
	static SDL_Texture* bullet_explosion;

	static SDL_Texture* alien;
	static SDL_Texture* alien_bullet;
	static SDL_Texture* alien_explosion;

	static SDL_Texture* background;
	static SDL_Texture* icebullet;
	
	static void Release();
	static bool LoadAssets(void);
	
	static MediaLoader media;
private:
	Assets(void);
};
