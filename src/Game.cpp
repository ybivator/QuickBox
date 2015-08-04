#ifdef _WIN32
#include "stdafx.h"
#include <Windows.h>
#endif

#include <Game.h>
#include <iostream>
#include <GL/gl.h>

using std::cout;
using std::endl;


Game::Game(SDL_Window *win, SDL_GameController *gpad): window(win), gamepad(gpad),
                                                       box(0, 0, 50, 50),
                                                       fpsCounter(),
						       eventHandler(gamepad)
{
}

void Game::update()
{
   glViewport(0, 0, width, height);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

   glOrtho(0, width, 0, height, 1, -1);

   if(!eventHandler.update(box))
   {
      state = EXIT;
   }
#ifdef DEBUG
   fpsCounter.countFps();
#endif   
}
void Game::draw()
{
   glClearColor(1.0, 1.0, 1.0, 1.0);
   glClear(GL_COLOR_BUFFER_BIT);

   box.draw();
#ifdef DEBUG
   fpsCounter.drawFps(height);
#endif
   SDL_GL_SwapWindow(window);
}

Box& Game::getBox()
{
   return box;
}
