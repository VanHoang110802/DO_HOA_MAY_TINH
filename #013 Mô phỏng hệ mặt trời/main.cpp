/* mo phong he mat troi */
#include <conio.h>
#include <graphics.h>
#include <math.h>

#define SUNRADIUS 100
#define EARTHRADIUS 10
#define MOONRADIUS 3
#define SUNEARTH 200
#define EARTHMOON 30
#define DELAY 20

void he_mat_troi()
{
  int xsun, ysun, xearth, yearth, xmoon, ymoon;
  int earth_angle = 0, moon_angle = 0;

  rectangle(0, 0, getmaxx(), getmaxy());

  xsun = getmaxx() / 2;
  ymoon = yearth = ysun = getmaxy() / 2;
  xearth = xsun + SUNEARTH;
  xmoon = xearth + EARTHMOON;

  setcolor(YELLOW);
  setfillstyle(SOLID_FILL, YELLOW);
  fillellipse(xsun, ysun, SUNRADIUS, SUNRADIUS);
  do {
    setcolor(11);
    setfillstyle(SOLID_FILL, 11);
    fillellipse(xearth, yearth, EARTHRADIUS, EARTHRADIUS);
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    fillellipse(xmoon, ymoon, MOONRADIUS, MOONRADIUS);
    delay(DELAY);
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    fillellipse(xearth, yearth, EARTHRADIUS, EARTHRADIUS);
    fillellipse(xmoon, ymoon, MOONRADIUS, MOONRADIUS);
    earth_angle += 1;
    moon_angle += 12;
    xearth = xsun + SUNEARTH * cos(M_PI * earth_angle / 180);
    yearth = ysun + SUNEARTH * sin(M_PI * earth_angle / 180);
    xmoon = xearth + EARTHMOON * cos(M_PI * moon_angle / 180);
    ymoon = yearth + EARTHMOON * sin(M_PI * moon_angle / 180);
  } while (!kbhit());
}

int main()
{
  //int gr_drive = DETECT, gr_mode;

  //initgraph(&gr_drive, &gr_mode, "");
     initwindow(700,500,"Hoang Dep Trai Nhung Dang That Tinh :((",200,100);
  he_mat_troi();
  getch();
  closegraph();
}
