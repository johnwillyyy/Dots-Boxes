
void create_grid(char** A){
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++){
            if(i==0&&j%cols_c==0&&j!=0)
                A[i][j]=48+j/cols_c;
            else if(j==0&&i%rows_c==0&&i!=0)
                A[i][j]=48+i/rows_c;
            else if(i%rows_c!=0||j%cols_c!=0||(i==0&&j==0))
                A[i][j]=' ';
            else
                A[i][j]=254;
        }
}



void print_grid(char **A,int **F){
    for (int i=0;i<rows;i++){
        printf("\n");
        printf("\t\t");
        for (int j=0;j<cols;j++){
            if(j%cols_c==0){
                if(F[i][j]==0||F[i][j]==-2)
                    printf(YEL "%c" RESET,A[i][j]);
                else if(F[i][j]==1||F[i][j]==-1)
                    printf(CYN "%c" RESET,A[i][j]);
                else
                    printf(RESET "%c" RESET,A[i][j]);
            }
            else{
                    if(F[i][j]==0||F[i][j]==-2)
                        printf(YEL "%c%c%c" RESET,A[i][j],A[i][j],A[i][j]);
                    else if(F[i][j]==1||F[i][j]==-1)
                        printf(CYN "%c%c%c" RESET,A[i][j],A[i][j],A[i][j]);
                    else
                        printf( "%c%c%c",A[i][j],A[i][j],A[i][j]);
            }
        }
    }
    printf("\n");
}


void print_data(player *p1,player *p2,double begin,int boxes){

printf(YEL"Player 1"RESET);
printf(CYN"\t\t\t\tPlayer 2\n"RESET);



printf(YEL"Name: %s"RESET,p1->name);
printf(CYN"\t\t\t\tName: %s\n"RESET,p2->name);


printf(YEL"Score = %d"RESET,p1->score);
printf(CYN"\t\t\t\tScore = %d\n"RESET,p2->score);

printf(YEL"moves: %d"RESET,p1->moves);
printf(CYN"\t\t\t\tmoves: %d\n"RESET,p2->moves);

printf(BLU"Time: %d:%d",minutes,current_time(begin));


printf("\t\t\t\tRemaining BOXES = %d\n"RESET,(boxes) - (p2->score+p1->score));

printf("\t\t\t\t\t(Enter -1 -1 -1 -1 to exit game)\n");
printf("\t\t\t\t\t(Enter 1 1 1 1 to save game)\n");
printf("\t\t\t\t\t(Enter 2 2 2 2 to Undo)\n");
printf("\t\t\t\t\t(Enter 3 3 3 3 to Redo)\n");
if (flag == 0)printf(YEL "Player 1 Turn\nEnter your move:" RESET);
else printf(CYN "Player 2 Turn\nEnter your move:" RESET);
}
