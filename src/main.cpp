#ifdef _WIN32
#include "stdafx.h"
#include <windows.h>
#endif

#include <SDL2/SDL.h>
#include <iostream>
#include <GL/gl.h>
#include <SDL2/SDL_haptic.h>
#include <drawFunctions.h>

using std::cout;
using std::endl;


int main(int argc, char **argv)
{
   SDL_Window* window = NULL;

   if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER))	
   {
      cout << "SDL_init fail: " << SDL_GetError() << endl;
      return 1;
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
         return 1;
      }
      SDL_GLContext glContext = SDL_GL_CreateContext(window);
      if(!glContext)
      {
         cout << "Could not create OpenGL context: " << endl;
      }
   }
   
   SDL_GameController* joy = NULL;

   if(SDL_NumJoysticks() > 0)
   {
      for(int i = 0; i < SDL_NumJoysticks(); ++i)
      {
	 if(SDL_IsGameController(i))
	 {
	    joy = SDL_GameControllerOpen(i);
	    cout << "Joystick opened!!!" << endl;
	    cout << "Joystick name: " << SDL_GameControllerName(joy) << endl;
	 }
	 else
	 {
	    cout << "Joystick error: " << SDL_GetError() << endl;
	 }
      }
   }
   SDL_Joystick* joys = SDL_GameControllerGetJoystick(joy);
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

   

   bool state = true;
   int normStep = 5;
   int fastStep = 15;


   while(state)
   {
      SDL_Event event;
      SDL_PollEvent(&event);
      const Uint8* keyCode = SDL_GetKeyboardState(NULL);

      if(keyCode[SDL_SCANCODE_LSHIFT] && keyCode[SDL_SCANCODE_RIGHT])
      {
         draw(window, width, height, 1, fastStep);
      }
      else if(keyCode[SDL_SCANCODE_LSHIFT] && keyCode[SDL_SCANCODE_LEFT])
      {
         draw(window, width, height, 2, fastStep);
      }
      if(keyCode[SDL_SCANCODE_RIGHT] || SDL_GameControllerGetButton(joy, SDL_CONTROLLER_BUTTON_DPAD_RIGHT))
      {
         draw(window, width, height, 1, normStep);
      }
      else if(keyCode[SDL_SCANCODE_LEFT] || SDL_GameControllerGetButton(joy, SDL_CONTROLLER_BUTTON_DPAD_LEFT))

      {
         draw(window, width, height, 2, normStep);
      }

      if(SDL_GameControllerGetAxis(joy, SDL_CONTROLLER_AXIS_TRIGGERRIGHT) > 0 &&
         SDL_GameControllerGetAxis(joy, SDL_CONTROLLER_AXIS_LEFTX) > 10000)
      {
	 draw(window, width, height, 1, fastStep);
      }
      else if(SDL_GameControllerGetAxis(joy, SDL_CONTROLLER_AXIS_TRIGGERRIGHT) > 0 &&
              SDL_GameControllerGetAxis(joy, SDL_CONTROLLER_AXIS_LEFTX) < -10000)
      {
         draw(window, width, height, 2, fastStep);
      }
      else if(SDL_GameControllerGetAxis(joy, SDL_CONTROLLER_AXIS_LEFTX) > 10000)
      {
	 draw(window, width, height, 1, normStep);
      }
      else if(SDL_GameControllerGetAxis(joy, SDL_CONTROLLER_AXIS_LEFTX) < -10000)
      {
	 draw(window, width, height, 2, normStep);
      }
      
      if(event.type == SDL_QUIT)
      {
         break;
      }
      if(SDL_GameControllerGetButton(joy, SDL_CONTROLLER_BUTTON_BACK))
      {
         break;
      }

      draw(window, width, height, 0, normStep);
   }


   SDL_Quit();
   return 0;
}
