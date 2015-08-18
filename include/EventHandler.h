#ifndef _EVENTHANDLER_H_
#define _EVENTHANDLER_H_
#include <SDL2/SDL.h>
#include <Box.h>

enum State
{
   PLAY,
   PAUSE,
   NEW_GAME,
   GAME_OVER,
   QUIT
};

extern State state;

class EventHandler
{
public:
   EventHandler(SDL_GameController* gc);
   
   void update(Box& b);


private:
   SDL_GameController* gamePad;

   static const int normStep = 5;
   static const int fastStep = 15;
};
#endif

