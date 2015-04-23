#ifndef _BOX_H_
#define _BOX_H_

class Box
{
public:
   Box(int x, int y, int w, int h);
   void draw();
   void increaseX(int step);
   void decreaseX(int step);

   const int getBoxHeight() const;
   const int getBoxWidth() const;
   const int getBoxX() const;
   const int getBoxY() const;

private:
   int xPos;
   int yPos;
   int boxWidth;
   int boxHeight;
};
#endif

