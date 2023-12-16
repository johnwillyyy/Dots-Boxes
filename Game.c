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

void create_grid(int  rows,int cols,char A[rows][cols]){
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++){
            if(i==0&&j%cols_c==0)
                A[i][j]=48+j/cols_c;
            else if(j==0&&i%rows_c==0)
                A[i][j]=48+i/rows_c;
            else if(i%rows_c!=0||j%cols_c!=0)
                A[i][j]=' ';
            else
                A[i][j]=254;
        }
}

/*void move(char *A,int r1,int r2,int c1,int c2){
    if(r1==r2){
        int c = c1<c2 ? c1:c2;
        //int *ptr = &rows;
        //*((A+r1*2) + (4*c)) = *((A+r1*2) + (4*c+1)) = *((A+r1*2) + (4*c+2))= 205;
        //*(*(A + 1) + 2) = 205;
        *(A + ((r1+1) * 21 + (4*c)+1)) = *(A + ((r1+1) * 21 + (4*c)+2)) = 205;

}
   else if(c1==c2){
}
}
*/


void move(int rows,int cols, char A[rows][cols],int r1,int r2,int c1,int c2){
    if(r1==r2){
        int c = c1<c2 ? c1:c2;
        A[rows_c*r1][cols_c*c+1]=A[rows_c*r1][cols_c*c+2]=A[rows_c*r1][cols_c*c+3]=205;
        }
    else if(c1==c2){
        int r = r1<r2?r1:r2;
        A[rows_c*r1+1][cols_c*c1]=186;
        }
}


void print(char *arr, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++){
        printf("\n");
      for (j = 0; j < n; j++)
        printf("%c", *((arr+i*n) + j));
    }
    printf("\n");
}


int main() {
    int n,m;
    scanf("%d*%d",&n,&m);

    int rows = rows_c*n+1;
    int cols = cols_c*m+1;

    char A[rows][cols];
    create_grid(rows,cols,A);
     //char *ptr = &A[0][0];
    print((char *)A, rows, cols);

    int r1,r2,c1,c2;
    scanf("%d %d %d %d",&r1,&r2,&c1,&c2);
    //move((char *)A,r1,r2,c1,c2);
    move(rows,cols,A,r1,r2,c1,c2);
    system("cls");
    print((char *)A, rows, cols);
}