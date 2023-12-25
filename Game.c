int rows;
int cols;
#include "Menus.h"
#include "printing.h"
#include "time_handling.h"
#include "Game Logic.h"

int n=1,m=1;
int mode;
int *pn=&n , *pm=&m , *pmode=&mode;
double match_begun;
double player_begun;
int posflag=0;
int score1,score2;

int main() {
    system("cls");
    main_menu(pn,pm,pmode,&p1,&p2);
    int boxes = n*m;
    rows = rows_c*n+rows_c+1;
    cols = cols_c*m+cols_c+1;
    char A[rows][cols];
    int flagARR[rows][cols];
    int urARR[50]={0};
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            flagARR[i][j]=2;
    system("cls");
    create_grid(A);
    print_grid(A,flagARR);
    print_data(p1,p2,match_begun,boxes);
    clock_t match_begun = clock();

    while(p1.score+p2.score < n*m){
if(mode == 0 || (mode==1 && posflag==0)){
posflag = human_move(A,flagARR,urARR,posflag,&p1,&p2);
}

if(posflag == 1 && mode == 1){
posflag = computer_move(A,flagARR,posflag,&p1,&p2);
}


            system("cls");
            print_grid(A,flagARR);
            print_data(p1,p2,match_begun,boxes);
            printArray(urARR, p1.moves+p2.moves);

    }

    if(p1.score>p2.score)
        printf(RED"%s WINS"RESET,p1.name);
    else if(p1.score<p2.score)
        printf(BLU"%s WINS"RESET,p2.name);
    else
        printf("DRAW");
}
