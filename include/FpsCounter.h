#ifndef _FPS_COUNTER_H
#define _FPS_COUNTER_H

class FpsCounter
{
public:
   FpsCounter();

   void countFps();
   void drawFps(int height);

private:
   unsigned int lastTime;
   unsigned int frames;
   unsigned int majorFps;
   unsigned int minorFps;
   static const unsigned int refreshTime = 150;
};
#endif

