#include <conio.h>
#include <graphics.h>
#include <math.h>

typedef struct 
{
  double x, y, z;
} Point3D;

double yaw, roll, pitch, depth;
static Point3D p[] = {
{-35.0, -35.0, 35.0},
{35.0, -35.0, 35.0},
{35.0, 35.0, 35.0},
{-35.0, 35.0, 35.0},
{-35.0, -35.0, 35.0},
{-35.0, -35.0, -35.0},
{35.0, -35.0, -35.0},
{35.0, 35.0, -35.0},
{-35.0, 35.0, -35.0},
{-35.0, -35.0, -35.0}
};

void show_3d_1(Point3D p[], int n)
{
    setcolor(14);
  double sinyaw, cosyaw, sinroll, cosroll, sinpitch, cospitch,
         yawx, yawy, rollx, rollz, pitchx, pitchy, pitchz, sx, sy;
  int r;

  cleardevice();

  sinyaw = sin(yaw);
  cosyaw = cos(yaw);
  sinroll = sin(roll);
  cosroll = cos(roll);
  sinpitch = sin(pitch);
  cospitch = cos(pitch);

  for (r=0; r<n; r++)
  {
    yawx = (cosyaw * p[r].x) - (sinyaw * p[r].y);
    yawy = (sinyaw * p[r].x) + (cosyaw * p[r].y);
    rollx = (cosroll * yawx) + (sinroll * p[r].z);
    rollz = (cosroll * p[r].z) - (sinroll * p[r].z);
    pitchy = (cospitch * yawy) - (sinpitch * rollz);
    pitchz = (sinpitch * yawy) + (cospitch * rollz);

    sx = depth * (rollx+5) / (pitchy+250);
    sy = depth * (pitchz-5) / (pitchy+250);
    if (r == 0)
      moveto(sx+getmaxx() / 2, sy + getmaxy() / 2);
    else
      lineto(sx+getmaxx() / 2, sy+getmaxy() / 2);
  }
}
void show_3d_2(Point3D p[], int n)
{
  double sinyaw, cosyaw, sinroll, cosroll, sinpitch, cospitch,
         yawx, yawy, rollx, rollz, pitchx, pitchy, pitchz, sx, sy;
  int r;

  cleardevice();

  sinyaw = sin(yaw);
  cosyaw = cos(yaw);
  sinroll = sin(roll);
  cosroll = cos(roll);
  sinpitch = sin(pitch);
  cospitch = cos(pitch);

  for (r=0; r<n; r++)
  {
    yawx = (cosyaw * p[r].x) - (sinyaw * p[r].y);
    yawy = (sinyaw * p[r].x) + (cosyaw * p[r].y);
    rollx = (cosroll * yawx) + (sinroll * p[r].z);
    rollz = (cosroll * p[r].z) - (sinroll * p[r].z);
    pitchy = (cospitch * yawy) - (sinpitch * rollz);
    pitchz = (sinpitch * yawy) + (cospitch * rollz);

    sx = depth * (rollx+5) / (pitchy+250);
    sy = depth * (pitchz-5) / (pitchy+250);
    delay(1000);
    if (r == 0)
      moveto(sx+getmaxx() / 2, sy + getmaxy() / 2);
    else
      lineto(sx+getmaxx() / 2, sy+getmaxy() / 2);
  }
}
int main()
{
  int gr_drive = DETECT, gr_mode, c=0;

  initgraph(&gr_drive, &gr_mode, "");

  yaw = 5.7;
  roll = 6.3;
  pitch = 5.9;
  depth = 360;
  do{
    show_3d_2(p, 10);

  }while(kbhit());
  while (c != 27)
  {
    show_3d_1(p, 10);
    c = getch();
    if (c==0)
      c = getch();
    switch (c)
    {
      case 75 : yaw -= 0.1;
                break;
      case 77 : yaw += 0.1;
                break;
      case 72 : pitch -= 0.1;
                break;
      case 80 : pitch += 0.1;
                break;
    }
  }
  getch();
  closegraph();
}
