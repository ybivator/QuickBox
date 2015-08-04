#ifndef _GAME_H
#define _GAME_H
#include <SDL2/SDL.h>
#include <Box.h>
#include <EventHandler.h>
#include <FpsCounter.h>

enum State
{
   RUNNING,
   EXIT
};

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

   SDL_Window *window;
   SDL_GameController *gamepad;
   Box box;
   FpsCounter fpsCounter;
   EventHandler eventHandler;
};

#endif

