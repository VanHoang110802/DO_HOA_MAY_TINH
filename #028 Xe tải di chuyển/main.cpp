// tạo captcha
#include <stdlib.h>
#include <dos.h>
#include <graphics.h>
int main()
{
  int i = 0, key, n, x, gd = DETECT, gm;
  char a[10];

  initgraph(&gd, &gm, "");

  x = getmaxx()/2;

  settextstyle(SCRIPT_FONT, HORIZ_DIR, 5);
  settextjustify(CENTER_TEXT, CENTER_TEXT);
  setcolor(GREEN);
  outtextxy(x, 20, "CAPTCHA");
  settextstyle(SCRIPT_FONT, HORIZ_DIR, 2);
  outtextxy(x, 125, "Press any key to change the generated \"captcha\"");
  outtextxy(x, 150, "Press escape key to exit...");

  setcolor(WHITE);
  setviewport(100, 200, 600, 400, 1);
  setcolor(RED);
  rand();

  while (1)
  {
    while (i < 6)
    {
      n = rand()%3;

      if (n == 0)
        a[i] = 65 + rand()%26;    /* 65 is the ASCII value of A */
      else if (n == 1)
        a[i] = 97 + rand()%26;    /* 97 is the ASCII value of a */
      else
        a[i] = 48 + rand() % 10;    /* 48 is the ASCII value of 0 */
      i++;
    }
    a[i] = '\0';
    outtextxy(210, 100, a);
    key = getch();

    if (key == 27)  /* escape key */
      exit(0);
    clearviewport();
    i = 0;
  }
  return 0;
}
