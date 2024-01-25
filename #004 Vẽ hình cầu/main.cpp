#include <conio.h>
#include <graphics.h>
#include <math.h>

/* he so doi tu do sang radian */
#define RADS 0.017453293
#define RADIUS 100

typedef struct
{
  double x, y, z;
} Point3D;

double yaw   = 0,
       roll  = 0,
       pitch = M_PI/2,
       depth = 360,
       xc, yc;

void tinh_3d(Point3D p, double *x, double *y)
{
  double sinyaw, cosyaw, sinroll, cosroll, sinpitch, cospitch,
         yawx, yawy, rollx, rollz, pitchx, pitchy, pitchz;

  sinyaw = sin(yaw);
  cosyaw = cos(yaw);
  sinroll = sin(roll);
  cosroll = cos(roll);
  sinpitch = sin(pitch);
  cospitch = cos(pitch);

  yawx = (cosyaw * p.x) - (sinyaw * p.y);
  yawy = (sinyaw * p.x) + (cosyaw * p.y);
  rollx = (cosroll * yawx) + (sinroll * p.z);
  rollz = (cosroll * p.z) - (sinroll * p.z);
  pitchy = (cospitch * yawy) - (sinpitch * rollz);
  pitchz = (sinpitch * yawy) + (cospitch * rollz);

  *x = depth * (rollx+5) / (pitchy+250);
  *y = depth * (pitchz-5) / (pitchy+250);
}

void circle3d(double u)
{
  double v = 0.0, x, y, radius;
  Point3D p;
  radius = RADIUS * sin(u*RADS);
  p.x = radius * cos(v*RADS);
  p.z = radius * sin(v*RADS);
  p.y = RADIUS * cos(u*RADS);
     tinh_3d(p, &x, &y);
     moveto(xc + x, yc + y);
  for (v=0; v<=360; v = v + 10)
  {
     p.x = radius * cos(v*RADS);
     p.z = radius * sin(v*RADS);
  p.y = RADIUS * cos(u*RADS);
     tinh_3d(p, &x, &y);
     lineto(xc + x, yc + y);
  }
}

void sphere3D()
{
  double u, v, x, y;
  Point3D p;

  for (u=0; u<=180; u = u+10)
  {
    v = -90;
    p.x = RADIUS * cos(v*RADS) * cos(u*RADS);
    p.y = RADIUS * sin(v*RADS);
    p.z = RADIUS * cos(v*RADS) * sin(u*RADS);
    tinh_3d(p, &x, &y);
    moveto(xc + x, yc + y);
    for (v=-90; v<=270; v = v+10)
    {
       p.x = RADIUS * cos(v*RADS) * cos(u*RADS);
       p.y = RADIUS * sin(v*RADS);
       p.z = RADIUS * cos(v*RADS) * sin(u*RADS);
       tinh_3d(p, &x, &y);
       lineto(xc + x, yc + y);
    }
    circle3d(u);
    delay(500);
  }
}

int main()
{
  int gr_drive = DETECT, gr_mode;

  initgraph(&gr_drive, &gr_mode, "");
  xc = getmaxx() / 2;
  yc = getmaxy() / 2;

  sphere3D();
  getch();
  closegraph();
}
