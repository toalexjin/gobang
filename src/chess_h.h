
#define HIGH 20
#define RADIOUS 8
#define X_1 60
#define Y_1 80
#define WELCOME_FONT 0
#define WELCOME_DIRECTION 0
#define WELCOME_CHARSIZE 2
#define WELCOME_X 242
#define WELCOME_Y 30
#define BOARD_X_1 X_1-35
#define BOARD_Y_1 Y_1-30
#define N 19
#define EFFECT_REGION 6
#define  X_2 X_1+(N-1)*HIGH
#define Y_2 Y_1+(N-1)*HIGH
#define BOARD_X_2 X_2+35
#define BOARD_Y_2 Y_2+30
#define B_STYLE 12

#define B_BOTTON_HIGH  35
#define B_BOTTON_WIDTH 104
#define B_INTERVAL 14

#define B_NEW_X1 504-8
#define B_NEW_Y1 96
#define B_NEW_X2 B_NEW_X1+B_BOTTON_WIDTH
#define B_NEW_Y2 B_NEW_Y1+B_BOTTON_HIGH
#define B_LOAD_Y1 B_NEW_Y2+B_INTERVAL
#define B_LOAD_Y2 B_LOAD_Y1+B_BOTTON_HIGH
#define B_SAVE_Y1 B_LOAD_Y2+B_INTERVAL
#define B_SAVE_Y2 B_SAVE_Y1+B_BOTTON_HIGH
#define B_CURRENT_Y1 B_SAVE_Y2+B_INTERVAL
#define B_CURRENT_Y2 B_CURRENT_Y1+B_BOTTON_HIGH


#define B_UNDO_Y1 B_CURRENT_Y2+B_INTERVAL
#define B_UNDO_Y2 B_UNDO_Y1+B_BOTTON_HIGH
#define B_DOS_Y1 B_UNDO_Y2+B_INTERVAL
#define B_DOS_Y2 B_DOS_Y1+B_BOTTON_HIGH
#define B_EXIT_Y1 B_DOS_Y2+B_INTERVAL
#define B_EXIT_Y2 B_EXIT_Y1+B_BOTTON_HIGH
#define B_X1 B_NEW_X1-18
#define B_Y1 79
#define B_X2 B_NEW_X2+16
#define B_Y2 Y_1+18*20+1
#define WIN_FONT 0
#define WIN_DIRECTION 0
#define WIN_CHARSIZE 2
#define WIN_X (X_1+X_2)/2+4
#define WIN_Y (Y_1+Y_2)/2

#define CURRENT_COLOR 1
#define SOUND_DELAY 2500
#define NOSOUND_DELAY 2500
#define MAN_WIN_SOUND 1000
#define MACHINE_WIN_SOUND 100
#define HEAD_FILLCOLOR 12

struct chess
{
int x,y,flag,count;
struct chess *up,*down,*left,*right,*leftup,*leftdown,*rightup,*rightdown;
};

