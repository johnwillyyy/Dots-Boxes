void check_special_entries(int r1,int r2,int c1,int c2,char A[rows][cols],int F[rows][cols],player *p1,player *p2,int *store){
if(r1==-1 && r2==-1 && c1==-1 && c2==-1){exit(0);}
else if(r1==1 && r2==1 && c1==1 && c2==1)printf("SAVE GAME Function");
else if(r1==2 && r2==2 && c1==2 && c2==2)undo(rows,cols,A,F,store,p1,p2);
else if(r1==3 && r2==3 && c1==3 && c2==3)printf("REDO");
}


int check_box(char A[rows][cols],int r1,int r2,int c1,int c2,int F[rows][cols],int flag,player *p1,player *p2){
    int check=0;
    if(r1==r2){
        int c = c1<c2 ? c1:c2;
        if(A[r1-1][c1]==-70&&A[r1-1][c2]==-70&&A[r1-rows_c][c+1]==-51){
            A[r1-1][c+1]=178;
            F[r1-1][c+1]=flag;
            check++;;
        }
        if(A[r1+1][c1]==-70&&A[r1+1][c2]==-70&&A[r1+rows_c][c+1]==-51){
            A[r1+1][c+1]=178;
            F[r1+1][c+1]=flag;
            check++;
        }
    }
    else if(c1==c2){
        int r = r1<r2 ? r1:r2;
        if(A[r1][c1-1]==-51&&A[r2][c1-1]==-51&&A[r+1][c1-cols_c]==-70){
            A[r+1][c1-1]=178;
            F[r+1][c1-1]=flag;
            check++;
        }
        if(A[r1][c1+1]==-51&&A[r2][c1+1]==-51&&A[r+1][c1+cols_c]==-70){
            A[r+1][c1+1]=178;
            F[r+1][c1+1]=flag;
            check++;
        }
    }
    if (check>0) {
            if (flag ==0) {p1->score+=check; return flag;}
            else if (flag ==1) {p2->score+=check; return flag;}
    }
    else return flag^=1;


}



int human_move(char A[rows][cols],int F[rows][cols],int *store,int flag, player *p1,player*p2){
        int r1,r2,c1,c2;
        scanf("%d %d %d %d",&r1,&r2,&c1,&c2);
        store_move(r1,r2,c1,c2,store,p1,p2);
        check_special_entries(r1,r2,c1,c2,A,F,p1,p2,store);
        r1=rows_c*r1;
        r2=rows_c*r2;
        c1=cols_c*c1;
        c2=cols_c*c2;
    if(r1==r2 && abs(c1-c2) == cols_c){
        int c = c1<c2 ? c1:c2;
        if(A[r1][c+1] != -51){
        A[r1][c+1]=-51;
        F[r1][c+1]=flag;}
        }
    else if(c1==c2 && abs(r1-r2) == rows_c){
        int r = r1<r2?r1:r2;
        if(A[r+1][c1] != -70){
        A[r+1][c1]=-70;
        F[r+1][c1]=flag;}
        }
        if (flag == 0)p1->moves++;
        if (flag == 1)p2->moves++;


    return check_box(A,r1,r2,c1,c2,F,flag,p1,p2);
}




int computer_move(char A[rows][cols],int F[rows][cols],int flag,player *p1,player*p2){
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
    bank = c2 + 10*c1 + 100*r2 + 1000*r1;
    printf("BANK = %d\n",bank);
    store[(p1->moves)+(p2->moves)] = bank;
    printf("STORE AT %d thevalue %d",(p1->moves)+(p2->moves),bank);
    sleep(1);
    return bank;
}

void printArray(int * arr, int size) {
  for (int i = 0; i < size; i++)
    printf("% d -", arr[i]);
}

void undo(char A[rows][cols],int F[rows][cols],int *store,player *p1,player *p2){

int temp = store[p1->moves+p1->moves];
int rem = temp%10; int c2 = rem; temp/=10;
rem = temp%10; int c1 = rem; temp/=10;
rem = temp%10; int r2 = rem; temp/=10;
rem = temp; int r1 = rem;
//printf("sikooo %d%d%d%d",r1,r2,c1,c2); sleep(1);
}






