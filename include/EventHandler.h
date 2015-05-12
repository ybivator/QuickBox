#ifndef _EVENTHANDLER_H_
#define _EVENTHANDLER_H_
#include <SDL2/SDL.h>
#include <Box.h>
class EventHandler
{
public:
   EventHandler(SDL_GameController* gc);
   
   bool update(Box& b);


private:
   SDL_GameController* gamePad;

   static const int normStep = 5;
   static const int fastStep = 15;
};
#endif

