void allocateArrays(){
             A = (char **)malloc(rows * sizeof(int *));  // Allocate memory for rows
    for (int i = 0; i < rows; i++) {
        A[i] = (char *)malloc(cols * sizeof(int));  // Allocate memory for columns
    }

 flagARR = (int **)malloc(rows * sizeof(int *));  // Allocate memory for rows
    for (int i = 0; i < rows; i++) {
        flagARR[i] = (int *)malloc(cols * sizeof(int));  // Allocate memory for columns
    }
}


void gameLoop(char **A,int **flagARR){
 while(p1.score+p2.score < n*m){
if(mode == 0 || (mode==1 && flag==0)){
flag = human_move(A,flagARR,uARR,rARR,&p1,&p2);
}

if(flag == 1 && mode == 1){
flag = computer_move(A,flagARR,&p1,&p2);
}

            system("cls");
            print_grid(A,flagARR);
            print_data(p1,p2,match_begun,n*m);
       /*    printArray(uARR, 50);
            printf("\n");
            printArray(rARR, count);
            printf("\n");
            printf("Count = %d | ",count);
            printf("MOVECOUNT = %d | ", movecount);
            printf("FLAG = %d\n", flag);  */
    }
}


void winnerCheck(){
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
}


void Top10Save() {

      printf(GRN"TOP 10 PLAYERS\n"RESET);
    readTopScores(topPlayers);
    updateTopScores(topPlayers, winnerName, winnerScore);
    writeTopScores(topPlayers);
    display();
}


void gameInit(char **A, int ** flagARR) {

        for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            flagARR[i][j]=2;}
            }

        for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            A[i][j]='0';}
            }

                  for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d",flagARR[i][j]);
            }
            printf("\n");
            }
            sleep(1);

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d",A[i][j]);
            }
            printf("\n");
            }
            sleep(1);

    system("cls");
    create_grid(A);
    print_grid(A,flagARR);
    print_data(p1,p2,match_begun,n*m);
    clock_t match_begun = clock();


}
