#ifdef _WIN32
#include "stdafx.h"
#include <Windows.h>
#endif

#include <Game.h>
#include <iostream>
#include <ctime>
#include <GL/gl.h>

using std::cout;
using std::endl;


Game::Game(SDL_Window *win, SDL_GameController *gpad): window(win), gamepad(gpad),
                                                       box(0, 0, 35, 35),
                                                       fpsCounter(),
						       eventHandler(gamepad)
{
   srand(time(NULL));
}

void Game::update()
{
   glViewport(0, 0, width, height);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

   glOrtho(0, width, 0, height, 1, -1);

   static int count = 0;
   const int distanceBetweenLines = 150;
   const int lineSpeed = 2;

   if(count >= distanceBetweenLines)
   {
      int holeX = rand() % (width - box.getBoxWidth() + 1);
      int holeWidth = 90;
      
      lineList.push_back(Line(height, holeX, holeWidth));
      count = 0;
   }
   else
   {
      count += lineSpeed;
   }

   std::list<Line>::iterator it;
   for(it = lineList.begin(); it != lineList.end(); ++it)
   {
      if((*it).getY() <= (box.getBoxY() + box.getBoxHeight()))
      {
         if((*it).getHoleX() >= box.getBoxX() ||
	    ((*it).getHoleX() + (*it).getHoleWidth()) <= (box.getBoxX() + box.getBoxWidth()))
	 {
	    state = GAME_OVER;
	    break;
	 }
      }

      (*it).decrease(lineSpeed);
      if((*it).getY() <= 0)
      {
         lineList.erase(it);
	 break;
      }

   }
   eventHandler.update(box);
#ifdef DEBUG
   fpsCounter.countFps();
#endif   
}
void Game::draw()
{
   glClearColor(1.0, 1.0, 1.0, 1.0);
   glClear(GL_COLOR_BUFFER_BIT);

   std::list<Line>::iterator it;
   for(it = lineList.begin(); it != lineList.end(); ++it)
   {
      (*it).draw();
   }
   box.draw();
#ifdef DEBUG
   fpsCounter.drawFps(height);
#endif
   SDL_GL_SwapWindow(window);
}

void Game::restart()
{
   lineList.clear();
}

Box& Game::getBox()
{
   return box;
}
