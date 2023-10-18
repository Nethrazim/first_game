#pragma once
#include "Sprite.h"
#include "SDL.h"
#include <string>

class Alien : public Sprite
{
public:
	Alien(int,int);
	~Alien(void);

	bool direction;

	void Update();
	void Shoot();
	void SetDestroyedState();
	void SetAliveState();

	static int nr_of_aliens;
private:
	SDL_Texture* _explosion;
	SDL_Texture* _front;
	int _step;
	void _Move();
	Uint32 _stateTime;
};
