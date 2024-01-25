#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
#define pi 3.14
#define CLIP_ON 1
int n,c,t,mau;
float hs,go;
//--------------------------------------------------------------------------
int dau()
{
   if (rand()%2 == 0)
      return -1;
   else
      return 1;
}
//--------------------------------------------------------------------------
void cay(int x,int y,float h,float g,float gw,int k)
{
   int x1,y1,i,j,d,leaf,c;
   float dg,tt;
   if (k > 0)
      for (j = 1; j <= rand()%t + t ; j++)
	 {
	    x1 = x + h * cos(g);
	    y1 = y + h * sin(g);
	    setcolor(DARKGRAY);
	    for (i = 0; i <= (h/35)*(h/35); i++)
	       {
		  line(x + i, y, x1 + i, y1);
		  for (d = 1; d <= (h/5); d++)
		     {
			tt = rand()%1;
			putpixel((1-tt)*x+tt*x1+i,(1-tt)*y+tt*y1,LIGHTGRAY);
		     }
	       }
	    dg = gw/(2*n+1);
	    for (i = -n; i <= n; i++)
	      if (rand()%1000*0.001 > 0.5)
	       cay(x1,y1,h*(0.5+(rand()%1000*0.001)/3),g+i*dg,gw*hs,k-1);
	    x = x1;
	    y = y1;
	    g = g + M_PI/18;
	 }
   else
     {
	setfillstyle(1,rand()%15);
	setcolor(rand()%15);
	for (leaf = 1; leaf <= 2; leaf++)
	   fillellipse(x+rand()%8*dau(),y+rand()%5*dau(),rand()%5+2,rand()%2+1);
	for (leaf = 1; leaf <= 70; leaf++)
	   {
	      switch (leaf)
		{
		   case 0:
		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),BLUE);
			  break;
		     }
		     case 1:
		     		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),BLUE);
			  break;
		     }
		     case 2:
		     		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),BLUE);
			  break;
		     }
		     case 3:
		     		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),BLUE);
			  break;
		     }
		     case 4:
		     		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),BLUE);
			  break;
		     }
		     case 5:
		     		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),BLUE);
			  break;
		     }
		     case 6:
		     		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),BLUE);
			  break;
		     }
		     case 7:
		     		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),BLUE);
			  break;
		     }
		     case 8:
		     		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),BLUE);
			  break;
		     }
		     case 9:
		     		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),BLUE);
			  break;
		     }
		     case 10:
		     		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),BLUE);
			  break;
		     }
		     case 11:
		     		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),BLUE);
			  break;
		     }
		     case 12:
		     		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),BLUE);
			  break;
		     }
		     case 13:
		     		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),BLUE);
			  break;
		     }
		     case 14:
		     		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),BLUE);
			  break;
		     }
		     case 15:
		     		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),BLUE);
			  break;
		     }
		     case 16:
		     		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),BLUE);
			  break;
		     }
		     case 17:
		     		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),BLUE);
			  break;
		     }
		     case 18:
		     		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),BLUE);
			  break;
		     }
		     case 19:
		    		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),BLUE);
			  break;
		     }
		     case 20:
		     		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),BLUE);
			  break;
		     }
		   case 21:
		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),LIGHTBLUE);
			  break;
		     }
		      case 22:
		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),LIGHTBLUE);
			  break;
		     }
		      case 23:
		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),LIGHTBLUE);
			  break;
		     }
		      case 24:
		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),LIGHTBLUE);
			  break;
		     }
		      case 25:
		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),LIGHTBLUE);
			  break;
		     }
		   case 26:
		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),LIGHTGREEN);
			  break;
		     }
		     case 27:
		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),LIGHTGREEN);
			  break;
		     }
		     case 28:
		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),LIGHTGREEN);
			  break;
		     }
		     case 29:
		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),LIGHTGREEN);
			  break;
		     }
		     case 30:
		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),LIGHTGREEN);
			  break;
		     }
		     case 31:
		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),LIGHTGREEN);
			  break;
		     }
		     case 32:
		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),LIGHTGREEN);
			  break;
		     }
		     case 33:
		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),LIGHTGREEN);
			  break;
		     }
		     case 34:
		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),LIGHTGREEN);
			  break;
		     }
		     case 35:
		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),LIGHTGREEN);
			  break;
		     }
		     case 36:
		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),LIGHTGREEN);
			  break;
		     }
		     case 37:
		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),LIGHTGREEN);
			  break;
		     }
		     case 38:
		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),LIGHTGREEN);
			  break;
		     }
		     case 39:
		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),LIGHTGREEN);
			  break;
		     }
		     case 40:
		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),LIGHTGREEN);
			  break;
		     }
		     case 41:
		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),LIGHTGREEN);
			  break;
		     }
		     case 42:
		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),LIGHTGREEN);
			  break;
		     }
		     case 43:
		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),LIGHTGREEN);
			  break;
		     }
		     case 44:
		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),LIGHTGREEN);
			  break;
		     }
		     case 45:
		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),LIGHTGREEN);
			  break;
		     }
		     case 46:
		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),LIGHTGREEN);
			  break;
		     }
		     case 47:
		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),LIGHTGREEN);
			  break;
		     }
		     case 48:
		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),LIGHTGREEN);
			  break;
		     }
		     case 49:
		     {
			  putpixel(x+rand()%15*dau(),y+rand()%5*dau(),LIGHTGREEN);
			  break;
		     }
		}
	   }
     }
}
//--------------------------------------------------------------------------
void cloud(int x,int y,float Rx,float Ry,int k)
{
   int i;
   if (k > 0)
     for (i = 1; i <= 5; i++)
	cloud(x+(rand()%(int)Rx),y+(rand()%(int)Ry),Rx*0.8,Ry*0.6,k-1);
   else
     for (i = 1; i <= (sqrt(Rx*Ry)/3.5); i++)
	putpixel(x+(rand()%(int)Rx),y+(rand()%(int)Ry),WHITE);  // phải ép kiểu ở đây :vv
}
//--------------------------------------------------------------------------
void phong()
{
   int l,i;
   l = (getmaxy() / 7) * 5;
   setfillstyle(1,(mau=rand()%15));
   bar(0,0,getmaxx(),l);
   setfillstyle(1,LIGHTGRAY);
   bar(0,l,getmaxx(),getmaxy());
   for (i = 1; i < 20000; i++)
      switch (rand()%8)
	 {
	    case 0:
	      {
		putpixel(rand()%getmaxx(),l+rand()%getmaxy()-l,GREEN);
		break;
	      }
	      case 1:
	      {
		putpixel(rand()%getmaxx(),l+rand()%getmaxy()-l,GREEN);
		break;
	      }
	      case 2:
	      {
		putpixel(rand()%getmaxx(),l+rand()%getmaxy()-l,GREEN);
		break;
	      }
	      case 3:
	      {
		putpixel(rand()%getmaxx(),l+rand()%getmaxy()-l,GREEN);
		break;
	      }
	      case 4:
	      {
		putpixel(rand()%getmaxx(),l+rand()%getmaxy()-l,GREEN);
		break;
	      }
	    case 5:
	      {
		putpixel(rand()%getmaxx(),l+rand()%getmaxy()-l,YELLOW);
		break;
	      }
	      case 6:
	      {
		putpixel(rand()%getmaxx(),l+rand()%getmaxy()-l,YELLOW);
		break;
	      }
	    case 7:
	      {
		putpixel(rand()%getmaxx(),l+rand()%getmaxy()-l,LIGHTRED);
		break;
	      }
	 }
   if (mau!=RED)
    {
      if (mau!=BLACK)
     {
       setfillstyle(1,RED);
       setcolor(RED);
     }
    }
   else
     {
       setfillstyle(1,YELLOW);
       setcolor(YELLOW);
     }
   fillellipse(rand()%getmaxx() / 2+300,100,30,30);
   for (i = 1; i <= 5; i++)
      cloud(rand()%getmaxx(),rand()%150+10,rand()%60+60,rand()%40+20,5);
}
//--------------------------------------------------------------------------
int main()
{
   int i,graphdriver,graphmode;
   char ch;
   rand();
   graphdriver = DETECT; //graphmode;
   initgraph(&graphdriver, &graphmode,"");
   setviewport(0,0,getmaxx(),getmaxy(),CLIP_ON);
   do
     {
	n = 1;
	hs = 1.2;
	go = M_PI /2.8;
	t = 2;
	phong();
	cay(((getmaxx()-100) /5)+rand()%60,(getmaxy()/ 7)*6+rand()%30*dau(),getmaxy() / 6,-M_PI/2,go,5);
	ch= getch();
      }while (ch!=27);
   closegraph();
}
