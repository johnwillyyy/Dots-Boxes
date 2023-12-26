int check_box(char A[rows][cols],int r1,int r2,int c1,int c2,int F[rows][cols],int flag,player *p1,player *p2){
    int check=0,checkinv =0;
    if(r1==r2){
        int c = c1<c2 ? c1:c2;

        if(A[r1-1][c1]==-70&&A[r1-1][c2]==-70&&A[r1-rows_c][c+1]==-51){
                if(A[r1-1][c+1] != 178){
                    A[r1-1][c+1]=178;
                    F[r1-1][c+1]=flag;
                    check++;}

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
    movecount++;

    if (check>0) {
            if (flag ==0) {p1->score+=check; return flag;}
            else if (flag ==1) {p2->score+=check; return flag;}
    }
    else {movecount = 0;
            return flag^=1;
}}


void check_box_inv(char A[rows][cols],int r1,int r2,int c1,int c2,int F[rows][cols],int flag,player *p1,player *p2){
    int check =0;
    if(r1==r2){
        int c = c1<c2 ? c1:c2;

        if(A[r1-1][c1]==-70&&A[r1-1][c2]==-70&&A[r1-rows_c][c+1]==-51){
                    A[r1-1][c+1]=' ';
                    F[r1-1][c+1]=2;
                    check++;

        }
        if(A[r1+1][c1]==-70&&A[r1+1][c2]==-70&&A[r1+rows_c][c+1]==-51){
            A[r1+1][c+1]=' ';
            F[r1+1][c+1]=2;
            check++;
        }
    }
    else if(c1==c2){
        int r = r1<r2 ? r1:r2;
        if(A[r1][c1-1]==-51&&A[r2][c1-1]==-51&&A[r+1][c1-cols_c]==-70){
            A[r+1][c1-1]=' ';
            F[r+1][c1-1]=2;
            check++;
        }
        if(A[r1][c1+1]==-51&&A[r2][c1+1]==-51&&A[r+1][c1+cols_c]==-70){
            A[r+1][c1+1]=' ';
            F[r+1][c1+1]=2;
            check++;
        }
    }
    if (check>0) {
            if (flag ==0) {p1->score-=check;}
            else if (flag ==1) {p2->score-=check;}
    }
}
