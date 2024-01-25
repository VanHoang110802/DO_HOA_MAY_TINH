/* - Qua lac dao dong */
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>

/* he so doi tu do sang radian */
#define RADS 0.017453293
#define BIENDO 30
#define DAY 200
#define RADIUS 5

void daodong()
{
  int goc = BIENDO, congtru = 0;
  double x, y, xgoc, ygoc;

  xgoc = getmaxx() / 2;
  ygoc = 10;
  line(xgoc - 5, ygoc, xgoc + 5, ygoc);

  do {
    x = xgoc + DAY * sin(goc* RADS);
    y = ygoc + DAY * cos(goc* RADS);
    setcolor(YELLOW);
    line(xgoc, ygoc, x, y);
    setfillstyle(SOLID_FILL, GREEN);
    setcolor(GREEN);
    fillellipse(x, y, RADIUS, RADIUS);
    delay(50);
    setcolor(BLACK);
    line(xgoc, ygoc, x, y);
    setfillstyle(SOLID_FILL, BLACK);
    setcolor(BLACK);
    fillellipse(x, y, RADIUS, RADIUS);
    if (congtru)
    {
      goc ++;
      if (goc == BIENDO)
        congtru = 0;
    }
    else
    {
      goc--;
      if (goc == -BIENDO)
        congtru = 1;
    }
  } while (!kbhit());
}

int main()
{
  int gr_drive = DETECT, gr_mode;

  initgraph(&gr_drive, &gr_mode, "");
  daodong();

  getch();
  closegraph();
}
