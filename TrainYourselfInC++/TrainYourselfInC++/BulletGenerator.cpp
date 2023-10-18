#include "BulletGenerator.h"
#include "Logger.h"
#include "GameConfiguration.h"

extern Logger* logger;

BulletGenerator* BulletGenerator::instance = 0;

BulletGenerator::BulletGenerator(void)
{
	instance = this;
	contor1 = 0;
	contor2 = 0;
}

BulletGenerator::~BulletGenerator(void)
{
}

void BulletGenerator::CreateBullet(int type, int x, int y)
{	
	switch(type)
	{
	case 0:
		{
			Bullet *bullet = &(standardBullets[contor1]);

			bullet->setPosition(x,  y);
			bullet->SetSurface(0);
			bullet->SetOffset(0, -20);

			bullet->AddBulletToRendering();	
			contor1++;
			if(contor1 == gameconfig::BulletCount)
			{
				contor1 =0;
			}
		}
		break;
	case 1:
		{
			bullets2[contor2].Use(x, y);
			contor2 ++;
			if(contor2 == gameconfig::BulletCount)
				contor2 = 0;
		}
		break;
	}
}

BulletGenerator * BulletGenerator::GetInstance()
{
	if(!instance)
	{
		new BulletGenerator();
	}
	return instance;
}