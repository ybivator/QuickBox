#ifdef _WIN32
#include "stdafx.h"
#include <windows.h>
#endif

#include <SDL2/SDL.h>
#include <iostream>
#include <GL/gl.h>
#include <SDL2/SDL_haptic.h>
#include <Game.h>
#include <Box.h>
#include <EventHandler.h>

using std::cout;
using std::endl;

const int width = 550;
const int height = 700;

int main(int argc, char **argv)
{
   Game game(width, height);

   if(!game.InitSDL())
   {
      return 1;
   }

   if(!game.InitGamePad())
   {
      return 1;
   }

   EventHandler eventHandler(game.getGamePad());

   Uint32 lastTime = SDL_GetTicks();
   Uint32 frames = 0;

   while(true)
   {
      Uint32 currentTime = SDL_GetTicks();
      Uint32 delta = currentTime - lastTime;
      if(eventHandler.update(game.getBox()))
      {
         game.draw();
      }
      else
      {
         break;
      }
      if(delta > 200)
      {
         cout << frames * 1000.0 / delta << endl;
	 lastTime = currentTime;
	 frames = 0;
      }
      frames++;
      
   }

   game.Quit();
   return 0;
}
