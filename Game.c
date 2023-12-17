#include <stdio.h>
#include <stdlib.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define RESET "\x1B[0m"
#define CYN   "\x1B[36m"

#define rows_c 2
#define cols_c 4

int check_box(int rows,int cols, char A[rows][cols],int r1,int r2,int c1,int c2,int F[rows][cols]){
    int check=0;
    if(r1==r2){
        int c = c1<c2 ? c1:c2;
        if(A[r1-1][c1]==-70&&A[r1-1][c2]==-70&&A[r1-rows_c][c+1]==-51){
            A[r1-1][c+1]=A[r1-1][c+2]=A[r1-1][c+3]=178;
            F[r1-1][c+1]=F[r1-1][c+2]=F[r1-1][c+3]=1;
            check=1;
            F[0][0]++;
        }
        if(A[r1+1][c1]==-70&&A[r1+1][c2]==-70&&A[r1+rows_c][c+1]==-51){
            A[r1+1][c+1]=A[r1+1][c+2]=A[r1+1][c+3]=178;
            F[r1+1][c+1]=F[r1+1][c+2]=F[r1+1][c+3]=1;
            check=1;
            F[0][0]++;
        }
    }
    else if(c1==c2){
        int r = r1<r2 ? r1:r2;
        if(A[r1][c1-1]==-51&&A[r2][c1-1]==-51&&A[r+1][c1-cols_c]==-70){
            A[r+1][c1-1]=A[r+1][c1-2]=A[r+1][c1-3]=178;
            F[r+1][c1-1]=F[r+1][c1-2]=F[r+1][c1-3]=1;
            check=1;
            F[0][0]++;
        }
        if(A[r1][c1+1]==-51&&A[r2][c1+1]==-51&&A[r+1][c1+cols_c]==-70){
            A[r+1][c1+1]=A[r+1][c1+2]=A[r+1][c1+3]=178;
            F[r+1][c1+1]=F[r+1][c1+2]=F[r+1][c1+3]=1;
            check=1;
            F[0][0]++;
        }
    }
    return check;
}

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

int move(int rows,int cols, char A[rows][cols],int r1,int r2,int c1,int c2,int F[rows][cols]){
    if(r1==r2){
        int c = c1<c2 ? c1:c2;
        A[r1][c+1]=A[r1][c+2]=A[r1][c+3]=-51;
        F[r1][c+1]=F[r1][c+2]=F[r1][c+3]=1;
        }
    else if(c1==c2){
        int r = r1<r2?r1:r2;
        A[r+1][c1]=-70;
        F[r+1][c1]=1;
        }
    int check=check_box(rows,cols,A,r1,r2,c1,c2,F);
    return check;
}

void print(int rows,int cols,char A[rows][cols],int R[rows][cols],int B[rows][cols]){
    for (int i=0;i<rows;i++){
        printf("\n");
      for (int j=0;j<cols;j++){
        if(R[i][j]==1)
            printf(RED"%c"RESET,A[i][j]);
        else if(B[i][j]==1)
            printf(BLU"%c"RESET,A[i][j]);
        else
            printf("%c",A[i][j]);
      }
    }
    printf("\n");
}


int main() {
    int n,m;
    scanf("%d*%d",&n,&m);

    int rows = rows_c*n+rows_c+1;
    int cols = cols_c*m+cols_c+1;

    char A[rows][cols];
    int R[rows][cols],B[rows][cols];
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            R[i][j]=B[i][j]=0;
    create_grid(rows,cols,A);
    print(rows,cols,A,R,B);

    int r1,r2,c1,c2;
    for(int k=0;k<(rows+1)*cols+(cols+1)*rows;k++){
        if(R[0][0]+B[0][0]==n*m)break;
        scanf("%d %d %d %d",&r1,&r2,&c1,&c2);
        r1=rows_c*r1;
        r2=rows_c*r2;
        c1=cols_c*c1;
        c2=cols_c*c2;
        if(k%2==0){
            int check=move(rows,cols,A,r1,r2,c1,c2,R);
            if(check==1)
                k--;
            system("cls");
            print(rows,cols,A,R,B);
        }
        else{
            int check=move(rows,cols,A,r1,r2,c1,c2,B);
            if(check==1)
                k--;
            system("cls");
            print(rows,cols,A,R,B);
        }
    }
    if(R[0][0]>B[0][0])
        printf(RED"RED WINS"RESET);
    else if(B[0][0]>R[0][0])
        printf(BLU"BLUE WINS"RESET);
    else
        printf("DRAW");
}