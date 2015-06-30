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

   while(true)
   {
      if(game.update())
      {
	 game.draw();
      }
      else
      {
         break;
      }
   }

   game.Quit();
   return 0;
}
