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
   RESTART,
   QUIT
};

extern State state;

class EventHandler
{
public:
   EventHandler();
   
   void updateState(SDL_GameController *gamePad);
   void updateKeyboard(Box &b);
   void updateGamepad(SDL_GameController *gamePad, Box &b);


private:
   static const int normStep = 5;
   static const int fastStep = 15;
};
#endif

