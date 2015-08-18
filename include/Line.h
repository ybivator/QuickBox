#ifndef _LINE_H_
#define _LINE_H_

extern const unsigned int width;
extern const unsigned int height;

class Line
{
public:
   Line(int y, int hX, int hW);

   void draw();
   void decrease(int num);

   const int getY();
   void setY(int num);



private:
   int xPos;
   int yPos;
   int holeX;
   int holeWidth;
};
#endif

