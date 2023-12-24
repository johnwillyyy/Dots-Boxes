void check_special_entries(int r1,int r2,int c1,int c2){
if(r1==-1 && r2==-1 && c1==-1 && c2==-1){exit(0);}
else if(r1==1 && r2==1 && c1==1 && c2==1)printf("SAVE GAME Function");
else if(r1==2 && r2==2 && c1==2 && c2==2)printf("UNDO");
else if(r1==3 && r2==3 && c1==3 && c2==3)printf("REDO");
}


int check_box(int rows,int cols, char A[rows][cols],int r1,int r2,int c1,int c2,int F[rows][cols],int flag,player *p1,player *p2){
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



int human_move(int rows,int cols, char A[rows][cols],int F[rows][cols],int flag, player *p1,player*p2){
        int r1,r2,c1,c2;
        scanf("%d %d %d %d",&r1,&r2,&c1,&c2);
        check_special_entries(r1,r2,c1,c2);
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


    return check_box(rows,cols,A,r1,r2,c1,c2,F,flag,p1,p2);
}




int computer_move(int rows,int cols, char A[rows][cols],int F[rows][cols],int flag,player *p1,player*p2){
int i,j;

for(i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
            if(i%cols_c!=0 && j%cols_c!=0 && i>2 && j>2){
            printf("lol\n");
            if(A[i+1][j]!=-51){A[i+1][j]=-51; F[i+1][j]=flag;    p2->moves++;return    check_box(rows,cols,A,i+1,i+1,j-1,j+1,F,flag,p1,p2);}
            else if(A[i-1][j]!=-51){A[i-1][j]=-51;  F[i-1][j]=flag;    p2->moves++;return    check_box(rows,cols,A,i-1,i-1,j-1,j+1,F,flag,p1,p2);}
            else if(A[i][j+1]!=-70){A[i][j+1]=-70;   F[i][j+1]=flag;  p2->moves++;return    check_box(rows,cols,A,i-1,i+1,j+1,j+1,F,flag,p1,p2);}
            else if(A[i][j-1]!=-70){A[i][j-1]=-70;    F[i][j-1]=flag;  p2->moves++;return    check_box(rows,cols,A,i-1,i+1,j-1,j-1,F,flag,p1,p2);}
}
}
}
}






