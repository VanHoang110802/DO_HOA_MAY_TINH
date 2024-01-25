/* - Chuong trinh ve duong Hoa hong */
#include <conio.h>
#include <graphics.h>
#include <math.h>

#define K 150

void rose(int n)
{
   double goc = 0.0;
   double f, xc, yc;

   if (n % 2 == 0)
     n /= 2;
   xc = getmaxx() / 2;
   yc = getmaxy() / 2;
   while (!kbhit())
   {
      f = K * cos(goc * n);
      putpixel(xc + f * cos(goc), yc + f * sin(goc), YELLOW);
      goc += 0.01;
   }
}

int main()
{
  int gr_drive = DETECT, gr_mode;
  int n;

  printf("\nCho biet so canh hoa : ");
  scanf("%d", &n);
  initgraph(&gr_drive, &gr_mode, "");
  rose(n);

  getch();
  closegraph();
}
