#ifdef _WIN32
#include "stdafx.h"
#include <windows.h>
#endif

#include <Box.h>
#include <GL/gl.h>
#include <SDL2/SDL.h>
#include <iostream>

using std::cout;
using std::endl;


Box::Box(int x, int y, int w, int h): xPos(x), yPos(y),
                                      boxWidth(w), boxHeight(h)
{
}

void Box::draw()
{
   glColor3f(0.0f, 0.0f, 0.0f);

   glBegin(GL_LINE_LOOP);
      glVertex2i(xPos, yPos);
      glVertex2i(xPos, yPos + boxHeight);
      glVertex2i(xPos + boxWidth, yPos + boxHeight);
      glVertex2i(xPos + boxWidth, yPos);
      glVertex2i(xPos, yPos);
   glEnd();
}

void Box::increase(int step)
{
   int leftBorder = xPos + step;
   int rightBorder = xPos + boxWidth + step;

   if(leftBorder <= 0 && leftBorder >= step)
   {
      xPos = 0;
   }
   else if(rightBorder > static_cast<int>(width) && (rightBorder - static_cast<int>(width)) <= step)
   {
      xPos = width - boxWidth;
   }
   else if(xPos >= 0 && xPos <= static_cast<int>(width))
   {
      xPos += step;
   }
   glPushMatrix();
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef(xPos, 0.0f, 0.0f);
   glPopMatrix();
}

void Box::decrease(int step)
{
   increase(-step);
}

const int Box::getBoxHeight() const
{
   return boxHeight;
}

const int Box::getBoxWidth() const
{
   return boxWidth;
}

const int Box::getBoxX() const
{
   return xPos;
}

const int Box::getBoxY() const
{
   return yPos;
}
