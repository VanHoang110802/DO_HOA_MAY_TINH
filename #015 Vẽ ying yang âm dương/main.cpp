/* Yinyang */
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>

/* 1 / sqrt(2) */
#define FCT 0.7071067
/* he so doi tu do sang radian */
#define RADS 0.017453293
#define DELAY 5
#define RADIUS1 30.0
#define RADIUS2 2.0

double xc, yc, x1, y5, x2, y2, angle;

void xoa()
{
  setcolor(BLACK);
  setfillstyle(SOLID_FILL, BLACK);
  fillellipse(xc, yc, RADIUS1, RADIUS1);
}

void ve()
{
  setcolor(WHITE);
  setfillstyle(SOLID_FILL,WHITE);
  circle(xc, yc, RADIUS1);
  arc(xc + (x1-xc)/2, yc + (y5-yc)/2, -angle, -angle + 180, RADIUS1 / 2);
  arc(xc + (x2-xc)/2, yc + (y2-yc)/2, 180-angle, 360-angle, RADIUS1 / 2);
  circle(xc + (x1-xc)/2, yc + (y5-yc)/2, RADIUS2);
  circle(xc + (x2-xc)/2, yc + (y2-yc)/2, RADIUS2);
  floodfill(xc + (x2-xc)/2, yc + (y2-yc)/2, WHITE);
  floodfill(xc + (x1-xc)/2 + RADIUS2 +5, y5 + (y2-yc)/2 + RADIUS2 + 5, WHITE);
}
void tinh()
{
  angle += 1.0;
  if (angle >= 360.0)
    angle = 0.0;
  x1 = xc - RADIUS1 * cos(angle * RADS);
  y5 = yc - RADIUS1 * sin(angle * RADS);
  x2 = xc + RADIUS1 * cos(angle * RADS);
  y2 = yc + RADIUS1 * sin(angle * RADS);
}

void yinyang()
{
  do {
    ve();
    delay(DELAY);
    xoa();
    tinh();
  } while (!kbhit());
}

int main()
{
  int gr_drive = DETECT, gr_mode;

  initgraph(&gr_drive, &gr_mode, "");
  xc = getmaxx() / 2;
  y5 = y2 = yc = getmaxy() / 2;
  x1 = xc - RADIUS1;
  x2 = xc + RADIUS1;
  angle = 0.0;
  yinyang();
  getch();
  closegraph();
}
