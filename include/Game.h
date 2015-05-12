#ifndef _GAME_H
#define _GAME_H
#include <SDL2/SDL.h>
#include <Box.h>

class Game
{
public:
   Game(int w, int h);

   bool InitSDL();
   bool InitGamePad();

   void Quit();

   void draw();

   SDL_Window* getWindow();
   SDL_GameController* getGamePad();
   Box& getBox();

private:
   Game(const Game&);
   void operator=(const Game&);

   int windowWidth;
   int windowHeight;

   SDL_Window* window;
   SDL_GameController* gamePad;

   Box box;
};


#endif

