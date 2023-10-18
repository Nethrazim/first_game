#include "Sprite.h"


Sprite::Sprite(int x, int y)
{	
	setPosition(x, y);
}

Sprite::Sprite()
{
}

Sprite::~Sprite(void)
{
}

void Sprite::setPosition(int x, int y)
{
	dstRect.x = x;
	dstRect.y = y;
}

void Sprite::MoveX(int x)
{
	dstRect.x += x;
}

void Sprite::MoveY(int y)
{
	dstRect.y += y;
}

void Sprite::Set_SpriteDimensions()
{
	SDL_QueryTexture(this->surface, NULL, NULL, &(this->spriteWidth), &(this->spriteHeight));
	dstRect.w = spriteWidth;
	dstRect.h = spriteHeight;
}