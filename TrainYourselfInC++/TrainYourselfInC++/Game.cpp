#include <ctime>
#include "Game.h"
#include "Logger.h"
#include "LaunchPoint.h"
#include "Assets.h"
#include "GameConfiguration.h"
#include "SDL_Image.h"
#include "Dropout.h"
#include "SoundPlayer.h"

extern Logger* logger;

Game::Game(WindowManager* manager)
{
	logger->info("OBJ-GAME()");
	this->windowManager = manager;
	_FPS = 50;
	_sleepTime = 1000/50;
	srand((unsigned int)time(NULL));
	_renderer = windowManager->renderer;
}

Game::~Game(void)
{
}

void Game::GameLoop()
{
	gameIsRunning = 1;
	Uint32 sleep = 0;
	while(gameIsRunning)
	{	
		_gameTime = SDL_GetTicks();
		sleep = 0;
		_GetUserInput();
		GameUpdate();
		GameDraw();
		_endFrame_timeElapsed = SDL_GetTicks();

		Uint32 frameDuration = _endFrame_timeElapsed - _gameTime;
		
		//logger->info(frameDuration);
		sleep = _sleepTime - frameDuration;
		SDL_Delay(20);	
	}
}

void Game::_GetUserInput()
{	
	SDL_Event event;
	while(SDL_PollEvent(&event) && gameIsRunning==1)
	{
		_HandleKeys(&event);
	}
}

void Game::GameUpdate()
{	
	//Update Bullets
	for(unsigned int i=0; i < _player->bullets.size(); i++)
	{
		_player->bullets.at(i)->Update();
	}
	if(_player->isAlive())
	{
		int x = -666;
		if(_gameTime % 113 == 0)
		{
			x = rand()%10;
		}
		//Update Aliens
		for(int i =0; i < gameconfig::AliensCount; i++)
		{
			Alien *alien = sprites->GetAlienAt(i);
			if(i == x)
			{
				alien->Shoot();
			}
			alien->Update();
		}	
	}
	//drop->Update();
	for(unsigned int i=0; i < sprites->dropouts.size(); i++)
	{
		sprites->dropouts[i]->Update();
	}
	//Update HUD
	sprites->hud->Update();
}


void Game::GameDraw()
{		
		SDL_RenderClear(_renderer);
		_DrawBackground();
		_DrawAliens(); 
		_DrawDropouts();
		_DrawPlayer();
		_DrawBullets();
		_DrawInfo();

		SDL_SetRenderTarget(_renderer, NULL );
		SDL_RenderCopy(_renderer, _backgroundSurface, NULL, NULL);
		SDL_RenderPresent(_renderer);
}

void Game::_HandleKeys(SDL_Event* event)
{	
	if(event->type == SDL_KEYDOWN)
	{	
		
		SDL_Keycode code = event->key.keysym.sym;

		if(code == SDLK_LEFT || code == SDLK_a)
		{
			_player->act('l');
		}else if(code == SDLK_RIGHT || code == SDLK_d)
		{
			_player->act('r');
		}	
		
		switch(code)
		{
		case SDLK_SPACE:
			_player->act('s');
			break;
		case SDLK_LSHIFT:
			_player->act('c');
			break;
		case SDLK_LCTRL:
			_player->act('h');
			break;
		case SDLK_ESCAPE:
			this->gameIsRunning = 0;
			break;
		}
	}
}

void Game::_CreateSprites()
{	
	bool success = true;
	_player = new Player(704,585);
	_player->SetMovementBounds(0, gameconfig::SCREEN_WIDTH);
	
	sprites = SpritesHolder::GetInstance();
	sprites->hud = new HUD(1125,10);

	for(int i=0; i<gameconfig::AliensCount; i++)
	{
		int ax = rand()%600;
		int ay = rand()%400;
		sprites->AddAlien(new Alien(ax, ay));
	}
}

void Game::GameInit()
{	
	_ReadGameConfiguration();
	_LoadResources();
	_CreateSprites();
}

void Game::GameQuit()
{	
	SoundPlayer::CloseAudio();
	delete _player;
	sprites->DestroySprites();
	Assets::Release();
	SDL_DestroyTexture(_backgroundSurface);
	windowManager->DestroyWindow();
}
bool Game::_LoadResources()
{	
	if(!(IMG_Init(IMG_INIT_JPG)) || !(IMG_Init(IMG_INIT_PNG)))
	{
		logger->error("Could not init SDL_Image module");
		return false;
	}

	_backgroundSurface = SDL_CreateTexture(_renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET, gameconfig::SCREEN_WIDTH, gameconfig::SCREEN_HEIGHT);
	
	if(Assets::LoadAssets() != true)
	{
		logger->error("Asset could not be loaded");
		return false;
		
	}else
	{
		_background = Assets::background;
	}
	
	if(SoundPlayer::OpenAudio() != true)
	{
		return false;
	}

	SoundPlayer::LoadSounds();

	return true;
}

void Game::_DrawBullets()
{
	for(unsigned int i=0; i<_player->bullets.size(); i++)
	{	
		Sprite *bullet = _player->bullets.at(i);
		SDL_RenderCopy(_renderer, bullet->surface, NULL, &(bullet->dstRect));
	}
}

void Game::_DrawDropouts()
{	
	for(unsigned int i=0; i < sprites->dropouts.size(); i++)
	{	
		Sprite *dropout = sprites->dropouts.at(i);
		SDL_RenderCopy(_renderer, dropout->surface, NULL, &(dropout->dstRect));
	}
}
void Game::_DrawAliens()
{	
	for(int i=0; i < gameconfig::AliensCount; i++)
	{
		Sprite *alien = sprites->aliens[i];
		SDL_RenderCopy(_renderer, alien->surface, NULL, &(alien->dstRect));
	}
}

void Game::_DrawPlayer()
{
	SDL_RenderCopy(_renderer, _player->surface, NULL, &(_player->dstRect));
}

void Game::_DrawInfo()
{	
	SDL_RenderCopy(_renderer, sprites->hud->surface, NULL, &(sprites->hud->dstRect));
}

void Game::_ReadGameConfiguration()
{
	Alien::nr_of_aliens = gameconfig::AliensCount;
}

void Game::_DrawBackground()
{
	SDL_SetRenderTarget(_renderer, _backgroundSurface);
	SDL_RenderCopy(_renderer, _background, NULL, NULL);
}