#ifdef _WIN32
#include "stdafx.h"
#include <windows.h>
#endif

#include <SDL2/SDL.h>
#include <iostream>
#include <GL/gl.h>
#include <SDL2/SDL_haptic.h>
#include <drawFunctions.h>
#include <Game.h>

using std::cout;
using std::endl;


int main(int argc, char **argv)
{
   Game game;

   if(!game.InitSDL())
   {
      return 1;
   }

   if(!game.InitGamePad())
   {
      return 1;
   }

   SDL_Joystick* joys = SDL_GameControllerGetJoystick(game.getGamePad());
   SDL_Haptic* haptic = SDL_HapticOpenFromJoystick(joys);
   if(haptic == NULL)
   {
      cout << "haptic = NULL: " << SDL_GetError() << endl;
   }
   if(SDL_HapticRumbleSupported(haptic) == SDL_TRUE)
   {
      cout << "Rumble is supported" << endl;
   }
   else
   {
      cout << "Rumble is not supported" << endl;
   }

   SDL_HapticRumbleInit(haptic);


   

   bool state = true;
   int normStep = 5;
   int fastStep = 15;


   while(state)
   {
      SDL_Event event;
      SDL_PollEvent(&event);
      const Uint8* keyCode = SDL_GetKeyboardState(NULL);

      if(event.type == SDL_QUIT)
      {
         break;
      }

      if(keyCode[SDL_SCANCODE_LSHIFT] && keyCode[SDL_SCANCODE_RIGHT])
      {
         draw(game.getWindow(), width, height, 1, fastStep);
      }
      else if(keyCode[SDL_SCANCODE_LSHIFT] && keyCode[SDL_SCANCODE_LEFT])
      {
         draw(game.getWindow(), width, height, 2, fastStep);
      }
      if(keyCode[SDL_SCANCODE_RIGHT] || SDL_GameControllerGetButton(game.getGamePad(), SDL_CONTROLLER_BUTTON_DPAD_RIGHT))
      {
         draw(game.getWindow(), width, height, 1, normStep);
      }
      else if(keyCode[SDL_SCANCODE_LEFT] || SDL_GameControllerGetButton(game.getGamePad(), SDL_CONTROLLER_BUTTON_DPAD_LEFT))

      {
         draw(game.getWindow(), width, height, 2, normStep);
      }

      if(SDL_GameControllerGetAxis(game.getGamePad(), SDL_CONTROLLER_AXIS_TRIGGERRIGHT) > 0 &&
         SDL_GameControllerGetAxis(game.getGamePad(), SDL_CONTROLLER_AXIS_LEFTX) > 10000)
      {
	 draw(game.getWindow(), width, height, 1, fastStep);
      }
      else if(SDL_GameControllerGetAxis(game.getGamePad(), SDL_CONTROLLER_AXIS_TRIGGERRIGHT) > 0 &&
              SDL_GameControllerGetAxis(game.getGamePad(), SDL_CONTROLLER_AXIS_LEFTX) < -10000)
      {
         draw(game.getWindow(), width, height, 2, fastStep);
      }
      else if(SDL_GameControllerGetAxis(game.getGamePad(), SDL_CONTROLLER_AXIS_LEFTX) > 10000)
      {
	 draw(game.getWindow(), width, height, 1, normStep);
      }
      else if(SDL_GameControllerGetAxis(game.getGamePad(), SDL_CONTROLLER_AXIS_LEFTX) < -10000)
      {
	 draw(game.getWindow(), width, height, 2, normStep);
      }
      
      if(SDL_GameControllerGetButton(game.getGamePad(), SDL_CONTROLLER_BUTTON_BACK))
      {
         break;
      }

      draw(game.getWindow(), width, height, 0, normStep);
   }


   SDL_Quit();
   return 0;
}
