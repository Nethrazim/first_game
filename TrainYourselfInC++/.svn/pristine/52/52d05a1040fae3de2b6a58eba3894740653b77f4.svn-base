#pragma once
#include "SDL.h"


class WindowManager
{
public:
	WindowManager();
	~WindowManager();
	
	//Members
	SDL_Window* window;
	SDL_Surface* _screenSurface;
	static SDL_Renderer *renderer;

	//Methods
	bool SetupWindow();
	SDL_Window* GetWindow();
	void DestroyWindow();

	static SDL_Renderer* GetRenderer(void);
};
