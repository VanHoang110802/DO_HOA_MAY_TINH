/* bau troi day sao */

#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <dos.h>
#define MAXPOINT 100
#define DELAY 100

struct point {
  int x, y, state, color, congtru;
};

void drawpoint(struct point p, int vexoa)
{
  int color;
  if (vexoa)
	color = p.color;
  else
	color = BLACK;
  setcolor(color);
  switch(p.state)
  {
	case 0: putpixel(p.x, p.y, color);
			break;
	case 1: line(p.x-1, p.y, p.x+1, p.y);
			line(p.x, p.y-1, p.x, p.y+1);
			break;
	case 2: line(p.x-2, p.y, p.x+2, p.y);
			line(p.x, p.y-2, p.x, p.y+2);
			break;
	case 3: line(p.x-4, p.y, p.x+4, p.y);
			line(p.x, p.y-4, p.x, p.y+4);
			rectangle(p.x-1, p.y-1, p.x+1, p.y+1);
			break;
  }
}

int main()
{
   struct point p[MAXPOINT];
   int i, gd = DETECT, gm, maxx, maxy;

   initgraph(&gd, &gm, "");
   maxx = getmaxx();
   maxy = getmaxy();
   rand();
   for (i=0; i<MAXPOINT; i++)
   {
	 p[i].x = rand() % maxx;
	 p[i].y = rand() % maxy;
	 p[i].state = rand() % 16;
	 p[i].color = rand() % 16;
	 p[i].congtru = rand() % 2;
   }

   while (!kbhit())
   {
	 for (i=0; i<MAXPOINT; i++)
	   drawpoint(p[i], 1);
	 delay(DELAY);
	 for (i=0; i<MAXPOINT; i++)
	   drawpoint(p[i], 0);
	 for (i=0; i<MAXPOINT; i++)
	 {
	   if (p[i].congtru)
	   {
		 p[i].state++;
		 if (p[i].state >= 3)
		   p[i].congtru = 0;
	   }
	   else
	   {
		 p[i].state--;
		 if (p[i].state <= 0)
		   p[i].congtru = 1;
	   }
	 }
   }
   closegraph();
}
