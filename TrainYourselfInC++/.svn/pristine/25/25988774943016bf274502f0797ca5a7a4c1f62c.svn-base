#include "WindowManager.h"
#include "GameConfiguration.h"
#include "Logger.h"

extern Logger* logger;

SDL_Renderer* WindowManager::renderer = NULL;

WindowManager::WindowManager()
{
	logger->info("WINDOWMANAGER-Created");
}

WindowManager::~WindowManager(void)
{
}

bool WindowManager::SetupWindow()
{
	logger->info("SetupWindow:INIT");
	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
	{
		logger->info("SDL could not initialize" );
		//todo add reason
	}

	window = SDL_CreateWindow(
		"Game Window", 
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		gameconfig::SCREEN_WIDTH, 
		gameconfig::SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN
	);
	
	if(window == NULL)
	{	
		logger->info("Window Creation: FAILED");
		return false;
	}
	logger->info("Succesfully Created: SDL-WINDOW");	
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	_screenSurface = SDL_GetWindowSurface(window);
	return true;
}

void WindowManager::DestroyWindow()
{	
	logger->info("DestroyWindow()");
	
	SDL_FreeSurface(_screenSurface);
	_screenSurface = NULL;


	SDL_DestroyWindow(window);
	window = NULL;

	SDL_Quit();
}

SDL_Renderer* WindowManager::GetRenderer()
{
	return WindowManager::renderer;
}
SDL_Window* WindowManager::GetWindow()
{
	return window;
}