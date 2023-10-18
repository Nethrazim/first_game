#pragma once
#include <vector>
#include "Bullet.h"
#include "Alien.h"
#include "HUD.h"
#include "GameConfiguration.h"
#include "Dropout.h"

class SpritesHolder
{
public:
	static SpritesHolder *instance;
	static SpritesHolder* GetInstance();
	~SpritesHolder(void);
	
	std::vector<Alien*> aliens;
	std::vector<Dropout*> dropouts;
	HUD* hud;	
	
	void AddAlien(Alien*);
	Alien* GetAlienAt(int);
	void AddDropout(Dropout*);
	void RemoveDropout(Dropout*);

	void AddToCollisionSpace(int);
	void RemoveFromCollisionSpace(Alien*);
	
	void DestroySprites();

private:
		SpritesHolder(void);
		
		std::vector<Alien*> I;
		std::vector<Alien*> II;
		std::vector<Alien*> III;
		std::vector<Alien*> IV;
};
