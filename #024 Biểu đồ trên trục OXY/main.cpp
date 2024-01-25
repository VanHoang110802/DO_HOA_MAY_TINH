// vẽ biểu đồ cột trên trục oxy
#include <graphics.h>
#include <conio.h>

int main() {
  int gd=DETECT,gm,maxx,maxy,x,y,button;
  initgraph(&gd,&gm,"");
  outtextxy(70,153,"O ");
  line(80,150,200,150);
  line(80,150,80,50);
  settextstyle(1,HORIZ_DIR,1);
  outtextxy(190,153,"<-x ");
  settextstyle(1,VERT_DIR,1);
  outtextxy(60,50,"<-y ");
  bar(100,100,120,150);
  bar(130,120,150,150);
  getch();
  closegraph();
  return 0;
}
