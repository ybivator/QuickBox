#ifndef _LINE_H_
#define _LINE_H_

extern const int width;
extern const int height;

class Line
{
public:
   Line(int hX, int hW);

   void draw();
   void decrease(int num);


private:
   int xPos;
   int yPos;
   int holeX;
   int holeWidth;
};
#endif
