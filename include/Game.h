#ifndef _GAME_H
#define _GAME_H
#include <SDL2/SDL.h>
#include <Box.h>
#include <Line.h>
#include <list>
#include <EventHandler.h>
#include <FpsCounter.h>


extern const unsigned int width;
extern const unsigned int height;
extern State state;

class Game
{
public:
   Game(SDL_Window *win, SDL_GameController *gpad);

   bool InitSDL();
   bool InitGamePad();

   void update();
   void draw();

   Box& getBox();

private:
   Game(const Game&);
   void operator=(const Game&);

   std::list<Line> lineList;
   SDL_Window *window;
   SDL_GameController *gamepad;
   Box box;
   FpsCounter fpsCounter;
   EventHandler eventHandler;
};

#endif

