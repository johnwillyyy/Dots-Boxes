#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define RESET "\x1B[0m"
#define CYN   "\x1B[36m"

#define rows_c 2
#define cols_c 2

typedef struct{
char name[30];
int score;
int moves;
}player;
player p1;
player p2;



void grid_menu(int n,int m){
system("cls");
printf("Select Grid Size\n");
printf( RED"1- Easy | 2x2 Grid\n\n"RESET);
printf( BLU"2- Expert | 5x5 Grid\n\n"RESET);
printf( BLU"3- Custom Grid\n\n"RESET);
int input;
scanf("%d",&input);
    if (input == 1){n=2;m=2;}
    else if (input == 2){ n=5;m=5;}
    else if (input == 3){ printf("custom");}
    else {printf("Please enter a valid choice\n");
    sleep(1);
    system("cls");
    grid_menu(n,m);}
    }


void mode_menu(int n,int m,player *p1,player *p2){
    system("cls");
    printf("Select Game Mode\n");
    printf( RED"1- Human vs. Human\n\n"RESET);
    printf( BLU"2- Human vs. Computer\n\n"RESET);
    int input;
    scanf("%d",&input);
    if (input == 1){
        printf("Enter Player 1 name: ");gets(p1->name);printf("\n");
        printf("Enter Player 2 name: ");gets(p2->name);printf("\n");
        grid_menu(n,m);}
    else if (input == 2){
       printf("Enter Player name: ");gets(p1->name);
       grid_menu(n,m);}
    else {printf("Please enter a valid choice\n");
    sleep(1);
    system("cls");
    mode_menu(n,m,&p1,&p2);}
    }






void main_menu(int n,int m, player *p1, player *p2){

printf( RED"1- New Game\n\n"RESET);
printf( BLU"2- Load Game\n\n"RESET);
printf( BLU"3- Top 10 Players\n\n"RESET);
printf( GRN"4- EXIT\n\n"RESET);
printf( "Select A Number: ");
int input;
scanf("%d",&input);
    if(input == 1){
        system("cls");
        mode_menu(n,m,&p1,&p2);
}
    else if (input == 2){ printf("Choice 2");}
    else if (input == 3){ printf("Choice 3");}
    else if (input == 4){ exit(1);}
    else    {printf("Please enter a valid choice\n");
    sleep(1);
    system("cls");
    main_menu(n,m,&p1,&p2);}
}