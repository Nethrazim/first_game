#include "Player.h"
#include "Assets.h"
#include "Logger.h"
#include "LaunchPoint.h"
#include "SpritesHolder.h"
#include "Dropout.h"
#include "SoundPlayer.h"

extern Logger* logger;

Player* Player::instance = 0;

Player::Player(int x,int y) : Sprite(x, y)
{
	instance = this;
	//Set Player surfaces
	front = Assets::player_front;
	left = Assets::player_left;
	right = Assets::player_right;
	dead = Assets::player_dead;
	shield = Assets::player_shield;

	surface = front;
	state = STATE_ALIVE;

	bullets.reserve(40);
	bulletType = bullet1;
	score = 0;
	this->Set_SpriteDimensions();
	hasShield = false;
	logger->info("PLAYER-Created()");
}

Player::~Player(void)
{
}

void Player::moveLeft()
{
	surface = left;
	if(this->dstRect.x >= leftLimit)
	{
		MoveX(-16);
		DetectCollisionWithDropout();
	}
}

void Player::moveRight()
{
	surface = right;
	if(this->dstRect.x <= rightLimit - 40)
	{
		MoveX(16);
		DetectCollisionWithDropout();
	}
}

void Player::stopMoving()
{
	this->surface = front;
}

void Player::Shoot()
{
	lasttime_launchedBullet = time_launchedBullet;
	time_launchedBullet = SDL_GetTicks();

	if(time_launchedBullet - lasttime_launchedBullet > 200)
	{
		int lx = this->dstRect.x + (this->spriteWidth / 2);
		int ly = this->dstRect.y - 25;
		
		BulletGenerator::GetInstance()->CreateBullet(bulletType, lx, ly);
		SoundPlayer::PlayShoot();
	}
}

void Player::SetDefaultState()
{
	this->state = STATE_ALIVE;
	this->surface = front;
	this->setPosition(this->dstRect.x, 585);
	Set_SpriteDimensions();
}
void Player::SetDestroyedState()
{
	this->state = STATE_DESTROYED;
	this->surface = this->dead;
	this->_stateTime = SDL_GetTicks();
	this->setPosition(this->dstRect.x, 620);
	Set_SpriteDimensions();
}

Player* Player::getInstance()
{
	return instance;
}

void Player::ChangeBulletType()
{
	switch(this->bulletType)
	{
		case bullet1:
			bulletType = bullet2;
			break;
		case bullet2: 
			bulletType = bullet1;
			break;
	}
}

void Player::SetMovementBounds(int left, int right)
{
	this->leftLimit = left;
	this->rightLimit = right;
}

void Player::RemoveBullet(Bullet *bullet)
{
	for(unsigned int i=0; i < bullets.size(); i++)
	{
		if(bullet == bullets.at(i))
		{
			bullets.erase(bullets.begin() + i);
		}
	}
}

void Player::act(char c)
{
	if(state == STATE_ALIVE && hasShield == true)
	{
		switch(c)
		{
		case 'h':
			SetShield();
			break;
		}
	}else if (state == STATE_ALIVE && !hasShield)
	{
		switch(c)
		{
		case 'l':
			moveLeft();
			break;
		case 'r':
			moveRight();
			break;
		case 's':
			Shoot();
			break;
		case 'c':
			ChangeBulletType();
			break;
		case 'h':
			SetShield();
			break;
		}
	}
}

bool Player::isAlive()
{
	if( this->state == STATE_ALIVE )
	{
		return true;
	}
	return false;
}

void Player::SetShield()
{
	if(hasShield == false)
	{
		this->surface = shield;
		this->hasShield = true;
		_shieldTime = SDL_GetTicks();
		Set_SpriteDimensions();
		setPosition(dstRect.x, (570));
	}
	else
	{
		this->surface = front;
		this->hasShield = false;
		Set_SpriteDimensions();
		setPosition(dstRect.x, 585);
	}
}
void Player::DetectCollisionWithDropout()
{
	std::vector<Dropout*> *dropouts = &(SpritesHolder::GetInstance()->dropouts);
}