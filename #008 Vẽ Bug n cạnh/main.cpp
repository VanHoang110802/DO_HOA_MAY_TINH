/* - Chuong trinh ve duong Bug n canh*/
#include <conio.h>
#include <graphics.h>
#include <math.h>

/* he so doi tu do sang radian */
#define RADS 0.017453293
/* So luong canh toi da */
#define MAX 10
/* Ti so */
#define RATE 0.1

typedef struct POINT1 {
  double x, y;
} POINT1 ;

void Bug(int n)
{
  int i, centerx, centery, angle;
  POINT1 temp[MAX], P[MAX];
  double j;

  centerx = getmaxx() / 2;
  centery = getmaxy() / 2;
  angle   = 360 / n;

  for (i=0; i<n; i++)
  {
    P[i].x = centerx + cos((i * angle - 90.0) * RADS) * (centery - 10);
    P[i].y = centery + sin((i * angle - 90.0) * RADS) * (centery - 10);
  }

  do {
    for (i=0; i<n-1; i++)
      line(P[i].x, P[i].y, P[i+1].x, P[i+1].y);
    line(P[n-1].x, P[n-1].y, P[0].x, P[0].y);
    for (i=0; i<n-1; i++)
    {
      temp[i+1].x = P[i].x + (P[i+1].x - P[i].x) * RATE;
      temp[i+1].y = P[i].y + (P[i+1].y - P[i].y) * RATE;
    }
    temp[0].x = P[n-1].x + (P[0].x - P[n-1].x) * RATE;
    temp[0].y = P[n-1].y + (P[0].y - P[n-1].y) * RATE;
    for (i=0; i<n; i++)
      P[i] = temp[i];
    j = (double)(P[1].x - P[0].x)*(double)(P[1].x - P[0].x) +
        (double)(P[1].y - P[0].y)*(double)(P[1].y - P[0].y);
  } while (j>100.0);
}

int main()
{
  int gr_drive = DETECT, gr_mode, i;

  initgraph(&gr_drive, &gr_mode, "");
  setcolor(YELLOW);

  for (i=3; i<=MAX; i++)
  {
    cleardevice();
    rectangle(0, 0, getmaxx(), getmaxy());
    Bug(i);
    getch();
  }
  closegraph();
  return 0;
}
