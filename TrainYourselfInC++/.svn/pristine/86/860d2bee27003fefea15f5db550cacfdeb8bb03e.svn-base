#include "Assets.h"
#include "Logger.h"

extern Logger *logger;

MediaLoader Assets::media = MediaLoader();

Assets::Assets(void)
{
}

Assets::~Assets(void)
{
}

SDL_Texture* Assets::background = NULL;

SDL_Texture* Assets::player_front = NULL;
SDL_Texture* Assets::player_left = NULL;
SDL_Texture* Assets::player_right = NULL;
SDL_Texture* Assets::player_dead  = NULL;
SDL_Texture* Assets::player_shield = NULL;

SDL_Texture* Assets::bullet1 = NULL;
SDL_Texture* Assets::bullet2 = NULL;
SDL_Texture* Assets::bullet_explosion = NULL;

SDL_Texture* Assets::alien = NULL;
SDL_Texture* Assets::alien_explosion = NULL;
SDL_Texture* Assets::alien_bullet = NULL;

SDL_Texture* Assets::icebullet = NULL;

void Assets::Release()
{
	SDL_DestroyTexture(player_front);
	SDL_DestroyTexture(player_left);
	SDL_DestroyTexture(player_right);
	SDL_DestroyTexture(player_shield);

	SDL_DestroyTexture(bullet1);
	SDL_DestroyTexture(bullet2);

	SDL_DestroyTexture(alien);
	SDL_DestroyTexture(alien_explosion);
	SDL_DestroyTexture(alien_bullet);
	
	SDL_DestroyTexture(background);

	SDL_DestroyTexture(icebullet);
}

bool Assets::LoadAssets(void)
{	
	media.Set_SDLRenderer();
	background = media.LoadImage("resources/background/background.jpg");
	
	bullet1 = media.LoadImage("resources/bullets/bullet1.png");
	bullet2 = media.LoadImage("resources/bullets/bullet2.png");
	bullet_explosion = media.LoadImage("resources/bullets/bullet_explosion.png");

	alien = media.LoadImage("resources/alien/little_alien.png");
	alien_bullet = media.LoadImage("resources/alien/alien_bullet.png");
	alien_explosion = media.LoadImage("resources/alien/little_alien_explosion.png");

	player_front = media.LoadImage("resources/player/front_side.png");
	player_left = media.LoadImage("resources/player/left_side.png");
	player_right = media.LoadImage("resources/player/right_side.png");
	player_dead = media.LoadImage("resources/player/player_dead.png");
	player_shield = media.LoadImage("resources/player/player_shield.png");
	
	icebullet = media.LoadImage("resources/dropouts/dropout.png");

	if(background == NULL || bullet1 == NULL || bullet2 == NULL || 
		bullet_explosion == NULL || alien == NULL || alien_explosion == NULL ||
		player_front == NULL || player_left == NULL || player_right == NULL ||
		player_dead == NULL || player_shield == NULL || icebullet == NULL
		)
	{
		return false;
	}
	return true;
}