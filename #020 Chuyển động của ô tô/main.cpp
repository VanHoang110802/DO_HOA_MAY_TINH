/*- Chuong trinh chuyen dong cua o to */

#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <math.h>

float t = 0.0;
float x, y;

void VeBanhXe()
{
  int x1, y1, x2, y2;
  circle(x, y, 17);
  x1 = x - 17 * cos(t);
  y1 = y - 17 * sin(t);
  x2 = x + 17 * cos(t);
  y2 = y + 17 * sin(t);
  line(x1, y1, x2, y2);
}

int main()
{
initwindow(700,500,"Truong Van Hoang",200,100);

for(int i = 0;i<500;i++){
    outtextxy(250,50,"O TO LAN BANH");

        // ve than xe
    arc(110+i,370,0,180,20);
    line(50+i,370,90+i,370);
    line(130+i,370,220+i,370);
    arc(240+i,370,0,180,20);
    line(260+i,370,300+i,370);
    line(300+i,370,300+i,350);
    line(300+i,350,240+i,330);
    line(240+i,330,200+i,300);
    line(200+i,300,110+i,300);
    line(110+i,300,80+i,330);
    line(80+i,330,50+i,340);
    line(50+i,340,50+i,370);

    // ve cua so
    line(165+i,305,165+i,330);
    line(165+i,330,230+i,330);
    line(230+i,330,195+i,305);
    line(195+i,305,165+i,305);

    line(160+i,305,160+i,330);
    line(160+i,330,95+i,330);
    line(90+i,330,120+i,305);
    line(120+i,305,160+i,305);

    x = 110 + i;
    y = 370;
    VeBanhXe();
    x = 240 + i;
    y = 370;
    VeBanhXe();
    t += 0.05;
    if(i > 450) i =0;
    delay(5);
    cleardevice();
    //ve duong di:
    line(0,390,700,390);
}
  getch();
  closegraph();
  return 0;
}
