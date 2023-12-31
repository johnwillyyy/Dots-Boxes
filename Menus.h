#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
//#include <pthread.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define RESET "\x1B[0m"
#define CYN   "\x1B[36m"
#define MAG "\e[0;35m"

#define rows_c 2
#define cols_c 2

typedef struct{
char name[30];
int score;
int moves;
}player;
player p1;
player p2;
player topPlayers[MAX_PLAYERS];
FILE *file;


void grid_menu(int *pn,int *pm){
    system("cls");              //printing choices
    printf("Select Grid Size\n");
    printf( CYN"1- Easy | 2x2 Grid\n\n"RESET);
    printf( RED"2- Expert | 5x5 Grid\n\n"RESET);
    printf( YEL"3- Custom Grid\n\n"RESET);

    int input;
    do{
    printf( "Select A Number: ");       //geting valid input
        if(scanf("%d",&input)!=1);
            while(getchar()!='\n');
    }while(input!=1&&input!=2&&input!=3);
    switch(input){
    case 1:*pn=2;*pm=2;break;   //Easy | 2x2 Grid
    case 2:*pn=5;*pm=5;break;   //Expert | 5x5 Grid
    case 3:printf("Enter your grid n*n: ");scanf("%d*%d",pn,pm);break;  //Custom Grid
    }
}


void mode_menu(int *pn,int *pm,int *pmode,player *p1,player *p2){
    system("cls");
    printf("Select Game Mode\n");               //printing choices
    printf( YEL"1- Human vs. Human\n\n"RESET);
    printf( CYN"2- Human vs. Computer\n\n"RESET);
    
    int input;
    do{
    printf( "Select A Number: ");       //geting valid input
        if(scanf("%d",&input)!=1);
            while(getchar()!='\n');
    }while(input!=1&&input!=2);
    
    char x;
    switch(input){
    case 1:                     //Human vs. Human
        *pmode = 0;
        printf("Enter Player 1 name: ");

        do{x=getchar();         //skip invalid inputs
        }while(x=='\n'||x==' '||x=='\t');
        gets(p1->name);         //get first player name

        printf("Enter Player 2 name: ");

        do{x=getchar();         //skip invalid inputs
        }while(x=='\n'||x==' '||x=='\t');
        gets(p2->name);     //get second player name

        grid_menu(pn,pm);
        break;
    case 2:                     //Human vs. Computer
        *pmode = 1;
       printf("Enter Player name: ");

       do{x=getchar();         //skip invalid inputs
        }while(x=='\n'||x==' '||x=='\t');
       gets(p1->name);  //get player name

       strcpy(p2->name, "Mina&John");
       grid_menu(pn,pm);
       break;
    }
}


void main_menu(int *pn,int *pm, int *pmode, player *p1, player *p2){
    printf( CYN"1- New Game\n\n"RESET);         //printing the choices
    printf( BLU"2- Load Game\n\n"RESET);
    printf( YEL"3- Top 10 Players\n\n"RESET);
    printf( GRN"4- EXIT\n\n"RESET);

    int input;
    do{
        printf( "Select A Number: ");       //geting valid input
        if(scanf("%d",&input)!=1);
            while(getchar()!='\n');
    }while(input!=1&&input!=2&&input!=3&&input!=4);

    switch(input){
        case 1:mode_menu(pn,pm,pmode,p1,p2);break;  //New Game
        case 2:loadGame("lol.txt",p1, p2);break;    //Load Game
        case 3:printf("\n");display();sleep(5);system("cls");main_menu(pn,pm,pmode,p1,p2);break;   //Top 10 Players
        case 4:exit(0);     //Exit
    }
}


void ending_menu(int *pn,int *pm, int *pmode, player *p1, player *p2){
    printf( CYN"1- Main Menu\n\n"RESET);         //printing the choices
    printf( BLU"2- Exit\n\n"RESET);

    int input;
    do{
        printf( "Select A Number: ");       //geting valid input
        if(scanf("%d",&input)!=1);
            while(getchar()!='\n');
    }while(input!=1&&input!=2);

    switch(input){
        case 1:system("cls");main_menu(pn,pm,pmode,p1,p2);break;  //Main Menu
        case 2:exit(0);     //Exit
    }
}