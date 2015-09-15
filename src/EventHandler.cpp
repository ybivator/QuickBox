#ifdef _WIN32
#include "stdafx.h"
#include <Windows.h>
#endif

#include <EventHandler.h>
#include <iostream>

using std::cout;
using std::endl;

EventHandler::EventHandler()
{
}

void EventHandler::updateState(SDL_GameController *gamePad)
{
   SDL_Event event;
   const Uint8 *keyCode = SDL_GetKeyboardState(NULL);
   
   while(SDL_PollEvent(&event) != 0)
   {
      if(event.type == SDL_QUIT)
      {
         state = QUIT;
      }

      if(gamePad)
      {
        if(SDL_GameControllerGetButton(gamePad, SDL_CONTROLLER_BUTTON_BACK))
        {
           state = QUIT;
        }
//	if(SDL_GameControllerGetButton(gamePad, SDL_CONTROLLER_BUTTON_START))
//	{
//	   if(state != PAUSE)
//	   {
//	      state = PAUSE;
//	   }
//	   else
//	   {
//	      state = PLAY;
//	   }
//	}
      }

      if(keyCode[SDL_SCANCODE_ESCAPE])
      {
	 if(state != PAUSE)
	 {
	    state = PAUSE;
	 }
	 else
	 {
	    state = PLAY;
	 }
      }

      if(keyCode[SDL_SCANCODE_R])
      {
         state = RESTART;
      }

   }
}

void EventHandler::updateKeyboard(Box &b)
{
   const Uint8 *keyCode = SDL_GetKeyboardState(NULL);
   if(keyCode[SDL_SCANCODE_LSHIFT] && keyCode[SDL_SCANCODE_RIGHT])
   {
      b.increase(fastStep);
   }
   else if(keyCode[SDL_SCANCODE_LSHIFT] && keyCode[SDL_SCANCODE_LEFT])
   {
      b.decrease(fastStep);
   }
   else if(keyCode[SDL_SCANCODE_RIGHT])
   {
      b.increase(normStep);
   }
   else if(keyCode[SDL_SCANCODE_LEFT])
   {
      b.decrease(normStep);
   }
}

void EventHandler::updateGamepad(SDL_GameController *gamePad, Box &b)
{
   if(gamePad)
   {
      if((SDL_GameControllerGetAxis(gamePad, SDL_CONTROLLER_AXIS_TRIGGERRIGHT) > 0 &&
          SDL_GameControllerGetAxis(gamePad, SDL_CONTROLLER_AXIS_LEFTX) > 10000))
      {
         b.increase(fastStep);
      }
      else if((SDL_GameControllerGetAxis(gamePad, SDL_CONTROLLER_AXIS_TRIGGERRIGHT) > 0
             && SDL_GameControllerGetAxis(gamePad, SDL_CONTROLLER_AXIS_LEFTX) < -10000))
      {
         b.decrease(fastStep);
      }
      else if(SDL_GameControllerGetButton(gamePad, SDL_CONTROLLER_BUTTON_DPAD_RIGHT) ||
              SDL_GameControllerGetAxis(gamePad, SDL_CONTROLLER_AXIS_LEFTX) > 10000)
      {
         b.increase(normStep);
      }
      else if(SDL_GameControllerGetButton(gamePad, SDL_CONTROLLER_BUTTON_DPAD_LEFT) ||
              SDL_GameControllerGetAxis(gamePad, SDL_CONTROLLER_AXIS_LEFTX) < -10000)
      {
         b.decrease(normStep);
      }
   }
}
