#include "Alien.h"
#include "Logger.h"
#include "Assets.h"
#include "SpritesHolder.h"
#include "Bullet.h"

extern Logger* logger;

int Alien::nr_of_aliens = 0;

Alien::Alien(int x, int y) : Sprite(x , y)
{
	_explosion = Assets::alien_explosion;
	_front = Assets::alien;

	_step = 8;
	direction = 0;
	
	this->state = STATE_ALIVE;
	this->surface = this->_front;
	this->Set_SpriteDimensions();
}

Alien::~Alien(void)
{
}

void Alien::Update()
{	
	if(state == STATE_ALIVE)
	{
		_Move();	
	}
	else
	{
		Uint32 time = SDL_GetTicks();
		Uint32 diff = time - this->_stateTime;
		if(diff > 1000)
		{
			int x = rand()%500;
			this->setPosition(x, dstRect.y);
			SetAliveState();
		}
	}
}

void Alien::_Move()
{
	if(direction == 0)
	{	
		if((dstRect.x + this->spriteWidth) < 1260)
		{	
			MoveX(_step);
		}
		else
			direction = 1;
	}
	else
	{
		if(dstRect.x > 20)
		{	
			MoveX(-_step);
		}
		else
			direction = 0;
	}
}

void Alien::Shoot()
{
	if(this->state==STATE_ALIVE)
	{
		int ly = this->dstRect.y + (this->spriteHeight);
		int lx = this->dstRect.x + (this->spriteWidth / 2);

		new Bullet(2, lx, ly, 0, -16);
	}
}

void Alien::SetDestroyedState()
{
	this->state = STATE_DESTROYED;
	this->surface = this->_explosion;
	this->_stateTime = SDL_GetTicks();
	Set_SpriteDimensions();
	
	if((rand()%500) % 3 == 0 )
	{	
		//SpritesHolder::GetInstance()->AddDropout(new Dropout(0, dstRect.x, dstRect.y));
	}
}

void Alien::SetAliveState()
{
	direction = 0;
	this->surface = this->_front;
	state = STATE_ALIVE; 
	Set_SpriteDimensions();
}