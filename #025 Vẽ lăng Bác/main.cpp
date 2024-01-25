/* Vẽ lăng Bác */

#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>

#define round(a) int(a+0.5)
#define MAXPOINT 100
#define DELAY 100

struct point {
  int x, y, state, color, congtru;
};
// Hàm dịch chuyển con trỏ đến tọa độ x, y.
void gotoxy(int x,int y){
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = {x-1,y-1};
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}


void InitGraph()
{
   initwindow(700,500,"Hoang Dep Trai",200,100);
}

void dda(int x1, int y1, int x2, int y2, int c)
{
    float x=x1,y=y1,m;
    if (x1!=x2)
    {   m=float(y2-y1)/(x2-x1);
        putpixel(x,round(y),c);
        if ( m>-1 && m<1)
        {   if (x1<x2)
                for (x=x1; x<=x2; x++)
                y+=m,putpixel(x,round(y),c);
            if (x1>x2)
                for (x=x1; x>=x2; x--)
                    y-=m,putpixel(x,round(y),c);
        }
        if (m<=-1 || m>=1)
        {   if (y1<y2)
                for (y=y1; y<=y2; y++)
                    x+=1/m,putpixel(round(x),y,c);
            if (y1>y2)
                for (y=y1; y>=y2; y--)
                    x-=1/m,putpixel(round(x),y,c);
        }
        }
    else
            for (int i=y1; i<=y2; i++) putpixel(x1,i,c);
}

void toquet1(int xmin,int ymin, int xmax, int ymax, int c)   // dung cho hcn
{
    for (int i=ymin+1; i<ymax; i++)
        dda(xmin,i,xmax,i,c);
}

void toquet2(int xt,int yt,int r,int c) // dung cho hinh tron
{
    int xmin=xt-r,ymin=yt-r,xmax=xt+r,ymax=yt+r,i,j;
    for (i=xmin; i<=xmax; i++)
        for (j=ymin; j<=ymax; j++)
            if (((i-xt)*(i-xt)+(j-yt)*(j-yt))<=r*r)
                putpixel(i,j,c);
}

void totrai(int x, int y, int mauto, int maubien);
void tophai(int x, int y, int mauto, int maubien);
void totren(int x, int y, int mauto, int maubien);
void toduoi(int x, int y, int mauto, int maubien);

void totrai(int x, int y, int mauto, int maubien)
{
    int maudiem;
    maudiem=getpixel(x,y);
    if ((maudiem!=mauto)&&(maudiem!=maubien))
    {   putpixel(x,y,mauto);
        totrai(x-1,y,mauto,maubien);
        totren(x,y-1,mauto,maubien);
        toduoi(x,y+1,mauto,maubien);
    }
}

void tophai(int x, int y, int mauto, int maubien)
{
    int maudiem;
    maudiem=getpixel(x,y);
    if ((maudiem!=mauto)&&(maudiem!=maubien))
    {   putpixel(x,y,mauto);
        tophai(x+1,y,mauto,maubien);
        totren(x,y-1,mauto,maubien);
        toduoi(x,y+1,mauto,maubien);
    }
}

void totren(int x, int y, int mauto, int maubien)
{
    int maudiem;
    maudiem=getpixel(x,y);
    if ((maudiem!=mauto)&&(maudiem!=maubien))
    {   putpixel(x,y,mauto);
        totrai(x-1,y,mauto,maubien);
        tophai(x+1,y,mauto,maubien);
        totren(x,y-1,mauto,maubien);
    }
}

void toduoi(int x, int y, int mauto, int maubien)
{
    int maudiem;
    maudiem=getpixel(x,y);
    if ((maudiem!=mauto)&&(maudiem!=maubien))
    {   putpixel(x,y,mauto);
        totrai(x-1,y,mauto,maubien);
        tophai(x+1,y,mauto,maubien);
        toduoi(x,y+1,mauto,maubien);
    }
}

void tomau(int x, int y, int mauto, int maubien)    //(x,y) toa do tam
{
    int maudiem;
    maudiem=getpixel(x,y);
    if ((maudiem!=mauto)&&(maudiem!=maubien))
    {   putpixel(x,y,mauto);
        totrai(x-1,y,mauto,maubien);
        tophai(x+1,y,mauto,maubien);
        totren(x,y-1,mauto,maubien);
        toduoi(x,y+1,mauto,maubien);
    }
}

void put8pixel(int x,int y,int xt,int yt, int color)    // (xt,yt) toa do tam
{
    putpixel(x+xt,y+yt,color);  putpixel(y+xt,x+yt,color);
    putpixel(x+xt,-y+yt,color); putpixel(y+xt,-x+yt,color);
    putpixel(-x+xt,y+yt,color); putpixel(-y+xt,x+yt,color);
    putpixel(-x+xt,-y+yt,color);    putpixel(-y+xt,-x+yt,color);
}

void put30pixel(int a,int b,int xt, int yt,int c)
{   int i;
    float x[30],y[30],grad=(12*3.14)/180;
    x[0]=a; y[0]=b;
    for(i=1; i<30; i++)
    {   x[i]=x[0]*cos(i*grad)-y[0]*sin(i*grad)+yt*sin(i*grad)+xt*(1-cos(i*grad));
        y[i]=x[0]*sin(i*grad)+y[0]*cos(i*grad)+yt*(1-cos(i*grad))-xt*sin(i*grad);
    }
    for (i=0; i<30; i++)    putpixel(round(x[i]),round(y[i]),c);
}

void put8ht(int x, int y, int xt, int yt, int c)
{
    toquet2(x+xt,y+yt,2,c);     toquet2(y+xt,x+yt,2,c);
    toquet2(x+xt,-y+yt,2,c);    toquet2(y+xt,-x+yt,2,c);
    toquet2(-x+xt,y+yt,2,c);    toquet2(-y+xt,x+yt,2,c);
    toquet2(-x+xt,-y+yt,2,c);   toquet2(-y+xt,-x+yt,2,c);
}

//************************************************************************


void hcn(int x1, int y1, int x2, int y2,int c)
{
    dda(x1,y1,x2,y1,c); dda(x1,y2,x2,y2,c);
    dda(x1,y1,x1,y2,c);     dda(x2,y1,x2,y2,c);
}



void hinhtron1(int xt, int yt, int r,int color) //(xt,yt) toa do tam
{
    int x=0,y=r,p=3-2*r;
    put8pixel(x,y,xt,yt,color);
    while (x<=y)
    {   if (p<0) p+=4*x+6;
        else p+=4*(x-y)+10,y--;
        x++;
        put8pixel(x,y,xt,yt,color);
    }
}

void hinhtron2(int xt, int yt, int r,int c) //(xt,yt) toa do tam
{
    int x=0,y=r,p=3-2*r;
    put8ht(x,y,xt,yt,c);
    while (x<=y)
    {   if (p<0) p+=4*x+6;
        else p+=4*(x-y)+10,y--;
        x++;
           if (x%8==0)  put8ht(x,y,xt,yt,c);
        else put8ht(x,y,xt,yt,0);
    }
}

void bonghoa(int xt, int yt,int r,int c)
{
    float x[5],y[5],grad=(72*3.14)/180;
    x[0]=xt; y[0]=yt-2*r;
    for (int i=1; i<5; i++)
    {   x[i]=x[0]*cos(i*grad)-y[0]*sin(i*grad)+yt*sin(i*grad)+xt*(1-cos(i*grad));
        y[i]=x[0]*sin(i*grad)+y[0]*cos(i*grad)+yt*(1-cos(i*grad))-xt*sin(i*grad);
    }
    hinhtron1(round(x[0]),round(y[0]),2*r,c); toquet2(round(x[0]),round(y[0]),2*r,c);
    hinhtron1(round(x[1]),round(y[1]),2*r,c); toquet2(round(x[1]),round(y[1]),2*r,c);
    hinhtron1(round(x[2]),round(y[2]),2*r,c); toquet2(round(x[2]),round(y[2]),2*r,c);
    hinhtron1(round(x[3]),round(y[3]),2*r,c); toquet2(round(x[3]),round(y[3]),2*r,c);
    hinhtron1(round(x[4]),round(y[4]),2*r,c); toquet2(round(x[4]),round(y[4]),2*r,c);
    hinhtron1(xt,yt,r,14); toquet2(xt,yt,r,14);
}

void ngoisao(int xt, int yt, int r)
{
    float x[5],y[5],grad=(72*3.14)/180;
    x[0]=xt; y[0]=yt-2*r;
    for (int i=1; i<5; i++)
    {   x[i]=x[0]*cos(i*grad)-y[0]*sin(i*grad)+yt*sin(i*grad)+xt*(1-cos(i*grad));
        y[i]=x[0]*sin(i*grad)+y[0]*cos(i*grad)+yt*(1-cos(i*grad))-xt*sin(i*grad);
    }
        dda(round(x[0]),round(y[0]),round(x[2]),round(y[2]),15);
        dda(round(x[0]),round(y[0]),round(x[3]),round(y[3]),15);
    dda(round(x[1]),round(y[1]),round(x[3]),round(y[3]),15);
    dda(round(x[1]),round(y[1]),round(x[4]),round(y[4]),15);
        dda(round(x[2]),round(y[2]),round(x[4]),round(y[4]),15);

    tomau(xt,yt,14,15);                 tomau(xt-r/2,yt+r,14,15);
    tomau(xt,yt-r,14,15);                   tomau(xt+4*r/5,yt+r,14,15);
    tomau(xt-r,round((yt+y[1])/2),14,15);           tomau(xt+r,round((yt+y[4])/2),14,15);
}

void cay(int xt, int yt,int r)
{
    toquet2(xt,yt,r,10);
    toquet1(xt-r/4,yt,xt+r/4,yt+4*r,6);
    toquet2(xt-r,yt,r,10);
    toquet2(xt+r,yt,r,10);
    toquet2(xt,yt-r,r,10);
}

void chauhoa(int xt, int yt, int r, int c)
{
    int i,j,k;
    arc(xt,yt,180,360,r);
        dda(xt-r,yt,xt+r,yt,c);
    hcn(xt-r/2,yt,xt+r/2,yt+2*r,c);
    toquet1(xt-r/2,yt,xt+r/2,yt+2*r,c);
    for(i=xt-r; i<=xt+r; i++)
        for(j=yt; j<=yt+r; j++)
            if (((i-xt)*(i-xt)+(j-yt)*(j-yt))<=r*r) putpixel(i,j,c);
    rand(); k=1;
    while (k<=30)
    {   i=rand() % 2*r+xt-r;
        j=rand()%r+yt-r;
        bonghoa(i,j,1,rand()%13+1);
        k++;
    }
}

void moon(int xt, int yt, int r)
{
    toquet2(xt,yt,r,14);
    toquet2(xt+r/2,yt,r,0);
}

void phongnen()
{
    int i;
    hcn(200,400,440,450,0); toquet1(200,400,440,450,7);
    hcn(220,390,420,400,0); toquet1(220,390,420,400,7);
    hcn(240,300,400,310,0); toquet1(240,300,400,310,7);
    hcn(240,380,400,390,0); toquet1(240,380,400,390,7);
    hcn(260,290,380,300,0); toquet1(260,290,380,300,7);
    hcn(280,280,360,290,0); toquet1(280,280,360,290,7);
    for (i=0; i<6; i++)
        hcn(260+i*22,310,270+i*22,380,0);
    for (i=0;i<6; i++)
        toquet1(260+i*22,310,270+i*22,380,7);
    for (i=0; i<5; i++)
        toquet1(270+i*22,310,282+i*22,380,6);
    hcn(300,430,340,450,0); toquet1(300,430,340,450,6);
    dda(320,431,320,449,0);
    //bacthang
    hcn(280,465,360,470,0); toquet1(280,465,360,470,8);
    hcn(285,460,355,465,0); toquet1(285,460,355,465,8);
    hcn(290,455,350,460,0); toquet1(290,455,350,460,8);
    hcn(295,450,345,455,0); toquet1(295,450,345,455,8);
    toquet1(295,465,345,470,4);toquet1(300,460,340,465,4);
    toquet1(305,455,335,460,4);toquet1(310,450,330,455,4);
    //tuongdai2ben
    for(i=0;i<5;i++)
    {   hcn(440+i*20,443-i*7,640,450-i*7,0);    toquet1(440+i*20,443-i*7,640,450-i*7,7);
        hcn(200-i*20,443-i*7,0,450-i*7,0);  toquet1(200-i*20,443-i*7,0,450-i*7,7);
    }
    //cotco
    hcn(210,460,250,480,0); toquet1(210,460,250,480,8);
    toquet1(228,280,232,460,15); toquet2(230,279,2,15);
    toquet1(232,280,272,310,4); ngoisao(252,295,5);
    cay(50,370,30);  cay(150,400,20);
    cay(590,370,30); cay(490,400,20);
    moon(30,30,20);
    for (i=0; i<4; i++)
    {   chauhoa(460+i*40,450,15,15);
        chauhoa(180-i*40,450,15,15);
    }
}
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
void runstart(){   // ve bau troi co sao lap lanh
    struct point p[MAXPOINT];
    int i,maxx, maxy;
    maxx = getmaxx();
   maxy = getmaxy();
   rand();
   for (i=0; i<MAXPOINT; i++)
   {
	 p[i].x = rand() % maxx - 10;
	 p[i].y = rand() % maxy - 250;
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
}
int main()
{
    InitGraph();
    phongnen();
    runstart();
    getch();
    closegraph();
    return 0;
}
