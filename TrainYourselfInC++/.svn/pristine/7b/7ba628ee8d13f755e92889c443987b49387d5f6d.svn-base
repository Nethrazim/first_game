#pragma once
#include <vector>
#include "BulletGenerator.h"
#include "GameConfiguration.h"

class Player : public Sprite
{
public:
	Player(void);
	Player(int,int);
	~Player(void);
	
	//Player images
	SDL_Texture* front;
	SDL_Texture* left;	
	SDL_Texture* right;
	SDL_Texture* dead;
	SDL_Texture* shield;

	//Player actions
	void act(char);
	
	//Bullet 
	int bulletType;
	std::vector<Bullet*> bullets;
	Uint32 time_launchedBullet;
	Uint32 lasttime_launchedBullet;
	
	void RemoveBullet(Bullet *bullet);
	void SetMovementBounds(int, int);
	void SetDestroyedState();
	void SetDefaultState();
	void SetShield();

	enum BulletType
	{
		bullet1,
		bullet2
	};
	
	bool hasShield ;
	unsigned int score;

	static unsigned short step;
	static Player* instance;
	static Player* getInstance();
	bool isAlive();
private:
	int leftLimit;
	int rightLimit;
	Uint32 _stateTime;
	
	Uint32 _shieldTime;

	void moveLeft();
	void moveRight();
	void stopMoving();
	void Shoot();
	void ChangeBulletType();
	void DetectCollisionWithDropout();

};

