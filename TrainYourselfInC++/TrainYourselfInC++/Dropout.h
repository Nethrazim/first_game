#pragma once
#include "Sprite.h" 

class Dropout : public Sprite
{
public:
	Dropout(int, int x = 10, int y = 10);
	~Dropout(void);

	enum Dropout_type
	{
		Dropout_TYPE1,
		Dropout_TYPE2,
		Dropout_TYPE3
	};

	void SetSurfaceType(int);
	void Update(void);
private:
	bool _dropped;
	Uint32 now;
	Uint32 dropped_time;
	void _RemoveDropout();
};
