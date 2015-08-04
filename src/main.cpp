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
#include <Init.h>

using std::cout;
using std::endl;


const unsigned int width = 550;
const unsigned int height = 700;

State state = RUNNING;

int main(int argc, char **argv)
{

   Init init;
   Game game(init.getWindow(), init.getGamepad());

   while(state == RUNNING)
   {
      game.update();
      game.draw();
   }

   init.quit();
   return 0;
}
