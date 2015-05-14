#ifndef _LINE_H_
#define _LINE_H_
class Line
{
public:
   Line(int hX, int hW);

   void draw();


private:
   int xPos;
   int yPos;
   int holeX;
   int holeWidth;
};
#endif

