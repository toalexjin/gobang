          /**********  GAME :   CHESS -- FIVE  ************/
	  /**********  TIME :   1999/6-1999/7  ************/
	  /**********  AUTHER : JIN LI ZHONG   ************/
#include <stdio.h>
#include <dos.h>
#include <graphics.h>
#include <time.h>
#include "button.h"
#include "screen.h"
#include "mouse.h"
#include "key.h"
#include "chess_h.h"

struct chess table[N][N];
int chess_ready;
int BOARD_BACKCOLOR,LINE_COLOR,BOARD_STYLE,WELCOME_COLOR,MAN_CHESS_COLOR,MAN_CHESS_STYLE;
int MACHINE_CHESS_COLOR,MACHINE_CHESS_STYLE,B_COLOR,B_BOTTON_BACKCOLOR,B_BOTTON_STYLE,B_BOTTON_FORECOLOR;


		       /**** PUBLIC VARIABLE *****/


int WIN_COLOR,olddisk,person,sound_ready,p,win_flag,man_auto_i,man_auto_j,man[N*N/2][2],man_value,man_ram,machine[N*N/2][2],auto_i,auto_j,machine_i,machine_ram,machine_value,machine_j,i,j,i_n,j_n,chess_count;
char B_CUSTOM_1[]={0x00,0x10,0x28,0x7c,0xba,0x7c,0xfe,0x00},B_CUSTOM_2[]={0x00,0x18,0x00,0x7e,0x24,0x24,0x7e,0x00},B_CUSTOM_3[]={0x00,0x10,0x7c,0x54,0x54,0x7c,0x10,0x00};
char *path_bak,oldpath[200];
time_t  time1,time2;
unsigned timex;
       /*****************       STRUCT CHESS      ***********************/
       /*************     FLAG=1:MAN  FLAG=2:MACHINE          ***********/
       /****** COUNT : INDICATE ORDER FOR FUNCTION UNDO AND CURRENT *****/
       /*****************    X AND Y : POSITION   ***********************/

enter_in()
{
int i,j,x1,y1,x2,y2,x_mid,y_mid;
chess_count=0;
win_flag=0;
person=1;
setcolor(15);
line(0,0,0,480);
line(0,0,640,0);
arc(260,470,90,180,470);
setfillstyle(2,HEAD_FILLCOLOR);
floodfill(2,2,15);
setcolor(0);
line(0,0,0,480);
line(0,0,640,0);
arc(260,470,90,180,470);
settextjustify(1,1);
settextstyle(WELCOME_FONT,WELCOME_DIRECTION,WELCOME_CHARSIZE);
/*
setcolor((WELCOME_COLOR==11)?4:3);
for(i=3;i>0;i--)
   outtextxy(WELCOME_X-i,WELCOME_Y+i,"WELCOME TO PLAY CHESS!");
  */
setcolor(WELCOME_COLOR);

outtextxy(WELCOME_X,WELCOME_Y,"WELCOME TO PLAY CHESS!");
win3d(BOARD_X_1,BOARD_Y_1,BOARD_X_2,BOARD_Y_2,12,5,(BOARD_BACKCOLOR==0)?15:0,1);
x1=X_1-14;
y1=Y_1-14;
x2=X_2+14;
y2=Y_2+14;
y_mid=(y1+y2)/2;
x_mid=(x1+x2)/2;
setfillstyle(BOARD_STYLE,BOARD_BACKCOLOR);
delay(2400);
for(i=2;i<=(y2-y1)/2;i++)
 {
 bar(x_mid-i,y_mid-i,x_mid+i,y_mid+i);
 delay(150);
 }
bar(x1-5,y1,x2+5,y2);

setcolor(LINE_COLOR);
/*
for (i=Y_1;i<=Y_2;i=i+HIGH)
  for(j=0;j<=X_2-X_1;j++)
   {
   line(X_1,i,X_1+j,i);
   delay(10);
   }

for(i=X_1;i<=X_2;i=i+HIGH)
 for(j=0;j<=Y_2-Y_1;j++)
   {
 line(i,Y_1,i,Y_1+j);
    delay(10);
    }
	*/
if (BOARD_BACKCOLOR!=LINE_COLOR)
{
for (i=0;i<9;i++)
  for(j=0;j<=X_2-X_1;j++)
   {
   line(X_1+i*HIGH,Y_1,X_1+i*HIGH,Y_1+j);
   line(X_1,Y_1+i*HIGH,X_1+j,Y_1+i*HIGH);
   delay(5);
   }
for (i=N-1;i>9;i--)
  for(j=0;j<=X_2-X_1;j++)
   {
   line(X_1+i*HIGH,Y_1,X_1+i*HIGH,Y_1+j);
   line(X_1,Y_1+i*HIGH,X_1+j,Y_1+i*HIGH);
   delay(5);
   }
delay(100);
for(i=0;i<9*HIGH;i++)
   {
   line(X_1+9*HIGH-i,Y_1+9*HIGH,X_1+9*HIGH+i,Y_1+9*HIGH);
   line(X_1+9*HIGH,Y_1+9*HIGH-i,X_1+9*HIGH,Y_1+9*HIGH+i);
   delay(50);
   }
}
else
{
 for(i=X_1;i<=X_2;i=i+HIGH)
 line(i,Y_1,i,Y_2);
for (i=Y_1;i<=Y_2;i=i+HIGH)
 line(X_1,i,X_2,i);

}
for(i=0;i<N;i++)
 for(j=0;j<N;j++)
  {
  table[i][j].x=X_1+HIGH*j;
  table[i][j].y=Y_1+HIGH*i;
  table[i][j].flag=0;
  table[i][j].count=0;
  }

 }

/******* GAME RENEW FOR A NEW GAME ******/


gamerenew()
{
int i,j;
mousehide();
chess_count=0;
win_flag=0;
person=1;
/*setbkcolor(3);   */
setfillstyle(BOARD_STYLE,BOARD_BACKCOLOR);
bar(X_1-10,Y_1-10,X_2+10,Y_2+10);

setcolor(LINE_COLOR);

for(i=X_1;i<=X_2;i=i+HIGH)
 line(i,Y_1,i,Y_2);
for (i=Y_1;i<=Y_2;i=i+HIGH)
 line(X_1,i,X_2,i);

for(i=0;i<N;i++)
 for(j=0;j<N;j++)
  {
  table[i][j].x=X_1+HIGH*j;
  table[i][j].y=Y_1+HIGH*i;
  table[i][j].flag=0;
  table[i][j].count=0;
  }
 }


init_button()
{
  int i,j,row,column;
  /***** DRAW BOTTON ******/
  /***** SOUND: SAVE ******/
settextjustify(1,1);
settextstyle(WELCOME_FONT,WELCOME_DIRECTION,WELCOME_CHARSIZE);
setcolor(WELCOME_COLOR);
outtextxy(WELCOME_X,WELCOME_Y,"WELCOME TO PLAY CHESS!");
/*setbkcolor(3);*/
setfillstyle(B_STYLE,B_COLOR);
setfillpattern(B_CUSTOM_1,B_COLOR);
row=(B_Y2-B_Y1)/8;
column=(B_X2-B_X1)/8+7;
for(i=0;i<row;i++)
    for(j=0;j<column;j++)
     if ((i+j)%3==0)
      bar(B_X1+j*8,B_Y1+i*8,B_X1+j*8+8,B_Y1+i*8+8);  /* JIN */

setfillpattern(B_CUSTOM_3,B_COLOR);
for(i=0;i<row;i++)
    for(j=0;j<column;j++)
     if ((i+j)%3==2)
      bar(B_X1+j*8,B_Y1+i*8,B_X1+j*8+8,B_Y1+i*8+8);   /* ZHONG */

setfillpattern(B_CUSTOM_2,B_COLOR);
for(i=0;i<row;i++)
    for(j=0;j<column;j++)
     if ((i+j)%3==1)
      bar(B_X1+j*8,B_Y1+i*8,B_X1+j*8+8,B_Y1+i*8+8); /* LI */


/*bar(B_X1,B_Y1,B_X2,B_Y2);*/
upbox1(B_X1,B_Y1,B_X2,B_Y2);

box1(B_NEW_X1,B_NEW_Y1,B_NEW_X2,B_NEW_Y2,B_BOTTON_BACKCOLOR,B_BOTTON_STYLE);
box1(B_NEW_X1,B_LOAD_Y1,B_NEW_X2,B_LOAD_Y2,B_BOTTON_BACKCOLOR,B_BOTTON_STYLE);
box1(B_NEW_X1,B_SAVE_Y1,B_NEW_X2,B_SAVE_Y2,B_BOTTON_BACKCOLOR,B_BOTTON_STYLE);
box1(B_NEW_X1,B_CURRENT_Y1,B_NEW_X2,B_CURRENT_Y2,B_BOTTON_BACKCOLOR,B_BOTTON_STYLE);
box1(B_NEW_X1,B_UNDO_Y1,B_NEW_X2,B_UNDO_Y2,B_BOTTON_BACKCOLOR,B_BOTTON_STYLE);
box1(B_NEW_X1,B_DOS_Y1,B_NEW_X2,B_DOS_Y2,B_BOTTON_BACKCOLOR,B_BOTTON_STYLE);
box1(B_NEW_X1,B_EXIT_Y1,B_NEW_X2,B_EXIT_Y2,B_BOTTON_BACKCOLOR,B_BOTTON_STYLE);

settextjustify(1,1);
setcolor(B_BOTTON_FORECOLOR);
settextstyle(0,0,0);

outtextxy((B_NEW_X1+B_NEW_X2)/2,(B_NEW_Y2+B_NEW_Y1)/2,"NEW(/N)");
outtextxy((B_NEW_X1+B_NEW_X2)/2,(B_LOAD_Y2+B_LOAD_Y1)/2,"SETTING(/E)");
if (sound_ready)
     outtextxy((B_NEW_X1+B_NEW_X2)/2,(B_SAVE_Y2+B_SAVE_Y1)/2,"NO BELL(/B)");
   else
outtextxy((B_NEW_X1+B_NEW_X2)/2,(B_SAVE_Y2+B_SAVE_Y1)/2,"BELL(/B)");
outtextxy((B_NEW_X1+B_NEW_X2)/2,(B_CURRENT_Y2+B_CURRENT_Y1)/2,"PROMPT(/T)");
outtextxy((B_NEW_X1+B_NEW_X2)/2,(B_UNDO_Y2+B_UNDO_Y1)/2,"UNDO(/U)");
outtextxy((B_NEW_X1+B_NEW_X2)/2,(B_DOS_Y2+B_DOS_Y1)/2,"DOS(/D)");
outtextxy((B_NEW_X1+B_NEW_X2)/2,(B_EXIT_Y2+B_EXIT_Y1)/2,"EXIT(/ESC)");
effect_fan(B_X1-10,B_Y1-10,B_X2+10,B_Y1,3,0);
effect_fan(B_X1-10,B_Y1-10,B_X1,B_Y2+10,3,0);
effect_fan(B_X1-10,B_Y2,B_X2+10,B_Y2+10,3,0);
effect_fan(B_X2,B_Y1-10,B_X2+10,B_Y2+10,3,0);

}

     /********* TEST 19 **********/

int test_19(int i,int j,int *next_i,int *next_j)
{
      /******* CASE 19 ********/

int i1,j1,test_i_1,test_j_1,test_i_2,test_j_2,x_flag,test_i_3,test_j_3,flag,prove;
struct chess *p,*q;
flag=table[i][j].flag;
prove=0;
x_flag=(flag==1)?2:1;

if (test_9(i,j,&test_i_1,&test_j_1))
     {
       table[i][j].flag=x_flag;
       table[test_i_1][test_j_1].flag=flag;
       if (test_13(test_i_1,test_j_1,&test_i_2,&test_j_2)&&(prove<3))
		     {
	       prove=3;
	       *next_i=test_i_1;
	       *next_j=test_j_1;
		    }
      if (test_14(test_i_1,test_j_1,&test_i_2,&test_j_2)&&(prove<2))
		     {
	       prove=2;
	       *next_i=test_i_1;
	       *next_j=test_j_1;
		    }
      if (test_15(test_i_1,test_j_1,&test_i_2,&test_j_2)&&(prove<1))
		     {
	       prove=1;
	       *next_i=test_i_1;
	       *next_j=test_j_1;
		    }

      table[i][j].flag=flag;
      table[test_i_1][test_j_1].flag=0;
       }
if (prove==3)
      return 3;

if (test_8(i,j,&test_i_1,&test_j_1))
     {
       table[i][j].flag=x_flag;
       table[test_i_1][test_j_1].flag=flag;
        if (test_13(test_i_1,test_j_1,&test_i_2,&test_j_2)&&(prove<3))
		     {
	       prove=3;
	       *next_i=test_i_1;
	       *next_j=test_j_1;
		    }
      if (test_14(test_i_1,test_j_1,&test_i_2,&test_j_2)&&(prove<2))
		     {
	       prove=2;
	       *next_i=test_i_1;
	       *next_j=test_j_1;
		    }
      if (test_15(test_i_1,test_j_1,&test_i_2,&test_j_2)&&(prove<1))
		     {
	       prove=1;
	       *next_i=test_i_1;
	       *next_j=test_j_1;
		    }
	table[i][j].flag=flag;
      table[test_i_1][test_j_1].flag=0;

	 if (prove!=3)
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
	if (test_13(test_i_2,test_j_2,&test_i_3,&test_j_3)&&(prove<3))
		     {
	       prove=3;
	       *next_i=test_i_2;
	       *next_j=test_j_2;
		    }
      if (test_14(test_i_2,test_j_2,&test_i_3,&test_j_3)&&(prove<2))
		     {
	       prove=2;
	       *next_i=test_i_2;
	       *next_j=test_j_2;
		    }
      if (test_15(test_i_2,test_j_2,&test_i_3,&test_j_3)&&(prove<1))
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
if (prove==3)
      return 3;

if (prove!=3)
  if (test_6(i,j,&test_i_1,&test_j_1)||test_12(i,j,&test_i_1,&test_j_1))
   {
    table[i][j].flag=x_flag;
    table[test_i_1][test_j_1].flag=flag;
      if (test_13(test_i_1,test_j_1,&test_i_2,&test_j_2)&&(prove<3))
		     {
	       prove=3;
	       *next_i=test_i_1;
	       *next_j=test_j_1;
		    }
      if (test_14(test_i_1,test_j_1,&test_i_2,&test_j_2)&&(prove<2))
		     {
	       prove=2;
	       *next_i=test_i_1;
	       *next_j=test_j_1;
		    }
      if (test_15(test_i_1,test_j_1,&test_i_2,&test_j_2)&&(prove<1))
		     {
	       prove=1;
	       *next_i=test_i_1;
	       *next_j=test_j_1;
		    }
    table[i][j].flag=flag;
    table[test_i_1][test_j_1].flag=0;
   }
  if (prove==3)
      return 3;

if ((prove!=3)&&test_10(i,j,&test_i_1,&test_j_1))
     {
       test_9(i,j,&i1,&j1);
       table[i1][j1].flag=x_flag;
       table[i][j].flag=x_flag;
       table[test_i_1][test_j_1].flag=flag;
        if (test_13(test_i_1,test_j_1,&test_i_2,&test_j_2)&&(prove<3))
		     {
	       prove=3;
	       *next_i=test_i_1;
	       *next_j=test_j_1;
		    }
      if (test_14(test_i_1,test_j_1,&test_i_2,&test_j_2)&&(prove<2))
		     {
	       prove=2;
	       *next_i=test_i_1;
	       *next_j=test_j_1;
		    }
      if (test_15(test_i_1,test_j_1,&test_i_2,&test_j_2)&&(prove<1))
		     {
	       prove=1;
	       *next_i=test_i_1;
	       *next_j=test_j_1;
		    }
      table[i][j].flag=flag;
      table[test_i_1][test_j_1].flag=0;
       table[i1][j1].flag=0;
       if (prove!=3)
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
              	if (test_13(test_i_2,test_j_2,&test_i_3,&test_j_3)&&(prove<3))
		     {
	       prove=3;
	       *next_i=test_i_2;
	       *next_j=test_j_2;
		    }
      if (test_14(test_i_2,test_j_2,&test_i_3,&test_j_3)&&(prove<2))
		     {
	       prove=2;
	       *next_i=test_i_2;
	       *next_j=test_j_2;
		    }
      if (test_15(test_i_2,test_j_2,&test_i_3,&test_j_3)&&(prove<1))
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
if (prove==3)
      return 3;


if (prove!=3)
  if (test_16(i,j,&test_i_1,&test_j_1,&i1,&j1))
   {
    table[i][j].flag=x_flag;
    table[test_i_1][test_j_1].flag=flag;
    table[i1][j1].flag=x_flag;
            if (test_13(test_i_1,test_j_1,&test_i_2,&test_j_2)&&(prove<3))
		     {
	       prove=3;
	       *next_i=test_i_1;
	       *next_j=test_j_1;
		    }
      if (test_14(test_i_1,test_j_1,&test_i_2,&test_j_2)&&(prove<2))
		     {
	       prove=2;
	       *next_i=test_i_1;
	       *next_j=test_j_1;
		    }
      if (test_15(test_i_1,test_j_1,&test_i_2,&test_j_2)&&(prove<1))
		     {
	       prove=1;
	       *next_i=test_i_1;
	       *next_j=test_j_1;
		    }

    table[i][j].flag=flag;
    table[test_i_1][test_j_1].flag=0;
     table[i1][j1].flag=0;
     if (prove!=3)
      {
        table[i][j].flag=x_flag;
    table[i1][j1].flag=flag;
    table[test_i_1][test_j_1].flag=x_flag;
	    if (test_13(i1,j1,&test_i_2,&test_j_2)&&(prove<3))
		     {
	       prove=3;
	       *next_i=i1;
	       *next_j=j1;
		    }
      if (test_14(i1,j1,&test_i_2,&test_j_2)&&(prove<2))
		     {
	       prove=2;
	       *next_i=i1;
	       *next_j=j1;
		    }
      if (test_15(i1,j1,&test_i_2,&test_j_2)&&(prove<1))
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
return prove;
}


           /********** MAIN TEST **********/

/********  O:NONE ; *: OBJECT CHESS; !:HOST CHESS *******/
 /********* CASE 1---TEST_1: O!!!!O  ******/
 /********* CASE 2---TEST_1:  *!!!!O  ******/
 /********* CASE 3---TEST_3:  !O!!!  ******/
 /********* CASE 3---TEST_3:  !!!O!  ******/
 /********* CASE 4---TEST_4:  O!!!OO  ******/
 /********* CASE 5---TEST_5:  O!O!!O  ******/
 /********* CASE 6---TEST_6:  *!!!OO  ******/
 /********* CASE 8---TEST_8:  OO!!OO  ******/
 /********* CASE 9---TEST_9:  O!O!OOO ->O!!!OO ******/
 /********* CASE 10---TEST_10:O!O!OOO ->O!O!!O ******/
 /********* CASE 11---TEST_11:O!OOOO   ******/
 /********* CASE 12---TEST_12:*!!O!O   ******/
 /********* CASE 13---TEST_13:  !    ******/
 /********* CASE 13---TEST_13:!!O!O   ******/
 /********* CASE 13---TEST_13:  !    ******/
 /********* CASE 13---TEST_13:  !    ******/
 /********* CASE 13---TEST_13:  O    ******/

 /********* CASE 14---TEST_14:!!O!   ******/
 /********* CASE 14---TEST_14:  !    ******/
 /********* CASE 14---TEST_14:  !    ******/
 /********* CASE 14---TEST_14:  O    ******/

 /********* CASE 15---TEST_15:!!O    ******/
 /********* CASE 15---TEST_15:  !    ******/
 /********* CASE 15---TEST_15:  !    ******/
 /********* CASE 15---TEST_15:  O    ******/
 /********* CASE 16---TEST_16:O!OO!O ******/
 /********* CASE 17---TEST_17:O!O!OO ******/
 /*********                     !    ******/

 /********* CASE 18---TEST_18:OO!!OO ******/
 /*********                       !    ******/


int test(int i,int j,int *next_i,int *next_j)
{
int ni,i1,nj;
if (test_1(i,j,next_i,next_j))
 if (between(*next_i)&&between(*next_j)&&(table[*next_i][*next_j].flag==0))
   return 30;
if (test_3(i,j,next_i,next_j)==1)
  if (between(*next_i)&&between(*next_j)&&(table[*next_i][*next_j].flag==0))
   return 30;
if (person==2)
 if (test_4(i,j,next_i,next_j))
    if (between(*next_i)&&between(*next_j)&&(table[*next_i][*next_j].flag==0))
     return 29;
 if (person==2)
  if (test_5(i,j,next_i,next_j))
      if (between(*next_i)&&between(*next_j)&&(table[*next_i][*next_j].flag==0))
     return 29;
if (person==2)
 {
if (test_13(i,j,next_i,next_j))
  if (between(*next_i)&&between(*next_j)&&(table[*next_i][*next_j].flag==0))
   return 28;
 if (test_14(i,j,next_i,next_j))
  if (between(*next_i)&&between(*next_j)&&(table[*next_i][*next_j].flag==0))
      return 27;
}
if (person==2)
 if (test_12(i,j,next_i,next_j))
 if (between(*next_i)&&between(*next_j)&&(table[*next_i][*next_j].flag==0))
  return 26;
if (person==1)
 if (test_4(i,j,next_i,next_j))
 if (between(*next_i)&&between(*next_j)&&(table[*next_i][*next_j].flag==0))
  return 25;

if (person==1)
 if (test_5(i,j,next_i,next_j))
 if (between(*next_i)&&between(*next_j)&&(table[*next_i][*next_j].flag==0))
  return 25;
if (person==1)
 {
 if (test_13(i,j,next_i,next_j))
  if (between(*next_i)&&between(*next_j)&&(table[*next_i][*next_j].flag==0))
    return 24;
 if (test_14(i,j,next_i,next_j))
  if (between(*next_i)&&between(*next_j)&&(table[*next_i][*next_j].flag==0))
    return 23;
 }

if (person==2)
 if (test_15(i,j,next_i,next_j))
  if (between(*next_i)&&between(*next_j)&&(table[*next_i][*next_j].flag==0))
   return 22;

if (person==2)
  {
    i1=test_19(i,j,next_i,next_j);
  if (between(*next_i)&&between(*next_j)&&(table[*next_i][*next_j].flag==0))
    {
     if (i1==3)
      return 20;
     if (i1==2)
      return 19;
if (i1==1)
      return 18;
    }
  }

if (timex%3==1)
{
if ((person==2)&&(test_18(i,j,next_i,next_j)))
  if (between(*next_i)&&between(*next_j)&&(table[*next_i][*next_j].flag==0))
   return 17;
if ((person==2)&&(test_17(i,j,next_i,next_j)))
 if (between(*next_i)&&between(*next_j)&&(table[*next_i][*next_j].flag==0))
  return 16;
}
else
 {
if ((person==2)&&(test_17(i,j,next_i,next_j)))
  if (between(*next_i)&&between(*next_j)&&(table[*next_i][*next_j].flag==0))
   return 17;
if ((person==2)&&(test_18(i,j,next_i,next_j)))
 if (between(*next_i)&&between(*next_j)&&(table[*next_i][*next_j].flag==0))
  return 16;
 }
if ((person==1)&&(test_15(i,j,next_i,next_j)))
  if (between(*next_i)&&between(*next_j)&&(table[*next_i][*next_j].flag==0))
   return 15;

if ((person==2)&&(test_12(i,j,next_i,next_j)))
  if (between(*next_i)&&between(*next_j)&&(table[*next_i][*next_j].flag==0))
   return 14;
if ((person==2)&&(test_6(i,j,next_i,next_j)))
  if (between(*next_i)&&between(*next_j)&&(table[*next_i][*next_j].flag==0))
   return 14;

if ((person==2)&&(test_9(i,j,next_i,next_j)))
 {
 if ((i!=*next_i)&&(j!=*next_j))
  {
  if (test_10(i,j,next_i,next_j))
    if (between(*next_i)&&between(*next_j)&&(table[*next_i][*next_j].flag==0))
	if ((timex%2)==1)
	     return 13;
	     else
	       return 12;
  }
  else
  {
  if (test_9(i,j,next_i,next_j))
    if (between(*next_i)&&between(*next_j)&&(table[*next_i][*next_j].flag==0))
	   if ((timex%2)==0)
	     return 13;
	     else
	       return 12;
  }
}

if (timex%2==1)
{
if ((person==2)&&(test_8(i,j,next_i,next_j)))
 if (between(*next_i)&&between(*next_j)&&(table[*next_i][*next_j].flag==0))
  return 13;
if (person==2)
if (test_16(i,j,next_i,next_j,&ni,&nj))
  if (between(*next_i)&&between(*next_j)&&(table[*next_i][*next_j].flag==0))
   return 12;
 }
 else
  {
if ((person==2)&&(test_16(i,j,next_i,next_j,&ni,&nj)))
 if (between(*next_i)&&between(*next_j)&&(table[*next_i][*next_j].flag==0))
  return 13;
if (person==2)
if (test_8(i,j,next_i,next_j))
  if (between(*next_i)&&between(*next_j)&&(table[*next_i][*next_j].flag==0))
   return 12;
 }
if (person==1)
  {
    i1=test_19(i,j,next_i,next_j);
  if (between(*next_i)&&between(*next_j)&&(table[*next_i][*next_j].flag==0))
    {
     if (i1==3)
      return 12;
     if (i1==2)
      return 11;
if (i1==1)
      return 10;
    }
  }
if ((person==1)&&test_17(i,j,next_i,next_j))
  if (between(*next_i)&&between(*next_j)&&(table[*next_i][*next_j].flag==0))
  {
  return 9;
  }
if ((person==1)&&test_18(i,j,next_i,next_j))
  if (between(*next_i)&&between(*next_j)&&(table[*next_i][*next_j].flag==0))
  {
  return 8;
  }


if (person==1)
  if (test_6(i,j,next_i,next_j))
   if (between(*next_i)&&between(*next_j)&&(table[*next_i][*next_j].flag==0))
   return 6;
if (person==1)
  if (test_12(i,j,next_i,next_j))
   if (between(*next_i)&&between(*next_j)&&(table[*next_i][*next_j].flag==0))
   return 6;
if (person==1)
if (test_16(i,j,next_i,next_j,&ni,&nj))
  if (between(*next_i)&&between(*next_j)&&(table[*next_i][*next_j].flag==0))
  {
  return 5;
  }
if (person==2)
if (test_11(i,j,next_i,next_j,1))
  if (between(*next_i)&&between(*next_j)&&(table[*next_i][*next_j].flag==0))
  return 4;
if (test_11(i,j,next_i,next_j,0))
  if (between(*next_i)&&between(*next_j)&&(table[*next_i][*next_j].flag==0))
  return 3;

/*
if (test_14(i,j,next_i,next_j))
  if (between(*next_i)&&between(*next_j)&&(table[*next_i][*next_j].flag==0))
  return 3;
  */
return 0;
}


win(char *sentence)
{
int a,i;
struct textsettingstype b;
a=getcolor();
WIN_COLOR=((BOARD_BACKCOLOR==12)||(BOARD_BACKCOLOR==4))?1:4;
gettextsettings(&b);
chess_ready=0;
settextjustify(1,1);
settextstyle(WIN_FONT,WIN_DIRECTION,WIN_CHARSIZE);
setcolor((BOARD_BACKCOLOR==0)||(BOARD_BACKCOLOR==1)?15:0);

for(i=3;i>0;i--)
  outtextxy(WIN_X-i,WIN_Y+i,sentence);
setcolor(WIN_COLOR);

outtextxy(WIN_X,WIN_Y,sentence);
settextstyle(b.font,b.direction,b.charsize);
settextjustify(b.horiz,b.vert);
setcolor(a);
}

success(int x,int y,int dire,int fillstyle)
{
 int i,j,flag,color;
 struct chess *p;
 flag=table[x][y].flag;
 if (flag==2)
    {
     for(i=13;i>1;i--)
      if ((i!=MACHINE_CHESS_COLOR)&&(i!=MAN_CHESS_COLOR)&&(i!=BOARD_BACKCOLOR))
	if (((i+8)!=MACHINE_CHESS_COLOR)&&((i+8)!=MAN_CHESS_COLOR)&&((i+8)!=BOARD_BACKCOLOR))

     {
	color=i;
	break;
     }
  }
     else
          {
	   for(i=14;i>1;i--)
    if ((i!=MACHINE_CHESS_COLOR)&&(i!=MAN_CHESS_COLOR)&&(i!=BOARD_BACKCOLOR))
     {
       color=i;
	break;
	   }
  }
 win_flag=flag;
 if (dire==1)
     {
       /*** HENG ****/
    i=0;
    p=&table[x][y];
    while ((p->flag==flag)&&(p!=NULL))
	   {
	     win_drawcircle(x,y-i,color,fillstyle);
	     p=p->left;
	     i++;
	   }
    p=&table[x][y];
    i=0;
	while ((p->flag==flag)&&(p!=NULL))
	  {
	       win_drawcircle(x,y+i,color,fillstyle);
	       p=p->right;
	       i++;
	  }
 return;
 }
 if (dire==2)
     {
       /*** SHU ****/
    i=0;
    p=&table[x][y];
    while ((p->flag==flag)&&(p!=NULL))
	   {
	     win_drawcircle(x-i,y,color,fillstyle);
	     p=p->up;
	     i++;
	   }
    p=&table[x][y];
    i=0;
	while ((p->flag==flag)&&(p!=NULL))
	  {
	       win_drawcircle(x+i,y,color,fillstyle);
	       p=p->down;
	       i++;
	  }
 return;
 }
 if (dire==3)
     {
       /*** LINE '\' ****/
    i=0;
    p=&table[x][y];
    while ((p->flag==flag)&&(p!=NULL))
	   {
	     win_drawcircle(x-i,y-i,color,fillstyle);
	     p=p->leftup;
	     i++;
	   }
    p=&table[x][y];
    i=0;
	while ((p->flag==flag)&&(p!=NULL))
	  {
	       win_drawcircle(x+i,y+i,color,fillstyle);
	       p=p->rightdown;
	       i++;
	  }
 return;
 }
 if (dire==4)
     {
       /*** LINE '/' ****/
    i=0;
    p=&table[x][y];
    while ((p->flag==flag)&&(p!=NULL))
	   {
	     win_drawcircle(x+i,y-i,color,fillstyle);
	     p=p->leftdown;
	     i++;
	   }
    p=&table[x][y];
    i=0;
	while ((p->flag==flag)&&(p!=NULL))
	  {
	       win_drawcircle(x-i,y+i,color,fillstyle);
	       p=p->rightup;
	       i++;
	  }
 return;
 }

}/* success end */



process()
{
int dire,sound_c,i1,j1,i1_flag;
person=2;
if (chess_ready==1)
   {
	 p=0;
	   for(i=0;i<N;i++)
             for(j=0;j<N;j++)
              {
	      if (table[i][j].flag==2)
                 {
                  machine[p][0]=i;
		  machine[p][1]=j;
                  p++;
                  }
               }
	    machine_value=0;
	   time2=time(NULL);
	   timex=(unsigned)difftime(time2,time1);
	   if ((timex%2)==1)
	    {
		   for(i=0;i<p;i++)
		 {
	    machine_ram=test(machine[i][0],machine[i][1],&machine_i,&machine_j);
            if (machine_value<machine_ram)
		       {
            machine_value=machine_ram;
            auto_i=machine_i;
            auto_j=machine_j;
		       }
		 }
	   }
	   else
	       {
		for(i=p-1;i>=0;i--)
		 {
	    machine_ram=test(machine[i][0],machine[i][1],&machine_i,&machine_j);
            if (machine_value<machine_ram)
		       {
            machine_value=machine_ram;
            auto_i=machine_i;
            auto_j=machine_j;
		       }
		 }
	       }
/*** extra  test *
	 machine_value=0;
	    person=1;
	    if (test(i_n,j_n,&machine_i,&machine_j)>0)
             {
	      drawcircle(machine_i,machine_j,MACHINE_CHESS_COLOR,1);
              table[machine_i][machine_j].flag=2;
	      table[machine_i][machine_j].count=chess_count;

	      if (iswin(machine_i,machine_j,&dire))
		{
		 mousehide();
		 success(machine_i,machine_j,dire,1);
                 win("YOU HAVE BEEN DEFEATED!");
		 mouseshow();
		 }
	     }* EXTRA TEST * * * */

	  /*** TRUE PROGRAM  */
/*true */   person=1;
            p=0;
	  if (timex%2==0)
	   {
	   for(i=0;i<N;i++)
             for(j=0;j<N;j++)
              {
	      if (table[i][j].flag==1)
                 {
		  man[p][0]=i;
		  man[p][1]=j;
                  p++;
                  }
               }
	   }
	   else
	     {
		for(i=N-1;i>=0;i--)
	     for(j=N-1;j>=0;j--)
              {
	      if (table[i][j].flag==1)
                 {
		  man[p][0]=i;
		  man[p][1]=j;
                  p++;
                  }
               }
	     }
	    man_value=0;
           for(i=0;i<p;i++)
            {
	    man_ram=test(man[i][0],man[i][1],&machine_i,&machine_j);
	    if (man_value<man_ram)
              {
	    man_value=man_ram;
	    man_auto_i=machine_i;
	    man_auto_j=machine_j;
              }
           }
	  if ((man_value>machine_value)||(machine_value==0))
             {
	      if (table[man_auto_i][man_auto_j].flag==0)
		 {
	      drawcircle(man_auto_i,man_auto_j,MACHINE_CHESS_COLOR,MACHINE_CHESS_STYLE);
	      table[man_auto_i][man_auto_j].flag=2;
	      table[man_auto_i][man_auto_j].count=chess_count;
		 }
		 else
		    {
		    i1_flag=1;
		    for(i1=(int)(0.4*N);i1<(int)(0.6*N);i1++)
		       for(j1=(int)(0.4*N);j1<(int)(0.6*N);j1++)
			 if (table[i1][j1].flag==0)
			    if (i1_flag)
			    {
			    man_auto_i=i1;
			    man_auto_j=j1;
			    drawcircle(man_auto_i,man_auto_j,MACHINE_CHESS_COLOR,MACHINE_CHESS_STYLE);
	      table[man_auto_i][man_auto_j].flag=2;
	      table[man_auto_i][man_auto_j].count=chess_count;
			    i1_flag=0;
			    break;
			    }
		     if (i1_flag)
		   for(i1=(int)(0.3*N);i1<(int)(0.7*N);i1++)
		       for(j1=(int)(0.3*N);j1<(int)(0.7*N);j1++)
			 if (table[i1][j1].flag==0)
			    if (i1_flag)
			    {
			    man_auto_i=i1;
			    man_auto_j=j1;
			    drawcircle(man_auto_i,man_auto_j,MACHINE_CHESS_COLOR,MACHINE_CHESS_STYLE);
	      table[man_auto_i][man_auto_j].flag=2;
	      table[man_auto_i][man_auto_j].count=chess_count;
			    i1_flag=0;
			    break;
			    }
                       if (i1_flag)
		   for(i1=(int)(0.2*N);i<(int)(0.8*N);i1++)
		       for(j1=(int)(0.2*N);j1<(int)(0.8*N);j1++)
			 if (table[i1][j1].flag==0)
                             if (i1_flag)
			    {
			    man_auto_i=i1;
			    man_auto_j=j1;
			    drawcircle(man_auto_i,man_auto_j,MACHINE_CHESS_COLOR,MACHINE_CHESS_STYLE);
	      table[man_auto_i][man_auto_j].flag=2;
	      table[man_auto_i][man_auto_j].count=chess_count;
			    i1_flag=0;
			    break;
			    }
                        if (i1_flag)
		   for(i1=0;i1<N;i1++)
		       for(j1=0;j1<N;j1++)
			 if (table[i1][j1].flag==0)
                             if (i1_flag)
			    {
			    man_auto_i=i1;
			    man_auto_j=j1;
			    drawcircle(man_auto_i,man_auto_j,MACHINE_CHESS_COLOR,MACHINE_CHESS_STYLE);
	      table[man_auto_i][man_auto_j].flag=2;
	      table[man_auto_i][man_auto_j].count=chess_count;
			    i1_flag=0;
			    break;
			    }

		   }
	      if (iswin(man_auto_i,man_auto_j,&dire))
			  {
		success(man_auto_i,man_auto_j,dire,MACHINE_CHESS_STYLE);
                win("YOU HAVE BEEN DEFEATED!");
		 mouseshow();
		      if (sound_ready)
		      for(sound_c=0;sound_c<2;sound_c++)
			   {
			    sound(MACHINE_WIN_SOUND);
			    delay(SOUND_DELAY);
			    nosound();
			    delay(NOSOUND_DELAY);
			   }
		   }
	      }

            else
               {
		      if (table[auto_i][auto_j].flag==0)
		      {
	      drawcircle(auto_i,auto_j,MACHINE_CHESS_COLOR,MACHINE_CHESS_STYLE);
              table[auto_i][auto_j].flag=2;
	      table[auto_i][auto_j].count=chess_count;
		      }
		      else
		      {
		       i1_flag=1;
		       for(i1=(int)(0.4*N);i1<(int)(0.6*N);i1++)
		       for(j1=(int)(0.4*N);j1<(int)(0.6*N);j1++)
			 if (table[i1][j1].flag==0)
			    if (i1_flag)
			    {
			    auto_i=i1;
			    auto_j=j1;
			    drawcircle(auto_i,auto_j,MACHINE_CHESS_COLOR,MACHINE_CHESS_STYLE);
	      table[auto_i][auto_j].flag=2;
	      table[auto_i][auto_j].count=chess_count;
			    i1_flag=0;
			    break;
			    }
		     if (i1_flag)
		  for(i1=(int)(0.3*N);i1<(int)(0.7*N);i1++)
		       for(j1=(int)(0.3*N);j1<(int)(0.7*N);j1++)
			 if (table[i1][j1].flag==0)
			    if (i1_flag)
			    {
			    auto_i=i1;
			    auto_j=j1;
			    drawcircle(auto_i,auto_j,MACHINE_CHESS_COLOR,MACHINE_CHESS_STYLE);
	      table[auto_i][auto_j].flag=2;
	      table[auto_i][auto_j].count=chess_count;
			    i1_flag=0;
			    break;
			    }
                       if (i1_flag)
		   for(i1=(int)(0.2*N);i<(int)(0.8*N);i1++)
		       for(j1=(int)(0.2*N);j1<(int)(0.8*N);j1++)
			 if (table[i1][j1].flag==0)
			   if (i1_flag)
			    {
			   auto_i=i1;
			    auto_j=j1;
			    drawcircle(auto_i,auto_j,MACHINE_CHESS_COLOR,MACHINE_CHESS_STYLE);
	      table[auto_i][auto_j].flag=2;
	      table[auto_i][auto_j].count=chess_count;
			    i1_flag=0;
			    break;
			    }
                        if (i1_flag)
		   for(i1=0;i1<N;i1++)
		       for(j1=0;j1<N;j1++)
			 if (table[i1][j1].flag==0)
			    if (i1_flag)
			    {
			    auto_i=i1;
			    auto_j=j1;
			    drawcircle(auto_i,auto_j,MACHINE_CHESS_COLOR,MACHINE_CHESS_STYLE);
	      table[auto_i][auto_j].flag=2;
	      table[auto_i][auto_j].count=chess_count;
			    i1_flag=0;
			    break;
			    }
		      }
	      if (iswin(auto_i,auto_j,&dire))
		  {
		 success(auto_i,auto_j,dire,MACHINE_CHESS_STYLE);
                 win("YOU HAVE BEEN DEFEATED!");
                   mouseshow();
		      if (sound_ready)
		      for(sound_c=0;sound_c<2;sound_c++)
			   {
			    sound(MACHINE_WIN_SOUND);
			    delay(SOUND_DELAY);
			    nosound();
			    delay(NOSOUND_DELAY);
			   }


		   }

		} /*  true ***/

      }
  mouseshow();

 }
  /***** RETURN BACK *****/
returnback()
{
int i,j,dire;
setcolor(15);
line(0,0,0,480);
line(0,0,640,0);
arc(260,470,90,180,470);
setfillstyle(2,HEAD_FILLCOLOR);
floodfill(2,2,15);
setcolor(0);
line(0,0,0,480);
line(0,0,640,0);
arc(260,470,90,180,470);

win3d(BOARD_X_1,BOARD_Y_1,BOARD_X_2,BOARD_Y_2,12,5,BOARD_BACKCOLOR,BOARD_STYLE);
setcolor(LINE_COLOR);

for(i=X_1;i<=X_2;i=i+HIGH)
 line(i,Y_1,i,Y_2);
for (i=Y_1;i<=Y_2;i=i+HIGH)
 line(X_1,i,X_2,i);

for(i=0;i<N;i++)
 for(j=0;j<N;j++)
  {
  if (table[i][j].flag==1)
	 win_drawcircle(i,j,MAN_CHESS_COLOR,MAN_CHESS_STYLE);
  if (table[i][j].flag==2)
	 win_drawcircle(i,j,MACHINE_CHESS_COLOR,MACHINE_CHESS_STYLE);
  }
if (win_flag==1)
   {
    for(i=0;i<N;i++)
	for(j=0;j<N;j++)
	  if (table[i][j].flag==1)
	    if (iswin(i,j,&dire))
	      {
	      success(i,j,dire,MAN_CHESS_STYLE);
	      break;
	      }
    win("YOU ARE VICTORIOUS!");
   }
  else
    if (win_flag==2)
      {
      for(i=0;i<N;i++)
	for(j=0;j<N;j++)
	  if (table[i][j].flag==2)
	    if (iswin(i,j,&dire))
	      {
	      success(i,j,dire,MACHINE_CHESS_STYLE);
	      break;
	      }
           win("YOU HAVE BEEN DEFEATED!");
      }
}

  /***** UNDO  *******/
undo()
{
int i,j;
if (chess_count==0)
  return;
  else
    {
	 chess_ready=1;
	 win_flag=0;
	 mousehide();
	 popbox1(B_NEW_X1,B_UNDO_Y1,B_NEW_X2,B_UNDO_Y2);
	 mouseshow();
	 for(i=0;i<N;i++)
	   for(j=0;j<N;j++)
	    {
	      if (table[i][j].count==chess_count)
		  {
		    table[i][j].count=0;
		    table[i][j].flag=0;
		  }
	    }
   mousehide();
setfillstyle(BOARD_STYLE,BOARD_BACKCOLOR);
bar(X_1-10,Y_1-10,X_2+10,Y_2+10);
setcolor(LINE_COLOR);
for(i=X_1;i<=X_2;i=i+HIGH)
 line(i,Y_1,i,Y_2);
for (i=Y_1;i<=Y_2;i=i+HIGH)
 line(X_1,i,X_2,i);

for(i=0;i<N;i++)
 for(j=0;j<N;j++)
  {
  if (table[i][j].flag==1)
	 win_drawcircle(i,j,MAN_CHESS_COLOR,MAN_CHESS_STYLE);
  if (table[i][j].flag==2)
	 win_drawcircle(i,j,MACHINE_CHESS_COLOR,MACHINE_CHESS_STYLE);
  }

    mouseshow();
    chess_count--;
    return;
   }
}

       /******** CURRENT ***********/
current()
{
int cu_color,i,j,k,color;
    if (chess_count==0)
       return;
       else
    {
   mousehide();
   popbox1(B_NEW_X1,B_CURRENT_Y1,B_NEW_X2,B_CURRENT_Y2);
   mouseshow();
      if (win_flag==2)
       {
	 for(i=13;i>1;i--)
	if ((i!=MACHINE_CHESS_COLOR)&&(i!=MAN_CHESS_COLOR)&&(i!=BOARD_BACKCOLOR))
	  if  (((i-8)!=MACHINE_CHESS_COLOR)&&((i-8)!=MAN_CHESS_COLOR)&&((i-8)!=BOARD_BACKCOLOR))
	   { color=i;break;  }
       }
      else
	color=MACHINE_CHESS_COLOR;
	for(i=13;i>1;i--)
	  if ((i!=MACHINE_CHESS_COLOR)&&(i!=color)&&(i!=MAN_CHESS_COLOR)&&(i!=BOARD_BACKCOLOR))
	     if (((i-8)!=MACHINE_CHESS_COLOR)&&((i-8)!=color)&&((i-8)!=MAN_CHESS_COLOR)&&((i-8)!=BOARD_BACKCOLOR))
         	  { cu_color=i;break;}

   for(i=0;i<N;i++)
       for(j=0;j<N;j++)
	{
	  if ((table[i][j].flag==2)&&(table[i][j].count==((win_flag==1)?(chess_count-1):chess_count)))
	     {
	       for(k=0;k<6;k++)
		 {
		   mousehide();
		   if (k%2==0)
		       win_drawcircle(i,j,cu_color,MACHINE_CHESS_STYLE);
		     else
		       win_drawcircle(i,j,color,MACHINE_CHESS_STYLE);
		       mouseshow();
		       delay(10000);
		  }
		win_drawcircle(i,j,color,MACHINE_CHESS_STYLE);
		return;
	     }
    }
}
mouseshow();
}


	  /***** DOS **********/
dos()
{
 int i,j,dire;
 char tmp_path[200];
 mousehide();
 popbox1(B_NEW_X1,B_DOS_Y1,B_NEW_X2,B_DOS_Y2);
 mouseshow();
 cleardevice();
 closegraph();
 system("");
 graphinit();
 mouseinit();
 read_path(&i,tmp_path,path_bak);
 cleardevice();
 returnback();
 init_button();
 mouseshow();
}

sound_control()
{
setfillstyle(B_STYLE,B_COLOR);
popbox1(B_NEW_X1,B_SAVE_Y1,B_NEW_X2,B_SAVE_Y2);

box1(B_NEW_X1,B_SAVE_Y1,B_NEW_X2,B_SAVE_Y2,B_BOTTON_BACKCOLOR,B_BOTTON_STYLE);
settextjustify(1,1);
setcolor(B_BOTTON_FORECOLOR);
settextstyle(0,0,0);
sound_ready=(sound_ready)?0:1;
if (sound_ready)
outtextxy((B_NEW_X1+B_NEW_X2)/2,(B_SAVE_Y2+B_SAVE_Y1)/2,"NO BELL(/B)");
   else
     outtextxy((B_NEW_X1+B_NEW_X2)/2,(B_SAVE_Y2+B_SAVE_Y1)/2,"BELL(/B)");


}


	   /****************** MAIN PROGRAM *****************/
main(int argc,char *argv[])
{
int m1_exit,dire,sound_c,order_flag,enter_flag;
FILE *p;
graphinit();
gameinitweb();
mouseinit();
show_goldensoft();
cleardevice();
path_bak=argv[0];
sound_ready=0;
order_flag=0;
if (argc<0)
 exit(0);
read_path(&olddisk,oldpath,argv[0]);
_chmod("chess.jlz",1,0x20);
if ((p=fopen("chess.jlz","rb+"))==NULL)
     {  color_init();
       write_color_file();
      }
 else
    read_color(p);
enter_flag=0;
init_button();
 enter_in();
new:
time1=time(NULL);
if (enter_flag)
  gamerenew();
enter_flag=1;
mouseshow();
chess_ready=1;
m1_exit=1;
mouseshow();
if (order_flag==1)
   {     mousehide();
    win_drawcircle(8,9,MACHINE_CHESS_COLOR,MACHINE_CHESS_STYLE);
    mouseshow();
      table[8][9].flag=2;
      delay(5000);
       }

while (kbhit())
 getch();

while (m1_exit==1)
{
 /**** THE  1ST ASPECT ****/

if (inxy(X_1-EFFECT_REGION,Y_1-EFFECT_REGION,X_2+EFFECT_REGION,Y_2+EFFECT_REGION)&&(chess_ready==1))
 {
 if (mouseleft())
   {
    if(translate(&i_n,&j_n)==1)
	if (table[i_n][j_n].flag==0)
	 {
	   mousehide();
	   chess_count++;
	   drawcircle(i_n,j_n,MAN_CHESS_COLOR,MAN_CHESS_STYLE);
	      table[i_n][j_n].flag=1;
	     table[i_n][j_n].count=chess_count;
		    if (iswin(i_n,j_n,&dire))
			{
		success(i_n,j_n,dire,MAN_CHESS_STYLE);
                win("YOU ARE VICTORIOUS!");
                        mouseshow();
		      if (sound_ready)
			for(sound_c=0;sound_c<2;sound_c++)
			   {
			    sound(MAN_WIN_SOUND);
			    delay(SOUND_DELAY);
			    nosound();
			    delay(NOSOUND_DELAY);
			   }
			}
		    else
			  process();
            mouseshow();
	    delay(5000);
	}
    } /*** if mouseleft end  **/


}
 /**** THE 2ND ASPECT ****/
   if (inxy(B_NEW_X1,B_NEW_Y1,B_NEW_X2,B_NEW_Y2))
   {
    if (mouseleft())
     {
     mousehide();
     popbox1(B_NEW_X1,B_NEW_Y1,B_NEW_X2,B_NEW_Y2);
     order_flag=0;
     mouseshow();
     delay(4000);
     goto new;
      }
      if (mouseright())
     {
     mousehide();
     popbox1(B_NEW_X1,B_NEW_Y1,B_NEW_X2,B_NEW_Y2);
     order_flag=1;
     mouseshow();
     delay(4000);
     goto new;
      }
   }
   if (inxy(B_NEW_X1,B_LOAD_Y1,B_NEW_X2,B_LOAD_Y2))
   if (mouseleft())
     {
	mousehide();
	chess_set();
	mousehide();
	returnback();
	init_button();
	mouseshow();
	delay(5000);
     }
   if ((inxy(B_NEW_X1,B_SAVE_Y1,B_NEW_X2,B_SAVE_Y2))&&mouseleft())
    {
    mousehide();
    sound_control();
    mouseshow();
    delay(5000);
    }
    if ((inxy(B_NEW_X1,B_CURRENT_Y1,B_NEW_X2,B_CURRENT_Y2))&&mouseleft())
     {
     current();
     delay(4000);
     }
   if ((inxy(B_NEW_X1,B_UNDO_Y1,B_NEW_X2,B_UNDO_Y2))&&(mouseleft()))
    {
     undo();
     delay(6000);
    }
  if ((inxy(B_NEW_X1,B_DOS_Y1,B_NEW_X2,B_DOS_Y2))&&(mouseleft()))
     {
	write_path(olddisk,oldpath);
       dos();
     }
  if ((inxy(B_NEW_X1,B_EXIT_Y1,B_NEW_X2,B_EXIT_Y2))&&(mouseleft()))
   {
   mousehide();
   popbox1(B_NEW_X1,B_EXIT_Y1,B_NEW_X2,B_EXIT_Y2);
   mouseshow();
   m1_exit=0;
/*  ch_color(0,sound_ready);*/
   cleardevice();
   closegraph();
   write_path(olddisk,oldpath);
   return 1;
   }

 if (kbhit())
    switch(get_key())
	{
	 case CTRL_N: {
			   mousehide();
			   popbox1(B_NEW_X1,B_NEW_Y1,B_NEW_X2,B_NEW_Y2);
			   mouseshow();
			   delay(4000);
			   goto new;
		       }
	 case CTRL_E:  {
			mousehide();
	chess_set();
	mousehide();
	returnback();
	init_button();
	mouseshow();
	delay(5000);
	break;
			}
	 case CTRL_B:   {
			    mousehide();
			    sound_control();
			    mouseshow();
			    delay(4000);
			    break;
			  }
	case CTRL_T:   {
			    current();
			    delay(4000);
			    break;
			}
	case CTRL_U:   {
			      undo();
			      delay(6000);
			      break;
			}
	case CTRL_D:     {
			   	write_path(olddisk,oldpath);
				 dos();
				 break;
			  }
	case ESC:    {
			   mousehide();
			    popbox1(B_NEW_X1,B_EXIT_Y1,B_NEW_X2,B_EXIT_Y2);
			       mouseshow();
			  m1_exit=0;
			 /* ch_color(0,sound_ready); */
			  cleardevice();
			    closegraph();
			     write_path(olddisk,oldpath);
			      return 1;
		      }
	}/*switch*/
 }/* while end */
}
