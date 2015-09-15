#ifdef _WIN32
#include "stdafx.h"
#include <Windows.h>
#endif

#include <EventHandler.h>
#include <iostream>

using std::cout;
using std::endl;

EventHandler::EventHandler(SDL_GameController* gc): gamePad(gc)
{
}

void EventHandler::update(Box& b)
{
   SDL_Event event;
   const Uint8* keyCode = SDL_GetKeyboardState(NULL);
   
   while(SDL_PollEvent(&event) != 0)
   {
      if(event.type == SDL_QUIT)
      {
         state = QUIT;
      }

      if(keyCode[SDL_SCANCODE_ESCAPE])
      {
	 state = PAUSE;
      }
   }

   if(!gamePad)
   {
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
   else
   {
      if((keyCode[SDL_SCANCODE_LSHIFT] && keyCode[SDL_SCANCODE_RIGHT]) ||
         (SDL_GameControllerGetAxis(gamePad, SDL_CONTROLLER_AXIS_TRIGGERRIGHT) > 0 &&
	  SDL_GameControllerGetAxis(gamePad, SDL_CONTROLLER_AXIS_LEFTX) > 10000))
      {
         b.increase(fastStep);
      }
      else if((keyCode[SDL_SCANCODE_LSHIFT] && keyCode[SDL_SCANCODE_LEFT]) ||
             (SDL_GameControllerGetAxis(gamePad, SDL_CONTROLLER_AXIS_TRIGGERRIGHT) > 0
	     && SDL_GameControllerGetAxis(gamePad, SDL_CONTROLLER_AXIS_LEFTX) < -10000))
      {
         b.decrease(fastStep);
      }
      else if(keyCode[SDL_SCANCODE_RIGHT] ||
              SDL_GameControllerGetButton(gamePad, SDL_CONTROLLER_BUTTON_DPAD_RIGHT) ||
	      SDL_GameControllerGetAxis(gamePad, SDL_CONTROLLER_AXIS_LEFTX) > 10000)
      {
         b.increase(normStep);
      }
      else if(keyCode[SDL_SCANCODE_LEFT] ||
              SDL_GameControllerGetButton(gamePad, SDL_CONTROLLER_BUTTON_DPAD_LEFT) ||
	      SDL_GameControllerGetAxis(gamePad, SDL_CONTROLLER_AXIS_LEFTX) < -10000)
      {
         b.decrease(normStep);
      }
      else if(SDL_GameControllerGetButton(gamePad, SDL_CONTROLLER_BUTTON_BACK))
      {
         state = QUIT;
      }
   }
}
