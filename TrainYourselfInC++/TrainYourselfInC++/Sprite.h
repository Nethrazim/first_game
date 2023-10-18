#pragma once
#include "SDL.h"

class Sprite
{
public:
	Sprite();
	Sprite(int x, int y);
	
	~Sprite();
	
	int spriteWidth, spriteHeight;

	SDL_Rect dstRect;
	SDL_Rect srcRect;

	SDL_Texture* surface;

	virtual void setPosition(int x, int y);
	virtual void MoveX(int);
	virtual void MoveY(int);
	void Set_SpriteDimensions(void);
	enum SpriteState { STATE_ALIVE , STATE_DESTROYED};
	
	SpriteState state; 
};
