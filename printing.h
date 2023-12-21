
void create_grid(int  rows,int cols,char A[rows][cols]){
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



void print_grid(int rows,int cols,char A[rows][cols],int F[rows][cols]){
    for (int i=0;i<rows;i++){
        printf("\n");
        printf("\t\t");
        for (int j=0;j<cols;j++){
            if(j%cols_c==0){
                if(F[i][j]==0)
                    printf(RED"%c"RESET,A[i][j]);
                else if(F[i][j]==1)
                    printf(BLU"%c"RESET,A[i][j]);
                else
                    printf("%c",A[i][j]);
            }
            else{
                    if(F[i][j]==0)
                        printf(RED"%c%c%c"RESET,A[i][j],A[i][j],A[i][j]);
                    else if(F[i][j]==1)
                        printf(BLU"%c%c%c"RESET,A[i][j],A[i][j],A[i][j]);
                    else
                        printf("%c%c%c",A[i][j],A[i][j],A[i][j]);
            }
        }
    }
    printf("\n");
}


void print_data(player p1,player p2,double begin,int rows,int cols){

printf(RED"Player 1"RESET);
printf(BLU"\t\t\t\tPlayer 2\n"RESET);

printf(RED"Name: %s"RESET,p1.name);
printf(BLU"\t\t\t\tName: %s\n"RESET,p2.name);

printf(RED"Score = %d"RESET,p1.score);
printf(BLU"\t\t\t\tScore = %d\n"RESET,p2.score);

printf(RED"moves: %d"RESET,p1.moves);
printf(BLU"\t\t\t\tmoves: %d\n"RESET,p2.moves);

printf(CYN"Time: ");
current_time(begin);

printf("\t\t\t\tRemaining moves = %d\n"RESET,rows*cols - (p2.moves+p1.moves));

printf("\t\t\t\t Enter your move: ");

}
