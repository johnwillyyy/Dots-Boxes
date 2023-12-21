


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
            if (flag ==0) {p1->score++; return flag;}
            else if (flag ==1) {p2->score++; return flag;}
    }
    else return flag^=1;


}



int move(int rows,int cols, char A[rows][cols],int F[rows][cols],int flag, player *p1,player*p2){
        int r1,r2,c1,c2;
        scanf("%d %d %d %d",&r1,&r2,&c1,&c2);
        r1=rows_c*r1;
        r2=rows_c*r2;
        c1=cols_c*c1;
        c2=cols_c*c2;
    if(r1==r2 && abs(c1-c2) == 2){
        int c = c1<c2 ? c1:c2;
        if(A[r1][c+1] != -51){
        A[r1][c+1]=-51;
        F[r1][c+1]=flag;}
        }
    else if(c1==c2 && abs(r1-r2) == 2){
        int r = r1<r2?r1:r2;
        if(A[r+1][c1] != -70){
        A[r+1][c1]=-70;
        F[r+1][c1]=flag;}
        }
        if (flag == 0)p1->moves++;
        if (flag == 1)p2->moves++;


    return check_box(rows,cols,A,r1,r2,c1,c2,F,flag,&p1,&p2);
}


void score(player *p1,player *p2,int rows,int cols,int F[rows][cols]){

int i,j;
p1->score =0 ;
p2->score =0 ;

for(i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
if(i%cols_c!=0 && j%cols_c!=0 && F[i][j] == 0)
    {p1->score+=1;}

if (i%cols_c!=0 && j%cols_c!=0 && F[i][j] == 1)
{p2->score+=1;}

}
}
}



