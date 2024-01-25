/* - Chuong trinh ve duong Archimedian */
#include <conio.h>
#include <graphics.h>
#include <math.h>

#define K 4

void archimed()
{
   double goc = 0.0;
   double f, xc, yc;

   xc = getmaxx() / 2;
   yc = getmaxy() / 2;
   while (!kbhit())
   {
      f = K * goc;
      putpixel(xc + f * cos(goc), yc + f * sin(goc), YELLOW);
      goc += 0.01;
   }
}

int main()
{
  int gr_drive = DETECT, gr_mode;

  initgraph(&gr_drive, &gr_mode, "");
  archimed();

  getch();
  closegraph();
}
