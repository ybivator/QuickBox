#ifndef _GAME_H
#define _GAME_H
#include <SDL2/SDL.h>
#include <list>
#include <Line.h>
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

   float round(float num);
   int findMaxHeight(std::list<Line> &l);

   int windowWidth;
   int windowHeight;

   SDL_Window* window;
   SDL_GameController* gamePad;

   Box box;
};


#endif

