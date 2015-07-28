#ifdef _WIN32
#include "stdafx.h"
#include <Windows.h>
#endif

#include <FpsCounter.h>
#include <SDL2/SDL.h>
#include <rasterFpsCounter.h>

FpsCounter::FpsCounter(): lastTime(SDL_GetTicks()), frames(0),
                          majorFps(0), minorFps(0)
{
}

void FpsCounter::countFps()
{
   unsigned int currentTime = SDL_GetTicks();
   unsigned int delta = currentTime - lastTime;
   if(delta > refreshTime)
   {
      unsigned int fps = frames * 1000 / delta;
      if(fps < 100)
      {
         majorFps = fps / 10;
	 minorFps = fps % 10;
      }
      lastTime = currentTime;
      frames = 0;
   }
   frames++;
}

void FpsCounter::drawFps(int height)
{
   glColor3f(0.0f, 0.0f, 0.0f);
   glPixelStorei(GL_UNPACK_ALIGNMENT, 2);
   glRasterPos2i(0, height - 30);
   glBitmap(16, 26, 0, 0, 19.0, 0, (*numbers[majorFps]));
   glBitmap(16, 26, 0, 0, 0, 0, (*numbers[minorFps]));
}
