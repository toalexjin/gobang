              /********* FILE CHESS_3.H     ***********/
              /********* CHESS FIVE SETTING ***********/
#include <stdio.h>
#include <dos.h>
#include <graphics.h>
#include <time.h>

#include "chess_h.h"

#define FILE_ATTRIB  0x22
#define INTERVAL_1 13
#define INTERVAL_2 16
#define INTERVAL_3 30
#define INTERVAL_4 208
#define FRAME_BACKCOLOR 9
#define FRAME_STYLE 9
#define SET_WIDTH 190
#define SHADOW_COLOR 8
#define SHADOW_STYLE 11
#define LINECOLOR_1 1
#define LINECOLOR_2 5
#define LABELCOLOR_1 11
#define FRAME_WORD_COLOR 10
#define FRAME_LINECOLOR_1 15
#define FRAME_LINECOLOR_2 15
#define FRAME_WORD "CUSTOM SETTING"
#define FRAME_FONT 0
#define FRAME_SIZE 2

#define TABLE_X1 14
#define TABLE_Y1 60
#define TABLE_X2 TABLE_X1+SET_WIDTH
#define TABLE_Y2 240
#define TABLE_SET_COLOR 7
#define TABLE_SET_STYLE 1
#define CHESS_SET_COLOR 7
#define CHESS_SET_STYLE 1
#define BOTTON_SET_COLOR 7
#define BOTTON_SET_STYLE 1
#define SET_WORD_COLOR 1
#define TABLE_SETWORD_X1 30
#define TABLE_SETWORD_Y1 112
#define KUAN_WIDTH 25
#define KUAN_1_X1 164
#define KUAN_1_Y1 106
#define KUAN_2_X1 KUAN_1_X1+INTERVAL_2+SET_WIDTH
#define KUAN_2_Y1 106
#define KUAN_3_X1 KUAN_2_X1+INTERVAL_2+SET_WIDTH
#define KUAN_3_Y1 106
#define SHADUME_HEIGHT 100
#define COLOR_X1 14
#define COLOR_Y1 250
#define COLOR_X2 430
#define COLOR_Y2 COLOR_Y1+SHADUME_HEIGHT
#define COLOR_SET_COLOR 1
#define COLOR_SET_STYLE 11
#define COLOR_SELECT_X1 34
#define COLOR_SELECT_Y1 300
#define STYLE_X1 COLOR_X1
#define STYLE_Y1 358
#define STYLE_X2 430
#define STYLE_Y2 STYLE_Y1+SHADUME_HEIGHT
#define STYLE_SET_COLOR 1
#define STYLE_SET_STYLE 11
#define STYLE_SELECT_X1 34
#define STYLE_SELECT_Y1 410
#define COLOR_INTERVAL_1 35
#define COLOR_INTERVAL_2 35
#define COLOR_ITEM_X1 140
#define COLOR_ITEM_Y1  264
#define STYLE_ITEM_X1 156
#define STYLE_ITEM_Y1  374
#define COMMAND_FRAME_X1 440
#define COMMAND_FRAME_Y1 COLOR_Y1
#define COMMAND_FRAME_X2 617
#define COMMAND_FRAME_Y2 STYLE_Y2
#define ENTER_X1 475
#define ENTER_Y1 285
#define ENTER_WIDTH 18
#define COMMAND_INTERVAL_1 30
#define COMMAND_INTERVAL_2 44
#define COMMAND_ITEM_COLOR 7
#define COMMAND_SELECT_COLOR 10
#define COMMAND_BUTTON_X1 COMMAND_FRAME_X1+40
#define COMMAND_BUTTON_Y1 396
#define COMMAND_BUTTON_X2 COMMAND_FRAME_X2-40
#define COMMAND_BUTTON_Y2 427
#define COMMAND_BUTTON_COLOR 15
#define COMMAND_BUTTON_STYLE 1
/*
extern struct chess table[N][N];
extern int chess_ready;
*/
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


extern int BOARD_BACKCOLOR,LINE_COLOR,BOARD_STYLE,WELCOME_COLOR,MAN_CHESS_COLOR,MAN_CHESS_STYLE;
extern int MACHINE_CHESS_COLOR,MACHINE_CHESS_STYLE,B_COLOR,B_BOTTON_BACKCOLOR,B_BOTTON_STYLE,B_BOTTON_FORECOLOR;

char *path(char *str)
{
 char *p;
 int s,i,position,flag1,flag2;
 s=strlen(str);
 flag1=0;
 flag2=0;
 for(i=0;i<s;i++)
     {
	  if (str[i]=='\\')
	      {
		   position=i;
		   flag1++;
	       }
	  if (str[i]==':')
	       flag2++;
      }

if (flag1>0)
     {
	  p=(char *)malloc(position+1);
	  for (i=0;i<=position;i++)
		 p[i]=str[i];
	    p[position+1]='\0';
      }
      else
       if (flag2>0)
	   {
	     p=(char *)malloc(3);
	     p[0]=str[0];
	     p[1]=str[1];
	     p[2]='\0';
	    }
	    else
	       {
	       p=(char *)malloc(1);
	       p[0]='\0';
	       }
return p;
}


read_path(int *olddisk,char oldpath[],char *file)
{
char *new;
*olddisk=getdisk();
getcurdir(0,oldpath);
new=path(file);
   if (strlen(new)>=2)
	    if (new[1]==':')
		   setdisk(toupper(new[0])-'A');
 chdir(new);

}

write_path(int olddisk,char oldpath[])
{
setdisk(olddisk);
system("cd\\");
chdir(oldpath);
}

color_init()
{
 BOARD_BACKCOLOR=1;
 LINE_COLOR=3;
 BOARD_STYLE=1;
 WELCOME_COLOR=11;
 MAN_CHESS_COLOR=0;
 MAN_CHESS_STYLE=1;
 MACHINE_CHESS_COLOR=15;
 MACHINE_CHESS_STYLE=1;
 B_COLOR=11;
 B_BOTTON_BACKCOLOR=1;
 B_BOTTON_STYLE=9;
 B_BOTTON_FORECOLOR=15;
}

read_color(FILE *p)
{
 char r;
 r=fgetc(p),BOARD_BACKCOLOR=~r;
   r=fgetc(p),LINE_COLOR=~r;
  r=fgetc(p),BOARD_STYLE=~r;
  r=fgetc(p),WELCOME_COLOR=~r;
  r=fgetc(p),MAN_CHESS_COLOR=~r;
  r=fgetc(p),MAN_CHESS_STYLE=~r;
  r=fgetc(p),MACHINE_CHESS_COLOR=~r;
  r=fgetc(p),MACHINE_CHESS_STYLE=~r;
  r=fgetc(p),B_COLOR=~r;
  r=fgetc(p),B_BOTTON_BACKCOLOR=~r;
  r=fgetc(p),B_BOTTON_STYLE=~r;
  r=fgetc(p),B_BOTTON_FORECOLOR=~r;
 fclose(p);
_chmod("chess.jlz",1,FILE_ATTRIB);
}

write_color_file()
{
 char r,w;
 FILE *p;
  _chmod("chess.jlz",1,0x20);
  if ((p=fopen("chess.jlz","wb+"))==NULL)
   return;
 w=BOARD_BACKCOLOR;
 r=~w,fputc(r,p);
 w=LINE_COLOR;
  r=~w,fputc(r,p);
   w=BOARD_STYLE;
 r=~w,fputc(r,p);
  w=WELCOME_COLOR;
 r=~w,fputc(r,p);

 w=MAN_CHESS_COLOR;
 r=~w,fputc(r,p);

 w=MAN_CHESS_STYLE;
 r=~w,fputc(r,p);

 w=MACHINE_CHESS_COLOR;
 r=~w,fputc(r,p);

 w=MACHINE_CHESS_STYLE;
 r=~w,fputc(r,p);

 w=B_COLOR;
 r=~w,fputc(r,p);

 w=B_BOTTON_BACKCOLOR;
 r=~w,fputc(r,p);

 w=B_BOTTON_STYLE;
 r=~w,fputc(r,p);

 w=B_BOTTON_FORECOLOR;
 r=~w,fputc(r,p);

  fclose(p);
_chmod("chess.jlz",1,FILE_ATTRIB);
}

draw_fan(int x1,int y1,int x2,int y2,int color_1,int style_1,char *str)
{
setfillstyle(SHADOW_STYLE,SHADOW_COLOR);
bar(x1+INTERVAL_1,y1+INTERVAL_1,x2+INTERVAL_1,y2+INTERVAL_1);
setfillstyle(style_1,color_1);
bar(x1,y1,x2,y2);
setcolor(LINECOLOR_1);
rectangle(x1+3,y1+3,x2-3,y2-3);
rectangle(x1+6,y1+6,x2-6,y2-6);
setcolor(LABELCOLOR_1);
settextjustify(0,2);
settextstyle(0,0,0);
outtextxy(x1+16,y1+16,str);
setcolor(LINECOLOR_2);
line(x1+16,y1+30,x1+16+strlen(str)*8,y1+30);
line(x1+16,y1+33,x1+16+strlen(str)*8,y1+33);
}

write_word(int x1,int y1,char *str1,char *str2,char *str3,char *str4)
{
setcolor(SET_WORD_COLOR);
settextjustify(0,2);
settextstyle(0,0,0);
outtextxy(x1,y1,str1);
outtextxy(x1,y1+INTERVAL_3,str2);
outtextxy(x1,y1+INTERVAL_3*2,str3);
outtextxy(x1,y1+INTERVAL_3*3,str4);
}

draw_frame()
{
setfillstyle(FRAME_STYLE,FRAME_BACKCOLOR);
bar(0,0,639,479);
setcolor(FRAME_LINECOLOR_1);
rectangle(3,3,636,476);
rectangle(6,6,633,473);
setcolor(FRAME_WORD_COLOR);
settextjustify(0,2);
settextstyle(FRAME_FONT,0,FRAME_SIZE);
outtextxy(16,19,FRAME_WORD);
setcolor(FRAME_LINECOLOR_2);
line(16,44,14+strlen(FRAME_WORD)*16,44);
line(16,47,14+strlen(FRAME_WORD)*16,47);
}

draw_color(int x1,int y1,int color_1,int style_1,int color_2,int style_2,int color_3,int style_3,int color_4,int style_4)
{
box1(x1,y1,x1+KUAN_WIDTH,y1+KUAN_WIDTH,color_1,style_1);
box1(x1,y1+INTERVAL_3,x1+KUAN_WIDTH,y1+INTERVAL_3+KUAN_WIDTH,color_2,style_2);
box1(x1,y1+INTERVAL_3*2,x1+KUAN_WIDTH,y1+INTERVAL_3*2+KUAN_WIDTH,color_3,style_3);
box1(x1,y1+INTERVAL_3*3,x1+KUAN_WIDTH,y1+INTERVAL_3*3+KUAN_WIDTH,color_4,style_4);
prsbox1(x1,y1,x1+KUAN_WIDTH,y1+KUAN_WIDTH);
prsbox1(x1,y1+INTERVAL_3,x1+KUAN_WIDTH,y1+INTERVAL_3+KUAN_WIDTH);
prsbox1(x1,y1+INTERVAL_3*2,x1+KUAN_WIDTH,y1+INTERVAL_3*2+KUAN_WIDTH);
prsbox1(x1,y1+INTERVAL_3*3,x1+KUAN_WIDTH,y1+INTERVAL_3*3+KUAN_WIDTH);
}

draw_color_table(int color,int style)
{
int i;
for(i=0;i<8;i++)
    {
     box1(COLOR_ITEM_X1+COLOR_INTERVAL_1*i,COLOR_ITEM_Y1,COLOR_ITEM_X1+COLOR_INTERVAL_1*i+KUAN_WIDTH,COLOR_ITEM_Y1+KUAN_WIDTH,i,1);
     prsbox1(COLOR_ITEM_X1+COLOR_INTERVAL_1*i,COLOR_ITEM_Y1,COLOR_ITEM_X1+COLOR_INTERVAL_1*i+KUAN_WIDTH,COLOR_ITEM_Y1+KUAN_WIDTH);
    }
for(i=0;i<8;i++)
    {
     box1(COLOR_ITEM_X1+COLOR_INTERVAL_1*i,COLOR_ITEM_Y1+COLOR_INTERVAL_2,COLOR_ITEM_X1+COLOR_INTERVAL_1*i+KUAN_WIDTH,COLOR_ITEM_Y1+COLOR_INTERVAL_2+KUAN_WIDTH,(15-i),1);
     prsbox1(COLOR_ITEM_X1+COLOR_INTERVAL_1*i,COLOR_ITEM_Y1+COLOR_INTERVAL_2,COLOR_ITEM_X1+COLOR_INTERVAL_1*i+KUAN_WIDTH,COLOR_ITEM_Y1+COLOR_INTERVAL_2+KUAN_WIDTH);
    }
for(i=0;i<6;i++)
    {
     box1(STYLE_ITEM_X1+COLOR_INTERVAL_1*i,STYLE_ITEM_Y1,STYLE_ITEM_X1+COLOR_INTERVAL_1*i+KUAN_WIDTH,STYLE_ITEM_Y1+KUAN_WIDTH,14-i,i+1);
     prsbox1(STYLE_ITEM_X1+COLOR_INTERVAL_1*i,STYLE_ITEM_Y1,STYLE_ITEM_X1+COLOR_INTERVAL_1*i+KUAN_WIDTH,STYLE_ITEM_Y1+KUAN_WIDTH);
    }
for(i=0;i<5;i++)
    {
     box1(STYLE_ITEM_X1+COLOR_INTERVAL_1*i,STYLE_ITEM_Y1+COLOR_INTERVAL_2,STYLE_ITEM_X1+COLOR_INTERVAL_1*i+KUAN_WIDTH,STYLE_ITEM_Y1+COLOR_INTERVAL_2+KUAN_WIDTH,8-i,(i+7));
     prsbox1(STYLE_ITEM_X1+COLOR_INTERVAL_1*i,STYLE_ITEM_Y1+COLOR_INTERVAL_2,STYLE_ITEM_X1+COLOR_INTERVAL_1*i+KUAN_WIDTH,STYLE_ITEM_Y1+COLOR_INTERVAL_2+KUAN_WIDTH);
    }
     box1(COLOR_SELECT_X1,COLOR_SELECT_Y1,COLOR_SELECT_X1+KUAN_WIDTH*3,COLOR_SELECT_Y1+KUAN_WIDTH,color,1);
     prsbox1(COLOR_SELECT_X1,COLOR_SELECT_Y1,COLOR_SELECT_X1+KUAN_WIDTH*3,COLOR_SELECT_Y1+KUAN_WIDTH);
     box1(STYLE_SELECT_X1,STYLE_SELECT_Y1,STYLE_SELECT_X1+KUAN_WIDTH*3,STYLE_SELECT_Y1+KUAN_WIDTH,color,style);
     prsbox1(STYLE_SELECT_X1,STYLE_SELECT_Y1,STYLE_SELECT_X1+KUAN_WIDTH*3,STYLE_SELECT_Y1+KUAN_WIDTH);
}

draw_command_frame()
{
 setfillstyle(1,0);
 bar(COMMAND_FRAME_X1+INTERVAL_1,COMMAND_FRAME_Y1+INTERVAL_1,COMMAND_FRAME_X2+INTERVAL_1,COMMAND_FRAME_Y2+INTERVAL_1);
 setfillstyle(9,1);
 bar(COMMAND_FRAME_X1,COMMAND_FRAME_Y1,COMMAND_FRAME_X2,COMMAND_FRAME_Y2);
 setcolor(15);
 line(COMMAND_FRAME_X1+11,COMMAND_FRAME_Y1+11,COMMAND_FRAME_X1+11,COMMAND_FRAME_Y2-11);
 line(COMMAND_FRAME_X1+11,COMMAND_FRAME_Y1+11,COMMAND_FRAME_X2-11,COMMAND_FRAME_Y1+11);
 setcolor(0);
 line(COMMAND_FRAME_X1+11,COMMAND_FRAME_Y2-11,COMMAND_FRAME_X2-11,COMMAND_FRAME_Y2-11);
 line(COMMAND_FRAME_X2-11,COMMAND_FRAME_Y1+11,COMMAND_FRAME_X2-11,COMMAND_FRAME_Y2-11);
 setcolor(0);
 line(COMMAND_FRAME_X1+21,COMMAND_FRAME_Y1+21,COMMAND_FRAME_X1+21,COMMAND_FRAME_Y2-80);
 line(COMMAND_FRAME_X1+21,COMMAND_FRAME_Y2-70,COMMAND_FRAME_X1+21,COMMAND_FRAME_Y2-21);
 line(COMMAND_FRAME_X1+21,COMMAND_FRAME_Y1+21,COMMAND_FRAME_X2-21,COMMAND_FRAME_Y1+21);
 setcolor(15);
 line(COMMAND_FRAME_X2-21,COMMAND_FRAME_Y1+21,COMMAND_FRAME_X2-21,COMMAND_FRAME_Y2-80);
 line(COMMAND_FRAME_X2-21,COMMAND_FRAME_Y2-70,COMMAND_FRAME_X2-21,COMMAND_FRAME_Y2-21);
 line(COMMAND_FRAME_X1+21,COMMAND_FRAME_Y2-21,COMMAND_FRAME_X2-21,COMMAND_FRAME_Y2-21);
 prstriangle(ENTER_X1,ENTER_Y1,ENTER_X1+ENTER_WIDTH,ENTER_Y1+ENTER_WIDTH,COMMAND_SELECT_COLOR);
 triangle(ENTER_X1,ENTER_Y1+COMMAND_INTERVAL_1,ENTER_X1+ENTER_WIDTH,ENTER_Y1+COMMAND_INTERVAL_1+ENTER_WIDTH,COMMAND_ITEM_COLOR);
 triangle(ENTER_X1,ENTER_Y1+COMMAND_INTERVAL_1*2,ENTER_X1+ENTER_WIDTH,ENTER_Y1+COMMAND_INTERVAL_1*2+ENTER_WIDTH,COMMAND_ITEM_COLOR);
 setcolor(15);
 settextjustify(0,1);
 settextstyle(0,0,0);
 outtextxy(ENTER_X1+COMMAND_INTERVAL_2,ENTER_Y1+COMMAND_INTERVAL_1+10,"CANCEL");
 outtextxy(ENTER_X1+COMMAND_INTERVAL_2,ENTER_Y1+COMMAND_INTERVAL_1*2+10,"SAVE");
 setcolor(COMMAND_SELECT_COLOR);
 outtextxy(ENTER_X1+COMMAND_INTERVAL_2,ENTER_Y1+10,"ENTER");
 setcolor(15);
 line(COMMAND_FRAME_X1+21,COMMAND_FRAME_Y2-80,COMMAND_FRAME_X2-21,COMMAND_FRAME_Y2-80);
 setcolor(0);
 line(COMMAND_FRAME_X1+21,COMMAND_FRAME_Y2-70,COMMAND_FRAME_X2-21,COMMAND_FRAME_Y2-70);
 box1(COMMAND_BUTTON_X1,COMMAND_BUTTON_Y1,COMMAND_BUTTON_X2,COMMAND_BUTTON_Y2,COMMAND_BUTTON_COLOR,COMMAND_BUTTON_STYLE);
 setcolor(0);
 settextjustify(1,1);
 settextstyle(0,0,2);
 outtextxy((COMMAND_BUTTON_X1+COMMAND_BUTTON_X2)/2,(COMMAND_BUTTON_Y1+COMMAND_BUTTON_Y2)/2,"O K");
}

draw_kuan(int x1,int y1,int color,int style)
{
 mousehide();
 box1(x1,y1,x1+KUAN_WIDTH,y1+KUAN_WIDTH,color,style);
 prsbox1(x1,y1,x1+KUAN_WIDTH,y1+KUAN_WIDTH);
 mouseshow();
}



chess_set()
{
int exit_1,i,color_ready,color_ram,style_ram,P_TABLE_BACKCOLOR,P_TABLE_LINECOLOR,P_TABLE_STYLE,P_TABLE_WELCOMECOLOR,P_CHESS_MY_COLOR,P_CHESS_MA_COLOR,P_CHESS_MY_STYLE,P_CHESS_MA_STYLE,P_BUTTON_LISTBACKCOLOR;
int P_BUTTON_BACKCOLOR,P_BUTTON_STYLE,P_BUTTON_FORECOLOR,command_select;
FILE *p;

color_ram=12;
style_ram=7;
command_select=1;
cleardevice();
setbkcolor(0);

draw_frame();
draw_fan(TABLE_X1,TABLE_Y1,TABLE_X2,TABLE_Y2,TABLE_SET_COLOR,TABLE_SET_STYLE,"CHESS-BOARD COLOR");
draw_fan(TABLE_X2+INTERVAL_2,TABLE_Y1,TABLE_X2+INTERVAL_2+SET_WIDTH,TABLE_Y2,CHESS_SET_COLOR,CHESS_SET_STYLE,"CHESS-MAN COLOR");
draw_fan(TABLE_X2+INTERVAL_2*2+SET_WIDTH,TABLE_Y1,TABLE_X2+INTERVAL_2*2+SET_WIDTH*2,TABLE_Y2,BOTTON_SET_COLOR,BOTTON_SET_STYLE,"BOTTON COLOR");
write_word(TABLE_SETWORD_X1,TABLE_SETWORD_Y1,"BACKCOLOR","LINECOLOR","PATTERN","WELCOMECOLOR");
write_word(TABLE_SETWORD_X1+INTERVAL_4,TABLE_SETWORD_Y1,"MINE","PATTERN","MACHINE'S","PATTERN");
write_word(TABLE_SETWORD_X1+INTERVAL_4*2,TABLE_SETWORD_Y1,"LIST-BACKCOLOR","BACKCOLOR","PATTERN","FORECOLOR");

P_TABLE_BACKCOLOR=BOARD_BACKCOLOR;
P_TABLE_LINECOLOR=LINE_COLOR;
P_TABLE_STYLE=BOARD_STYLE;
P_TABLE_WELCOMECOLOR=WELCOME_COLOR;
P_CHESS_MY_COLOR=MAN_CHESS_COLOR;
P_CHESS_MA_COLOR=MACHINE_CHESS_COLOR;
P_CHESS_MY_STYLE=MAN_CHESS_STYLE;
P_CHESS_MA_STYLE=MACHINE_CHESS_STYLE;
P_BUTTON_LISTBACKCOLOR=B_COLOR;
P_BUTTON_BACKCOLOR=B_BOTTON_BACKCOLOR;
P_BUTTON_STYLE=B_BOTTON_STYLE;
P_BUTTON_FORECOLOR=B_BOTTON_FORECOLOR;

draw_color(KUAN_1_X1,KUAN_1_Y1,P_TABLE_BACKCOLOR,1,P_TABLE_LINECOLOR,1,P_TABLE_BACKCOLOR,P_TABLE_STYLE,P_TABLE_WELCOMECOLOR,1);
draw_color(KUAN_2_X1,KUAN_2_Y1,P_CHESS_MY_COLOR,1,P_CHESS_MY_COLOR,P_CHESS_MY_STYLE,P_CHESS_MA_COLOR,1,P_CHESS_MA_COLOR,P_CHESS_MA_STYLE);
draw_color(KUAN_3_X1,KUAN_3_Y1,P_BUTTON_LISTBACKCOLOR,1,P_BUTTON_BACKCOLOR,1,P_BUTTON_BACKCOLOR,P_BUTTON_STYLE,P_BUTTON_FORECOLOR,1);
draw_fan(COLOR_X1,COLOR_Y1,COLOR_X2,COLOR_Y2,COLOR_SET_COLOR,COLOR_SET_STYLE,"COLOR SELECT");
draw_fan(STYLE_X1,STYLE_Y1,STYLE_X2,STYLE_Y2,STYLE_SET_COLOR,STYLE_SET_STYLE,"PATTERN SELECT");
draw_color_table(color_ram,style_ram);
draw_command_frame();
mouseshow();

exit_1=1;
while (exit_1)
{
if (mouseleft())
    {
     color_ready=1;
    if (color_ready)
    {
     if (inxy(COMMAND_BUTTON_X1,COMMAND_BUTTON_Y1,COMMAND_BUTTON_X2,COMMAND_BUTTON_Y2))
       {
	color_ready=0;
	mousehide();
	popbox1(COMMAND_BUTTON_X1,COMMAND_BUTTON_Y1,COMMAND_BUTTON_X2,COMMAND_BUTTON_Y2);
          mouseshow();
	 if (command_select!=2)
	    {
BOARD_BACKCOLOR=P_TABLE_BACKCOLOR;
LINE_COLOR=P_TABLE_LINECOLOR;
BOARD_STYLE=P_TABLE_STYLE;
WELCOME_COLOR=P_TABLE_WELCOMECOLOR;
MAN_CHESS_COLOR=P_CHESS_MY_COLOR;
MACHINE_CHESS_COLOR=P_CHESS_MA_COLOR;
MAN_CHESS_STYLE=P_CHESS_MY_STYLE;
MACHINE_CHESS_STYLE=P_CHESS_MA_STYLE;
B_COLOR=P_BUTTON_LISTBACKCOLOR;
B_BOTTON_BACKCOLOR=P_BUTTON_BACKCOLOR;
B_BOTTON_STYLE=P_BUTTON_STYLE;
B_BOTTON_FORECOLOR=P_BUTTON_FORECOLOR;
	  }
	if (command_select==3)
          write_color_file();
       	  cleardevice();
          return;
         }
     }
     if (color_ready)
     {
     for(i=0;i<4;i++)
      {
	if (color_ready)
	{
	if (inxy(KUAN_1_X1,KUAN_1_Y1+INTERVAL_3*i,KUAN_1_X1+KUAN_WIDTH,KUAN_1_Y1+INTERVAL_3*i+KUAN_WIDTH))
	   {
	    color_ready=0;
	    switch(i)
	     {
	      case 0: {
			  if (P_TABLE_BACKCOLOR!=color_ram)
			     {
			       P_TABLE_BACKCOLOR=color_ram;
			       draw_kuan(KUAN_1_X1,KUAN_1_Y1+INTERVAL_3*i,color_ram,1);
			      draw_kuan(KUAN_1_X1,KUAN_1_Y1+INTERVAL_3*(i+2),P_TABLE_BACKCOLOR,P_TABLE_STYLE);
			      }
		       break;
		       }
	      case 1:  {
			  if (P_TABLE_LINECOLOR!=color_ram)
			     {
			       P_TABLE_LINECOLOR=color_ram;
			       draw_kuan(KUAN_1_X1,KUAN_1_Y1+INTERVAL_3*i,color_ram,1);
			      }
		       break;
		  }
	     case 2:   {
			  if (P_TABLE_STYLE!=style_ram)
			     {
			       P_TABLE_STYLE=style_ram;
			       draw_kuan(KUAN_1_X1,KUAN_1_Y1+INTERVAL_3*i,P_TABLE_BACKCOLOR,style_ram);
			      }
		       break;
		       }
	      case 3:   {
			  if (P_TABLE_WELCOMECOLOR!=color_ram)
			     {
			       P_TABLE_WELCOMECOLOR=color_ram;
			       draw_kuan(KUAN_1_X1,KUAN_1_Y1+INTERVAL_3*i,color_ram,1);
			      }
		       break;
		       }
     	     }/*switch*/
	   }
	}
      }
    } /** color_ready **/
     if (color_ready)
    {
     for(i=0;i<4;i++)
      {
	if (color_ready)
	{
	if (inxy(KUAN_2_X1,KUAN_2_Y1+INTERVAL_3*i,KUAN_2_X1+KUAN_WIDTH,KUAN_2_Y1+INTERVAL_3*i+KUAN_WIDTH))
	   {
	    color_ready=0;
	    switch(i)
	     {
	      case 0: {
			  if (P_CHESS_MY_COLOR!=color_ram)
			     {
			       P_CHESS_MY_COLOR=color_ram;
			       draw_kuan(KUAN_2_X1,KUAN_2_Y1+INTERVAL_3*i,color_ram,1);
			      draw_kuan(KUAN_2_X1,KUAN_2_Y1+INTERVAL_3*(i+1),P_CHESS_MY_COLOR,P_CHESS_MY_STYLE);
			      }
		       break;
		       }
	      case 1:   {
			  if (P_CHESS_MY_STYLE!=style_ram)
			     {
			       P_CHESS_MY_STYLE=style_ram;
			       draw_kuan(KUAN_2_X1,KUAN_2_Y1+INTERVAL_3*i,P_CHESS_MY_COLOR,style_ram);

			      }
			    break;
		       }
	      case 2:  {
			  if (P_CHESS_MA_COLOR!=color_ram)
			     {
			       P_CHESS_MA_COLOR=color_ram;
			       draw_kuan(KUAN_2_X1,KUAN_2_Y1+INTERVAL_3*i,color_ram,1);
			      draw_kuan(KUAN_2_X1,KUAN_2_Y1+INTERVAL_3*(i+1),P_CHESS_MA_COLOR,P_CHESS_MA_STYLE);
			      }
		       break;
		       }
	       case 3:   {
			  if (P_CHESS_MA_STYLE!=style_ram)
			     {
			       P_CHESS_MA_STYLE=style_ram;
			       draw_kuan(KUAN_2_X1,KUAN_2_Y1+INTERVAL_3*i,P_CHESS_MA_COLOR,style_ram);
			      }
		       break;
		       }


	     }/*switch*/
	   }
	}
      }

    } /** color_ready **/
     if (color_ready)
    {
     for(i=0;i<4;i++)
      {
	if (color_ready)
	{
	if (inxy(KUAN_3_X1,KUAN_3_Y1+INTERVAL_3*i,KUAN_3_X1+KUAN_WIDTH,KUAN_3_Y1+INTERVAL_3*i+KUAN_WIDTH))
	   {
	    color_ready=0;
	    switch(i)
	     {
	      case 0: {
			  if (P_BUTTON_LISTBACKCOLOR!=color_ram)
			     {
			       P_BUTTON_LISTBACKCOLOR=color_ram;
			       draw_kuan(KUAN_3_X1,KUAN_3_Y1+INTERVAL_3*i,color_ram,1);
			      }
		       break;
		       }
	      case 1:   {
			  if (P_BUTTON_BACKCOLOR!=color_ram)
			     {
			       P_BUTTON_BACKCOLOR=color_ram;
			       draw_kuan(KUAN_3_X1,KUAN_3_Y1+INTERVAL_3*i,color_ram,1);
			       draw_kuan(KUAN_3_X1,KUAN_3_Y1+INTERVAL_3*(i+1),P_BUTTON_BACKCOLOR,P_BUTTON_STYLE);
			      }
		       break;
		       }


	      case 2:  {
			  if (P_BUTTON_STYLE!=style_ram)
			     {
			       P_BUTTON_STYLE=style_ram;
			       draw_kuan(KUAN_3_X1,KUAN_3_Y1+INTERVAL_3*i,P_BUTTON_BACKCOLOR,style_ram);
			      }
		       break;
		       }
	       case 3:   {
			  if (P_BUTTON_FORECOLOR!=color_ram)
			     {
			       P_BUTTON_FORECOLOR=color_ram;
			       draw_kuan(KUAN_3_X1,KUAN_3_Y1+INTERVAL_3*i,color_ram,1);
			      }
		       break;
		       }


	     }/*switch*/
	   }
	}
      }

    } /** color_ready **/
   if (color_ready)
    {
      if (inxy(ENTER_X1,ENTER_Y1,ENTER_X1+ENTER_WIDTH,ENTER_Y1+ENTER_WIDTH))
	   {
	    color_ready=0;
	    if (command_select!=1)
		    {
	    mousehide();
	    prstriangle(ENTER_X1,ENTER_Y1,ENTER_X1+ENTER_WIDTH,ENTER_Y1+ENTER_WIDTH,COMMAND_SELECT_COLOR);
	    triangle(ENTER_X1,ENTER_Y1+COMMAND_INTERVAL_1,ENTER_X1+ENTER_WIDTH,ENTER_Y1+COMMAND_INTERVAL_1+ENTER_WIDTH,COMMAND_ITEM_COLOR);
	    triangle(ENTER_X1,ENTER_Y1+COMMAND_INTERVAL_1*2,ENTER_X1+ENTER_WIDTH,ENTER_Y1+COMMAND_INTERVAL_1*2+ENTER_WIDTH,COMMAND_ITEM_COLOR);
	    command_select=1;
             setcolor(15);
	    settextjustify(0,1);
	   settextstyle(0,0,0);
	   outtextxy(ENTER_X1+COMMAND_INTERVAL_2,ENTER_Y1+COMMAND_INTERVAL_1+10,"CANCEL");
	   outtextxy(ENTER_X1+COMMAND_INTERVAL_2,ENTER_Y1+COMMAND_INTERVAL_1*2+10,"SAVE");
	   setcolor(COMMAND_SELECT_COLOR);
            outtextxy(ENTER_X1+COMMAND_INTERVAL_2,ENTER_Y1+10,"ENTER");

	    mouseshow();
		    }
	    }
      }
	if (color_ready)
	 {
	   if (inxy(ENTER_X1,ENTER_Y1+COMMAND_INTERVAL_1,ENTER_X1+ENTER_WIDTH,ENTER_Y1+COMMAND_INTERVAL_1+ENTER_WIDTH))
	   {
	    color_ready=0;
	    if (command_select!=2)
		    {
	    mousehide();
	    triangle(ENTER_X1,ENTER_Y1,ENTER_X1+ENTER_WIDTH,ENTER_Y1+ENTER_WIDTH,COMMAND_ITEM_COLOR);
	    prstriangle(ENTER_X1,ENTER_Y1+COMMAND_INTERVAL_1,ENTER_X1+ENTER_WIDTH,ENTER_Y1+COMMAND_INTERVAL_1+ENTER_WIDTH,COMMAND_SELECT_COLOR);
	    triangle(ENTER_X1,ENTER_Y1+COMMAND_INTERVAL_1*2,ENTER_X1+ENTER_WIDTH,ENTER_Y1+COMMAND_INTERVAL_1*2+ENTER_WIDTH,COMMAND_ITEM_COLOR);
	    command_select=2;
               setcolor(15);
	    settextjustify(0,1);
	   settextstyle(0,0,0);
           outtextxy(ENTER_X1+COMMAND_INTERVAL_2,ENTER_Y1+10,"ENTER");
	   outtextxy(ENTER_X1+COMMAND_INTERVAL_2,ENTER_Y1+COMMAND_INTERVAL_1*2+10,"SAVE");
	   setcolor(COMMAND_SELECT_COLOR);
           outtextxy(ENTER_X1+COMMAND_INTERVAL_2,ENTER_Y1+COMMAND_INTERVAL_1+10,"CANCEL");

	    mouseshow();
		    }
	    }
	}

	if (color_ready)
	 {
	   if (inxy(ENTER_X1,ENTER_Y1+COMMAND_INTERVAL_1*2,ENTER_X1+ENTER_WIDTH,ENTER_Y1+COMMAND_INTERVAL_1*2+ENTER_WIDTH))
	   {
	    color_ready=0;
	    if (command_select!=3)
		    {
	    mousehide();
	    triangle(ENTER_X1,ENTER_Y1,ENTER_X1+ENTER_WIDTH,ENTER_Y1+ENTER_WIDTH,COMMAND_ITEM_COLOR);
	    triangle(ENTER_X1,ENTER_Y1+COMMAND_INTERVAL_1,ENTER_X1+ENTER_WIDTH,ENTER_Y1+COMMAND_INTERVAL_1+ENTER_WIDTH,COMMAND_ITEM_COLOR);
	    prstriangle(ENTER_X1,ENTER_Y1+COMMAND_INTERVAL_1*2,ENTER_X1+ENTER_WIDTH,ENTER_Y1+COMMAND_INTERVAL_1*2+ENTER_WIDTH,COMMAND_SELECT_COLOR);
	    command_select=3;
                 setcolor(15);
	    settextjustify(0,1);
	   settextstyle(0,0,0);
           outtextxy(ENTER_X1+COMMAND_INTERVAL_2,ENTER_Y1+10,"ENTER");
            outtextxy(ENTER_X1+COMMAND_INTERVAL_2,ENTER_Y1+COMMAND_INTERVAL_1+10,"CANCEL");

	   setcolor(COMMAND_SELECT_COLOR);
            outtextxy(ENTER_X1+COMMAND_INTERVAL_2,ENTER_Y1+COMMAND_INTERVAL_1*2+10,"SAVE");
	  mouseshow();
	     }
	    }
	}
   if (color_ready)
      {
      for(i=0;i<8;i++)
	   {
    if(inxy(COLOR_ITEM_X1+COLOR_INTERVAL_1*i,COLOR_ITEM_Y1,COLOR_ITEM_X1+COLOR_INTERVAL_1*i+KUAN_WIDTH,COLOR_ITEM_Y1+KUAN_WIDTH))
		   {
		     color_ready=0;
		     if (color_ram!=i)
			   {
      color_ram=i;
      box1(COLOR_SELECT_X1,COLOR_SELECT_Y1,COLOR_SELECT_X1+KUAN_WIDTH*3,COLOR_SELECT_Y1+KUAN_WIDTH,i,1);
     prsbox1(COLOR_SELECT_X1,COLOR_SELECT_Y1,COLOR_SELECT_X1+KUAN_WIDTH*3,COLOR_SELECT_Y1+KUAN_WIDTH);
      box1(STYLE_SELECT_X1,STYLE_SELECT_Y1,STYLE_SELECT_X1+KUAN_WIDTH*3,STYLE_SELECT_Y1+KUAN_WIDTH,color_ram,style_ram);
      prsbox1(STYLE_SELECT_X1,STYLE_SELECT_Y1,STYLE_SELECT_X1+KUAN_WIDTH*3,STYLE_SELECT_Y1+KUAN_WIDTH);

      delay(2000);
			   }
      break;
		 }
	   }
      }
   if (color_ready)
   {
   for(i=0;i<8;i++)
      {
    if(inxy(COLOR_ITEM_X1+COLOR_INTERVAL_1*i,COLOR_ITEM_Y1+COLOR_INTERVAL_2,COLOR_ITEM_X1+COLOR_INTERVAL_1*i+KUAN_WIDTH,COLOR_ITEM_Y1+COLOR_INTERVAL_2+KUAN_WIDTH))
	      {
	color_ready=0;
	if (color_ram!=15-i)
			{
	color_ram=15-i;
	 box1(COLOR_SELECT_X1,COLOR_SELECT_Y1,COLOR_SELECT_X1+KUAN_WIDTH*3,COLOR_SELECT_Y1+KUAN_WIDTH,15-i,1);
	prsbox1(COLOR_SELECT_X1,COLOR_SELECT_Y1,COLOR_SELECT_X1+KUAN_WIDTH*3,COLOR_SELECT_Y1+KUAN_WIDTH);
       box1(STYLE_SELECT_X1,STYLE_SELECT_Y1,STYLE_SELECT_X1+KUAN_WIDTH*3,STYLE_SELECT_Y1+KUAN_WIDTH,color_ram,style_ram);
      prsbox1(STYLE_SELECT_X1,STYLE_SELECT_Y1,STYLE_SELECT_X1+KUAN_WIDTH*3,STYLE_SELECT_Y1+KUAN_WIDTH);

       delay(2000);
			}
       break;
	     }
      }
 }

if (color_ready)
{
for(i=0;i<6;i++)
   {
    if (inxy(STYLE_ITEM_X1+COLOR_INTERVAL_1*i,STYLE_ITEM_Y1,STYLE_ITEM_X1+COLOR_INTERVAL_1*i+KUAN_WIDTH,STYLE_ITEM_Y1+KUAN_WIDTH))
      {
	  color_ready=0;
	  if (style_ram!=i+1)
		{
      style_ram=i+1;
      box1(STYLE_SELECT_X1,STYLE_SELECT_Y1,STYLE_SELECT_X1+KUAN_WIDTH*3,STYLE_SELECT_Y1+KUAN_WIDTH,color_ram,style_ram);
      prsbox1(STYLE_SELECT_X1,STYLE_SELECT_Y1,STYLE_SELECT_X1+KUAN_WIDTH*3,STYLE_SELECT_Y1+KUAN_WIDTH);
      delay(2000);
		}
      break;
      }

   }
}
if (color_ready)
  {
for(i=0;i<5;i++)
	 {
    if (inxy(STYLE_ITEM_X1+COLOR_INTERVAL_1*i,STYLE_ITEM_Y1+COLOR_INTERVAL_2,STYLE_ITEM_X1+COLOR_INTERVAL_1*i+KUAN_WIDTH,STYLE_ITEM_Y1+COLOR_INTERVAL_2+KUAN_WIDTH))
	     {
	   if (style_ram!=i+7)
		  {
      style_ram=i+7;
      box1(STYLE_SELECT_X1,STYLE_SELECT_Y1,STYLE_SELECT_X1+KUAN_WIDTH*3,STYLE_SELECT_Y1+KUAN_WIDTH,color_ram,style_ram);
      prsbox1(STYLE_SELECT_X1,STYLE_SELECT_Y1,STYLE_SELECT_X1+KUAN_WIDTH*3,STYLE_SELECT_Y1+KUAN_WIDTH);
      delay(2000);
		  }
      break;
	     }

	 }
  }

}/* mouseleft */



}
}
