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

State state = PLAY;

int main(int argc, char **argv)
{

   Init init;
   Game game(init.getWindow(), init.getGamepad());

   while(state != QUIT)
   {
      if(state == PLAY)
      {
         game.update();
         game.draw();
      }
      else if(state == PAUSE)
      {
         while(true)
	 {
	    const Uint8 *key = SDL_GetKeyboardState(NULL);
	    bool esc = false;
	    SDL_Event event;
	    while(SDL_PollEvent(&event) != 0)
	    {
               if(event.type == SDL_QUIT)
               {
                  state = QUIT;
		  esc = true;
		  break;
               }

	       if(key[SDL_SCANCODE_ESCAPE])
	       {
	          state = PLAY;
		  esc = true;
		  break;
	       }
	    }
	    if(esc)
	    {
	       break;
	    }
	 }
      }
      else if(state == GAME_OVER)
      {
         while(true)
	 {
	    const Uint8 *key = SDL_GetKeyboardState(NULL);
	    bool esc = false;
	    SDL_Event event;
	    while(SDL_PollEvent(&event) != 0)
	    {
               if(event.type == SDL_QUIT)
               {
                  state = QUIT;
		  esc = true;
		  break;
               }

	       if(key[SDL_SCANCODE_R])
	       {
		  game.restart();
	          state = PLAY;
		  esc = true;
		  break;
	       }
	    }
	    if(esc)
	    {
	       break;
	    }
	 }
      }
   }

   init.quit();
   return 0;
}
