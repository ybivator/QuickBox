#ifndef _INIT_H_
#define _INIT_H_

#include <SDL2/SDL.h>

extern const unsigned int width;
extern const unsigned int height;

class Init
{
public:
   Init();

   SDL_Window *getWindow();
   SDL_GameController *getGamepad();

   void quit();

private:
   void initSDL();
   void initGamepad();

   SDL_Window *window;
   SDL_GameController *gamepad;
};
#endif

