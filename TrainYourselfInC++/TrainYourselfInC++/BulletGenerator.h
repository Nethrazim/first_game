#pragma once
#include <vector>
#include "Bullet.h"

class BulletGenerator
{
public:
	~BulletGenerator(void);

	Bullet standardBullets[40];

	struct spreadbullet
	{
		Bullet bullet1;
		//Bullet bullet2;
		Bullet bullet3;

		void Use(int lx, int ly)
		{
			bullet1.setPosition(lx, ly);
			//bullet2.setPosition(lx, ly);
			bullet3.setPosition(lx, ly);

			bullet1.SetOffset(-2, -20);
			//bullet2.SetOffset(0, -20);
			bullet3.SetOffset(2, -20);
			
			bullet1.AddBulletToRendering();
			//bullet2.AddBulletToRendering();
			bullet3.AddBulletToRendering();
		}
	};
	
	//Ready To Use Bullets Type 2
	spreadbullet bullets2[5];
	unsigned int contor2;
	unsigned int contor1;

	void CreateBullet(int type, int x , int y);
	
	static BulletGenerator* GetInstance();

private:
	BulletGenerator(void);
	static BulletGenerator *instance;
};
