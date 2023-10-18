#pragma once
#include "Sprite.h"
#include "SDL.h"

class Bullet : public Sprite
{
public:
	Bullet(int type, int x, int y, int xOffset, int yOffset);
	Bullet(void);
	~Bullet(void);
	
	int xOffset;
	int yOffset;
	
	SDL_Texture *explosion;
	Uint32 explode_state_time;

	virtual void Update();
	
	void setPosition(int,int);
	void SetSurface(int);
	void SetOffset(int xOffset, int yOffset);
	void AddBulletToRendering(void);

	static int nr_of_bullets;
	static void SetBulletType(int);
private:
	SpriteState state;

	void _Move();
	void _DetectCollisionWithAliens();
	void _DetectCollisionWithPlayer();
	void _Explode();
	bool _isPlayerBullet;
	void _CalculateOffset();
	
};
