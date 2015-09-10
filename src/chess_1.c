
			 /****** chess.h **********/
			 /******function *********/
       /********** test_1-------- test_9 ***********/
       /*****************       STRUCT CHESS      ***********************/
       /*************     FLAG=1:MAN  FLAG=2:MACHINE          ***********/
       /****** COUNT : INDICATE ORDER FOR FUNCTION UNDO AND CURRENT *****/
       /*****************    X AND Y : POSITION   ***********************/

#include <stdio.h>
#include <dos.h>
#include <graphics.h>
#include <time.h>

#include "chess_h.h"

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


extern struct chess table[N][N];
extern int chess_ready;
/*
extern int BOARD_BACKCOLOR,LINE_COLOR,BOARD_STYLE,WELCOME_COLOR,MAN_CHESS_COLOR,MAN_CHESS_STYLE;
extern int MACHINE_CHESS_COLOR,MACHINE_CHESS_STYLE,B_COLOR,B_BOTTON_BACKCOLOR,B_BOTTON_STYLE,B_BOTTON_FORECOLOR;
  */
/******* GAME INIT: LINK THE POINTER FOR THE WEB *******/

gameinitweb()
{
int i,j;
 /****** THE FIRST LINE '---' ****/
 for(j=0;j<N;j++)
  {
  table[0][j].up=NULL;
  table[0][j].leftup=NULL;
  table[0][j].rightup=NULL;
  table[0][j].down=&table[1][j];
   if (j!=0)
   {
  table[0][j].left=&table[0][j-1];
  table[0][j].leftdown=&table[1][j-1];
   }
   else
  {
  table[0][j].left=NULL;
  table[0][j].leftdown=NULL;
  }
   if (j!=N-1)
   {
  table[0][j].right=&table[0][j+1];
  table[0][j].rightdown=&table[1][j+1];
   }
   else
  {
  table[0][j].right=NULL;
  table[0][j].rightdown=NULL;
  }
 }

/*****   THE LAST LINE '---' *****/
 for(j=0;j<N;j++)
  {
  table[N-1][j].down=NULL;
  table[N-1][j].leftdown=NULL;
  table[N-1][j].rightdown=NULL;
  table[N-1][j].up=&table[N-2][j];
   if (j!=0)
   {
  table[N-1][j].left=&table[N-1][j-1];
  table[N-1][j].leftup=&table[N-2][j-1];
   }
   else
  {
  table[N-1][j].left=NULL;
  table[N-1][j].leftup=NULL;
  }
   if (j!=N-1)
   {
  table[N-1][j].right=&table[N-1][j+1];
  table[N-1][j].rightup=&table[N-2][j+1];
   }
   else
  {
  table[N-1][j].right=NULL;
  table[N-1][j].rightup=NULL;
  }
 }
 /******* THE LEFTEST LINE '|' (NOT INCLUDE THE FIRST AND LAST TWO POTNT)******/
 for(i=1;i<N-1;i++)
  {
  table[i][0].up=&table[i-1][0];
  table[i][0].down=&table[i+1][0];
  table[i][0].left=NULL;
  table[i][0].right=&table[i][1];
  table[i][0].leftup=NULL;
  table[i][0].leftdown=NULL;
  table[i][0].rightup=&table[i-1][1];
  table[i][0].rightdown=&table[i+1][1];
  }

 /***** THE LAST LINE '|'(NOT INCLUDE THE FIRST AND LAST TWO POTNT) *********/
 for(i=1;i<N-1;i++)
  {
  table[i][N-1].up=&table[i-1][N-1];
  table[i][N-1].down=&table[i+1][N-1];
  table[i][N-1].left=&table[i][N-2];
  table[i][N-1].right=NULL;
  table[i][N-1].leftup=&table[i-1][N-2];
  table[i][N-1].leftdown=&table[i+1][N-2];
  table[i][N-1].rightup=NULL;
  table[i][N-1].rightdown=NULL;
  }

  /******* MIDDLE LINE (NOT INCLUDE THE FIRST AND LAST TWO POTNT)** *****/
  for(i=1;i<N-1;i++)
   for(j=1;j<N-1;j++)
   {
  table[i][j].up=&table[i-1][j];
  table[i][j].down=&table[i+1][j];
  table[i][j].left=&table[i][j-1];
  table[i][j].right=&table[i][j+1];
  table[i][j].leftup=&table[i-1][j-1];
  table[i][j].leftdown=&table[i+1][j-1];
  table[i][j].rightup=&table[i-1][j+1];
  table[i][j].rightdown=&table[i+1][j+1];
  }
  }


 int iswin(int x,int y,int *dire)
 {
 int sum,flag;
 struct chess *p;
 flag=table[x][y].flag;
 /*** HENG ****/
 sum=1;
  p=table[x][y].left;

    while ((p->flag==flag)&&(p!=NULL))
  {
  p=p->left;
  sum++;
  }
 p=table[x][y].right;
 while ((p->flag==flag)&&(p!=NULL))
 {
  p=p->right;
  sum++;
  }
 if (sum>=5)
  {
  *dire=1;
   chess_ready=0;
  return 1;
  }
  /**** SHU *****/
 sum=1;
  p=table[x][y].up;
  while ((p->flag==flag)&&(p!=NULL))
  {
  p=p->up;
  sum++;
  }
 p=table[x][y].down;
 while ((p->flag==flag)&&(p!=NULL))
 {
  p=p->down;
  sum++;
  }
 if (sum>=5)
  {
  *dire=2;
  chess_ready=0;
  return 1;
 }
 /****** XIE '\'*******/
 sum=1;
  p=table[x][y].leftup;
  while ((p->flag==flag)&&(p!=NULL))
  {
  p=p->leftup;
  sum++;
  }
 p=table[x][y].rightdown;
 while ((p->flag==flag)&&(p!=NULL))
 {
  p=p->rightdown;
  sum++;
  }
 if (sum>=5)
  {
  *dire=3;
    chess_ready=0;
  return 1;
 }
 /**** XIE '/'******/
 sum=1;
  p=table[x][y].rightup;
  while ((p->flag==flag)&&(p!=NULL))
  {
  p=p->rightup;
  sum++;
  }
 p=table[x][y].leftdown;
 while ((p->flag==flag)&&(p!=NULL))
 {
  p=p->leftdown;
  sum++;
  }
 if (sum>=5)
  {
  chess_ready=0;
  *dire=4;
  return 1;
 }
 /***** PAN DUANG WANG ******/
  return 0;
  }





int translate(int *in,int *jn)
{
   int i,j,iw,jw;
   mousexy(&j,&i);
    *jn=j-X_1;
    *in=i-Y_1;
    i=*in/HIGH;
    j=*jn/HIGH;
    iw=*in-i*HIGH;
    jw=*jn-j*HIGH;
   if (iw>=(HIGH-EFFECT_REGION))
     i++;
   if (jw>=(HIGH-EFFECT_REGION))
     j++;
   *in=i;
   *jn=j;
   if ((iw>=(HIGH-EFFECT_REGION))||iw<=EFFECT_REGION)
   if ((jw>=(HIGH-EFFECT_REGION))||jw<=EFFECT_REGION)
      return 1;
  return 0;
}



int between(int x)
{
  if ((x>=0)&&(x<N))
      return 1;
      else
      return 0;

}


	  /****** DRAW THE CHESS *****/

void drawcircle(int i,int j,int fillcolor,int fillstyle)
{
int a;
struct fillsettingstype b;
if ((table[i][j].flag==0)&&(i<N)&&(i>=0)&&(j>=0)&&(j<N))
   {
a=getcolor();
getfillsettings(&b);
setcolor((fillcolor<10)?(fillcolor+1):(fillcolor-1));
line(table[i][j].x-RADIOUS,table[i][j].y,table[i][j].x+RADIOUS,table[i][j].y);
line(table[i][j].x,table[i][j].y-RADIOUS,table[i][j].x,table[i][j].y+RADIOUS);

setcolor(fillcolor);
setfillstyle(fillstyle,fillcolor);
circle(table[i][j].x,table[i][j].y,RADIOUS);
floodfill(table[i][j].x,table[i][j].y,fillcolor);
setcolor(a);
setfillstyle(b.pattern,b.color);
  }
  else
     printf("ERROR i=%d j=%d ",i,j);
}

void win_drawcircle(int i,int j,int fillcolor,int fillstyle)
{
int a;
struct fillsettingstype b;
if ((i<N)&&(i>=0)&&(j>=0)&&(j<N))
   {
a=getcolor();
getfillsettings(&b);
setcolor((fillcolor<10)?(fillcolor+1):(fillcolor-1));
line(table[i][j].x-RADIOUS,table[i][j].y,table[i][j].x+RADIOUS,table[i][j].y);
line(table[i][j].x,table[i][j].y-RADIOUS,table[i][j].x,table[i][j].y+RADIOUS);

setcolor(fillcolor);
setfillstyle(fillstyle,fillcolor);
circle(table[i][j].x,table[i][j].y,RADIOUS);
floodfill(table[i][j].x,table[i][j].y,fillcolor);
setcolor(a);
setfillstyle(b.pattern,b.color);
  }
  else
     printf("ERROR i=%d j=%d ",i,j);
}



int test_1(int i,int j,int *next_i,int *next_j)
{
      /******* CASE :1 AND 2 ********/

int prove,flag,sum,empty,count;
struct chess *p;
flag=table[i][j].flag;

   /*** LINE '|' ***/
p=&table[i][j];
sum=0;
empty=0;
prove=0;
while ((p->flag==flag)&&(p!=NULL))
   {
	p=p->up;
	sum++;
   }
if ((p->flag==0)&&(p!=NULL))
  {
   *next_i=i-sum;
   *next_j=j;
   prove=1;
   empty++;
   }
count=0;
p=&table[i][j];
while ((p->flag==flag)&&(p!=NULL))
{
 p=p->down;
 sum++;
 count++;
}
if ((p->flag==0)&&(p!=NULL))
 {
     *next_i=i+count;
     *next_j=j;
     prove=1;
     empty++;
 }
if ((sum>=5)&&(empty>0)&&prove)
 return 5;

   /*** LINE '\' ***/

p=&table[i][j];
sum=0;
empty=0;
prove=0;
while ((p->flag==flag)&&(p!=NULL))
   {
	p=p->leftup;
	sum++;
   }
if ((p->flag==0)&&(p!=NULL))
  {
   *next_i=i-sum;
   *next_j=j-sum;
   prove=1;
   empty++;
   }
count=0;
p=&table[i][j];
while ((p->flag==flag)&&(p!=NULL))
{
 p=p->rightdown;
 sum++;
 count++;
}
if ((p->flag==0)&&(p!=NULL))
 {
     *next_i=i+count;
     *next_j=j+count;
     prove=1;
     empty++;
 }


if ((sum>=5)&&(empty>0)&&prove)
 return 5;

   /*** LINE '/' ***/
p=&table[i][j];
sum=0;
empty=0;
prove=0;
p=&table[i][j];
sum=0;
empty=0;
while ((p->flag==flag)&&(p!=NULL))
   {
	p=p->rightup;
	sum++;
   }
if ((p->flag==0)&&(p!=NULL))
  {
   *next_i=i-sum;
   *next_j=j+sum;
   prove=1;
   empty++;
   }
count=0;
p=&table[i][j];
while ((p->flag==flag)&&(p!=NULL))
{
 p=p->leftdown;
 sum++;
 count++;
}
if ((p->flag==0)&&(p!=NULL))
 {
     *next_i=i+count;
     *next_j=j-count;
     prove=1;
     empty++;
 }



if ((sum>=5)&&(empty>0)&&prove)
 return 5;



   /*** LINE '-----' ***/
p=&table[i][j];
sum=0;
empty=0;
prove=0;
while ((p->flag==flag)&&(p!=NULL))
   {
	p=p->left;
	sum++;
   }
if ((p->flag==0)&&(p!=NULL))
  {
   *next_i=i;
   *next_j=j-sum;
   prove=1;
   empty++;
   }
count=0;
p=&table[i][j];
while ((p->flag==flag)&&(p!=NULL))
{
 p=p->right;
 sum++;
 count++;
}
if ((p->flag==0)&&(p!=NULL))
 {
     *next_i=i;
     *next_j=j+count;
     prove=1;
     empty++;
 }


if ((sum>=5)&&(empty>0)&&prove)
 return 1;
return 0;

}


    /***** TEST 3 *********/

int test_3(int i,int j,int *next_i,int *next_j)
{
       /******* CASE 3 ********/

int flag,sum,count,prove,empty_sum;
struct chess *p,*q;
flag=table[i][j].flag;



 /******** LINE '/' ***********/
p=&table[i][j];
 sum=0;
 count=0;
 empty_sum=0;
 prove=0;
 while ((p->flag==flag)&&(p!=NULL))
  {
   p=p->rightup;
   sum++;
  }
  if ((p->flag==0)&&((p->rightup)->flag==flag)&&(p->rightup!=NULL))
    {
    q=p->rightup;
    *next_i=i-sum;
    *next_j=j+sum;
    prove=1;
    empty_sum++;
    while ((q->flag==flag)&&(q!=NULL))
       {
	q=q->rightup;
	sum++;
       }
    }
 count=0;
 p=&table[i][j];
 while ((p->flag==flag)&&(p!=NULL))
  {
   p=p->leftdown;
   sum++;
  count++;
  }
if ((p->flag==0)&&((p->leftdown)->flag==flag)&&(p->leftdown!=NULL))
    {
    q=p->leftdown;
    *next_i=i+count;
    *next_j=j-count;
    prove=1;
    empty_sum++;
    while ((q->flag==flag)&&(q!=NULL))
       {
	q=q->leftdown;
	sum++;
       }
    }
if (empty_sum<2)
 {
if ((sum>=5)&&(prove==1))
  {
  return 1;
  }
  }
  else
   if ((sum>=6)&&(prove==1))
  {
  return 1;
  }




 /******** LINE '\' ***********/
p=&table[i][j];
 sum=0;
 count=0;
 prove=0;
  empty_sum=0;
 while ((p->flag==flag)&&(p!=NULL))
  {
   p=p->leftup;
   sum++;
  }
  if ((p->flag==0)&&((p->leftup)->flag==flag)&&(p->leftup!=NULL))
    {
    q=p->leftup;
    *next_i=i-sum;
    *next_j=j-sum;
     empty_sum++;
    prove=1;
    while ((q->flag==flag)&&(q!=NULL))
       {
	q=q->leftup;
	sum++;
       }
    }
 count=0;
 p=&table[i][j];
 while ((p->flag==flag)&&(p!=NULL))
  {
   p=p->rightdown;
   sum++;
  count++;
  }
if ((p->flag==0)&&((p->rightdown)->flag==flag)&&(p->rightdown!=NULL))
    {
    q=p->rightdown;
    *next_i=i+count;
    *next_j=j+count;
    prove=1;
     empty_sum++;
    while ((q->flag==flag)&&(q!=NULL))
       {
	q=q->rightdown;
	sum++;
       }
    }
if (empty_sum<2)
 {
  if ((sum>=5)&&(prove==1))
   {
   return 1;
  }
 }
 else
  if ((sum>=6)&&(prove==1))
   {
   return 1;
  }


   /*** LINE '|' ***/
p=&table[i][j];
empty_sum=0;
 prove=0;
 sum=0;
 count=0;
 while ((p->flag==flag)&&(p!=NULL))
  {
   p=p->up;
   sum++;
  }
  if ((p->flag==0)&&((p->up)->flag==flag)&&(p->up!=NULL))
    {
    q=p->up;
    *next_i=i-sum;
    *next_j=j;
    prove=1;
    empty_sum++;

    while ((q->flag==flag)&&(q!=NULL))
       {
	q=q->up;
	sum++;
       }
    }
 count=0;
 p=&table[i][j];
 while ((p->flag==flag)&&(p!=NULL))
  {
   p=p->down;
   sum++;
  count++;
  }
if ((p->flag==0)&&((p->down)->flag==flag)&&(p->down!=NULL))
    {
    q=p->down;
    *next_i=i+count;
    *next_j=j;
    prove=1;
    empty_sum++;

    while ((q->flag==flag)&&(q!=NULL))
       {
	q=q->down;
	sum++;
       }
    }
 if (empty_sum<2)
  {
    if ((sum>=5)&&(prove==1))
      {
	 return 1;
      }
  }
  else
     if ((sum>=6)&&(prove==1))
      {
	 return 1;
      }


  /******* LINE '---' ******/
p=&table[i][j];
 sum=0;
 count=0;
 prove=0;
 empty_sum=0;
 while ((p->flag==flag)&&(p!=NULL))
  {
   p=p->left;
   sum++;
  }
  if ((p->flag==0)&&((p->left)->flag==flag)&&(p->left!=NULL))
    {
    q=p->left;
    *next_i=i;
    *next_j=j-sum;
    empty_sum++;
    prove=1;
    while ((q->flag==flag)&&(q!=NULL))
       {
	q=q->left;
	sum++;
       }
    }
 count=0;
 p=&table[i][j];
 while ((p->flag==flag)&&(p!=NULL))
  {
   p=p->right;
   sum++;
  count++;
  }
if ((p->flag==0)&&((p->right)->flag==flag)&&(p->right!=NULL))
    {
    q=p->right;
    *next_i=i;
    *next_j=j+count;
     empty_sum++;
    prove=1;
    while ((q->flag==flag)&&(q!=NULL))
       {
	q=q->right;
	sum++;
       }
    }
 if (empty_sum<2)
  {
 if ((sum>=5)&&(prove==1))
   {
   return 1;
  }
 }
 else
  if ((sum>=6)&&(prove==1))
   {
   return 1;
  }



return 0;

} /* THE END */


     /********* TEST 4 **********/

int test_4(int i,int j,int *next_i,int *next_j)
{
      /******* CASE 4 ********/

int flag,sum,empty,count,prove;
struct chess *p,*q;
flag=table[i][j].flag;

   /*** LINE '|' ***/
p=&table[i][j];
sum=0;
prove=0;
empty=0;

while ((p->flag==flag)&&(p!=NULL))
   {
	p=p->up;
	sum++;
   }

if ((p->flag==0)&&(p!=NULL))
  {
   empty++;
    q=p->up;
    if ((q->flag==0)&&(q!=NULL))
	  {
	  *next_i=i-sum;
	  *next_j=j;
	  prove=1;
	  empty++;
	  }
   }
count=0;
p=&table[i][j];
while ((p->flag==flag)&&(p!=NULL))
{
 p=p->down;
 sum++;
 count++;
}
if ((p->flag==0)&&(p!=NULL))
  {
   empty++;
    q=p->down;
    if ((q->flag==0)&&(q!=NULL))
	  {
	  *next_i=i+count;
	  *next_j=j;
	  prove=1;
	  empty++;
	  }
   }

if ((sum>=4)&&(empty>=3)&&prove)
 return 1;

  /***** CASE '/' ********/
p=&table[i][j];
sum=0;
prove=0;
empty=0;
while ((p->flag==flag)&&(p!=NULL))
   {
	p=p->rightup;
	sum++;
   }
if ((p->flag==0)&&(p!=NULL))
  {
   empty++;
    q=p->rightup;
    if ((q->flag==0)&&(q!=NULL))
	  {
	  *next_i=i-sum;
	  *next_j=j+sum;
	  prove=1;
	  empty++;
	  }
   }
count=0;
p=&table[i][j];
while ((p->flag==flag)&&(p!=NULL))
{
 p=p->leftdown;
 sum++;
 count++;
}
if ((p->flag==0)&&(p!=NULL))
  {
   empty++;
    q=p->leftdown;
    if ((q->flag==0)&&(q!=NULL))
	  {
	  *next_i=i+count;
	  *next_j=j-count;
	  prove=1;
	  empty++;
	  }
   }

if ((sum>=4)&&(empty>=3)&&prove)
 return 1;


  /***** CASE '\' ********/
p=&table[i][j];
sum=0;
prove=0;
empty=0;
while ((p->flag==flag)&&(p!=NULL))
   {
	p=p->rightdown;
	sum++;
   }
if ((p->flag==0)&&(p!=NULL))
  {
   empty++;
    q=p->rightdown;
    if ((q->flag==0)&&(q!=NULL))
	  {
	  *next_i=i+sum;
	  *next_j=j+sum;
	  prove=1;
	  empty++;
	  }
   }
count=0;
p=&table[i][j];
while ((p->flag==flag)&&(p!=NULL))
{
 p=p->leftup;
 sum++;
 count++;
}
if ((p->flag==0)&&(p!=NULL))
  {
   empty++;
    q=p->leftup;
    if ((q->flag==0)&&(q!=NULL))
	  {
	  *next_i=i-count;
	  *next_j=j-count;
	  prove=1;
	  empty++;
	  }
   }

if ((sum>=4)&&(empty>=3)&&prove)
 return 1;


  /***** CASE '---' ********/
p=&table[i][j];
sum=0;
prove=0;
empty=0;
while ((p->flag==flag)&&(p!=NULL))
   {
	p=p->left;
	sum++;
   }
if ((p->flag==0)&&(p!=NULL))
  {
   empty++;
    q=p->left;
    if ((q->flag==0)&&(q!=NULL))
	  {
	  *next_i=i;
	  *next_j=j-sum;
	  prove=1;
	  empty++;
	  }
   }
count=0;
p=&table[i][j];
while ((p->flag==flag)&&(p!=NULL))
{
 p=p->right;
 sum++;
 count++;
}
if ((p->flag==0)&&(p!=NULL))
  {
   empty++;
    q=p->right;
    if ((q->flag==0)&&(q!=NULL))
	  {
	  *next_i=i;
	  *next_j=j+count;
	  prove=1;
	  empty++;
	  }
   }

if ((sum>=4)&&(empty>=3)&&prove)
 return 1;

return 0;
}


     /********* TEST 5 **********/

int test_5(int i,int j,int *next_i,int *next_j)
{
      /******* CASE 5 ********/

int flag,sum,prove;
struct chess *p,*q;
flag=table[i][j].flag;


   /*** LINE '/' ***/
p=&table[i][j];
sum=0;
prove=0;

while ((p->flag==flag)&&(p!=NULL))
   {
	p=p->leftdown;
	sum++;
   }
p=&table[i][j];
while ((p->flag==flag)&&(p!=NULL))
   {
	p=p->rightup;
	sum++;
   }

p=&table[i][j];
if (sum==2)
   {
     if (((p->leftdown)->flag==0)&&((p->rightup)->flag==0))
	if ((p->leftdown!=NULL)&&(p->rightup!=NULL))
	{
	 q=(p->rightup)->rightup;
	 if ((q->flag==flag)&&((q->rightup)->flag==flag)&&(((q->rightup)->rightup)->flag==0))
	   if ((q!=NULL)&&(q->rightup!=NULL)&&((q->rightup)->rightup!=NULL))
	     {
	     prove=1;
	     *next_i=i-1;
	     *next_j=j+1;
	     }



	   q=(p->leftdown)->leftdown;
	   if ((q->flag==flag)&&((q->leftdown)->flag==flag)&&(((q->leftdown)->leftdown)->flag==0))
		   if ((q!=NULL)&&(q->leftdown!=NULL)&&((q->leftdown)->leftdown!=NULL))
		   {
	     prove=1;
	     *next_i=i+1;
	     *next_j=j-1;
		   }

       }
   }
if (sum==3)
  {
    if (((p->leftdown)->flag==0)&&(p->leftdown!=NULL))
      {
      q=(p->leftdown)->leftdown;
      if ((q->flag==flag)&&((q->leftdown)->flag==0))
	   if ((q!=NULL)&&(q->leftdown!=NULL))
	    {
	      q=p->rightup;
	      if ((q->flag==flag)&&((q->rightup)->flag==0))
	       if ((q!=NULL)&&(q->rightup!=NULL))
	      {
	       prove=1;
	       *next_i=i+1;
	       *next_j=j-1;
	      }
	   }
	q=p->rightup;
	if ((q->flag==flag)&&(q->rightup->flag==0)&&(q->rightup->rightup->flag==flag)&&(q->rightup->rightup->rightup->flag==0))
	  if ((q!=NULL)&&(q->rightup!=NULL)&&(q->rightup->rightup!=NULL)&&(q->rightup->rightup->rightup!=NULL))
	      {
	       prove=1;
	       *next_i=i-2;
	       *next_j=j+2;

	      }

      }
     else
      if (((p->rightup)->flag==0)&&(p->rightup!=NULL))
       {
	if ((p->leftdown->flag==flag)&&(p->leftdown->leftdown->flag==0))
	 if ((p->leftdown!=NULL)&&(p->leftdown->leftdown!=NULL))
	  {
	   q=p->rightup->rightup;
	   if ((q->flag==flag)&&(q->rightup->flag==0))
	      if ((q!=NULL)&&(q->rightup!=NULL))
		{
		 prove=1;
		 *next_i=i-1;
		 *next_j=j+1;
		 }
	    q=p->leftdown->leftdown->leftdown;
	    if ((q->flag==flag)&&(q->leftdown->flag==0))
	      if ((q!=NULL)&&(q->leftdown!=NULL))
		{
		prove=1;
		*next_i=i+2;
		*next_j=j-2;
		}


	  }

       }
    }
if (prove==1)
 return 1;

   /*** LINE '\' ***/
p=&table[i][j];
sum=0;
prove=0;

while ((p->flag==flag)&&(p!=NULL))
   {
	p=p->leftup;
	sum++;
   }
p=&table[i][j];
while ((p->flag==flag)&&(p!=NULL))
   {
	p=p->rightdown;
	sum++;
   }

p=&table[i][j];
if (sum==2)
   {
     if (((p->leftup)->flag==0)&&((p->rightdown)->flag==0))
	if ((p->leftup!=NULL)&&(p->rightdown!=NULL))
	{
	 q=(p->rightdown)->rightdown;
	 if ((q->flag==flag)&&((q->rightdown)->flag==flag)&&(((q->rightdown)->rightdown)->flag==0))
	   if ((q!=NULL)&&(q->rightdown!=NULL)&&((q->rightdown)->rightdown!=NULL))
	     {
	     prove=1;
	     *next_i=i+1;
	     *next_j=j+1;
	     }



	   q=(p->leftup)->leftup;
	   if ((q->flag==flag)&&((q->leftup)->flag==flag)&&(((q->leftup)->leftup)->flag==0))
		   if ((q!=NULL)&&(q->leftup!=NULL)&&((q->leftup)->leftup!=NULL))
		   {
	     prove=1;
	     *next_i=i-1;
	     *next_j=j-1;
		   }

       }
   }
if (sum==3)
  {
    if (((p->leftup)->flag==0)&&(p->leftup!=NULL))
      {
      q=(p->leftup)->leftup;
      if ((q->flag==flag)&&((q->leftup)->flag==0))
	   if ((q!=NULL)&&(q->leftup!=NULL))
	    {
	      q=p->rightdown;
	      if ((q->flag==flag)&&((q->rightdown)->flag==0))
	       if ((q!=NULL)&&(q->rightdown!=NULL))
	      {
	       prove=1;
	       *next_i=i-1;
	       *next_j=j-1;
	      }
	   }
	q=p->rightdown;
	if ((q->flag==flag)&&(q->rightdown->flag==0)&&(q->rightdown->rightdown->flag==flag)&&(q->rightdown->rightdown->rightdown->flag==0))
	  if ((q!=NULL)&&(q->rightdown!=NULL)&&(q->rightdown->rightdown!=NULL)&&(q->rightdown->rightdown->rightdown!=NULL))
	      {
	       prove=1;
	       *next_i=i+2;
	       *next_j=j+2;

	      }

      }
     else
      if (((p->rightdown)->flag==0)&&(p->rightdown!=NULL))
       {
	if ((p->leftup->flag==flag)&&(p->leftup->leftup->flag==0))
	 if ((p->leftup!=NULL)&&(p->leftup->leftup!=NULL))
	  {
	   q=p->rightdown->rightdown;
	   if ((q->flag==flag)&&(q->rightdown->flag==0))
	      if ((q!=NULL)&&(q->rightdown!=NULL))
		{
		 prove=1;
		 *next_i=i+1;
		 *next_j=j+1;
		 }
	    q=p->leftup->leftup->leftup;
	    if ((q->flag==flag)&&(q->leftup->flag==0))
	      if ((q!=NULL)&&(q->leftup!=NULL))
		{
		prove=1;
		*next_i=i-2;
		*next_j=j-2;
		}


	  }

       }
    }
if (prove==1)
 return 1;


   /*** LINE '--' ***/
p=&table[i][j];
sum=0;
prove=0;

while ((p->flag==flag)&&(p!=NULL))
   {
	p=p->left;
	sum++;
   }
p=&table[i][j];
while ((p->flag==flag)&&(p!=NULL))
   {
	p=p->right;
	sum++;
   }

p=&table[i][j];
if (sum==2)
   {
     if (((p->left)->flag==0)&&((p->right)->flag==0))
	if ((p->left!=NULL)&&(p->right!=NULL))
	{
	 q=(p->right)->right;
	 if ((q->flag==flag)&&((q->right)->flag==flag)&&(((q->right)->right)->flag==0))
	   if ((q!=NULL)&&(q->right!=NULL)&&((q->right)->right!=NULL))
	     {
	     prove=1;
	     *next_i=i;
	     *next_j=j+1;
	     }



	   q=(p->left)->left;
	   if ((q->flag==flag)&&((q->left)->flag==flag)&&(((q->left)->left)->flag==0))
		   if ((q!=NULL)&&(q->left!=NULL)&&((q->left)->left!=NULL))
		   {
	     prove=1;
	     *next_i=i;
	     *next_j=j-1;
		   }

       }
   }
p=&table[i][j];
if (sum==3)
  {
    if (((p->left)->flag==0)&&(p->left!=NULL))
      {
      q=(p->left)->left;
      if ((q->flag==flag)&&((q->left)->flag==0))
	   if ((q!=NULL)&&(q->left!=NULL))
	    {
	      q=p->right;
	      if ((q->flag==flag)&&((q->right)->flag==0))
	       if ((q!=NULL)&&(q->right!=NULL))
	      {
	       prove=1;
	       *next_i=i;
	       *next_j=j-1;
	      }
	   }
	q=p->right;
	if ((q->flag==flag)&&(q->right->flag==0)&&(q->right->right->flag==flag)&&(q->right->right->right->flag==0))
	  if ((q!=NULL)&&(q->right!=NULL)&&(q->right->right!=NULL)&&(q->right->right->right!=NULL))
	      {
	       prove=1;
	       *next_i=i;
	       *next_j=j+2;

	      }

      }
     else
      if (((p->right)->flag==0)&&(p->right!=NULL))
       {
	if ((p->left->flag==flag)&&(p->left->left->flag==0))
	 if ((p->left!=NULL)&&(p->left->left!=NULL))
	  {
	   q=p->right->right;
	   if ((q->flag==flag)&&(q->right->flag==0))
	      if ((q!=NULL)&&(q->right!=NULL))
		{
		 prove=1;
		 *next_i=i;
		 *next_j=j+1;
		 }
	    q=p->left->left->left;
	    if ((q->flag==flag)&&(q->left->flag==0))
	      if ((q!=NULL)&&(q->left!=NULL))
		{
		prove=1;
		*next_i=i;
		*next_j=j-2;
		}


	  }

       }
    }
if (prove==1)
 return 1;



   /*** LINE '|' ***/
p=&table[i][j];
sum=0;
prove=0;

while ((p->flag==flag)&&(p!=NULL))
   {
	p=p->up;
	sum++;
   }
p=&table[i][j];
while ((p->flag==flag)&&(p!=NULL))
   {
	p=p->down;
	sum++;
   }

p=&table[i][j];
if (sum==2)
   {
     if (((p->up)->flag==0)&&((p->down)->flag==0))
	if ((p->up!=NULL)&&(p->down!=NULL))
	{
	 q=(p->down)->down;
	 if ((q->flag==flag)&&((q->down)->flag==flag)&&(((q->down)->down)->flag==0))
	   if ((q!=NULL)&&(q->down!=NULL)&&((q->down)->down!=NULL))
	     {
	     prove=1;
	     *next_i=i+1;
	     *next_j=j;
	     }



	   q=(p->up)->up;
	   if ((q->flag==flag)&&((q->up)->flag==flag)&&(((q->up)->up)->flag==0))
		   if ((q!=NULL)&&(q->up!=NULL)&&((q->up)->up!=NULL))
		   {
	     prove=1;
	     *next_i=i-1;
	     *next_j=j;
		   }

       }
   }
if (sum==3)
  {
    if (((p->up)->flag==0)&&(p->up!=NULL))
      {
      q=(p->up)->up;
      if ((q->flag==flag)&&((q->up)->flag==0))
	   if ((q!=NULL)&&(q->up!=NULL))
	    {
	      q=p->down;
	      if ((q->flag==flag)&&((q->down)->flag==0))
	       if ((q!=NULL)&&(q->right!=NULL))
	      {
	       prove=1;
	       *next_i=i-1;
	       *next_j=j;
	      }
	   }
	q=p->down;
	if ((q->flag==flag)&&(q->down->flag==0)&&(q->down->down->flag==flag)&&(q->down->down->down->flag==0))
	  if ((q!=NULL)&&(q->down!=NULL)&&(q->down->down!=NULL)&&(q->down->down->down!=NULL))
	      {
	       prove=1;
	       *next_i=i+2;
	       *next_j=j;

	      }

      }
     else
      if (((p->down)->flag==0)&&(p->down!=NULL))
       {
	if ((p->up->flag==flag)&&(p->up->up->flag==0))
	 if ((p->up!=NULL)&&(p->up->up!=NULL))
	  {
	   q=p->down->down;
	   if ((q->flag==flag)&&(q->down->flag==0))
	      if ((q!=NULL)&&(q->down!=NULL))
		{
		 prove=1;
		 *next_i=i+1;
		 *next_j=j;
		 }
	    q=p->up->up->up;
	    if ((q->flag==flag)&&(q->up->flag==0))
	      if ((q!=NULL)&&(q->up!=NULL))
		{
		prove=1;
		*next_i=i-2;
		*next_j=j;
		}


	  }

       }
    }
if (prove==1)
 return 1;

return 0;

} /* test_5() end */



     /********* TEST 6 **********/

int test_6(int i,int j,int *next_i,int *next_j)
{
      /******* CASE 6 ********/

int flag,sum,empty,count,prove;
struct chess *p,*q;
flag=table[i][j].flag;

   /*** LINE '/' ***/
p=&table[i][j];
sum=0;
prove=0;
empty=0;
count=0;
while ((p->flag==flag)&&(p!=NULL))
   {
	p=p->rightup;
	sum++;
   }
if ((p->flag==0)&&(p!=NULL))
   {
    q=p->rightup;
    if ((q->flag==0)&&(q!=NULL))
      {
      prove=1;
      empty=2;
      *next_i=i-sum;
      *next_j=j+sum;
      }
    }

p=&table[i][j];
count=0;
while ((p->flag==flag)&&(p!=NULL))
   {
	p=p->leftdown;
	count++;
	sum++;
   }
if ((p->flag==0)&&(p!=NULL))
   {
    q=p->leftdown;
    if ((q->flag==0)&&(q!=NULL))
      {
      prove=1;
      empty=2;
      *next_i=i+count;
      *next_j=j-count;
      }
    }
if ((sum>3)&&(prove)&&(empty==2))
   return 1;


   /*** LINE '\' ***/
p=&table[i][j];
sum=0;
prove=0;
empty=0;
count=0;
while ((p->flag==flag)&&(p!=NULL))
   {
	p=p->leftup;
	sum++;
   }
if ((p->flag==0)&&(p!=NULL))
   {
    q=p->leftup;
    if ((q->flag==0)&&(q!=NULL))
      {
      prove=1;
      empty=2;
      *next_i=i-sum;
      *next_j=j-sum;
      }
    }

p=&table[i][j];
count=0;
while ((p->flag==flag)&&(p!=NULL))
   {
	p=p->rightdown;
	count++;
	sum++;
   }
if ((p->flag==0)&&(p!=NULL))
   {
    q=p->rightdown;
    if ((q->flag==0)&&(q!=NULL))
      {
      prove=1;
      empty=2;
      *next_i=i+count;
      *next_j=j+count;
      }
    }
if ((sum>3)&&(prove)&&(empty==2))
   return 1;

   /*** LINE '|' ***/
p=&table[i][j];
sum=0;
prove=0;
empty=0;
count=0;
while ((p->flag==flag)&&(p!=NULL))
   {
	p=p->up;
	sum++;
   }
if ((p->flag==0)&&(p!=NULL))
   {
    q=p->up;
    if ((q->flag==0)&&(q!=NULL))
      {
      prove=1;
      empty=2;
      *next_i=i-sum;
      *next_j=j;
      }
    }

p=&table[i][j];
count=0;

while ((p->flag==flag)&&(p!=NULL))
   {
	p=p->down;
	count++;
	sum++;
   }
if ((p->flag==0)&&(p!=NULL))
   {
    q=p->down;
    if ((q->flag==0)&&(q!=NULL))
      {
      prove=1;
      empty=2;
      *next_i=i+count;
      *next_j=j;
      }
    }
if ((sum>3)&&(prove)&&(empty==2))
   return 1;




   /*** LINE '--' ***/
p=&table[i][j];
sum=0;
prove=0;
empty=0;
count=0;
while ((p->flag==flag)&&(p!=NULL))
   {
	p=p->left;
	sum++;
   }
if ((p->flag==0)&&(p!=NULL))
   {
    q=p->left;
    if ((q->flag==0)&&(q!=NULL))
      {
      prove=1;
      empty=2;
      *next_i=i;
      *next_j=j-sum;
      }
    }

p=&table[i][j];
count=0;
while ((p->flag==flag)&&(p!=NULL))
   {
	p=p->right;
	count++;
	sum++;
   }
if ((p->flag==0)&&(p!=NULL))
   {
    q=p->right;
    if ((q->flag==0)&&(q!=NULL))
      {
      prove=1;
      empty=2;
      *next_i=i;
      *next_j=j+count;
      }
    }
if ((sum>3)&&(prove)&&(empty==2))
   return 1;


return 0;
}


     /********* TEST 8 **********/

int test_8(int i,int j,int *next_i,int *next_j)
{
      /******* CASE 8 ********/
int flag,sum,l_empty,r_empty,count,prove;
struct chess *p;
flag=table[i][j].flag;

    /****** LINE '\' ******/


p=&table[i][j];
sum=0;
prove=0;
l_empty=0;
r_empty=0;
count=0;

while ((p->flag==flag)&&(p!=NULL))
   {
	p=p->leftup;
	sum++;
   }
while ((p->flag==0)&&(p!=NULL))
   {
    p=p->leftup;
    l_empty++;
    }

p=&table[i][j];
count=0;

while ((p->flag==flag)&&(p!=NULL))
   {
	p=p->rightdown;
	sum++;
	count++;
   }
while ((p->flag==0)&&(p!=NULL))
   {
    p=p->rightdown;
    r_empty++;
    }
   if (r_empty>l_empty)
    {
     prove=1;
     *next_i=i+count;
     *next_j=j+count;
     }
     else
      {
        prove=1;
	*next_i=i-(sum-count);
	*next_j=j-(sum-count);
     }
if ((r_empty>=1)&&(l_empty>=1)&&((l_empty+r_empty)>=4)&&prove&&(sum>2))
    return 1;





    /****** LINE '/' ******/


p=&table[i][j];
sum=0;
prove=0;
l_empty=0;
r_empty=0;
count=0;

while ((p->flag==flag)&&(p!=NULL))
   {
	p=p->leftdown;
	sum++;
   }
while ((p->flag==0)&&(p!=NULL))
   {
    p=p->leftdown;
    l_empty++;
    }

p=&table[i][j];
count=0;

while ((p->flag==flag)&&(p!=NULL))
   {
	p=p->rightup;
	sum++;
	count++;
   }
while ((p->flag==0)&&(p!=NULL))
   {
    p=p->rightup;
    r_empty++;
    }
   if (r_empty>l_empty)
    {
     prove=1;
     *next_i=i-count;
     *next_j=j+count;
     }
     else
      {
        prove=1;
	*next_i=i+(sum-count);
	*next_j=j-(sum-count);
     }
if ((r_empty>=1)&&(l_empty>=1)&&((l_empty+r_empty)>=4)&&prove&&(sum>2))
    return 1;



   /*** LINE '|' ***/


p=&table[i][j];
sum=0;
prove=0;
l_empty=0;
r_empty=0;
count=0;

while ((p->flag==flag)&&(p!=NULL))
   {
	p=p->up;
	sum++;
   }
while ((p->flag==0)&&(p!=NULL))
   {
    p=p->up;
    l_empty++;
    }

p=&table[i][j];
count=0;

while ((p->flag==flag)&&(p!=NULL))
   {
	p=p->down;
	sum++;
	count++;
   }
while ((p->flag==0)&&(p!=NULL))
   {
    p=p->down;
    r_empty++;
    }
   if (r_empty>l_empty)
    {
     prove=1;
     *next_i=i+count;
     *next_j=j;
     }
     else
      {
        prove=1;
	*next_i=i-(sum-count);
	*next_j=j;
     }
if ((r_empty>=1)&&(l_empty>=1)&&((l_empty+r_empty)>=4)&&prove&&(sum>2))
    return 1;




    /****** LINE '--' ******/


p=&table[i][j];
sum=0;
prove=0;
l_empty=0;
r_empty=0;
count=0;

while ((p->flag==flag)&&(p!=NULL))
   {
	p=p->left;
	sum++;
   }
while ((p->flag==0)&&(p!=NULL))
   {
    p=p->left;
    l_empty++;
    }

p=&table[i][j];
count=0;

while ((p->flag==flag)&&(p!=NULL))
   {
	p=p->right;
	sum++;
	count++;
   }
while ((p->flag==0)&&(p!=NULL))
   {
    p=p->right;
    r_empty++;
    }
   if (r_empty>l_empty)
    {
     prove=1;
     *next_i=i;
     *next_j=j+count;
     }
     else
      {
        prove=1;
	*next_i=i;
	*next_j=j-(sum-count);
     }
if ((r_empty>=1)&&(l_empty>=1)&&((l_empty+r_empty)>=4)&&prove&&(sum>2))
    return 1;

return 0;
}

     /********* TEST 9 **********/
int test_9(int i,int j,int *next_i,int *next_j)
{
      /******* CASE 9 ********/

int flag,prove;
struct chess *p,*q;
flag=table[i][j].flag;
prove=0;
   /*** LINE '/' ***/
p=&table[i][j];
if ((p->leftdown!=NULL)&&(p->rightup!=NULL))
 if ((p->leftdown->flag==0)&&(p->rightup->flag==0))
   {
    q=p->rightup->rightup;
     if ((q!=NULL)&&(q->rightup!=NULL))
     if ((q->flag==flag)&&(q->rightup->flag==0))
	   if ((q->rightup->rightup!=NULL)||(p->leftdown->leftdown!=NULL))
		if ((q->rightup->rightup->flag==0)||(p->leftdown->leftdown->flag==0))
		 {
	    prove=1;
	    *next_i=i-1;
	    *next_j=j+1;
		 }
    if (prove==0)
	   {
	 q=p->leftdown->leftdown;
     if ((q!=NULL)&&(q->leftdown!=NULL))
     if ((q->flag==flag)&&(q->leftdown->flag==0))
	       if ((p->rightup->rightup!=NULL)||(q->leftdown->leftdown!=NULL))
		if ((p->rightup->rightup->flag==0)||(q->leftdown->leftdown->flag==0))
	       {
	    prove=1;
	    *next_i=i+1;
	    *next_j=j-1;
	     }
       }
  }
if (prove==1)
   return 1;
   /*** LINE '\' ***/
p=&table[i][j];
if ((p->leftup!=NULL)&&(p->rightdown!=NULL))
 if ((p->leftup->flag==0)&&(p->rightdown->flag==0))
   {
    q=p->rightdown->rightdown;
     if ((q!=NULL)&&(q->rightdown!=NULL))
     if ((q->flag==flag)&&(q->rightdown->flag==0))
	   if ((q->rightdown->rightdown!=NULL)||(p->leftup->leftup!=NULL))
		if ((q->rightdown->rightdown->flag==0)||(p->leftup->leftup->flag==0))
		 {
	    prove=1;
	    *next_i=i+1;
	    *next_j=j+1;
		 }
    if (prove==0)
	   {
	 q=p->leftup->leftup;
     if ((q!=NULL)&&(q->leftup!=NULL))
     if ((q->flag==flag)&&(q->leftup->flag==0))
	       if ((p->rightdown->rightdown!=NULL)||(q->leftup->leftup!=NULL))
		if ((p->rightdown->rightdown->flag==0)||(q->leftup->leftup->flag==0))
	       {
	    prove=1;
	    *next_i=i-1;
	    *next_j=j-1;
	     }
       }
  }
if (prove==1)
   return 1;

   /*** LINE '--' ***/
p=&table[i][j];
if ((p->left!=NULL)&&(p->right!=NULL))
 if ((p->left->flag==0)&&(p->right->flag==0))
   {
    q=p->right->right;
     if ((q!=NULL)&&(q->right!=NULL))
     if ((q->flag==flag)&&(q->right->flag==0))
	   if ((q->right->right!=NULL)||(p->left->left!=NULL))
		if ((q->right->right->flag==0)||(p->left->left->flag==0))
		 {
	    prove=1;
	    *next_i=i;
	    *next_j=j+1;
		 }
    if (prove==0)
	   {
	 q=p->left->left;
     if ((q!=NULL)&&(q->left!=NULL))
     if ((q->flag==flag)&&(q->left->flag==0))
	       if ((p->right->right!=NULL)||(q->left->left!=NULL))
		if ((p->right->right->flag==0)||(q->left->left->flag==0))
	       {
	    prove=1;
	    *next_i=i;
	    *next_j=j-1;
	     }
       }
  }
if (prove==1)
   return 1;

   /*** LINE '|' ***/
p=&table[i][j];
if ((p->up!=NULL)&&(p->down!=NULL))
 if ((p->up->flag==0)&&(p->down->flag==0))
   {
    q=p->down->down;
     if ((q!=NULL)&&(q->down!=NULL))
     if ((q->flag==flag)&&(q->down->flag==0))
	   if ((q->down->down!=NULL)||(p->up->up!=NULL))
		if ((q->down->down->flag==0)||(p->up->up->flag==0))
		 {
	    prove=1;
	    *next_i=i+1;
	    *next_j=j;
		 }
    if (prove==0)
	   {
	 q=p->up->up;
     if ((q!=NULL)&&(q->up!=NULL))
     if ((q->flag==flag)&&(q->up->flag==0))
	       if ((p->down->down!=NULL)||(q->up->up!=NULL))
		if ((p->down->down->flag==0)||(q->up->up->flag==0))
	       {
	    prove=1;
	    *next_i=i-1;
	    *next_j=j;
	     }
       }
  }
if (prove==1)
   return 1;
return 0;
}


