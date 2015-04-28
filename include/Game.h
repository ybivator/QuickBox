#ifndef _GAME_H
#define _GAME_H
#include <SDL2/SDL.h>

class Game
{
public:
   Game();

   void InitSDL();
//   void InitGamePad(){}
//
//   const SDL_Window& getWindow(){}
//   const SDL_GameController& getGamePad(){}

private:
   Game(const Game&);
   void operator=(const Game&);

   SDL_Window* window;
   SDL_GameController* gamePad;
};


#endif

