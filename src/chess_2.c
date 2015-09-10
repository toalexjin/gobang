     /******* CHESS FIVE'S HEAD FILE *******/
     /******* TEST_10 ------ TEST_18  *******/
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

/*
extern int chess_ready;
extern int BOARD_BACKCOLOR,LINE_COLOR,BOARD_STYLE,WELCOME_COLOR,MAN_CHESS_COLOR,MAN_CHESS_STYLE;
extern int MACHINE_CHESS_COLOR,MACHINE_CHESS_STYLE,B_COLOR,B_BOTTON_BACKCOLOR,B_BOTTON_STYLE,B_BOTTON_FORECOLOR;
  */
int test_10(int i,int j,int *next_i,int *next_j)
{
      /******* CASE 10 ********/
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
	  {
	   if ((q->rightup->rightup!=NULL)&&(q->rightup->rightup->flag==0))
                {
	    prove=1;
	    *next_i=i-3;
	    *next_j=j+3;
		 }
	 if   ((prove==0)&&(p->leftdown->leftdown!=NULL)&&(p->leftdown->leftdown->flag==0))
		 {
	    prove=1;
	    *next_i=i+1;
	    *next_j=j-1;
		 }
	  }
		if (prove==0)
	   {
	 q=p->leftdown->leftdown;
     if ((q!=NULL)&&(q->leftdown!=NULL))
     if ((q->flag==flag)&&(q->leftdown->flag==0))
             {
	   if ((p->rightup->rightup!=NULL)&&(p->rightup->rightup->flag==0))
                {
	    prove=1;
	    *next_i=i-1;
	    *next_j=j+1;
		 }
	 if   ((prove==0)&&(q->leftdown->leftdown!=NULL)&&(q->leftdown->leftdown->flag==0))
		 {
	    prove=1;
	    *next_i=i+3;
	    *next_j=j-3;
		 }
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
	  {
	   if ((q->rightdown->rightdown!=NULL)&&(q->rightdown->rightdown->flag==0))
                {
	    prove=1;
	    *next_i=i+3;
	    *next_j=j+3;
		 }
	 if   ((prove==0)&&(p->leftup->leftup!=NULL)&&(p->leftup->leftup->flag==0))
		 {
	    prove=1;
	    *next_i=i-1;
	    *next_j=j-1;
		 }
	  }
		if (prove==0)
	   {
	 q=p->leftup->leftup;
     if ((q!=NULL)&&(q->leftup!=NULL))
     if ((q->flag==flag)&&(q->leftup->flag==0))
             {
	   if ((p->rightdown->rightdown!=NULL)&&(p->rightdown->rightdown->flag==0))
                {
	    prove=1;
	    *next_i=i+1;
	    *next_j=j+1;
		 }
	 if   ((prove==0)&&(q->leftup->leftup!=NULL)&&(q->leftup->leftup->flag==0))
		 {
	    prove=1;
	    *next_i=i-3;
	    *next_j=j-3;
		 }
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
	  {
	   if ((q->right->right!=NULL)&&(q->right->right->flag==0))
                {
	    prove=1;
	    *next_i=i;
	    *next_j=j+3;
		 }
	 if   ((prove==0)&&(p->left->left!=NULL)&&(p->left->left->flag==0))
		 {
	    prove=1;
	    *next_i=i;
	    *next_j=j-1;
		 }
	  }
		if (prove==0)
	   {
	 q=p->left->left;
     if ((q!=NULL)&&(q->left!=NULL))
     if ((q->flag==flag)&&(q->left->flag==0))
             {
	   if ((p->right->right!=NULL)&&(p->right->right->flag==0))
                {
	    prove=1;
	    *next_i=i;
	    *next_j=j+1;
		 }
	 if   ((prove==0)&&(q->left->left!=NULL)&&(q->left->left->flag==0))
		 {
	    prove=1;
	    *next_i=i;
	    *next_j=j-3;
		 }
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
	  {
	   if ((q->down->down!=NULL)&&(q->down->down->flag==0))
                {
	    prove=1;
	    *next_i=i+3;
	    *next_j=j;
		 }
	 if   ((prove==0)&&(p->up->up!=NULL)&&(p->up->up->flag==0))
		 {
	    prove=1;
	    *next_i=i-1;
	    *next_j=j;
		 }
	  }
		if (prove==0)
	   {
	 q=p->up->up;
     if ((q!=NULL)&&(q->up!=NULL))
     if ((q->flag==flag)&&(q->up->flag==0))
             {
	   if ((p->down->down!=NULL)&&(p->down->down->flag==0))
                {
	    prove=1;
	    *next_i=i+1;
	    *next_j=j;
		 }
	 if   ((prove==0)&&(q->up->up!=NULL)&&(q->up->up->flag==0))
		 {
	    prove=1;
	    *next_i=i-3;
	    *next_j=j;
		 }
	  }
       }
  }
if (prove==1)
   return 1;

return 0;
}



     /********* TEST 11 **********/

int test_11(int i,int j,int *next_i,int *next_j,int direct)
{
      /******* CASE 11 ********/
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
if ((r_empty>=2)&&(l_empty>=2)&&((r_empty+l_empty)>=5)&&prove&&(sum>1))
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
if ((r_empty>=2)&&(l_empty>=2)&&((r_empty+l_empty)>=5)&&prove&&(sum>1))
    return 1;
if (direct==1)
 return 0;


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
if ((r_empty>=2)&&(l_empty>=2)&&((r_empty+l_empty)>=5)&&prove&&(sum>1))
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
if ((r_empty>=2)&&(l_empty>=2)&&((r_empty+l_empty)>=5)&&prove&&(sum>1))
    return 1;

return 0;
}


     /********* TEST 12 **********/

int test_12(int i,int j,int *next_i,int *next_j)
{
      /******* CASE 12 ********/

int test_i,test_j,flag,sum,prove;
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
    if ((p->leftdown->flag==0)&&(p->leftdown!=NULL))
         {
	   p->leftdown->flag=flag;
	   if (test_1(i,j,&test_i,&test_j))
		 {
		  prove=1;
		  *next_i=test_i;
		  *next_j=test_j;
		 }
	  p->leftdown->flag=0;
          }
      if ((p->rightup->flag==0)&&(p->rightup!=NULL))
         {
	   p->rightup->flag=flag;
	   if (test_1(i,j,&test_i,&test_j))
		 {
		 prove=1;
		 *next_i=test_i;
		 *next_j=test_j;
		 }
	  p->rightup->flag=0;
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
    if ((p->leftup->flag==0)&&(p->leftup!=NULL))
         {
	   p->leftup->flag=flag;
	   if (test_1(i,j,&test_i,&test_j))
		 {
		  prove=1;
		  *next_i=test_i;
		  *next_j=test_j;
		 }
	  p->leftup->flag=0;
          }
      if ((p->rightdown->flag==0)&&(p->rightdown!=NULL))
         {
	   p->rightdown->flag=flag;
	   if (test_1(i,j,&test_i,&test_j))
		 {
		 prove=1;
		 *next_i=test_i;
		 *next_j=test_j;
		 }
	  p->rightdown->flag=0;
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
    if ((p->left->flag==0)&&(p->left!=NULL))
         {
	   p->left->flag=flag;
	   if (test_1(i,j,&test_i,&test_j))
		 {
		  prove=1;
		  *next_i=test_i;
		  *next_j=test_j;
		 }
	  p->left->flag=0;
          }
      if ((p->right->flag==0)&&(p->right!=NULL))
         {
	   p->right->flag=flag;
	   if (test_1(i,j,&test_i,&test_j))
		 {
		 prove=1;
		 *next_i=test_i;
		 *next_j=test_j;
		 }
	  p->right->flag=0;
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
    if ((p->up->flag==0)&&(p->up!=NULL))
         {
	   p->up->flag=flag;
	   if (test_1(i,j,&test_i,&test_j))
		 {
		  prove=1;
		  *next_i=test_i;
		  *next_j=test_j;
		 }
	  p->up->flag=0;
          }
      if ((p->down->flag==0)&&(p->down!=NULL))
         {
	   p->down->flag=flag;
	   if (test_1(i,j,&test_i,&test_j))
		 {
		 prove=1;
		 *next_i=test_i;
		 *next_j=test_j;
		 }
	  p->down->flag=0;
          }
    }
if (prove==1)
   return 1;

return 0;
}


     /********* TEST 13 **********/

int test_13(int i,int j,int *next_i,int *next_j)
{
      /******* CASE 13 ********/

int test_i_1,test_j_1,test_i_2,test_j_2,flag,sum,prove;
struct chess *p,*q;
flag=table[i][j].flag;
prove=0;
if (test_5(i,j,&test_i_1,&test_j_1))
     {
       table[i][j].flag=0;
       table[test_i_1][test_j_1].flag=flag;
       if (test_1(test_i_1,test_j_1,&test_i_2,&test_j_2))
	      {
	       prove=1;
	       *next_i=test_i_1;
	       *next_j=test_j_1;
	      }
      table[i][j].flag=flag;
      table[test_i_1][test_j_1].flag=0;
       if (prove==0)
	      {
                 table[i][j].flag=0;
       table[test_i_1][test_j_1].flag=flag;
       if (test_3(test_i_1,test_j_1,&test_i_2,&test_j_2))
		    {
	       prove=1;
	       *next_i=test_i_1;
	       *next_j=test_j_1;
		    }
      table[i][j].flag=flag;
      table[test_i_1][test_j_1].flag=0;

	      }

     }

if (test_6(i,j,&test_i_1,&test_j_1))
     {
       table[i][j].flag=0;
       table[test_i_1][test_j_1].flag=flag;
       if (test_1(test_i_1,test_j_1,&test_i_2,&test_j_2))
		      {
	       prove=1;
	       *next_i=test_i_1;
	       *next_j=test_j_1;
		      }
      table[i][j].flag=flag;
      table[test_i_1][test_j_1].flag=0;
	 if (prove==0)
	    {
               table[i][j].flag=0;
       table[test_i_1][test_j_1].flag=flag;
       if (test_3(test_i_1,test_j_1,&test_i_2,&test_j_2))
		      {
	       prove=1;
	       *next_i=test_i_1;
	       *next_j=test_j_1;
		      }
      table[i][j].flag=flag;
      table[test_i_1][test_j_1].flag=0;


	    }
	 if (prove==0)
            {
		if (i>test_i_1)
		      test_i_2=test_i_1+4;
		       else
		  if (i==test_i_1)
		      test_i_2=i;
		       else
		       test_i_2=test_i_1-4;
	       if (j>test_j_1)
	       test_j_2=test_j_1+4;
	       else
	       if (j==test_j_1)
		   test_j_2=j;
		   else
	       test_j_2=test_j_1-4;
	    p=&table[test_i_2][test_j_2];
	    if ((p!=NULL)&&(p->flag==0))
		  if (between(test_i_2)&&between(test_j_2))
		   {
                    table[i][j].flag=0;
       table[test_i_2][test_j_2].flag=flag;
       if (test_1(test_i_2,test_j_2,&test_i_1,&test_j_1))
			    {
	       prove=1;
	       *next_i=test_i_2;
	       *next_j=test_j_2;

			    }
      table[i][j].flag=flag;
      table[test_i_2][test_j_2].flag=0;
		      if (prove==0)
			{

                                      table[i][j].flag=0;
       table[test_i_2][test_j_2].flag=flag;
       if (test_3(test_i_2,test_j_2,&test_i_1,&test_j_1))
			    {
	       prove=1;
	       *next_i=test_i_2;
	       *next_j=test_j_2;

			    }
      table[i][j].flag=flag;
      table[test_i_2][test_j_2].flag=0;




			}

		    }
	   }
   }


if (prove)
      return 1;
return 0;
}



     /********* TEST 14 **********/

int test_14(int i,int j,int *next_i,int *next_j)
{
      /******* CASE 14 ********/

int i1,j1,i2,j2,test_i_1,test_j_1,test_i_2,test_j_2,x_flag,test_i_3,test_j_3,flag,prove;
struct chess *p,*q;
flag=table[i][j].flag;
prove=0;
x_flag=(flag==1)?2:1;
 if (test_10(i,j,&test_i_1,&test_j_1))
     {
       table[i][j].flag=0;
       table[test_i_1][test_j_1].flag=flag;
       if (test_1(test_i_1,test_j_1,&test_i_2,&test_j_2))
	      {
	       prove=1;
	       *next_i=test_i_1;
	       *next_j=test_j_1;
	      }
      table[i][j].flag=flag;
      table[test_i_1][test_j_1].flag=0;
	if (prove==0)
	       {
                table[i][j].flag=0;
       table[test_i_1][test_j_1].flag=flag;
       if (test_3(test_i_1,test_j_1,&test_i_2,&test_j_2))
		     {
	       prove=1;
	       *next_i=test_i_1;
	       *next_j=test_j_1;
		      }
      table[i][j].flag=flag;
      table[test_i_1][test_j_1].flag=0;
		}

	 if (prove==0)
	      {
		if (i>test_i_1)
		     {
		      test_i_2=test_i_1+4;
		      test_i_3=test_i_1+5;
		     }
		       else
		  if (i==test_i_1)
		      {
		      test_i_2=i;
		      test_i_3=i;
		      }
		       else
		       {
		       test_i_2=test_i_1-4;
		       test_i_3=test_i_1-5;

		       }
	       if (j>test_j_1)
	       {
	       test_j_2=test_j_1+4;
	       test_j_3=test_j_1+5;
	       }
	       else
	       if (j==test_j_1)
		   {
		   test_j_2=j;
		   test_j_3=j;
		   }
		   else
	       {
	       test_j_2=test_j_1-4;
	       test_j_3=test_j_1-5;
	       }
	    p=&table[test_i_2][test_j_2];
	    q=&table[test_i_3][test_j_3];
	    if ((p!=NULL)&&(p->flag==0))
		    if ((q!=NULL)&&(q->flag!=x_flag))
		    if (between(test_i_2)&&between(test_j_2))
		      if (between(test_i_3)&&between(test_j_3))
			      {
                    table[i][j].flag=0;
       table[test_i_2][test_j_2].flag=flag;
       if (test_1(test_i_2,test_j_2,&test_i_1,&test_j_1))
					  {
	       prove=1;
	       *next_i=test_i_2;
	       *next_j=test_j_2;

					   }
      table[i][j].flag=flag;
      table[test_i_2][test_j_2].flag=0;
			   if (prove==0)
				     {

                                     table[i][j].flag=0;
       table[test_i_2][test_j_2].flag=flag;
       if (test_3(test_i_2,test_j_2,&test_i_1,&test_j_1))
					    {
	       prove=1;
	       *next_i=test_i_2;
	       *next_j=test_j_2;

					     }
      table[i][j].flag=flag;
      table[test_i_2][test_j_2].flag=0;
					}
				 }
       }

  }
if ((prove==0)&&(test_9(i,j,&test_i_1,&test_j_1)))
     {
       table[i][j].flag=0;
       table[test_i_1][test_j_1].flag=flag;
       if (test_1(test_i_1,test_j_1,&test_i_2,&test_j_2))
	      {
	       prove=1;
	       *next_i=test_i_1;
	       *next_j=test_j_1;
	      }
      table[i][j].flag=flag;
      table[test_i_1][test_j_1].flag=0;
       if (prove==0)
	    {
	     table[i][j].flag=0;
	     table[test_i_1][test_j_1].flag=flag;
	    if (test_3(test_i_1,test_j_1,&test_i_2,&test_j_2))
		     {
	       prove=1;
	       *next_i=test_i_1;
	       *next_j=test_j_1;
		     }
      table[i][j].flag=flag;
      table[test_i_1][test_j_1].flag=0;
	     }
     }

if ((prove==0)&&(test_8(i,j,&test_i_1,&test_j_1)))
     {
       table[i][j].flag=0;
       table[test_i_1][test_j_1].flag=flag;
       if (test_1(test_i_1,test_j_1,&test_i_2,&test_j_2))
		      {
	       prove=1;
	       *next_i=test_i_1;
	       *next_j=test_j_1;
		      }
      table[i][j].flag=flag;
      table[test_i_1][test_j_1].flag=0;
	 if (prove==0)
	   {
             table[i][j].flag=0;
       table[test_i_1][test_j_1].flag=flag;
       if (test_3(test_i_1,test_j_1,&test_i_2,&test_j_2))
		      {
	       prove=1;
	       *next_i=test_i_1;
	       *next_j=test_j_1;
		      }
      table[i][j].flag=flag;
      table[test_i_1][test_j_1].flag=0;
	   }
	 if (prove==0)
            {
	      if (i>test_i_1)
		      {
		      test_i_2=test_i_1+3;
		       test_i_3=test_i_1+4;
		      }
		       else
		  if (i==test_i_1)
		      {
		      test_i_2=i;
		      test_i_3=i;
		      }
		       else
		       {
		       test_i_2=test_i_1-3;
		       test_i_3=test_i_1-4;
		       }
	       if (j>test_j_1)
	       {
	       test_j_2=test_j_1+3;
	       test_j_3=test_j_1+4;
	       }
	       else
	       if (j==test_j_1)
		   {
		   test_j_2=j;
		   test_j_3=j;
		   }
		   else
	       {
	       test_j_2=test_j_1-3;
	       test_j_3=test_j_1-4;
	       }
	    p=&table[test_i_2][test_j_2];
	      q=&table[test_i_3][test_j_3];
		if ((p!=NULL)&&(p->flag==0))
		 if (between(test_i_2)&&between(test_j_2))
		 if ((q!=NULL)&&(q->flag!=x_flag))
		    if (between(test_i_3)&&between(test_j_3))
		    {
		      table[i][j].flag=0;
       table[test_i_2][test_j_2].flag=flag;
       if (test_1(test_i_2,test_j_2,&test_i_1,&test_j_1))
			    {
	       prove=1;
	       *next_i=test_i_2;
	       *next_j=test_j_2;

			    }
      table[i][j].flag=flag;
      table[test_i_2][test_j_2].flag=0;
			   if (prove==0)
			       {

                                     table[i][j].flag=0;
       table[test_i_2][test_j_2].flag=flag;
       if (test_3(test_i_2,test_j_2,&test_i_1,&test_j_1))
			    {
	       prove=1;
	       *next_i=test_i_2;
	       *next_j=test_j_2;

			    }
      table[i][j].flag=flag;
      table[test_i_2][test_j_2].flag=0;
			       }
		    }

	}
  }
if ((prove==0)&&(test_6(i,j,&test_i_1,&test_j_1)))
   {
    table[test_i_1][test_j_1].flag=flag;
    if (test_4(test_i_1,test_j_1,&test_i_2,&test_j_2))
          {    prove=1;  *next_i=test_i_1; *next_j=test_j_1; }
              else
     if (test_5(test_i_1,test_j_1,&test_i_2,&test_j_2))
           {    prove=1;  *next_i=test_i_1; *next_j=test_j_1; }
    table[test_i_1][test_j_1].flag=0;
   }
if ((prove==0)&&test_16(i,j,&i1,&j1,&i2,&j2))
 {
    table[i][j].flag=x_flag;
    table[i1][j1].flag=flag;
     if (test_1(i1,j1,&test_i_2,&test_j_2)||test_3(i1,j1,&test_i_2,&test_j_2))
	      {
	prove=1;
	*next_i=i1;
	*next_j=j1;
	     }
     table[i1][j1].flag=0;
     if (prove==0)
      {
       table[i2][j2].flag=flag;
	if (test_1(i2,j2,&test_i_2,&test_j_2)||test_3(i2,j2,&test_i_2,&test_j_2))
	      {
	prove=1;
	*next_i=i2;
	*next_j=j2;
	     }
     table[i2][j2].flag=0;
       }
   table[i][j].flag=flag;
 }


if (prove)
      return 1;
return 0;
}



     /********* TEST 15 **********/

int test_15(int i,int j,int *next_i,int *next_j)
{
      /******* CASE 15 ********/

int i1,j1,i2,j2,test_i_1,test_j_1,test_i_2,test_j_2,test_i_4,test_j_4,x_flag,test_i_3,test_j_3,flag,prove;
struct chess *p,*q;
flag=table[i][j].flag;
prove=0;
x_flag=(flag==1)?2:1;
 if (test_10(i,j,&test_i_1,&test_j_1))
     {
       table[i][j].flag=0;
       table[test_i_1][test_j_1].flag=flag;
       if (test_5(test_i_1,test_j_1,&test_i_2,&test_j_2))
	      {
	       prove=1;
	       *next_i=test_i_1;
	       *next_j=test_j_1;
	      }
      table[i][j].flag=flag;
      table[test_i_1][test_j_1].flag=0;
	if (prove==0)
	       {
                table[i][j].flag=0;
       table[test_i_1][test_j_1].flag=flag;
       if (test_4(test_i_1,test_j_1,&test_i_2,&test_j_2))
		     {
	       prove=1;
	       *next_i=test_i_1;
	       *next_j=test_j_1;
		      }
      table[i][j].flag=flag;
      table[test_i_1][test_j_1].flag=0;
		}

	 if (prove==0)
	      {
		if (i>test_i_1)
		     {
		      test_i_2=test_i_1+4;
		      test_i_3=test_i_1+5;
		     }
		       else
		  if (i==test_i_1)
		      {
		      test_i_2=i;
		      test_i_3=i;
		      }
		       else
		       {
		       test_i_2=test_i_1-4;
		       test_i_3=test_i_1-5;

		       }
	       if (j>test_j_1)
	       {
	       test_j_2=test_j_1+4;
	       test_j_3=test_j_1+5;
	       }
	       else
	       if (j==test_j_1)
		   {
		   test_j_2=j;
		   test_j_3=j;
		   }
		   else
	       {
	       test_j_2=test_j_1-4;
	       test_j_3=test_j_1-5;
	       }
	    p=&table[test_i_2][test_j_2];
	    q=&table[test_i_3][test_j_3];
	    if ((p!=NULL)&&(p->flag==0))
		    if ((q!=NULL)&&(q->flag!=x_flag))
                     if (between(test_i_3)&&between(test_j_3))
			if (between(test_i_2)&&between(test_j_2))
			      {
                    table[i][j].flag=0;
       table[test_i_2][test_j_2].flag=flag;
       if (test_5(test_i_2,test_j_2,&test_i_1,&test_j_1))
					  {
	       prove=1;
	       *next_i=test_i_2;
	       *next_j=test_j_2;

					   }
      table[i][j].flag=flag;
      table[test_i_2][test_j_2].flag=0;
			   if (prove==0)
				     {

                                     table[i][j].flag=0;
       table[test_i_2][test_j_2].flag=flag;
       if (test_4(test_i_2,test_j_2,&test_i_1,&test_j_1))
					    {
	       prove=1;
	       *next_i=test_i_2;
	       *next_j=test_j_2;

					     }
      table[i][j].flag=flag;
      table[test_i_2][test_j_2].flag=0;
					}
				 }
       }

  }
if (test_9(i,j,&test_i_1,&test_j_1))
     {
       table[i][j].flag=0;
       table[test_i_1][test_j_1].flag=flag;
       if (test_5(test_i_1,test_j_1,&test_i_2,&test_j_2))
	      {
	       prove=1;
	       *next_i=test_i_1;
	       *next_j=test_j_1;
	      }
      table[i][j].flag=flag;
      table[test_i_1][test_j_1].flag=0;
       if (prove==0)
	    {
	     table[i][j].flag=0;
	     table[test_i_1][test_j_1].flag=flag;
	    if (test_4(test_i_1,test_j_1,&test_i_2,&test_j_2))
		     {
	       prove=1;
	       *next_i=test_i_1;
	       *next_j=test_j_1;
		     }
      table[i][j].flag=flag;
      table[test_i_1][test_j_1].flag=0;
	     }
     }

if (test_8(i,j,&test_i_1,&test_j_1))
     {
       table[i][j].flag=0;
       table[test_i_1][test_j_1].flag=flag;
	if (test_5(test_i_1,test_j_1,&test_i_2,&test_j_2))
		      {
	       prove=1;
	       *next_i=test_i_1;
	       *next_j=test_j_1;
		      }
      table[i][j].flag=flag;
      table[test_i_1][test_j_1].flag=0;
	 if (prove==0)
	   {
             table[i][j].flag=0;
       table[test_i_1][test_j_1].flag=flag;
       if (test_4(test_i_1,test_j_1,&test_i_2,&test_j_2))
		      {
	       prove=1;
	       *next_i=test_i_1;
	       *next_j=test_j_1;
		      }
      table[i][j].flag=flag;
      table[test_i_1][test_j_1].flag=0;
	   }
	 if (prove==0)
            {
		if (i>test_i_1)
		      {
		      test_i_2=test_i_1+3;
		       test_i_3=test_i_1+4;
		      }
		       else
		  if (i==test_i_1)
		      {
		      test_i_2=i;
		      test_i_3=i;
		      }
		       else
		       {
		       test_i_2=test_i_1-3;
		       test_i_3=test_i_1-4;
		       }
	       if (j>test_j_1)
	       {
	       test_j_2=test_j_1+3;
	       test_j_3=test_j_1+4;
	       }
	       else
	       if (j==test_j_1)
		   {
		   test_j_2=j;
		   test_j_3=j;
		   }
		   else
	       {
	       test_j_2=test_j_1-3;
	       test_j_3=test_j_1-4;
	       }
	    p=&table[test_i_2][test_j_2];
	    q=&table[test_i_3][test_j_3];
		if ((p!=NULL)&&(p->flag==0))
		 if ((q!=NULL)&&(q->flag!=x_flag))
                      if (between(test_i_3)&&between(test_j_3))
			if (between(test_i_2)&&between(test_j_2))
		    {
                    table[i][j].flag=0;
       table[test_i_2][test_j_2].flag=flag;
       if (test_5(test_i_2,test_j_2,&test_i_4,&test_j_4))
			    {
	       prove=1;
	       *next_i=test_i_2;
	       *next_j=test_j_2;

			    }
      table[i][j].flag=flag;
      table[test_i_2][test_j_2].flag=0;
			   if (prove==0)
			       {

                                     table[i][j].flag=0;
       table[test_i_2][test_j_2].flag=flag;
       if (test_4(test_i_2,test_j_2,&test_i_4,&test_j_4))
			    {
	       prove=1;
	       *next_i=test_i_2;
	       *next_j=test_j_2;

			    }
      table[i][j].flag=flag;
      table[test_i_2][test_j_2].flag=0;
			       }
		    }

	}
       	 if (prove==0)
            {
		if (i>test_i_1)
		      {
		      test_i_2=test_i_1-1;
		       test_i_3=test_i_1-2;
			  }
		       else
		  if (i==test_i_1)
		      {
		      test_i_2=i;
		      test_i_3=i;
		      }
		       else
		       {
		       test_i_2=test_i_1+1;
		       test_i_3=test_i_1+2;
			}
	       if (j>test_j_1)
	       {
	       test_j_2=test_j_1-1;
	       test_j_3=test_j_1-2;
		}
	       else
	       if (j==test_j_1)
		   {
		   test_j_2=j;
		   test_j_3=j;
		    }
		   else
	       {
	       test_j_2=test_j_1+1;
	       test_j_3=test_j_1+2;
	       }
	    p=&table[test_i_2][test_j_2];
	    q=&table[test_i_3][test_j_3];
		if ((p!=NULL)&&(p->flag==0))
		 if ((q!=NULL)&&(q->flag!=x_flag))
                      if (between(test_i_3)&&between(test_j_3))
			if (between(test_i_2)&&between(test_j_2))
			      {
                    table[i][j].flag=0;
       table[test_i_2][test_j_2].flag=flag;
       if (test_5(test_i_2,test_j_2,&test_i_4,&test_j_4))
			    {
	       prove=1;
	       *next_i=test_i_2;
	       *next_j=test_j_2;

			    }
      table[i][j].flag=flag;
      table[test_i_2][test_j_2].flag=0;
			   if (prove==0)
			       {

                                     table[i][j].flag=0;
       table[test_i_2][test_j_2].flag=flag;
       if (test_4(test_i_2,test_j_2,&test_i_4,&test_j_4))
			    {
	       prove=1;
	       *next_i=test_i_2;
	       *next_j=test_j_2;

			    }
      table[i][j].flag=flag;
      table[test_i_2][test_j_2].flag=0;
			       }
		    }
	}
        	 if (prove==0)
            {
		if (i<test_i_1)
		      {
		      test_i_2=test_i_1-4;
		       test_i_3=test_i_1-5;
			  }
		       else
		  if (i==test_i_1)
		      {
		      test_i_2=i;
		      test_i_3=i;
		      }
		       else
		       {
		       test_i_2=test_i_1+4;
		       test_i_3=test_i_1+5;
			}
	       if (j<test_j_1)
	       {
	       test_j_2=test_j_1-4;
	       test_j_3=test_j_1-5;
		}
	       else
	       if (j==test_j_1)
		   {
		   test_j_2=j;
		   test_j_3=j;
		    }
		   else
	       {
	       test_j_2=test_j_1+4;
	       test_j_3=test_j_1+5;
	       }
	    p=&table[test_i_2][test_j_2];
	    q=&table[test_i_3][test_j_3];
		if ((p!=NULL)&&(p->flag==0))
		 if ((q!=NULL)&&(q->flag!=x_flag))
                      if (between(test_i_3)&&between(test_j_3))
			if (between(test_i_2)&&between(test_j_2))
			      {
                    table[i][j].flag=0;
       table[test_i_2][test_j_2].flag=flag;
       if (test_5(test_i_2,test_j_2,&test_i_1,&test_j_1))
			    {
	       prove=1;
	       *next_i=test_i_2;
	       *next_j=test_j_2;
			    }
      table[i][j].flag=flag;
      table[test_i_2][test_j_2].flag=0;
			   if (prove==0)
			       {
                                     table[i][j].flag=0;
       table[test_i_2][test_j_2].flag=flag;
       if (test_4(test_i_2,test_j_2,&test_i_1,&test_j_1))
			    {
	       prove=1;
	       *next_i=test_i_2;
	       *next_j=test_j_2;
			    }
      table[i][j].flag=flag;
      table[test_i_2][test_j_2].flag=0;
			       }
		    }   }  }
if ((prove==0)&&test_16(i,j,&i1,&j1,&i2,&j2))
 {
    table[i][j].flag=x_flag;
    table[i1][j1].flag=flag;
     if (test_4(i1,j1,&test_i_2,&test_j_2)||test_5(i1,j1,&test_i_2,&test_j_2))
	      {
	prove=1;
	*next_i=i1;
	*next_j=j1;
	     }
     table[i1][j1].flag=0;
     if (prove==0)
      {
       table[i2][j2].flag=flag;
	if (test_4(i2,j2,&test_i_2,&test_j_2)||test_5(i2,j2,&test_i_2,&test_j_2))
	      {
	prove=1;
	*next_i=i2;
	*next_j=j2;
	     }
     table[i2][j2].flag=0;
       }
   table[i][j].flag=flag;
 }
if (prove)
      return 1;
return 0;
}
int test_16(int i,int j,int *next_i,int *next_j,int *ni,int *nj)
{
      /******* CASE :1 AND 2 ********/

int prove,flag,x_flag;
struct chess *p,*p1;
flag=table[i][j].flag;
p=&table[i][j];
prove=0;
x_flag=(flag==1)?2:1;

   /*** LINE '\' ***/
if (prove==0)
{
p=&table[i][j];
if ((p->leftup->flag==0)&&(p->rightdown->flag==0))
 if ((p->leftup!=NULL)&&(p->rightdown!=NULL))
  {
   p1=p->rightdown->rightdown;
   if ((p1!=NULL)&&(p1->rightdown!=NULL)&&(p1->rightdown->rightdown!=NULL))
     if ((p1->flag==0)&&(p1->rightdown->flag==flag)&&(p1->rightdown->rightdown->flag!=x_flag))
    {
     prove=1;
     *next_i=i+1;
     *next_j=j+1;
     *ni=i+2;
     *nj=j+2;
    }
   if (prove==0)
    {
      p1=p->leftup->leftup;
   if ((p1!=NULL)&&(p1->leftup!=NULL)&&(p1->leftup->leftup!=NULL))
     if ((p1->flag==0)&&(p1->leftup->flag==flag)&&(p1->leftup->leftup->flag!=x_flag))
	{
     prove=1;
     *next_i=i-1;
     *next_j=j-1;
     *ni=i-2;
     *nj=j-2;
	}
    }
  }
if (prove==1)
 return 1;

}

 /**** LINE '/' ******/
if (prove==0)
 {
 p=&table[i][j];
if ((p->rightup->flag==0)&&(p->leftdown->flag==0))
 if ((p->rightup!=NULL)&&(p->leftdown!=NULL))
  {
   p1=p->leftdown->leftdown;
   if ((p1!=NULL)&&(p1->leftdown!=NULL)&&(p1->leftdown->leftdown!=NULL))
     if ((p1->flag==0)&&(p1->leftdown->flag==flag)&&(p1->leftdown->leftdown->flag!=x_flag))
    {
     prove=1;
     *next_i=i+1;
     *next_j=j-1;
     *ni=i+2;
     *nj=j-2;
    }
   if (prove==0)
    {
      p1=p->rightup->rightup;
   if ((p1!=NULL)&&(p1->rightup!=NULL)&&(p1->rightup->rightup!=NULL))
     if ((p1->flag==0)&&(p1->rightup->flag==flag)&&(p1->rightup->rightup->flag!=x_flag))
	{
     prove=1;
     *next_i=i-1;
     *next_j=j+1;
     *ni=i-2;
     *nj=j+2;
	}
    }
  }
if (prove==1)
 return 1;

 }

   /*** LINE '--' ***/
if (prove==0)
{
p=&table[i][j];
if ((p->left->flag==0)&&(p->right->flag==0))
 if ((p->left!=NULL)&&(p->right!=NULL))
  {
   p1=p->right->right;
   if ((p1!=NULL)&&(p1->right!=NULL)&&(p1->right->right!=NULL))
     if ((p1->flag==0)&&(p1->right->flag==flag)&&(p1->right->right->flag!=x_flag))
    {
     prove=1;
     *next_i=i;
     *next_j=j+1;
     *ni=i;
     *nj=j+2;
    }
   if (prove==0)
    {
      p1=p->left->left;
   if ((p1!=NULL)&&(p1->left!=NULL)&&(p1->left->left!=NULL))
     if ((p1->flag==0)&&(p1->left->flag==flag)&&(p1->left->left->flag!=x_flag))
	{
     prove=1;
     *next_i=i;
     *next_j=j-1;
     *ni=i;
     *nj=j-2;
	}
    }
  }
if (prove==1)
 return 1;

}

 /**** LINE '|' ******/
if (prove==0)
 {
 p=&table[i][j];
if ((p->up->flag==0)&&(p->down->flag==0))
 if ((p->up!=NULL)&&(p->down!=NULL))
  {
   p1=p->down->down;
   if ((p1!=NULL)&&(p1->down!=NULL)&&(p1->down->down!=NULL))
     if ((p1->flag==0)&&(p1->down->flag==flag)&&(p1->down->down->flag!=x_flag))
    {
     prove=1;
     *next_i=i+1;
     *next_j=j;
     *ni=i+2;
     *nj=j;
    }
   if (prove==0)
    {
      p1=p->up->up;
   if ((p1!=NULL)&&(p1->up!=NULL)&&(p1->up->up!=NULL))
     if ((p1->flag==0)&&(p1->up->flag==flag)&&(p1->up->up->flag!=x_flag))
	{
     prove=1;
     *next_i=i-1;
     *next_j=j;
     *ni=i-2;
     *nj=j;
	}
    }
  }
if (prove==1)
 return 1;

 }
 return 0;
}

     /********* TEST 17 **********/

int test_17(int i,int j,int *next_i,int *next_j)
{
      /******* CASE 17 ********/

int i_1,j_1,i_2,j_2,x_flag,flag,prove;
flag=table[i][j].flag;
prove=0;
x_flag=(flag==1)?2:1;
if (test_9(i,j,&i_1,&j_1))
  {
   table[i][j].flag=x_flag;
   table[i_1][j_1].flag=flag;
     if (test_8(i_1,j_1,&i_2,&j_2)||test_9(i_1,j_1,&i_2,&j_2)||test_6(i_1,j_1,&i_2,&j_2)||test_12(i_1,j_1,&i_2,&j_2))
       {
	prove=1;
	*next_i=i_1;
	*next_j=j_1;
       }

   table[i][j].flag=flag;
   table[i_1][j_1].flag=0;

  }
if (prove==1)
 return 1;
 else
  return 0;
}

     /********* TEST 18 **********/

int test_18(int i,int j,int *next_i,int *next_j)
{
      /******* CASE 18 ********/

int i1,j1,test_i_1,test_j_1,test_i_2,test_j_2,x_flag,test_i_3,test_j_3,flag,prove;
struct chess *p,*q;
flag=table[i][j].flag;
prove=0;
x_flag=(flag==1)?2:1;

if ((prove==0)&&(test_9(i,j,&test_i_1,&test_j_1)))
     {
       table[i][j].flag=x_flag;
       table[test_i_1][test_j_1].flag=flag;
       if (test_6(test_i_1,test_j_1,&test_i_2,&test_j_2)||test_8(test_i_1,test_j_1,&test_i_2,&test_j_2)||test_9(test_i_1,test_j_1,&test_i_2,&test_j_2)||test_12(test_i_1,test_j_1,&test_i_2,&test_j_2))
		     {
	       prove=1;
	       *next_i=test_i_1;
	       *next_j=test_j_1;
		    }
      table[i][j].flag=flag;
      table[test_i_1][test_j_1].flag=0;
       }
if (prove)
      return 1;

if ((prove==0)&&(test_8(i,j,&test_i_1,&test_j_1)))
     {
       table[i][j].flag=x_flag;
       table[test_i_1][test_j_1].flag=flag;
       if  (test_6(test_i_1,test_j_1,&test_i_2,&test_j_2)||test_8(test_i_1,test_j_1,&test_i_2,&test_j_2)||test_9(test_i_1,test_j_1,&test_i_2,&test_j_2)||test_12(test_i_1,test_j_1,&test_i_2,&test_j_2))
		    {
	       prove=1;
	       *next_i=test_i_1;
	       *next_j=test_j_1;
		      }
      table[i][j].flag=flag;
      table[test_i_1][test_j_1].flag=0;

	 if (prove==0)
            {
	      if (i>test_i_1)
		      {
		      test_i_2=test_i_1+3;
		       test_i_3=test_i_1+4;
		      }
		       else
		  if (i==test_i_1)
		      {
		      test_i_2=i;
		      test_i_3=i;
		      }
		       else
		       {
		       test_i_2=test_i_1-3;
		       test_i_3=test_i_1-4;
		       }
	       if (j>test_j_1)
	       {
	       test_j_2=test_j_1+3;
	       test_j_3=test_j_1+4;
	       }
	       else
	       if (j==test_j_1)
		   {
		   test_j_2=j;
		   test_j_3=j;
		   }
		   else
	       {
	       test_j_2=test_j_1-3;
	       test_j_3=test_j_1-4;
	       }
	    p=&table[test_i_2][test_j_2];
	      q=&table[test_i_3][test_j_3];
		if ((p!=NULL)&&(p->flag==0))
		 if (between(test_i_2)&&between(test_j_2))
		 if ((q!=NULL)&&(q->flag!=x_flag))
		    if (between(test_i_3)&&between(test_j_3))
		    {
		      table[i][j].flag=x_flag;
       table[test_i_2][test_j_2].flag=flag;
       if (test_6(test_i_2,test_j_2,&test_i_3,&test_j_3)||test_8(test_i_2,test_j_2,&test_i_3,&test_j_3)||test_9(test_i_2,test_j_2,&test_i_3,&test_j_3)||test_12(test_i_2,test_j_2,&test_i_3,&test_j_3))
			   {
	       prove=1;
	       *next_i=test_i_2;
	       *next_j=test_j_2;

			   }
      table[i][j].flag=flag;
      table[test_i_2][test_j_2].flag=0;

		    }

	}
  }
if (prove)
      return 1;

if (prove==0)
  if (test_6(i,j,&test_i_1,&test_j_1)||test_12(i,j,&test_i_1,&test_j_1))
   {
    table[i][j].flag=x_flag;
    table[test_i_1][test_j_1].flag=flag;
    if (test_6(test_i_1,test_j_1,&test_i_2,&test_j_2)||test_8(test_i_1,test_j_1,&test_i_2,&test_j_2)||test_9(test_i_1,test_j_1,&test_i_2,&test_j_2)||test_12(test_i_1,test_j_1,&test_i_2,&test_j_2))
	  {
	     prove=1;
	   *next_i=test_i_1;
	    *next_j=test_j_1;
	  }
    table[i][j].flag=flag;
    table[test_i_1][test_j_1].flag=0;
   }
  if (prove)
      return 1;

if ((prove==0)&&test_10(i,j,&test_i_1,&test_j_1))
     {
       test_9(i,j,&i1,&j1);
       table[i1][j1].flag=x_flag;
       table[i][j].flag=x_flag;
       table[test_i_1][test_j_1].flag=flag;
       if (test_6(test_i_1,test_j_1,&test_i_2,&test_j_2)||test_8(test_i_1,test_j_1,&test_i_2,&test_j_2)||test_9(test_i_1,test_j_1,&test_i_2,&test_j_2)||test_12(test_i_1,test_j_1,&test_i_2,&test_j_2))
	    {
	       prove=1;
	       *next_i=test_i_1;
	       *next_j=test_j_1;
	      }
      table[i][j].flag=flag;
      table[test_i_1][test_j_1].flag=0;
       table[i1][j1].flag=0;
       if (prove==0)
	      {
		if (i>test_i_1)
		     {
		      test_i_2=test_i_1+4;
		      test_i_3=test_i_1+5;
		     }
		       else
		  if (i==test_i_1)
		      {
		      test_i_2=i;
		      test_i_3=i;
		      }
		       else
		       {
		       test_i_2=test_i_1-4;
		       test_i_3=test_i_1-5;

		       }
	       if (j>test_j_1)
	       {
	       test_j_2=test_j_1+4;
	       test_j_3=test_j_1+5;
	       }
	       else
	       if (j==test_j_1)
		   {
		   test_j_2=j;
		   test_j_3=j;
		   }
		   else
	       {
	       test_j_2=test_j_1-4;
	       test_j_3=test_j_1-5;
	       }
	    p=&table[test_i_2][test_j_2];
	    q=&table[test_i_3][test_j_3];
	    if ((p!=NULL)&&(p->flag==0))
		    if ((q!=NULL)&&(q->flag!=x_flag))
		    if (between(test_i_2)&&between(test_j_2))
		      if (between(test_i_3)&&between(test_j_3))
			      {
		    table[i][j].flag=x_flag;
       table[test_i_2][test_j_2].flag=flag;
	 table[i1][j1].flag=x_flag;
              if (test_6(test_i_2,test_j_2,&test_i_3,&test_j_3)||test_8(test_i_2,test_j_2,&test_i_3,&test_j_3)||test_9(test_i_2,test_j_2,&test_i_3,&test_j_3)||test_12(test_i_2,test_j_2,&test_i_3,&test_j_3))
					  {
	       prove=1;
	       *next_i=test_i_2;
	       *next_j=test_j_2;

					   }
      table[i][j].flag=flag;
      table[test_i_2][test_j_2].flag=0;
	  table[i1][j1].flag=0;

				 }
       }

  }
if (prove)
      return 1;


if (prove==0)
  if (test_16(i,j,&test_i_1,&test_j_1,&i1,&j1))
   {
    table[i][j].flag=x_flag;
    table[test_i_1][test_j_1].flag=flag;
    table[i1][j1].flag=x_flag;
    if (test_6(test_i_1,test_j_1,&test_i_2,&test_j_2)||test_8(test_i_1,test_j_1,&test_i_2,&test_j_2)||test_9(test_i_1,test_j_1,&test_i_2,&test_j_2)||test_12(test_i_1,test_j_1,&test_i_2,&test_j_2))
	  {
	     prove=1;
	   *next_i=test_i_1;
	    *next_j=test_j_1;
	  }
    table[i][j].flag=flag;
    table[test_i_1][test_j_1].flag=0;
     table[i1][j1].flag=0;
     if (prove==0)
      {
        table[i][j].flag=x_flag;
    table[i1][j1].flag=flag;
    table[test_i_1][test_j_1].flag=x_flag;
    if (test_6(i1,j1,&test_i_2,&test_j_2)||test_8(i1,j1,&test_i_2,&test_j_2)||test_9(i1,j1,&test_i_2,&test_j_2)||test_12(i1,j1,&test_i_2,&test_j_2))
	  {
	     prove=1;
	   *next_i=i1;
	    *next_j=j1;
	  }
    table[i][j].flag=flag;
    table[i1][j1].flag=0;
    table[test_i_1][test_j_1].flag=0;
      }
   }
if (prove)
      return 1;

return 0;
}

