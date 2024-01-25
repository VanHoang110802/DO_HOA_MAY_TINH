/* Ban dai bac */
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>

/* 1 / sqrt(2) */
#define FCT 0.7071067
/* he so doi tu do sang radian */
#define RADS 0.017453293
#define g 9.8

double x1, y6, x2, y2, ang[2], vec[2];
void far*buf1, *buf2;
char *mess[2] = {
"Den luot nguoi ben trai di", "Den luot nguoi ben phai di"
};
void lineseg(int hpos1,int hpos2,int vpos1,int vpos2, int depth,int range)
{
  int midvpos;

  if (depth<=0)
     line(hpos1,vpos1,hpos2,vpos2);
  else {
    midvpos = (vpos1+vpos2)/2+rand()%range-range/2;
    lineseg(hpos1,(hpos1+hpos2)/2,vpos1,midvpos,depth-1,
             range/2);
    lineseg((hpos1+hpos2)/2,hpos2,midvpos,vpos2,depth-1,
             range/2);
  }
}

void vedb1()
{
  int y;
  setcolor(LIGHTGRAY);
  for (y=-3; y<=3; y++)
    line(x1-10*cos(RADS*ang[0]), y6 - 5 + 10*sin(RADS*ang[0])+y,
         x1+20*cos(RADS*ang[0]), y6 - 5 - 20*sin(RADS*ang[0])+y);
  setfillstyle(SOLID_FILL, CYAN);
  bar(x1-4, y6-20, x1+4, y6+20);
}

void vedb2()
{
  int y;
  setcolor(LIGHTGRAY);
  for (y=-3; y<=3; y++)
    line(x2-20*cos(RADS*ang[1]), y2 - 5 - 20*sin(RADS*ang[1])+y,
         x2+10*cos(RADS*ang[1]), y2 - 5 + 10*sin(RADS*ang[1])+y);
  setfillstyle(SOLID_FILL, CYAN);
  bar(x2-4, y2-20, x2+4, y2+20);
}

void screen()
{
  int depth, range;
  cleardevice();
  setcolor(YELLOW);
  rectangle(0, 0, getmaxx(), getmaxy());
  setcolor(BLUE);
  setfillstyle(SOLID_FILL, BLUE);
  bar(1, 1, getmaxx()-1, getmaxy()-31);
  setcolor(YELLOW);
  line(0, getmaxy()-30, getmaxx(), getmaxy()-30);
  rand();
  depth = rand()%5 + 5;
  lineseg(0, getmaxx(), getmaxy() / 2, getmaxy()-160, depth, 250);
  setfillstyle(SOLID_FILL, BROWN);
  floodfill(10, getmaxy()-40, YELLOW);
  x1 = rand()%getmaxx()/8+20;
  y6 = 1;
  while (getpixel(x1,y6) != YELLOW)
    y6++;
  x2 = getmaxx() - rand()%getmaxx()/8-20;
  y2 = 1;
  while (getpixel(x2,y2) != YELLOW)
    y2++;
  setcolor(YELLOW);
  setfillstyle(SOLID_FILL, YELLOW);
  fillellipse(getmaxx()/2, 50, 30, 30);
  ang[0] = ang[1] = 30;
  vec[0] = vec[1] = 100;
}

void hide(int player)
{
  int x1, x2;
  setcolor(BLUE);
  setfillstyle(SOLID_FILL, BLUE);
  switch(player)
  {
    case 0 : x1 = 10; x2 = 100; break;
    case 1 : x1 = getmaxx()-100;
             x2 = getmaxx()-10;
             break;
  }
  bar(x1, 10, x2, 50);
}

void show(int player)
{
  int x1;
  char s[20];
  setcolor(YELLOW);
  switch(player)
  {
    case 0 : x1 = 10; break;
    case 1 : x1 = getmaxx()-100; break;
  }
  sprintf(s, "VEC : %03.0lf", vec[player]);
  outtextxy(x1, 10, s);
  sprintf(s, "ANG : %02.0lf", ang[player]);
  outtextxy(x1, 20, s);
}

void message(int player)
{
  char c;
  setcolor(BLACK);
  setfillstyle(SOLID_FILL, BLACK);
  bar(1, getmaxy()-29, getmaxx()-1, getmaxy()-2);
  setcolor(YELLOW);
  outtextxy(10, getmaxy()-10, mess[player]);
  outtextxy(400, getmaxy()-10, "Nhan Enter de ban");
  do {
    c = getch();
    if (c == 0)
      c = getch();
    if (c != 13)
    {
      hide(player);
      switch(c)
      {
        case 75 : if (vec[player]>0)
                    vec[player]--;
                  break;
        case 77 : if (vec[player]<1000)
                    vec[player]++;
                  break;
        case 80 : if (ang[player]>0)
                    ang[player]--;
                  break;
        case 72 : if (ang[player]<90)
                    ang[player]++;
                  break;
      }
      switch(player)
      {
        case 0 : putimage(x1-20, y6-30, buf1, COPY_PUT);
                 vedb1();
                 break;
        case 1 : putimage(x2-20, y2-30, buf2, COPY_PUT);
                 vedb2();
                 break;
      }
      show(player);
    }
  } while (c != 13 && c != 27);
}

int shoot1()
{
  double x, y, vec1, t;
  int i, OK = 1;

  x = x1 + 20 * cos(RADS*ang[0]) + 4;
  y = y6 - 20 * sin(RADS*ang[0]) - 4;
  vec1 = vec[0];
  i = getpixel(x, y)==BLUE;
  t = 0.0;
  while (x>0 && (x<getmaxx()-1) && y>0 && (y<getmaxy()-1) && OK)
  {
    if (getpixel(x+4, y)==BROWN)
      OK = 0;
    else
      OK = 1;
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    fillellipse(x, y, 3, 3);
    delay(2);
    setcolor(BLUE);
    setfillstyle(SOLID_FILL, BLUE);
    fillellipse(x, y, 3, 3);
    x++;
    t += 0.1;
    y -= (vec1*sin(RADS*ang[0]) - g*t)/(vec1*cos(RADS*ang[0]));
  }
  setcolor(BLUE);
  setfillstyle(SOLID_FILL, BLUE);
  fillellipse(x, y, 6, 6);
  if (abs(x-x2) < 15 && abs(y-y2)<30)
    return 1;
  else
    return 0;
}

int shoot2()
{
  double x, y, vec2, t;
  int i, OK = 1;

  x = x2 - 20 * cos(RADS*ang[1]) - 4;
  y = y2 - 20 * sin(RADS*ang[1]) - 4;
  vec2 = vec[1];
  i = getpixel(x, y)==BLUE;
  t = 0.0;
  while (x>0 && (x<getmaxx()-1) && y>0 && (y<getmaxy()-1) && OK)
  {
    if (getpixel(x-4, y)==BROWN)
      OK = 0;
    else
      OK = 1;
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    fillellipse(x, y, 3, 3);
    delay(2);
    setcolor(BLUE);
    setfillstyle(SOLID_FILL, BLUE);
    fillellipse(x, y, 3, 3);
    x--;
    t += 0.1;
    y -= (vec2*sin(RADS*ang[1]) - g*t)/(vec2*cos(RADS*ang[1]));
  }
  setcolor(BLUE);
  setfillstyle(SOLID_FILL, BLUE);
  fillellipse(x, y, 6, 6);
  if (abs(x-x1) < 15 && abs(y-y6)<30)
    return 1;
  else
  return 0;
}

void run()
{
  int size, done;
  screen();
  size = imagesize(x1-20, y6-30, x1+20, y6+30);
  buf1 = malloc(size);
  buf2 = malloc(size);
  getimage(x1-20, y6-30, x1+20, y6+30, buf1);
  getimage(x2-20, y2-30, x2+20, y2+30, buf2);
  vedb1();
  vedb2();
  show(0);
  show(1);
  do {
    message(0);
    done = shoot1();
    if (!done)
    {
      message(1);
      done = shoot2();
      if (done)
      {
        setcolor(YELLOW);
        outtextxy(100, 100, "Player Two win");
      }
    }
    else
    {
      setcolor(YELLOW);
      outtextxy(100, 100, "Player One win");
    }
    if (done)
      outtextxy(100, 110, "Press any key to continue or ESCAPE to quit");
  } while (!done);
  free(buf1);
  free(buf2);
}

int main()
{
  int gr_drive = DETECT, gr_mode;
  char c;

  initgraph(&gr_drive, &gr_mode, "");
  do {
    run();
    c = getch();
  } while (c != 27);
  closegraph();
}
