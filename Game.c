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
int minutes;        // game time (minutes)
int j =0;
int x;
int mode;

char **A;           // Main Grid Array
int **flagARR;      // Flag array 
int uARR[50]={0};
int rARR[50]={0};

#define MAX_PLAYERS 10
#define max_name_length 20

#include "Menus.h"
#include "Box_Check.h"
#include "printing.h"
#include "time_handling.h"
#include "Game Logic.h"
#include "Top 10 Players.h"
#include "DFS.h"
#include "save_Load.h"
#include "Game Loop.h"

int *pn=&n ,*pm=&m ,*pmode=&mode;

int main() {
    player topPlayers[MAX_PLAYERS];
    system("cls");
    main_menu(pn,pm,pmode,&p1,&p2);
    rows = rows_c*n+rows_c+1;
    cols = cols_c*m+cols_c+1;




             A = (char **)malloc(rows * sizeof(char *));  // Allocate memory for rows
    for (int i = 0; i < rows; i++) {
        A[i] = (char *)malloc(cols * sizeof(char));  // Allocate memory for columns
    }

 flagARR = (int **)malloc(rows * sizeof(int *));  // Allocate memory for rows
    for (int i = 0; i < rows; i++) {
        flagARR[i] = (int *)malloc(cols * sizeof(int));  // Allocate memory for columns
    }

        for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            flagARR[i][j]=2;
        for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            A[i][j]=0;

    
    system("cls");
    create_grid(A);
    print_grid(A,flagARR);
    print_data(p1,p2,match_begun,n*m);
    clock_t match_begun = clock();

   gameLoop();

    if(p1.score>p2.score)
{
        printf(RED"\t\t\t\t\t%s WINS!!\n"RESET,p1.name);
    winnerName = p1.name;
    winnerScore = p1.score;}
    else if(p1.score<p2.score)
       {printf(BLU"\t\t\t\t\t\t%s WINS!!\n"RESET,p2.name);
            winnerName = p2.name;
            winnerScore = p2.score;}
    else
        printf("\t\t\t\t\t\t\tDRAW!!\n");

        printf(GRN"TOP 10 PLAYERS\n"RESET);
    readTopScores(topPlayers);
    updateTopScores(topPlayers, winnerName, winnerScore);
    writeTopScores(topPlayers);
    display();


}