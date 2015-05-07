#ifdef _WIN32
#include "stdafx.h"
#include <Windows.h>
#endif

#include <Game.h>
#include <iostream>

using std::cout;
using std::endl;

Game::Game():window(NULL), gamePad(NULL)
{
}

bool Game::InitSDL()
{
   
   Uint32 initFlags = SDL_INIT_VIDEO |
                      SDL_INIT_GAMECONTROLLER |
                      SDL_INIT_HAPTIC;

   if(SDL_Init(initFlags))
   {
      cout << "SDL_init fail: " << SDL_GetError() << endl;
      return false;
   }
   else
   {
      cout << "Init Success" << endl;
      window = SDL_CreateWindow(
         "Basic Matrix Movement",
         SDL_WINDOWPOS_UNDEFINED,
         SDL_WINDOWPOS_UNDEFINED,
         windowWidth,
         windowHeight,
         SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
      
      if(!window)
      {
         cout << "Window init fail: " << SDL_GetError() << endl;
         return false;
      }
      SDL_GLContext glContext = SDL_GL_CreateContext(window);
      if(!glContext)
      {
         cout << "Could not create OpenGL context: " << endl;
	 return false;
      }
   }
   return true;
}
