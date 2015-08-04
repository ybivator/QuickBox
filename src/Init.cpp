#ifdef _WIN32
#include "stdafx.h"
#include <Windows.h>
#endif

#include <Init.h>
#include <iostream>

using std::cout;
using std::endl;

Init::Init()
{
   initSDL();
   initGamepad();
}

void Init::initSDL()
{
   Uint32 initFlags = SDL_INIT_VIDEO |
                      SDL_INIT_GAMECONTROLLER |
                      SDL_INIT_HAPTIC;

   if(SDL_Init(initFlags))
   {
      cout << "SDL_init fail: " << SDL_GetError() << endl;
      exit(1);
   }
   else
   {
      cout << "Init Success" << endl;
      window = SDL_CreateWindow(
         "Basic Matrix Movement",
         SDL_WINDOWPOS_UNDEFINED,
         SDL_WINDOWPOS_UNDEFINED,
         width,
         height,
         SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
      
      if(!window)
      {
         cout << "Window init fail: " << SDL_GetError() << endl;
         exit(1);
      }
      SDL_GLContext glContext = SDL_GL_CreateContext(window);
      if(!glContext)
      {
         cout << "Could not create OpenGL context: " << endl;
	 exit(1);
      }
   }
}

void Init::initGamepad()
{
   if(SDL_NumJoysticks() > 0)
   {
      for(int i = 0; i < SDL_NumJoysticks(); ++i)
      {
	 if(SDL_IsGameController(i))
	 {
	    gamepad = SDL_GameControllerOpen(i);
	    cout << "Joystick opened!!!" << endl;
	    cout << "Joystick name: " << SDL_GameControllerName(gamepad) << endl;
	 }
	 else
	 {
	    cout << "Joystick error: " << SDL_GetError() << endl;
	    exit(1);
	 }
      }
   }
   else
   {
      gamepad = NULL;
   }
}

SDL_Window *Init::getWindow()
{
   return window;
}

SDL_GameController *Init::getGamepad()
{
   return gamepad;
}

void Init::quit()
{
   SDL_GameControllerClose(gamepad);
   SDL_DestroyWindow(window);
   SDL_Quit();
}
