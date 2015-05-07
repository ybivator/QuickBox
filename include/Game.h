#ifndef _GAME_H
#define _GAME_H
#include <SDL2/SDL.h>

class Game
{
public:
   Game();

   bool InitSDL();
   bool InitGamePad();

   SDL_Window* getWindow();
   SDL_GameController* getGamePad();

private:
   Game(const Game&);
   void operator=(const Game&);

   SDL_Window* window;
   SDL_GameController* gamePad;

   const static int windowWidth = 550;
   const static int windowHeight = 700;
};


#endif

