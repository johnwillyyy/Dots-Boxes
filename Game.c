#include "Menus.h"
#include "printing.h"
#include "time_handling.h"
#include "Game Logic.h"

int n,m;
double match_begun;
double player_begun;
int posflag=0;
int score1,score2;

int main() {
    clock_t match_begun = clock();
    system("cls");
    scanf("%d*%d",&n,&m);
    //main_menu(&p1,&p2,n,m);
    int rows = rows_c*n+rows_c+1;
    int cols = cols_c*m+cols_c+1;
    char A[rows][cols];
    int flagARR[rows][cols];
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            flagARR[i][j]=2;
    create_grid(rows,cols,A);
    print_grid(rows,cols,A,flagARR);
    print_data(p1,p2,match_begun,rows,cols);


    while(p1.score+p2.score < n*m){
            posflag = move(rows,cols,A,flagARR,posflag,&p1,&p2);
            system("cls");
            print_grid(rows,cols,A,flagARR);
            score(&p1,&p2,rows,cols,flagARR);
            print_data(p1,p2,match_begun,rows,cols);
    }

    if(p1.score>p2.score)
        printf(RED"RED WINS"RESET);
    else if(p1.score<p2.score)
        printf(BLU"BLUE WINS"RESET);
    else
        printf("DRAW");
}
