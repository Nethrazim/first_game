#include <stdio.h>
#include "Logger.h"
#include "WindowManager.h"
#include "Game.h"
#include <iostream>
#include "SDL.h"
#include <iostream>

#define main SDL_main

Logger* logger = Logger::getInstance();


int main(int argc, char* argv[])
{
	WindowManager window = WindowManager();
	bool result = window.SetupWindow();
	if(!result)
	{
		logger->error("LAUNCH FAILED");
		return -1;
	}

	Game game = Game(&window);	

	game.GameInit();
	
	game.GameLoop();	

	game.GameQuit();

	return 0;
}
