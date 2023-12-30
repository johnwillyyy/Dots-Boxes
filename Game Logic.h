void check_special_entries(int r1,int r2,int c1,int c2,char A[rows][cols],int F[rows][cols],player *p1,player *p2,int *store,int *redo){
if(r1==-1 && r2==-1 && c1==-1 && c2==-1)exit(0);
else if(r1==1 && r2==1 && c1==1 && c2==1){
   save_Game();
}
else if(r1==2 && r2==2 && c1==2 && c2==2)Undo(A,F,store,redo, p1,p2);
else if(r1==3 && r2==3 && c1==3 && c2==3)Redo(A,F,store,redo, p1,p2);
}



int human_move(char **A,int **F,int *undo,int *redo, player *p1,player*p2){

player_begun = clock();
                    //pthread_t timer;
 int r1,r2,c1,c2;
                    //pthread_create(&timer, NULL, timerThread, &exitFlag);
int numbers[4];
    int parsed;

    // Keep prompting the user until correct input is provided
    do {
        // Prompt user for input
        printf("Enter four numbers separated by spaces: ");
        // Use scanf to parse the input
        parsed = scanf("%d%d%d%d", &numbers[0], &numbers[1], &numbers[2], &numbers[3]);
        // Consume the remaining characters in the input buffer
        while (getchar() != '\n');
        // Check if scanf successfully parsed 4 integers
        if (parsed == 4) {
            // Check if each number is a digit
            int isValid = 1;
            for (int i = 0; i < 4; i++) {
                if (isdigit(numbers[i])) {
                    printf("Error: Non-digit character detected.\n");
                    isValid = 0;
                    break;
                }
            }
            // Display the parsed numbers if input is valid
            if (isValid) {
                printf("Parsed numbers: %d %d %d %d\n", numbers[0], numbers[1], numbers[2], numbers[3]);
                r1 = numbers[0];
                r2 = numbers[1];
                c1 = numbers[2];
                c2 = numbers[3];
                break;  // Exit the loop if input is valid
            }
        }
        else {
            printf("Error: Invalid input format.\n");
        }
    } while (1);  // Infinite loop until valid input is provided

                    //exitFlag = 1;
                    //pthread_cancel(timer);
                    //     exitFlag = 0;

 move(r1,r2,c1,c2,A,F,undo,redo,p1,p2);

}





int move(int r1,int r2,int c1, int c2,char A[rows][cols],int F[rows][cols],int *undo,int *redo, player *p1,player*p2){
       int c,r,valid;
        char place;
        if(r1 <= n+1 && r2 <= n+1 && c1 <= m+1 && c2 <= m+1){
            if (r1==r2 && c1==c2 && r1==c2) {check_special_entries(r1,r2,c1,c2,A,F,p1,p2,undo,redo);return flag;}

            else if (r1==r2 && abs(c1-c2) == 1){place = '1'; store_move(r1,r2,c1,c2,undo,p1,p2);valid=1;}

            else if (c1==c2 && abs(r1-r2) == 1){place = '2'; store_move(r1,r2,c1,c2,undo,p1,p2);valid=1;}
        }
            else {
                printf("\nEnter Valid input: ");
                human_move(A,F,undo,redo,p1,p2);}

        if(valid==1){for(int k = count; k>=0; k--){
            redo[k] = 0;
            count = 0;
        }}
        r1=rows_c*r1;
        r2=rows_c*r2;
        c1=cols_c*c1;
        c2=cols_c*c2;

        switch(place){
        case '1':
            c = c1<c2 ? c1:c2;
            if(A[r1][c+1] != -51){
            A[r1][c+1]=-51;
            F[r1][c+1]=flag;
            if (flag == 0)p1->moves++;
            if (flag == 1)p2->moves++;}
            else human_move(A,F,undo,redo,p1,p2);
            break;

        case '2':
            r = r1<r2?r1:r2;
            if(A[r+1][c1] != -70){
            A[r+1][c1]=-70;
            F[r+1][c1]=flag;
            if (flag == 0)p1->moves++;
            if (flag == 1)p2->moves++;}
            else human_move(A,F,undo,redo,p1,p2);
        }

    return check_box(A,r1,r2,c1,c2,F,flag,p1,p2);
}




int computer_move(char A[rows][cols],int F[rows][cols],player *p1,player*p2){
int i,j;

for(i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
            if(i%cols_c!=0 && j%cols_c!=0 && i>2 && j>2){
            if(A[i+1][j]!=-51){A[i+1][j]=-51; F[i+1][j]=flag;    p2->moves++;return    check_box(A,i+1,i+1,j-1,j+1,F,flag,p1,p2);}
            else if(A[i-1][j]!=-51){A[i-1][j]=-51;  F[i-1][j]=flag;    p2->moves++;return    check_box(A,i-1,i-1,j-1,j+1,F,flag,p1,p2);}
            else if(A[i][j+1]!=-70){A[i][j+1]=-70;   F[i][j+1]=flag;  p2->moves++;return    check_box(A,i-1,i+1,j+1,j+1,F,flag,p1,p2);}
            else if(A[i][j-1]!=-70){A[i][j-1]=-70;    F[i][j-1]=flag;  p2->moves++;return    check_box(A,i-1,i+1,j-1,j-1,F,flag,p1,p2);}
}
    }
        }
            }


int store_move(int r1,int r2,int c1,int c2,int *store,player *p1,player *p2){
    int bank;
    bank = flag+ 10*c2 + 100*c1 + 1000*r2 + 10000*r1;
    store[(p1->moves)+(p2->moves)] = bank;
    return bank;
}

void printArray(int * arr, int size) {
  for (int i = 0; i < size; i++)
    printf("% d -", arr[i]);
}

void Undo(char A[rows][cols],int F[rows][cols],int * undo,int *redo, player *p1,player *p2){


            int temp = undo[p1->moves + p2->moves -1];
            int temp2 = undo[p1->moves + p2->moves -1];
            undo[p1->moves + p2->moves -1] = 0;
            //printf("p1 moves = %d\n",p1->moves);
            //printf("temp  %d",temp); sleep(1);

        if(movecount == 0 && redo[0] == 0){flag^=1;}
        int rem = temp%10; int current  = rem; temp/=10;
        rem = temp%10; int c2 = rem; temp/=10;
        rem = temp%10; int c1 = rem; temp/=10;
        rem = temp%10; int r2 = rem; temp/=10;
        rem = temp; int r1 = rem;
        if((movecount == 0 && redo[0] != 0) || movecount <0 || temp2 == 0){
          //  movecount++;
                printf("\nYOUCANTUNDO\nEnter move: ");
                flag = human_move(A,F,undo,redo,p1,p2);
             //   flag = check_box(A,r1,r2,c1,c2,F,flag,p1,p2);
                }



        else{
        r1=rows_c*r1;
        r2=rows_c*r2;
        c1=cols_c*c1;
        c2=cols_c*c2;
         if (flag == 0) p1->moves--;
         else if (flag == 1) p2->moves--;
if(r1==r2){
          int  c = c1<c2 ? c1:c2;
            A[r1][c+1]=' ';
            F[r1][c+1]=2;
            }
if(c1==c2){
         int   r = r1<r2?r1:r2;
            A[r+1][c1]=' ';
            F[r+1][c1]=2;}

            redo[*i] = temp2;
            *i+=1;
movecount--;
return check_box_inv(A,r1,r2,c1,c2,F,flag,p1,p2);

}

}


void Redo(char A[rows][cols],int F[rows][cols],int * undo,int *redo, player *p1,player *p2){

        int temp = redo[count-1];
        int temp2 = redo[count-1];
        if (temp == 0 || count<=0){printf("NO MORE REDOS\nENTER MOVE: ");human_move(A,F,undo,redo,p1,p2);}

        else{
        count-=1;
        undo[p1->moves + p2->moves] = temp;
        int rem = temp%10; int current  = rem; temp/=10;
        rem = temp%10; int c2 = rem; temp/=10;
        rem = temp%10; int c1 = rem; temp/=10;
        rem = temp%10; int r2 = rem; temp/=10;
        rem = temp; int r1 = rem;
        r1=rows_c*r1;
        r2=rows_c*r2;
        c1=cols_c*c1;
        c2=cols_c*c2;
         if (flag == 0) p1->moves++;
         else if (flag == 1) p2->moves++;
        if(r1==r2){
          int  c = c1<c2 ? c1:c2;
            A[r1][c+1]=-51;
            F[r1][c+1]=flag;
            }
        if(c1==c2){
         int   r = r1<r2?r1:r2;
            A[r+1][c1]=-70;
            F[r+1][c1]=flag;
}
check_box(A,r1,r2,c1,c2,F,current,p1,p2);
        }
}


bool checkDigits(char *str) {
    while (*str) {
        if (!isdigit(*str)) {
            return false;
        }
        str++;
    }
    return true;
}

void separateNumbers(char *str, int *r1, int *r2, int *c1, int *c2) {
    int count = 0;
    char *token = strtok(str, " ");
   // printf("%s\n",token);

        if (token != NULL && count < 4 && checkDigits(token)) {
                r1 = atoi(token);
                printf("r1 = %d",r1);sleep(2);
                count++;
                token = strtok(NULL, " ");
    }
            if (token != NULL && count < 4 && checkDigits(token)) {
                r2 = atoi(token);
                printf("r2 = %d",r2);sleep(2);

                count++;
                token = strtok(NULL, " ");
    }
            if (token != NULL && count < 4 && checkDigits(token)) {
                c1 = atoi(token);
                count++;
                token = strtok(NULL, " ");
    }
            if (token != NULL && count < 4 && checkDigits(token)) {
                c2 = atoi(token);
                count++;
                token = strtok(NULL, " ");
    }

    if (count != 4) {
        printf("Error: Invalid input\n");
    }
}




