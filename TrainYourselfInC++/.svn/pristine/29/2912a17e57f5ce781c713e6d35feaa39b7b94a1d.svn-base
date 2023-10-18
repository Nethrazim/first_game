#include "Logger.h"
#include "Player.h"
#include "Alien.h"
#include "Assets.h"
#include "SpritesHolder.h"
#include <cmath>

extern Logger* logger;
#define noop ((void)0)
int Bullet::nr_of_bullets = 0;

Bullet::Bullet(int type, int x, int y, int xOffset, int yOffset): Sprite(x, y)
{
	this->xOffset = xOffset;
	this->yOffset = yOffset;
	
	SetSurface(type);
	explosion = Assets::bullet_explosion;
	Set_SpriteDimensions();
	AddBulletToRendering();
	state = STATE_ALIVE;
}

Bullet::Bullet() : Sprite(0,0)
{	
	surface = Assets::bullet2;
	explosion = Assets::bullet_explosion;
	_isPlayerBullet = true;
	Set_SpriteDimensions();
	state = STATE_ALIVE;
}

Bullet::~Bullet(void)
{
	logger->info("Bullet destroyed");
}

void Bullet::Update()
{	
	if(state == STATE_ALIVE)
		_Move();
	else
	{
		Uint32 now = SDL_GetTicks();
		if(now - explode_state_time > 100)
		{
			Player::getInstance()->RemoveBullet(this);
		}
	}
}

void Bullet::_Move()
{	
	Player *player = Player::getInstance();
	this->dstRect.x += xOffset;
	this->dstRect.y += yOffset;
	if(_isPlayerBullet == true)
	{
		_DetectCollisionWithAliens();
	}
	else
	{
		_DetectCollisionWithPlayer();
	}

	if(dstRect.y < 0 || dstRect.y > 1000 || dstRect.x <= 0 || dstRect.x >= 1300)
	{
		player->RemoveBullet(this);
	}
}

void Bullet::_DetectCollisionWithPlayer()
{	
	int left = dstRect.x;
	int top = dstRect.y;
	int right = left + this->spriteWidth;
	int bottom = top + this->spriteHeight;
	
	Player *player = Player::getInstance();
	SDL_Rect *rect = &(player->dstRect);
	int pleft = rect->x + 10;
	int ptop = rect->y + 10;
	int pright = pleft + player->spriteWidth - 10;
	int pbottom = ptop + player->spriteHeight - 10;
	
	if( !( (pbottom < top) || (ptop > bottom) || (pleft > right) || (pright < left) ) )
	{	
		if(!player->hasShield)
		{
			player->SetDestroyedState();
			player->RemoveBullet(this);
		}else
		{
			_Explode();
		}
	}
}

void Bullet::_DetectCollisionWithAliens()
{
	int left = dstRect.x;
	int top = dstRect.y;
	int right = left + this->spriteWidth;
	int bottom = top + this->spriteHeight;
	
	for(int i=0; i<Alien::nr_of_aliens; i++)
	{
		Alien *alien = SpritesHolder::GetInstance()->aliens[i];
		if(alien->state == STATE_ALIVE) 
		{
			SDL_Rect *rect = &(alien->dstRect);

			int aleft = rect->x;
			int atop = rect->y;
			int aright = aleft + alien->spriteWidth;
			int abottom = atop + alien->spriteHeight;

			if( !( (abottom < top) || (atop > bottom) || (aleft > right) || (aright < left) ) )
			{	
 				alien->SetDestroyedState();
				Player* player = Player::getInstance();
				player->score += 10;
				player->RemoveBullet(this);
				break;
			}
		}
	}//end for
}

void Bullet::setPosition(int x, int y)
{
	dstRect.x = x;
 	dstRect.y = y;
}

void Bullet::SetOffset(int xOffset, int yOffset)
{
	this->xOffset = xOffset;
	this->yOffset = yOffset;
}

void Bullet::AddBulletToRendering()
{
	Player::getInstance()->bullets.push_back(this);
}

void Bullet::SetSurface(int type)
{
	switch(type)
	{
	case 0:
	{
		surface = Assets::bullet1;
		_isPlayerBullet = true;
	}
	break;
	case 1:
	{
		surface = Assets::bullet2;
		_isPlayerBullet = true;
	}
	break;
	case 2:
	{
		surface = Assets::alien_bullet;
		_isPlayerBullet = false;
		_CalculateOffset();
	}
	break;
	}
}

void Bullet::_CalculateOffset()
{
	int x2 = Player::getInstance()->dstRect.x;
	int y2 = Player::getInstance()->dstRect.y;
	int x1 = this->dstRect.x;
	int y1 = this->dstRect.y;

	int xm = x2 - x1; 
	xm == 0 ? xm = 5 : noop;
	float c = abs((y2 - y1)/(xm));
	int m =0;
	c >= 0 && c < 1 ? m = 1 : m = c;

	this->yOffset = 4;	
	if(x2 > x1)	
	{	
		this->xOffset = this->yOffset / m;
	}
	else if (x2 < x1)
	{
		this->xOffset = - (this->yOffset / m);
	}else
	{
		this->xOffset = 0;
	}
}

void Bullet::_Explode()
{
	this->state = STATE_DESTROYED;
	this->surface = explosion;
	this->explode_state_time = SDL_GetTicks();
}