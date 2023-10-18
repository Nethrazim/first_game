#include "SpritesHolder.h"
#include "Logger.h"

extern Logger* logger;

SpritesHolder::SpritesHolder(void)
{
	SpritesHolder::instance = this;

	aliens.reserve(gameconfig::AliensCount);
	dropouts.reserve(1);

	I.reserve(gameconfig::AliensCount);
	II.reserve(gameconfig::AliensCount);
	III.reserve(gameconfig::AliensCount);
	IV.reserve(gameconfig::AliensCount);
}

SpritesHolder::~SpritesHolder(void)
{
}

SpritesHolder * SpritesHolder::instance = 0;

SpritesHolder* SpritesHolder::GetInstance()
{
	if(!instance)
	{
		new SpritesHolder();
	}

	return instance;
}

void SpritesHolder::AddAlien(Alien *alien)
{
	aliens.push_back(alien);
}


Alien* SpritesHolder::GetAlienAt(int x)
{
	return aliens.at(x);
}

void SpritesHolder::AddDropout(Dropout * dropout)
{
	this->dropouts.push_back(dropout);
}

void SpritesHolder::RemoveDropout(Dropout* dropout)
{
	for(unsigned int i=0; i < dropouts.size(); i++)
	{
		if(dropout == dropouts.at(i))
		{
			dropouts.erase(dropouts.begin() + i);
		}
	}
}


void SpritesHolder::DestroySprites()
{
	for(size_t i=0; i < aliens.size(); i++)
	{
		delete aliens[i];
	}

	for(size_t i=0; i < dropouts.size(); i++)
	{
		delete dropouts[i];
	}

	hud->ReleaseFontSystem();
}