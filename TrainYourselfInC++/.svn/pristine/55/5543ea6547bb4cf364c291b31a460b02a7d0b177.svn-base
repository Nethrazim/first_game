#pragma once
#include "WindowManager.h"
#include "Alien.h"
#include "Player.h"
#include "Bullet.h"
#include "SDL.h"
#include "SpritesHolder.h"

class Game
{
public:
	Game(WindowManager*);
	~Game(void);
	
	//primitive
	int gameIsRunning;
	
	//Members
	WindowManager* windowManager;
	SpritesHolder* sprites;
	Player* _player;
	Dropout *drop;
	SDL_Texture* _backgroundSurface;
	SDL_Texture* _background;
	
	
	//Methods
	void GameInit();
	void GameLoop();
	void GameQuit();
	void GameUpdate();
	void GameDraw();
	
private:
	SDL_Renderer *_renderer;
	Uint32 _endFrame_timeElapsed;
	
	short _FPS;

	Uint32 _sleepTime;
	Uint32 _gameTime;

	void _HandleKeys(SDL_Event*);
	bool _LoadResources();
	void _CreateSprites();
	void _GetUserInput();
	void _BulletsUpdate();
	void _DrawBullets();
	void _DrawDropouts();
	void _DrawAliens();
	void _DrawPlayer();
	void _DrawInfo();
	void _DrawBackground();
	void _ReadGameConfiguration();
};
