#ifdef _WIN32
#include "stdafx.h"
#include <Windows.h>
#endif

#include <Line.h>
#include <GL/gl.h>

Line::Line(int hX, int hW): xPos(0), yPos(height - 10), holeX(hX), holeWidth(hW)
{
}

void Line::draw()
{
   glBegin(GL_LINES);
      glVertex2i(xPos, yPos);
      glVertex2i(holeX, yPos);
      glVertex2i(holeX + holeWidth, yPos);
      glVertex2i(width, yPos);
   glEnd();
}

void Line::decrease(int num)
{
   if(num > 0)
   {
      yPos -= num;
   }
}
