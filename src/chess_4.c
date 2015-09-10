#include <stdio.h>
#include <dos.h>
#include <graphics.h>
#include <time.h>

#define G_X1  200
#define G_Y1  150
#define G_X2  440
#define G_Y2  290
#define G_JG  30
#define GOBANG_Y 190
#define G_LINE_Y 210
#define SOFT_X 239
#define SOFT_Y 230
#define SKIP_TIME 5000
char record[165][25];

extern void triangle(int x1,int y1,int x2,int y2,int color);
extern void prstriangle(int x1,int y1,int x2,int y2,int color);
extern void win3d(int x1,int y1,int x2,int y2,int wide,int border_color,int main_color,int fillstyle);
extern void prswin3d(int x1,int y1,int x2,int y2,int wide,int border_color,int main_color);
extern void box0(int x,int y,int l,int h,int color);
extern void box1(int x,int y,int l,int h,int color,int style);
extern void prsbox1(int x,int y,int l,int h);
extern void upbox1(int x,int y,int l,int h);
extern void popbox1(int x,int y,int l,int h);
extern void prsbox2(int x,int y,int l,int h);
extern void popup1(int x,int y,int l,int h);
extern get_key();
extern graphinit();
extern void read_palette();
extern void set_palette(unsigned char *pal);
extern void waitch();
extern void ch_color(int delay_time,int sound_control);
extern void scrdisable();
extern void screnable();
extern int mouseinit();
extern void mouseshow();
extern void mousehide();
extern int mouseleft();
extern int mouseright();
extern void mousexy(int *x,int *y);
extern int inxy(int x1,int y1,int x2,int y2);
extern int prsmouse(int botton);
extern int releasemouse(int botton);


/*
diamond(int x0,int y0,int r,int n,int flag,int color)
{
float t;
int i,j;
int x[50],y[50];
t=6.28/n;
setcolor(color);
for(i=0;i<n;i++)
 {
  x[i]=r*cos(i*t)+x0;
  y[i]=r*sin(i*t)+y0;
 }
for(i=0;i<=n-2;i++)
 for(j=i+1;j<=n-1;j++)
  {
  if (flag)
    setcolor((i+j)%color);
  line(x[i],y[i],x[j],y[j]);
  }
return;
}

heart(int x0,int y0,int r,int color)
{
 int x,y,y1,r1;
 double a;
 setcolor(color);
 y1=y0-r;
 for(a=0;a<2*3.14;a+=3.14/18)
  {

  x=r*cos(a)+x0;
  y=r*sin(a)+y0;
  r1=sqrt((x-x0)*(x-x0)+(y-y1)*(y-y1));
  circle(x,y,r1);
 }
return;
}
*/
effect_fan(int x1,int y1,int x2,int y2,int style,int delay_time)
{
int i,j,k;
 for(i=x1;i<=x2;i++)
    for(j=y1;j<=y2;j++)
       	{
	putpixel(i,j,15-(i+j)%style);
	delay(delay_time);
	}

}
go_forward(int x1,int y1,int x2,int y2,int oldcolor,int newcolor,int delay_time)
{
 int i,j;
 for(i=x1;i<=x2;i++)
  for(j=y1;j<=y2;j++)
   {
    if (getpixel(i,j)==oldcolor)
     {
     putpixel(i,j,newcolor);
     delay(delay_time);
     }
   }
}
goldensoft()
{
 int i,j,k;
 time_t tm1,tm2;
  for(i=0;i<165;i++)
   for(j=0;j<25;j++)
	record[i][j]=0;
 settextstyle(0,0,2);
   settextjustify(1,1);
  setcolor(1);
   for(i=4;i>0;i--)
      outtextxy(320+i,240+i,"GOLDENSOFT");
setcolor(12);
     outtextxy(320,240,"GOLDENSOFT");
rectangle(235,225,405,255);
 for(i=239;i<404;i++)
   for(j=229;j<254;j++)
    {
     k=getpixel(i,j);
     if (k!=0)
      record[i-239][j-229]=k;
    }
 tm1=time(NULL);
 tm2=tm1;
 while (difftime(tm2,tm1)<3)
  {
   if (kbhit())
    {
     i=getch();
     return;
    }
   if (mouseleft()||mouseright())
     {
      delay(SKIP_TIME);
      return;
     }
   tm2=time(NULL);
  }
pict_exit(230,220,410,260,70);
}

pict_exit(int x1,int y1,int x2,int y2,int delay_time)
{
 int i,j,k;
 for(k=8;k>=1;k--)
  {
  for(i=x1;i<x2;i++)
    for(j=y2;j>y1;j--)
	 {
	  if ((i+j)%k==0)
	  putpixel(i,j,0);

	 if (kbhit())
	   {
	    i=getch();
	     return;
	     }
   if (mouseleft()||mouseright())
     {
      delay(SKIP_TIME);
      return;
     }

	}
    delay(delay_time);
   }
}
frame_updown(int x1,int y1,int x2,int y2,int flag)
{
 int color1,color2;
 color1=(flag==1)?15:8;
 color2=(color1==15)?8:15;
 setcolor(color2);
 line(x1,y1,x2,y1);
 line(x1,y1,x1,y2);
line(x2-1,y1+1,x2-1,y2-1);
line(x1+1,y2-1,x2-1,y2-1);
 setcolor(color1);
 line(x2,y1+1,x2,y2);
 line(x1+1,y2,x2,y2);
line(x1+1,y1+1,x2-1,y1+1);
line(x1+1,y1+1,x1+1,y2-1);

}
show_goldensoft()
{
int i,j,k;
char color[]={15,1,10,14,12,0};
time_t tm1,tm2;
goldensoft();
setfillstyle(1,0);
bar(200,200,500,400);
delay(2000);
effect_fan(G_X1,G_Y1,G_X2,G_Y2,8,0);
setfillstyle(1,1);
frame_updown(G_X1+5,G_Y1+5,G_X2-5,G_Y2-5,0);
 settextstyle(0,0,2);
 settextjustify(1,1);

 setcolor(1);
 for(i=0;i<4;i++)
 outtextxy(320,GOBANG_Y-i,"PY GOB");
 setcolor(15);
 outtextxy(320,GOBANG_Y-i,"PY GOB");
 setcolor(1);
 for(i=0;i<3;i++)
 outtextxy(251-i,GOBANG_Y-i,"HAP");
 setcolor(15);
 outtextxy(251-i,GOBANG_Y-4,"HAP");
 setcolor(1);
 for(i=0;i<3;i++)
 outtextxy(390+i,GOBANG_Y-i,"ANG");
 setcolor(15);
 outtextxy(390+i,GOBANG_Y-4,"ANG");
 for(i=0;i<94;i++)
  {
   setcolor(15);
   line(320-i,G_LINE_Y,320+i,G_LINE_Y);
   setcolor(8);
   line(320-i,G_LINE_Y-1,320+i,G_LINE_Y-1);
   delay(500);
   if (kbhit())
     {
     i=getch();
     return;
     }
   if (mouseleft()||mouseright())
     {
      delay(SKIP_TIME);
      return;
     }

  }
for(k=3;k<9;k++)
{
for(i=0;i<165;i++)
   for(j=0;j<25;j++)
    {
    if (record[i][j]==1)
       {
    putpixel(i+SOFT_X,j+SOFT_Y,color[k%6]);
    delay(20);
	}
       else
	 if (record[i][j]!=0)
       {
	putpixel(i+SOFT_X,j+SOFT_Y,(i+j+k)%7);
	delay(20);
	}
    if (kbhit())
       {
	i=getch();
	return;
       }
   if (mouseleft()||mouseright())
     {
      delay(SKIP_TIME);
      return;
     }

    }
}
tm1=time(NULL);
tm2=tm1;
 while (difftime(tm2,tm1)<3)
  {
   if (kbhit())
    {
     i=getch();
     return;
    }
   if (mouseleft()||mouseright())
     {
      delay(SKIP_TIME);
      return;
     }

   tm2=time(NULL);
  }
}

