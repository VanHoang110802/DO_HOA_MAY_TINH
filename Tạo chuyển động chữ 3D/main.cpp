#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>

/* he so doi tu do sang radian */
#define RADS 0.017453293

#define xc (getmaxx()/2)
#define yc (getmaxy()/2)
#define UX 20
#define UY 20
#define UZ 20
#define OX (0.8*M_PI)
#define OY (0.2*M_PI)
#define X(x,y,z) (xc+(x)*UX*cos(OX)+(y)*UY*cos(OY))
#define Y(x,y,z) (yc+(x)*UX*sin(OX)+(y)*UY*sin(OY)-(z)*UZ)

typedef struct {
  double x, y, z;
} Point3D;

#define MAX 14

Point3D point[MAX] = {
{-4, 6, 0}, {-1, 6, 0}, {-3, 4, 0}, {-1, 3, 0}, {-1, 1, 0}, {-2, 0, 0}, {-4, 0, 0},
{1, 6, 0}, {3, 6, 0}, {4, 5, 0}, {4, 1, 0}, {3, 0, 0}, {1, 0, 0}, {1, 6, 0}
};

void _3D()
{
  int i, j, angle = 0;
  Point3D p, _p[MAX];
  for (i=0; i<MAX; i++)
  {
    point[i].x = point[i].x * cos(RADS*180);
    point[i].z = point[i].x * sin(RADS*180);
  }
  do {
    cleardevice();
    for (i=0; i<MAX; i++)
    {
      _p[i].x = point[i].x;
      _p[i].y = point[i].y * cos(RADS*angle);
      _p[i].z = point[i].y * sin(RADS*angle);
      p = _p[i];
      if (i==0 || i==7)
        moveto(X(p.x, p.z, p.y), Y(p.x, p.z, p.y));
      else
        lineto(X(p.x, p.z, p.y), Y(p.x, p.z, p.y));
    }
    angle--;
    angle %= 360;
    delay(10);
  } while (!kbhit());
}

int main()
{
  int gr_drive = DETECT, gr_mode;

  initgraph(&gr_drive, &gr_mode, "");

  _3D();
  getch();
  closegraph();
}
