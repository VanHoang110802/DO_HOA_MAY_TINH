/* Analog */
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>

void screen()
{
  cleardevice();
  setcolor(GREEN);
  rectangle(0, 0, getmaxx(), getmaxy());
}

void drawarea()
{
  int i;
  char s[5];
  setfillstyle(SOLID_FILL, LIGHTGRAY);
  setcolor(LIGHTGRAY);
  bar(50, 10, getmaxx() - 11, getmaxy() - 21);
  for (i=14; i>-14; i--)
  {
    itoa(i, s, 10);
    setcolor(YELLOW);
    outtextxy(47 - textwidth(s), getmaxy()/2 - i * 16, s);
    setcolor(GREEN);
    line(48, getmaxy()/2 - i * 16 + 4, getmaxx()-11, getmaxy()/2 - i * 16 + 4);
  }
}

void message (char *s)
{
  setcolor(BLACK);
  setfillstyle(SOLID_FILL, BLACK);
  bar(100, getmaxy()-12, getmaxx()-1, getmaxy() - 2);
  setcolor(WHITE);
  outtextxy(100, getmaxy()- 12, s);
}

void run()
{
  int done = 0, i, OK, first = 1;
  double r;
  char c;
  screen();
  rand();
  do {
    drawarea();
    if (first)
    {
      message("Nhan phim bat ky de tiep tuc");
      c = getch();
      while (kbhit())
        c = getch();
      first = 0;
    }
    message("Nhan phim ESC de ket thuc");
    i = 0;
    OK = 1;
    do {
      setcolor(BLUE);
      setwritemode(XOR_PUT);
      line(51+i, 10, 51+i, getmaxy() - 21);
      delay(10);
      line(51+i, 10, 51+i, getmaxy() - 21);
      setwritemode(COPY_PUT);
      setcolor(BLACK);
      r = (rand()%2700 - 1300) / 100.0;
      if (i == 0)
        moveto(51+i, -r*16 + getmaxy() / 2 + 4);
      else
        lineto(51+i, -r*16 + getmaxy() / 2 + 4);
      if (kbhit())
      {
        c = getch();
        if (c == 27)
          done = 1;
      }
      i++;
      if (i>= (getmaxx()-62))
        OK = 0;
    } while (OK && !done);
  } while (!done);
}

int main()
{
  int gr_drive = DETECT, gr_mode;

  initgraph(&gr_drive, &gr_mode, "");
  run();
  closegraph();
}
