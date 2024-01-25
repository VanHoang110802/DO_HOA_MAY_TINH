/*Ve cap doi ngam sao*/
#include <stdio.h>  // c - chuyển sang c++ vẫn được
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>
#define MAXPOINT 100
#define DELAY 100

struct point {
  int x, y, state, color, congtru;
};
void ktdh()
{
    initwindow(700,500,"KHONG BIET DAT TEN NHU THE NAO LUON :,D",240,160);
}
void dda(int,int,int,int,int=YELLOW);
void dda(int x1,int y1,int x2,int y2,int color)
{
    delay(100);
    float x=x1,y=y1,temp=(abs(x2-x1)>=abs(y2-y1))?abs(x2-x1):abs(y2-y1);
    putpixel(int(x+.05),int(y+0.5),color);
    for(int i=0;i<temp;i++)
    {
        x+=(x2-x1)/temp;
        y+=(y2-y1)/temp;
        putpixel(int(x+.05),int(y+0.5),color);
    }
}
void put8pixel(int x,int y,int xc,int yc,int c)
{
    putpixel( x+xc , y+yc, c);
    putpixel(-x+xc , y+yc, c);
    putpixel( x+xc ,-y+yc, c);
    putpixel(-x+xc ,-y+yc, c);
    putpixel( y+xc , x+yc, c);
    putpixel(-y+xc , x+yc, c);
    putpixel( y+xc ,-x+yc, c);
    putpixel(-y+xc ,-x+yc, c);
}
void hinhtron(int xc,int yc,int r,int c)
{
    int x=0,y=r,p=3-2*r;
    put8pixel(x,y,xc,yc,c);
    while (x<=y)
    {
        delay(100);
        if(p<0)p+=4*x+++6;
        else p+= 4*(x++-y--)+10;
        put8pixel(x,y,xc,yc,c);
    }
}

void khungcanh()
{
    line(0,395,700,395);

    //mini star
    int x,y;
    for (int i=0;i<150;i++)
    {
        delay(30);
        x=rand()%640;
        y=rand()%370;
        if (y>240&&x>330&&x<525){i--;continue;}
        putpixel(x,y,rand()%15+1);
    }

    //nguoi
    dda(363,382,366,408,8);dda(366,408,376,408,8);dda(376,408,375,382,8);
    dda(363,382,381,382,8);dda(381,382,388,406,8);dda(388,406,396,405,8);
    dda(396,405,391,379,8);dda(391,379,381,382,8);dda(366,400,374,399,0);
    putpixel(370,399,0);dda(386,399,394,399,0);
    setcolor(8);arc(371,408,180,360,5);arc(392,406,183,360,4);
    dda(360,355,360,377,8);dda(361,377,361,380,8);dda(361,380,363,381,8);
    dda(363,381,388,380,8);dda(388,379,392,379,8);dda(394,377,394,374,8);
    dda(393,374,393,369,8);dda(392,369,392,366,8);dda(391,366,391,360,8);
    dda(390,360,390,356,8);dda(390,354,393,357,8);dda(393,357,394,357,8);
    dda(395,358,396,358,8);dda(396,359,397,359,8);dda(398,360,398,361,8);
    dda(400,361,401,361,8);dda(402,362,403,362,8);dda(404,363,411,363,8);
    dda(412,364,413,364,8);dda(413,364,413,356,8);dda(414,357,413,357,8);
    dda(413,356,410,356,8);dda(410,355,407,355,8);dda(407,354,405,354,8);
    dda(405,353,403,353,8);dda(403,352,402,352,8);dda(401,351,400,351,8);
    dda(400,350,399,350,8);dda(399,350,394,345,8);dda(394,345,394,344,8);
    dda(394,344,391,342,8);dda(390,341,390,340,8);dda(390,341,388,342,8);
    dda(388,342,388,347,8);dda(357,345,356,348,8);dda(347,312,349,317,8);
    setcolor(8);ellipse(376,349,180,300,20,7);ellipse(376,342,189,300,20,7);
    arc(373,319,180,250,30);hinhtron(343,313,4,8);dda(351,266,339,322,8);
    dda(373,293,372,293,8);dda(372,292,369,292,8);dda(368,293,366,293,8);
    dda(365,294,363,294,8);dda(362,295,361,295,8);dda(361,296,359,296,8);
    dda(359,297,358,297,8);dda(358,298,357,298,8);dda(357,299,356,299,8);
    dda(356,300,354,302,8);dda(354,303,353,303,8);dda(353,304,352,305,8);
    dda(352,306,351,307,8);dda(351,308,350,309,8);dda(350,309,350,316,8);
    dda(351,317,351,320,8);dda(351,321,351,322,8);dda(352,323,352,325,8);
    dda(353,324,353,325,8);dda(354,325,354,327,8);dda(355,327,355,329,8);
    dda(356,330,356,332,8);dda(357,333,360,336,8);dda(360,336,362,336,8);
    dda(362,336,362,338,8);dda(363,338,367,342,8);dda(367,341,369,343,8);
    dda(370,343,372,345,8);dda(374,346,375,345,8);dda(376,345,377,344,8);
    dda(377,344,382,344,8);dda(383,342,385,341,8);dda(386,341,390,337,8);
    dda(389,339,391,337,8);dda(390,337,393,337,8);dda(392,337,401,328,8);
    dda(393,337,397,333,8);dda(401,328,401,327,8);dda(402,327,402,324,8);
    dda(403,324,403,321,8);dda(404,320,404,313,8);dda(403,312,403,311,8);
    dda(402,311,402,310,8);dda(401,309,401,306,8);dda(401,306,395,300,8);
    dda(394,300,393,299,8);dda(392,299,392,296,8);dda(392,297,394,297,8);
    dda(392,296,390,296,8);dda(390,296,387,293,8);dda(387,293,377,293,8);
    dda(379,292,382,292,8);dda(382,291,384,291,8);dda(375,293,372,293,8);
    setcolor(8);ellipse(416,360,0,360,2,4);dda(362,338,358,342,8);
    dda(446,383,446,397,8);dda(446,398,454,398,8);dda(455,397,455,383,8);
    dda(447,383,455,383,8);dda(461,383,462,396,8);dda(462,396,470,396,8);
    dda(470,396,470,382,8);dda(461,383,470,382,8);dda(447,397,452,397,BLACK);
    dda(454,396,450,396,BLACK);dda(445,382,470,382,8);dda(471,381,479,379,8);
    dda(478,370,479,378,8);dda(445,375,445,382,8);
    dda(445,375,456,375,8);dda(457,374,469,374,8);dda(467,373,474,373,8);
    dda(472,372,475,372,8);dda(476,371,478,371,8);dda(445,374,456,374,8);
    dda(457,373,469,373,8);dda(467,372,474,372,8);dda(472,371,475,371,8);
    dda(476,370,478,370,8);
    setcolor(8);ellipse(466,397,180,360,5,4);ellipse(451,399,180,361,5,4);
    dda(444,360,444,374,8);dda(474,345,474,352,8);dda(475,352,475,355,8);
    dda(476,355,476,358,8);dda(477,359,477,360,8);dda(478,361,479,362,8);
    dda(479,362,479,364,8);dda(479,364,482,368,8);dda(482,368,478,370,8);
    dda(433,365,443,360,8);dda(432,366,420,364,8);dda(420,364,419,357,8);
    dda(419,357,426,357,8);dda(426,357,431,355,8);dda(431,355,436,352,8);
    dda(436,352,439,349,8);dda(440,348,444,350,8);dda(444,350,452,351,8);
    dda(452,351,461,349,8);dda(461,349,469,347,8);dda(469,347,472,344,8);
    dda(472,344,475,344,8);dda(475,344,479,347,8);dda(479,347,484,350,8);
    dda(484,350,491,351,8);dda(491,351,496,352,8);dda(496,352,507,352,8);
    dda(507,352,513,350,8);dda(513,350,518,349,8);dda(518,349,524,344,8);
    dda(516,346,520,344,8);dda(512,344,518,341,8);dda(509,340,514,339,8);
    dda(514,339,518,335,8);dda(507,337,511,336,8);dda(511,336,514,334,8);
    dda(507,336,510,333,8);dda(510,333,507,331,8);dda(505,336,499,337,8);
    dda(498,338,483,338,8);dda(483,338,477,334,8);dda(477,334,473,333,8);
    dda(473,333,468,336,8);dda(468,336,461,337,8);dda(461,337,455,341,8);
    dda(455,341,442,340,8);dda(442,340,438,340,8);dda(438,341,437,344,8);
    dda(437,344,439,347,8);dda(473,332,477,333,8);dda(477,333,479,327,8);
    dda(479,327,479,324,8);dda(479,324,476,329,8);dda(476,329,473,332,8);
    dda(481,315,482,309,8);dda(482,309,482,295,8);dda(482,295,481,293,8);
    dda(481,293,480,291,8);dda(480,291,475,292,8);dda(475,292,474,293,8);
    dda(474,293,473,298,8);dda(473,298,472,302,8);dda(472,302,475,308,8);
    dda(475,308,478,311,8);dda(478,311,481,315,8);dda(472,302,463,296,8);
    dda(463,296,455,296,8);dda(455,296,452,297,8);dda(452,297,450,299,8);
    dda(450,299,444,299,8);dda(444,299,439,302,8);dda(439,302,435,305,8);
    dda(435,305,432,309,8);dda(432,309,431,313,8);dda(431,313,430,318,8);
    dda(430,318,430,327,8);dda(430,327,430,329,8);dda(430,329,424,333,8);
    dda(424,333,418,337,8);dda(418,337,427,349,8);dda(427,349,430,340,8);
    dda(430,340,434,337,8);dda(479,322,483,323,8);dda(483,323,486,323,8);
    dda(486,323,491,328,8);dda(491,328,495,321,8);dda(495,321,493,314,8);
    dda(493,314,486,316,8);dda(486,316,481,315,8);dda(426,333,432,338,8);
    dda(486,316,486,323,8);dda(459,259,474,285,8);dda(460,259,475,285,8);
    hinhtron(475,288,4,8);

		//trai tim
    delay(90);
    putpixel(391,228,8);delay(90);putpixel(389,225,8);putpixel(386,223,8);
    putpixel(382,221,8);delay(90);putpixel(378,221,8);putpixel(375,219,8);
    putpixel(370,221,8);delay(90);putpixel(367,222,8);putpixel(364,221,8);
    putpixel(364,224,8);delay(90);putpixel(361,224,8);putpixel(361,227,8);
    putpixel(358,227,8);delay(90);putpixel(359,230,8);putpixel(355,231,8);
    putpixel(357,233,8);delay(90);putpixel(353,233,8);putpixel(352,236,8);
    putpixel(355,237,8);delay(90);putpixel(355,242,8);putpixel(352,243,8);
    putpixel(354,247,8);delay(90);putpixel(350,248,8);putpixel(355,252,8);
    putpixel(351,254,8);delay(90);putpixel(356,257,8);putpixel(352,259,8);
    putpixel(352,263,8);delay(90);putpixel(354,264,8);putpixel(354,266,8);
    putpixel(353,269,8);delay(90);putpixel(352,270,8);putpixel(346,269,8);
    putpixel(346,266,8);delay(90);putpixel(344,264,8);putpixel(346,262,8);
    putpixel(348,262,8);delay(90);putpixel(358,270,8);putpixel(357,275,8);
    putpixel(361,274,8);delay(90);putpixel(362,279,8);putpixel(365,278,8);
    putpixel(366,283,8);delay(90);putpixel(371,281,8);putpixel(370,285,8);
    putpixel(375,283,8);delay(90);putpixel(373,288,8);putpixel(376,289,8);
    putpixel(380,285,8);delay(90);putpixel(385,288,8);putpixel(390,289,8);
    putpixel(397,292,8);delay(90);putpixel(405,292,8);putpixel(404,295,8);
    putpixel(409,293,8);delay(90);putpixel(415,291,8);putpixel(417,295,8);
    putpixel(422,290,8);delay(90);putpixel(425,293,8);putpixel(430,286,8);
    putpixel(431,289,8);delay(90);putpixel(435,283,8);putpixel(438,285,8);
    putpixel(440,281,8);delay(90);putpixel(441,279,8);putpixel(445,281,8);
    putpixel(445,287,8);delay(90);putpixel(449,277,8);putpixel(447,274,8);
    putpixel(452,273,8);delay(90);putpixel(408,234,8);putpixel(410,232,8);
    putpixel(413,231,8);delay(90);putpixel(416,230,8);putpixel(421,228,8);
    putpixel(425,227,8);delay(90);putpixel(428,225,8);putpixel(428,228,8);
    putpixel(432,228,8);delay(90);putpixel(435,226,8);putpixel(439,230,8);
    putpixel(441,228,8);delay(90);putpixel(444,235,8);putpixel(447,232,8);
    putpixel(452,236,8);delay(90);putpixel(448,241,8);putpixel(451,245,8);
    putpixel(455,243,8);delay(90);putpixel(455,249,8);putpixel(453,266,8);
    putpixel(450,268,8);delay(90);putpixel(456,271,8);putpixel(457,261,8);
    putpixel(454,259,8);delay(90);putpixel(454,257,8);putpixel(456,257,8);
    putpixel(457,254,8);delay(90);putpixel(460,253,8);putpixel(461,255,8);
    putpixel(463,255,8);delay(90);putpixel(463,257,8);putpixel(463,260,8);
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
void runstart(){
    struct point p[MAXPOINT];
    int i,maxx, maxy;
    maxx = getmaxx();
   maxy = getmaxy();
   rand();
   for (i=0; i<MAXPOINT; i++)
   {
	 p[i].x = rand() % maxx - 10;
	 p[i].y = rand() % maxy - 200;
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
    ktdh();
    khungcanh();
    delay(1000);
    runstart();
    getch();
    closegraph();
    return 0;
}
