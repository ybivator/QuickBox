#ifdef _WIN32
#include "stdafx.h"
#include <windows.h>
#endif

#include <drawFunctions.h>
#include <GL/gl.h>
#include <Box.h>
#include <iostream>

using std::cout;
using std::endl;


void draw(SDL_Window* win, int w, int h, int key, int step)
{
   glClearColor(1.0, 1.0, 1.0, 1.0);
   glClear(GL_COLOR_BUFFER_BIT);

   glViewport(0, 0, w, h);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

   glOrtho(0, w, 0, h, 1, -1);

   static Box box(0, 0, 50, 50);

   if(key == 1)
   {
      box.increaseX(step);
   }
   else if(key == 2)
   {
      box.decreaseX(step);
   }
   
   box.draw();
   SDL_GL_SwapWindow(win);
}
