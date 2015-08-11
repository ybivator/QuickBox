#ifdef _WIN32
#include "stdafx.h"
#include <Windows.h>
#endif

#include <Line.h>
#include <GL/gl.h>

Line::Line(int y, int hX, int hW): xPos(0), yPos(y), holeX(hX), holeWidth(hW)
{
}

void Line::draw()
{
   glColor3f(0.0f, 0.0f, 0.0f);

   glBegin(GL_LINES);
      glVertex2i(xPos, yPos);
      glVertex2i(holeX, yPos);
      glVertex2i(holeX + holeWidth, yPos);
      glVertex2i(width, yPos);
   glEnd();
}

void Line::decrease(int num)
{
   if(yPos >= 0)
   {
      if(num > 0)
      {
         yPos -= num;
         glPushMatrix();
         glMatrixMode(GL_MODELVIEW);
         glLoadIdentity();
   
         glTranslatef(0.0f, yPos, 0.0f);
         glPopMatrix();
      }
   }
   else
   {
      yPos = height;
      glPushMatrix();
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();

      glTranslatef(0.0f, yPos, 0.0f);
      glPopMatrix();
   }
}

const int Line::getY()
{
   return yPos;
}

void Line::setY(int num)
{
   yPos = num;
}
