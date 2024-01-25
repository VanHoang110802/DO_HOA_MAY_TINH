/*Game caro*/
#include <stdio.h>
#include <graphics.h>
#define MAX 25
#define HEIGHT 16

int a[MAX][MAX];
int xleft, yleft;
int order;

void print_X_O()
{
  switch(order)
  {
    case 0 :  setcolor(9);
              outtextxy(xleft+MAX*HEIGHT+205, 40, "O");
              break;
    case 1 :  setcolor(12);
              outtextxy(xleft+MAX*HEIGHT+205, 40, "X");
              break;
  }
}

void printf_banco()
{
   int i, j;
   xleft = 10;
   yleft = (getmaxy() - MAX * HEIGHT) / 2;
   setcolor(15);
   for (i=0; i<=MAX; i++)
   {
     line(xleft, yleft + i*HEIGHT, xleft + MAX*HEIGHT, yleft + i*HEIGHT);
     line(xleft + i*HEIGHT, yleft, xleft + i*HEIGHT, yleft + MAX*HEIGHT);
   }
   setcolor(14);
   rectangle(xleft-1, yleft-1,xleft+MAX*HEIGHT+1,yleft+MAX*HEIGHT+1);
   rectangle(xleft-2, yleft-2,xleft+MAX*HEIGHT+2,yleft+MAX*HEIGHT+2);
   order = 0;
   for (i=0; i<MAX; i++)
     for (j=0; j<MAX; j++)
       a[i][j] = -1;
}

void taodongcot(int x, int y, int *row, int *col)
{
  *col = (x - xleft) / HEIGHT;
  *row = (y - yleft) / HEIGHT;
}

int check(int row, int col)
{
  int i, j, tong = 0;
  for (i=-4; i<=4; i++)
    if (col + i >= 0 && col+i < MAX)
      if (a[row][col+i] == order)
        tong++;
      else
        break;
  if (tong >= 5)
    return 1;
  tong = 0;
  for (i=-4; i<=4; i++)
    if (row + i >= 0 && row+i < MAX)
      if (a[row+i][col] == order)
        tong++;
      else
        break;
  if (tong >= 5)
    return 1;
  tong = 0;
  for (i=-4; i<=4; i++)
    if (row + i >= 0 && row+i < MAX && col + i > 0 && col + i < MAX)
      if(a[row+i][col+i] == order)
        tong++;
      else
        break;
  if (tong >= 5)
    return 1;
  tong = 0;
  for (i=-4, j=4; i<=4; i++, j--)
    if (row + j > 0 && row+j < MAX && col + i > 0 && col + i < MAX)
      if (a[row+j][col+i] == order)
        tong++;
      else
        break;
  if (tong >= 5)
    return 1;
  return 0;
}

void print_winloss()
{
  switch(order)
  {
    case 0 : setcolor(15);
             outtextxy(xleft+MAX*HEIGHT+30, 140, "O winner");
             break;
    case 1 : setcolor(15);
             outtextxy(xleft+MAX*HEIGHT+30, 140, "X winner");
             break;
  }
  setcolor(YELLOW);
  outtextxy(xleft+MAX*HEIGHT+30, 160, "Game Over");
}

int main()
{
  int x = 0, y = 0;
  int gameover = 0;
  int row, col;
  initwindow(700,500,"GAME X-O",200,100);
  rectangle(0, 0, getmaxx(), getmaxy());
  outtextxy(xleft+MAX*HEIGHT+30, 40, "Luot di hien tai cua quan co: ");
  printf_banco();

  while (!gameover)
  {
    print_X_O();
    getmouseclick(WM_LBUTTONDOWN, x, y);
    if (WM_LBUTTONDOWN)
    {
       taodongcot(x, y, &row, &col);
       if (a[row][col]==-1 && row>=0 && col>=0 && row<MAX && col<MAX)
       {
         a[row][col] = order;
         if (check(row, col))
         {
           print_winloss();
           gameover = 1;
         }
         switch(order)
         {
            case 0 :  setcolor(9);
                      outtextxy(col*HEIGHT+xleft+5, row*HEIGHT+yleft +1, "O");
                      order = 1;
                      break;
            case 1 :  setcolor(12);
                      outtextxy(col*HEIGHT+xleft+5, row*HEIGHT+yleft+1, "X");
                      order = 0;
                      break;
         }
       }
    }
  }
  getch();
  closegraph();
  return 0;
}
