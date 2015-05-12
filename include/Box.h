#ifndef _BOX_H_
#define _BOX_H_

extern const int width;

class Box
{
public:
   Box(int x, int y, int w, int h);
   void draw();
   void increase(int step);
   void decrease(int step);

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

