/* Minh hoa chuyen dong cua mot piston(pittong) */
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>

/* 1 / sqrt(2) */
#define FCT 0.7071067
/* he so doi tu do sang radian */
#define RADS 0.017453293

#define RADIUS1 50
#define SQRRADIUS1 2500
#define RADIUS2 150
#define SQRRADIUS2 22500

void piston()
{
  double angle = 45, xc, yc, x1, y1, y2;
  xc = getmaxx() / 2;
  yc = getmaxy() / 2 + 100;
  setcolor(WHITE);
  line(xc - 31, 110, xc-31, 265);
  line(xc - 32, 110, xc-32, 265);
  line(xc + 31, 110, xc+31, 265);
  line(xc + 32, 110, xc+32, 265);
  while (!kbhit())
  {
    x1 = xc + RADIUS1 * cos(angle * RADS);
    y1 = yc + RADIUS1 * sin(angle * RADS);
    y2 = y1 - sqrt(SQRRADIUS2 - SQRRADIUS1*cos((angle+90)*RADS)*cos((angle+90)*RADS));
    setcolor(11);
    rectangle(xc-30, y2 - 35, xc+30,y2+35);
    line(xc, yc, x1, y1);
    line(xc, y2, x1, y1);
    setfillstyle(SOLID_FILL, 7);
    fillellipse(xc, yc, 2, 2);
    fillellipse(x1, y1, 2, 2);
    fillellipse(xc, y2, 2, 2);
    delay(100);
    setcolor(0);
    rectangle(xc-30, y2 - 35, xc+30,y2+35);
    line(xc, yc, x1, y1);
    line(xc, y2, x1, y1);
    fillellipse(xc, yc, 2, 2);
    fillellipse(x1, y1, 2, 2);
    fillellipse(xc, y2, 2, 2);
    angle += 5;
  }
}

int main()
{
  int gr_drive = DETECT, gr_mode;

  initgraph(&gr_drive, &gr_mode, "");
  piston();
  getch();
  closegraph();
}
