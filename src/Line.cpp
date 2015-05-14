#ifdef _WIN32
#include "stdafx.h"
#include <Windows.h>
#endif

#include <Line.h>

Line::Line(int hX, int hW): xPos(0), yPos(0), holeX(hX), holeWidth(hW)
{
}

void Line::draw()
{
}
