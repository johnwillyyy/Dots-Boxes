int n=1,m=1;
int rows;
int cols;           // Board Dimensions
int count = 0;
int *i = &count;    // redo Array Counter
int flag=0;         // Position flag (flag 0 for player 1 , flag 1 for player 2)
int r1,r2,c1,c2;    // points' Coordinates
int movecount =0;   // Number of moves since new turn
double match_begun;
double player_begun;// starting times for the game / player's turn
int exitFlag = 0;   // Thread's exit flag
int minutes;  
int seconds;      // game time (minutes)
int j =0;
int mode;
char **A;           // Main Grid Array
int **flagARR;      // Flag array
int uARR[100]={0};
int rARR[100]={0};
int savenum = 0;
int *pn=&n ,*pm=&m ,*pmode=&mode;

#define MAX_PLAYERS 10
#define max_name_length 20
#define MAX_FILENAME_LENGTH 100
#define MAX_STRING_LENGTH 50

#include "Menus.h"
#include "Box_Check.h"
#include "printing.h"
#include "time_handling.h"
#include "Game Logic.h"
#include "Top 10 Players.h"
#include "DFS.h"
#include "Game Loop.h"
#include "save_Load.h"



int main() {
    system("cls");
    main_menu(pn,pm,pmode,&p1,&p2);
    rows = rows_c*n+rows_c+1;
    cols = cols_c*m+cols_c+1;
    allocateArrays();
    gameInit(A,flagARR);
    gameLoop(A,flagARR);
    winnerCheck();
    Top10Save();
}