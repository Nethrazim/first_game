#include "Dropout.h"
#include "Assets.h"
#include "SpritesHolder.h"
#include "Logger.h"

extern Logger *logger;

#define noop ((void)0)

Dropout::Dropout(int type, int x, int y) : Sprite(x,y)
{	
	dropped_time = 0;
	SetSurfaceType(type);
}

Dropout::~Dropout(void)
{
}

void Dropout::SetSurfaceType(int type)
{
	switch(type)
	{
	case Dropout_TYPE1:
		surface = Assets::icebullet;
		break;
	case Dropout_TYPE2:
		break;
	case Dropout_TYPE3:
		break;
	}
	Set_SpriteDimensions();
}

void Dropout::Update(void)
{
	if(dstRect.y < 590)
	{
		dstRect.y += 20; 
		logger->info("Dropout Y = ", dstRect.y);
		return;
	}
	else
	{	
		if(_dropped == true)
			goto ticks;
		dstRect.y = 590;
		_dropped = true;
		dropped_time = SDL_GetTicks();
	}

	ticks:
	now = SDL_GetTicks();
	if(now - dropped_time > 2000)
	{
		SpritesHolder::GetInstance()->RemoveDropout(this);
	}
}

void Dropout::_RemoveDropout()
{
	
}
