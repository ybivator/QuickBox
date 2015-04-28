#ifndef _GAME_H
#define _GAME_H
#include <SDL2/SDL.h>

class Game
{
public:
   static Game& game();

//   void Init_SDL(){}
//   void Init_GamePad(){}
//
//   const SDL_Window& getWindow(){}
//   const SDL_GameController& getGamePad(){}

private:
   Game();
   Game(const Game&);
   void operator=(const Game&);

   SDL_Window* window;
   SDL_GameController* gamePad;
};


#endif

