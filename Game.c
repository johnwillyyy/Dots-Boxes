int rows;
int cols;
int count = 0;
int *i = &count;
int flag=0;
int prevflag=0;
int j =0;
int r1,r2,c1,c2;
int movecount =0;

#define MAX_PLAYERS 10
#define max_name_length 50

#include "Menus.h"
#include "Box_Check.h"
#include "printing.h"
#include "time_handling.h"
#include "Game Logic.h"
#include "Top 10 Players.h"

int n=1,m=1;
int mode;
int *pn=&n , *pm=&m , *pmode=&mode;
double match_begun;
double player_begun;
int score1,score2;

int main() {
    player topPlayers[MAX_PLAYERS];
    prevflag = flag;
    system("cls");
    main_menu(pn,pm,pmode,&p1,&p2);
    int boxes = n*m;
    rows = rows_c*n+rows_c+1;
    cols = cols_c*m+cols_c+1;
    char A[rows][cols];
    int flagARR[rows][cols];
    int uARR[50]={1};
    int rARR[50]={0};

    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            flagARR[i][j]=2;
    system("cls");
    create_grid(A);
    print_grid(A,flagARR);
    print_data(p1,p2,match_begun,boxes);
    clock_t match_begun = clock();

    while(p1.score+p2.score < n*m){
if(mode == 0 || (mode==1 && flag==0)){
flag = human_move(A,flagARR,uARR,rARR,&p1,&p2);
}

if(flag == 1 && mode == 1){
flag = computer_move(A,flagARR,&p1,&p2);
}
            system("cls");
            print_grid(A,flagARR);
            print_data(p1,p2,match_begun,boxes);
            printArray(uARR, 50);
            printf("\n");
            printArray(rARR, count);
            printf("\n");
            printf("Count = %d | ",count);
            printf("MOVECOUNT = %d | ", movecount);
            printf("FLAG = %d\n", flag);

    }

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

