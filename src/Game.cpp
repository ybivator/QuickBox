#ifdef _WIN32
#include "stdafx.h"
#include <Windows.h>
#endif

#include <Game.h>
#include <iostream>
#include <GL/gl.h>
#include <Line.h>
#include <list>

using std::cout;
using std::endl;

Game::Game(int w, int h):windowWidth(w), windowHeight(h), 
                         window(NULL), gamePad(NULL),
			 box(0, 0, 50, 50)
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

bool Game::InitGamePad()
{
   if(SDL_NumJoysticks() > 0)
   {
      for(int i = 0; i < SDL_NumJoysticks(); ++i)
      {
	 if(SDL_IsGameController(i))
	 {
	    gamePad = SDL_GameControllerOpen(i);
	    cout << "Joystick opened!!!" << endl;
	    cout << "Joystick name: " << SDL_GameControllerName(gamePad) << endl;
	 }
	 else
	 {
	    cout << "Joystick error: " << SDL_GetError() << endl;
	    return false;
	 }
      }
   }
   return true;
}

void Game::draw()
{
   glClearColor(1.0, 1.0, 1.0, 1.0);
   glClear(GL_COLOR_BUFFER_BIT);

   glViewport(0, 0, windowWidth, windowHeight);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

   glOrtho(0, windowWidth, 0, windowHeight, 1, -1);


   static std::list<Line> lineList;
   static int count = 0;
   if(count == 0)
   {
      lineList.push_back(Line(20, 90));
      count++;
   }
   else
   {
      for(std::list<Line>::iterator it = lineList.begin(); it != lineList.end(); ++it)
      {
         (*it).decrease(3);
	 (*it).draw();
      }
      if(count > 20)
      {
         count = 0;
      }
      else
      {
         count++;
      }
   }

//   line.decrease(3);
//   line.draw();

   box.draw();
   SDL_GL_SwapWindow(window);
}

void Game::Quit()
{
   SDL_GameControllerClose(gamePad);
   SDL_Quit();
}

SDL_Window* Game::getWindow()
{
   return window;
}

SDL_GameController* Game::getGamePad()
{
   return gamePad;
}

Box& Game::getBox()
{
   return box;
}
