int check_chain(char **A,int **F,int r1,int r2,int c1, int c2,player *p1,player *p2,int right,int left,int up,int down,int check){
    int x=0,y=0,z=0;
    /*if(r1<2||r1>rows-1||r2<2||r2>rows-1||c1<2||c1>cols-1||c2<2||c2>cols-1)return 0;*/
    if(r1==r2){
        int c = c1<c2 ? c1:c2;
        if(up==0&&down==1){
            if(r1+1<rows && A[r1+1][c1]==-70 && A[r1+1][c2]==-70 && A[r1+rows_c][c+1]!=-51){  // move down
               x=check_chain(A,F,r1+rows_c,r2+rows_c,c1,c2,p1,p2,right,left,up,down,check);  //call function to move down
               if(x){
                    /*printf("%d %d %d %d",r1/2,r2/2,c1/2,c2/2);sleep(2);*/
                    if(!check)dfsmove(A,F,r1,r2,c1,c2,right,left,up,down,p1,p2);       //make a box down
                    return 1;
                }
            }
            else if(r1+1<rows && A[r1+1][c1]==-70 && A[r1+1][c2]==-70 && A[r1+rows_c][c+1]==-51){   //check the end of going down
                    /*printf("%d %d %d %d",r1/2,r2/2,c1/2,c2/2);sleep(2);*/
                    if(!check)dfsmove(A,F,r1,r2,c1,c2,right,left,up,down,p1,p2);     //make a box down
                    return 1;
            }
            else if(r1+1<rows && A[r1+rows_c][c+1]==-51 && A[r1+1][c]==-70 && A[r1+1][c+cols_c]!=-70){ //moving down then find path right
                x=check_chain(A,F,r1,r2+rows_c,c+cols_c,c+cols_c,p1,p2,1,0,0,0,check); //call function to move to the right
                if(x){
                    /*printf("%d %d %d %d",r1/2,r2/2,c1/2,c2/2);sleep(2);*/
                    if(!check)dfsmove(A,F,r1,r2,c1,c2,right,left,up,down,p1,p2);  //make box in the junction
                    return 1;
                }
            }
            else if(r1+1<rows && A[r1+rows_c][c+1]==-51 && A[r1+1][c]!=-70 && A[r1+1][c+cols_c]==-70){ //moving down then find path left
                x=check_chain(A,F,r1,r2+rows_c,c,c,p1,p2,0,1,0,0,check); //call function to move to the left
                if(x){
                    /*printf("%d %d %d %d",r1/2,r2/2,c1/2,c2/2);sleep(2);*/
                    if(!check)dfsmove(A,F,r1,r2,c1,c2,right,left,up,down,p1,p2);  //make box in the junction
                    return 1;
                }
            }
            else if(r1+1<rows && A[r1+rows_c][c+1]==-51 && A[r1+1][c]!=-70 && A[r1+1][c+cols_c]!=-70){ //moving down then find paths right and left
                x=check_chain(A,F,r1,r2+rows_c,c+cols_c,c+cols_c,p1,p2,1,0,0,0,1); //call function check the right
                y=check_chain(A,F,r1,r2+rows_c,c,c,p1,p2,0,1,0,0,1); //call function to check the left
                if(x&&y){
                    /*printf("%d %d %d %d",r1/2,r2/2,c1/2,c2/2);sleep(2);*/
                    if(!check){
                    check_chain(A,F,r1,r2+rows_c,c+cols_c,c+cols_c,p1,p2,1,0,0,0,0); //call function to move to the right
                    check_chain(A,F,r1,r2+rows_c,c,c,p1,p2,0,1,0,0,0); //call function to to move to the left
                    dfsmove(A,F,r1,r2,c1,c2,right,left,up,down,p1,p2);    //make box in the junction
                    }
                    return 1;
                }
            }
            else if(r1+1<rows && A[r1+rows_c][c+1]!=-51 && A[r1+1][c]==-70 && A[r1+1][c+cols_c]!=-70){ //moving down then find paths right and down
                x=check_chain(A,F,r1,r2+rows_c,c+cols_c,c+cols_c,p1,p2,1,0,0,0,1); //call function check the right
                y=check_chain(A,F,r1+rows_c,r2+rows_c,c1,c2,p1,p2,0,0,0,1,1); //call function to check down
                if(x&&y){
                    /*printf("%d %d %d %d",r1/2,r2/2,c1/2,c2/2);sleep(2);*/
                    if(!check){
                    check_chain(A,F,r1,r2+rows_c,c+cols_c,c+cols_c,p1,p2,1,0,0,0,0); //call function to move to the right
                    check_chain(A,F,r1+rows_c,r2+rows_c,c1,c2,p1,p2,0,0,0,1,0); //call function to to move down
                    dfsmove(A,F,r1,r2,c1,c2,right,left,up,down,p1,p2);   //make box in the junction
                    }
                    return 1;
                }
            }
            else if(r1+1<rows && A[r1+rows_c][c+1]!=-51 && A[r1+1][c]!=-70 && A[r1+1][c+cols_c]==-70){ //moving down then find paths left and down
                x=check_chain(A,F,r1,r2+rows_c,c,c,p1,p2,0,1,0,0,1); //call function check the left
                y=check_chain(A,F,r1+rows_c,r2+rows_c,c1,c2,p1,p2,0,0,0,1,1); //call function to check down
                if(x&&y){
                    /*printf("%d %d %d %d",r1/2,r2/2,c1/2,c2/2);sleep(2);*/
                    if(!check){
                    check_chain(A,F,r1,r2+rows_c,c,c,p1,p2,0,1,0,0,0); //call function to move to the left
                    check_chain(A,F,r1+rows_c,r2+rows_c,c1,c2,p1,p2,0,0,0,1,0); //call function to to move down
                    dfsmove(A,F,r1,r2,c1,c2,right,left,up,down,p1,p2);   //make box in the junction
                    }
                    return 1;
                }
            }
            else if(r1+1<rows && A[r1+rows_c][c+1]!=-51 && A[r1+1][c]!=-70 && A[r1+1][c+cols_c]!=-70&&check!=2){ //moving down then find paths right and left and down
                x=check_chain(A,F,r1,r2+rows_c,c,c,p1,p2,0,1,0,0,2); //call function check the left
                y=check_chain(A,F,r1+rows_c,r2+rows_c,c1,c2,p1,p2,0,0,0,1,2); //call function to check down
                z=check_chain(A,F,r1,r2+rows_c,c+cols_c,c+cols_c,p1,p2,1,0,0,0,2); //call function to check the right
                if(x&&y&&z){
                    /*printf("%d %d %d %d",r1/2,r2/2,c1/2,c2/2);sleep(2);*/
                    if(!check){
                    check_chain(A,F,r1,r2+rows_c,c,c,p1,p2,0,1,0,0,0); //call function to move to the left
                    check_chain(A,F,r1+rows_c,r2+rows_c,c1,c2,p1,p2,0,0,0,1,0); //call function to to move down
                    check_chain(A,F,r1,r2+rows_c,c+cols_c,c+cols_c,p1,p2,1,0,0,0,0); //call function to move to the right
                    dfsmove(A,F,r1,r2,c1,c2,right,left,up,down,p1,p2);   //make box in the junction
                    }
                    return 1;
                }
            }
        }
        else if(up==1&&down==0){
            if(r1-1>=2 && A[r1-1][c1]==-70 && A[r1-1][c2]==-70 && A[r1-rows_c][c+1]!=-51){   // move up
               x=check_chain(A,F,r1-rows_c,r2-rows_c,c1,c2,p1,p2,right,left,up,down,check); //call function to move up
               if(x){
                    /*printf("%d %d %d %d",r1/2,r2/2,c1/2,c2/2);sleep(2);*/
                    if(!check)dfsmove(A,F,r1,r2,c1,c2,right,left,up,down,p1,p2);     //make a box up
                    return 1;
                }
            }
            else if(r1-1>=2 && A[r1-1][c1]==-70 && A[r1-1][c2]==-70 && A[r1-rows_c][c+1]==-51){      //check the end of going up
                    /*printf("%d %d %d %d",r1/2,r2/2,c1/2,c2/2);sleep(2);*/
                    if(!check)dfsmove(A,F,r1,r2,c1,c2,right,left,up,down,p1,p2);    //make a box up
                    return 1;
            }
            else if(r1-1>=2 && A[r1-rows_c][c+1]==-51 && A[r1-1][c]==-70 && A[r1-1][c+cols_c]!=-70){ //moving up then find path right
                x=check_chain(A,F,r1,r2-rows_c,c+cols_c,c+cols_c,p1,p2,1,0,0,0,check); //call function to move to the right
                if(x){
                    /*printf("%d %d %d %d",r1/2,r2/2,c1/2,c2/2);sleep(2);*/
                    if(!check)dfsmove(A,F,r1,r2,c1,c2,right,left,up,down,p1,p2);  //make box in the junction
                    return 1;
                }
            }
            else if(r1-1>=2 && A[r1-rows_c][c+1]==-51 && A[r1-1][c]!=-70 && A[r1-1][c+cols_c]==-70){ //moving up then find path left
                x=check_chain(A,F,r1,r2-rows_c,c,c,p1,p2,0,1,0,0,check); //call function to move to the left
                if(x){
                    /*printf("%d %d %d %d",r1/2,r2/2,c1/2,c2/2);sleep(2);*/
                    if(!check)dfsmove(A,F,r1,r2,c1,c2,right,left,up,down,p1,p2);  //make box in the junction
                    return 1;
                }
            }
            else if(r1-1>=2 && A[r1-rows_c][c+1]==-51 && A[r1-1][c]!=-70 && A[r1-1][c+cols_c]!=-70){ //moving up then find paths right and left
                x=check_chain(A,F,r1,r2-rows_c,c+cols_c,c+cols_c,p1,p2,1,0,0,0,1); //call function check the right
                y=check_chain(A,F,r1,r2-rows_c,c,c,p1,p2,0,1,0,0,1); //call function to check the left
                if(x&&y){
                    /*printf("%d %d %d %d",r1/2,r2/2,c1/2,c2/2);sleep(2);*/
                    if(!check){
                    check_chain(A,F,r1,r2-rows_c,c+cols_c,c+cols_c,p1,p2,1,0,0,0,0); //call function to move to the right
                    check_chain(A,F,r1,r2-rows_c,c,c,p1,p2,0,1,0,0,0); //call function to to move to the left
                    dfsmove(A,F,r1,r2,c1,c2,right,left,up,down,p1,p2);   //make box in the junction
                    }
                    return 1;
                }
            }
            else if(r1-1>=2 && A[r1-rows_c][c+1]!=-51 && A[r1-1][c]==-70 && A[r1-1][c+cols_c]!=-70){ //moving up then find paths right and up
                x=check_chain(A,F,r1,r2-rows_c,c+cols_c,c+cols_c,p1,p2,1,0,0,0,1); //call function check the right
                y=check_chain(A,F,r1-rows_c,r2-rows_c,c1,c2,p1,p2,0,0,1,0,1); //call function to check up
                if(x&&y){
                    /*printf("%d %d %d %d",r1/2,r2/2,c1/2,c2/2);sleep(2);*/
                    if(!check){
                    check_chain(A,F,r1,r2-rows_c,c+cols_c,c+cols_c,p1,p2,1,0,0,0,0); //call function to move to the right
                    check_chain(A,F,r1-rows_c,r2-rows_c,c1,c2,p1,p2,0,0,1,0,0); //call function to to move up
                    dfsmove(A,F,r1,r2,c1,c2,right,left,up,down,p1,p2);   //make box in the junction
                    }
                    return 1;
                }
            }
            else if(r1-1>=2 && A[r1-rows_c][c+1]!=-51 && A[r1-1][c]!=-70 && A[r1-1][c+cols_c]==-70){ //moving up then find paths left and up
                x=check_chain(A,F,r1,r2-rows_c,c,c,p1,p2,0,1,0,0,1); //call function check the left
                y=check_chain(A,F,r1-rows_c,r2-rows_c,c1,c2,p1,p2,0,0,1,0,1); //call function to check up
                if(x&&y){
                    /*printf("%d %d %d %d",r1/2,r2/2,c1/2,c2/2);sleep(2);*/
                    if(!check){
                    check_chain(A,F,r1,r2-rows_c,c,c,p1,p2,0,1,0,0,0); //call function to move to the left
                    check_chain(A,F,r1-rows_c,r2-rows_c,c1,c2,p1,p2,0,0,1,0,0); //call function to to move up
                    dfsmove(A,F,r1,r2,c1,c2,right,left,up,down,p1,p2);   //make box in the junction
                    }
                    return 1;
                }
            }
            else if(r1-1>=2 && A[r1-rows_c][c+1]!=-51 && A[r1-1][c]!=-70 && A[r1-1][c+cols_c]!=-70&&check!=2){ //moving up then find paths right and left and up
                x=check_chain(A,F,r1,r2-rows_c,c,c,p1,p2,0,1,0,0,2); //call function check the left
                y=check_chain(A,F,r1-rows_c,r2-rows_c,c1,c2,p1,p2,0,0,1,0,2); //call function to check up
                z=check_chain(A,F,r1,r2-rows_c,c+cols_c,c+cols_c,p1,p2,1,0,0,0,2); //call function check the right
                if(x&&y&&z){
                    /*printf("%d %d %d %d",r1/2,r2/2,c1/2,c2/2);sleep(2);*/
                    if(!check){
                    check_chain(A,F,r1,r2-rows_c,c,c,p1,p2,0,1,0,0,0); //call function to move to the left
                    check_chain(A,F,r1-rows_c,r2-rows_c,c1,c2,p1,p2,0,0,1,0,0); //call function to to move up
                    check_chain(A,F,r1,r2-rows_c,c+cols_c,c+cols_c,p1,p2,1,0,0,0,0); //call function to move to the right
                    dfsmove(A,F,r1,r2,c1,c2,right,left,up,down,p1,p2);   //make box in the junction
                    }
                    return 1;
                }
            }
        }
    }
    if(c1==c2){
        int r = r1<r2 ? r1:r2;
        if(left==0&&right==1){
            if(c1+1<cols && A[r][c1+1]==-51 && A[r+rows_c][c1+1]==-51 && A[r+1][c1+cols_c]!=-70){  //move to the right
               x=check_chain(A,F,r1,r2,c1+cols_c,c2+rows_c,p1,p2,right,left,up,down,check); //call function to move to the right
               if(x){
                   /*printf("%d %d %d %d",r1/2,r2/2,c1/2,c2/2);sleep(2);*/
                   if(!check)dfsmove(A,F,r1,r2,c1,c2,right,left,up,down,p1,p2); //make a box on its right
                  return 1;
                  }
            }
            else if(c1+1<cols && A[r][c1+1]==-51 && A[r+rows_c][c1+1]==-51 && A[r+1][c1+cols_c]==-70){ //check the end of going right
                    /*printf("%d %d %d %d",r1/2,r2/2,c1/2,c2/2);sleep(2);*/
                    if(!check)dfsmove(A,F,r1,r2,c1,c2,right,left,up,down,p1,p2);  //make a box on its right
                    return 1;
            }
            else if(c1+1<cols && A[r][c1+1]==-51 && A[r+rows_c][c1+1]!=-51 && A[r+1][c1+cols_c]==-70){ //moving to the right then find path down
                x=check_chain(A,F,r+rows_c,r+rows_c,c1,c2+cols_c,p1,p2,0,0,0,1,check); //call function to move down
                if(x){
                    /*printf("%d %d %d %d",r1/2,r2/2,c1/2,c2/2);sleep(2);*/
                    if(!check)dfsmove(A,F,r1,r2,c1,c2,right,left,up,down,p1,p2);  //make box in the junction
                    return 1;
                }
            }
            else if(c1+1<cols && A[r][c1+1]!=-51 && A[r+rows_c][c1+1]==-51 && A[r+1][c1+cols_c]==-70){ //moving to the right then find path up
                x=check_chain(A,F,r,r,c1,c2+cols_c,p1,p2,0,0,1,0,check);  //call function to move up
                if(x){
                    /*printf("%d %d %d %d",r1/2,r2/2,c1/2,c2/2);sleep(2);*/
                    if(!check)dfsmove(A,F,r1,r2,c1,c2,right,left,up,down,p1,p2); //make box at the junction
                    return 1;
                }
            }
            else if(c1+1<cols && A[r][c1+1]!=-51 && A[r+rows_c][c1+1]!=-51 && A[r+1][c1+cols_c]==-70){ //moving right then find paths up and down
                x=check_chain(A,F,r,r,c1,c2+cols_c,p1,p2,0,0,1,0,1); //call function check up
                y=check_chain(A,F,r+rows_c,r+rows_c,c1,c2+cols_c,p1,p2,0,0,0,1,1); //call function to check down
                if(x&&y){
                    /*printf("%d %d %d %d",r1/2,r2/2,c1/2,c2/2);sleep(2);*/
                    if(!check){
                    check_chain(A,F,r,r,c1,c2+cols_c,p1,p2,0,0,1,0,0); //call function to move up
                    check_chain(A,F,r+rows_c,r+rows_c,c1,c2+cols_c,p1,p2,0,0,0,1,0); //call function to to move down
                    dfsmove(A,F,r1,r2,c1,c2,right,left,up,down,p1,p2);   //make box in the junction
                    }
                    return 1;
                }
            }
            else if(c1+1<cols && A[r][c1+1]==-51 && A[r+rows_c][c1+1]!=-51 && A[r+1][c1+cols_c]!=-70){ //moving right then find paths right and down
                x=check_chain(A,F,r1,r2,c1+cols_c,c2+cols_c,p1,p2,1,0,0,0,1); //call function check the right
                y=check_chain(A,F,r+rows_c,r+rows_c,c1,c2+cols_c,p1,p2,0,0,0,1,1); //call function to check down
                if(x&&y){
                    /*printf("%d %d %d %d",r1/2,r2/2,c1/2,c2/2);sleep(2);*/
                    if(!check){
                    check_chain(A,F,r1,r2,c1+cols_c,c2+cols_c,p1,p2,1,0,0,0,0); //call function to move to the right
                    check_chain(A,F,r+rows_c,r+rows_c,c1,c2+cols_c,p1,p2,0,0,0,1,0); //call function to to move down
                    dfsmove(A,F,r1,r2,c1,c2,right,left,up,down,p1,p2);   //make box in the junction
                    }
                    return 1;
                }
            }
            else if(c1+1<cols && A[r][c1+1]!=-51 && A[r+rows_c][c1+1]==-51 && A[r+1][c1+cols_c]!=-70){ //moving right then find paths right and up
                x=check_chain(A,F,r1,r2,c1+cols_c,c2+cols_c,p1,p2,1,0,0,0,1); //call function check the right
                y=check_chain(A,F,r,r,c1,c2+cols_c,p1,p2,0,0,1,0,1); //call function check up
                if(x&&y){
                    /*printf("%d %d %d %d",r1/2,r2/2,c1/2,c2/2);sleep(2);*/
                    if(!check){
                    check_chain(A,F,r1,r2,c1+cols_c,c2+cols_c,p1,p2,1,0,0,0,0); //call function to move to the right
                    check_chain(A,F,r,r,c1,c2+cols_c,p1,p2,0,0,1,0,0);   //call function to to move up
                    dfsmove(A,F,r1,r2,c1,c2,right,left,up,down,p1,p2);   //make box in the junction
                    }
                    return 1;
                }
            }
            else if(c1+1<cols && A[r][c1+1]!=-51 && A[r+rows_c][c1+1]!=-51 && A[r+1][c1+cols_c]!=-70&&check!=2){ //moving right then find paths right and up and down
                x=check_chain(A,F,r1,r2,c1+cols_c,c2+cols_c,p1,p2,1,0,0,0,2); //call function check the right
                y=check_chain(A,F,r,r,c1,c2+cols_c,p1,p2,0,0,1,0,2); //call function check up
                z=check_chain(A,F,r+rows_c,r+rows_c,c1,c2+cols_c,p1,p2,0,0,0,1,2); //call function to check down
                if(x&&y&&z){
                    /*printf("%d %d %d %d",r1/2,r2/2,c1/2,c2/2);sleep(2);*/
                    if(!check){
                    check_chain(A,F,r1,r2,c1+cols_c,c2+cols_c,p1,p2,1,0,0,0,0); //call function to move to the right
                    check_chain(A,F,r,r,c1,c2+cols_c,p1,p2,0,0,1,0,0);   //call function to to move up
                    check_chain(A,F,r+rows_c,r+rows_c,c1,c2+cols_c,p1,p2,0,0,0,1,0); //call function to to move down
                    dfsmove(A,F,r1,r2,c1,c2,right,left,up,down,p1,p2);   //make box in the junction
                    }
                    return 1;
                }
            }
        }
        else if(left==1&&right==0){
            if(c1-1>=2 && A[r][c1-1]==-51 && A[r+rows_c][c1-1]==-51 && A[r+1][c1-cols_c]!=-70){  //move to the left
                x=check_chain(A,F,r1,r2,c1-cols_c,c2-rows_c,p1,p2,right,left,up,down,check); //call function to move left
                if(x){
                    /*printf("%d %d %d %d",r1/2,r2/2,c1/2,c2/2);sleep(2);*/
                    if(!check)dfsmove(A,F,r1,r2,c1,c2,right,left,up,down,p1,p2);  //make a box on its left
                    return 1;
                }
            }
            else if(c1-1>=2 && A[r][c1-1]==-51 && A[r+rows_c][c1-1]==-51 && A[r+1][c1-cols_c]==-70){  //check the end of going left
                    /*printf("%d %d %d %d",r1/2,r2/2,c1/2,c2/2);sleep(2);*/
                    if(!check)dfsmove(A,F,r1,r2,c1,c2,right,left,up,down,p1,p2); //make a box on its left
                    return 1;
            }
            else if(c1-1>=2 && A[r][c1-1]==-51 && A[r+rows_c][c1-1]!=-51 && A[r+1][c1-cols_c]==-70){ //moving to the left then find path down
                x=check_chain(A,F,r+rows_c,r+rows_c,c1,c2-cols_c,p1,p2,0,0,0,1,check); //call function to move down
                if(x){
                    /*printf("%d %d %d %d",r1/2,r2/2,c1/2,c2/2);sleep(2);*/
                    if(!check)dfsmove(A,F,r1,r2,c1,c2,right,left,up,down,p1,p2);  //make box in the junction
                    return 1;
                }
            }
            else if(c1-1>=2 && A[r][c1-1]!=-51 && A[r+rows_c][c1-1]==-51 && A[r+1][c1-cols_c]==-70){ //moving to the left then find path up
                x=check_chain(A,F,r,r,c1,c2-cols_c,p1,p2,0,0,1,0,check);  //call function to move up
                if(x){
                    /*printf("%d %d %d %d",r1/2,r2/2,c1/2,c2/2);sleep(2);*/
                    if(!check)dfsmove(A,F,r1,r2,c1,c2,right,left,up,down,p1,p2); //make box at the junction
                    return 1;
                }
            }
            else if(c1-1>=2 && A[r][c1-1]!=-51 && A[r+rows_c][c1-1]!=-51 && A[r+1][c1-cols_c]==-70){ //moving left then find paths up and down
                x=check_chain(A,F,r,r,c1,c2-cols_c,p1,p2,0,0,1,0,1); //call function check up
                y=check_chain(A,F,r+rows_c,r+rows_c,c1,c2-cols_c,p1,p2,0,0,0,1,1); //call function to check down
                if(x&&y){
                    /*printf("%d %d %d %d",r1/2,r2/2,c1/2,c2/2);sleep(2);*/
                    if(!check){
                    check_chain(A,F,r,r,c1,c2-cols_c,p1,p2,0,0,1,0,0); //call function to move up
                    check_chain(A,F,r+rows_c,r+rows_c,c1,c2-cols_c,p1,p2,0,0,0,1,0); //call function to to move down
                    dfsmove(A,F,r1,r2,c1,c2,right,left,up,down,p1,p2);   //make box in the junction
                    }
                    return 1;
                }
            }
            else if(c1-1>=2 && A[r][c1-1]==-51 && A[r+rows_c][c1-1]!=-51 && A[r+1][c1-cols_c]!=-70){ //moving left then find paths left and down
                x=check_chain(A,F,r1,r2,c1-cols_c,c2-cols_c,p1,p2,0,1,0,0,1); //call function check the left
                y=check_chain(A,F,r+rows_c,r+rows_c,c1,c2-cols_c,p1,p2,0,0,0,1,1); //call function to check down
                if(x&&y){
                    /*printf("%d %d %d %d",r1/2,r2/2,c1/2,c2/2);sleep(2);*/
                    if(!check){
                    check_chain(A,F,r1,r2,c1-cols_c,c2-cols_c,p1,p2,0,1,0,0,0); //call function to move to the left
                    check_chain(A,F,r+rows_c,r+rows_c,c1,c2-cols_c,p1,p2,0,0,0,1,0); //call function to to move down
                    dfsmove(A,F,r1,r2,c1,c2,right,left,up,down,p1,p2);   //make box in the junction
                    }
                    return 1;
                }
            }
            else if(c1-1>=2 && A[r][c1-1]!=-51 && A[r+rows_c][c1-1]==-51 && A[r+1][c1-cols_c]!=-70){ //moving left then find paths left and up
                x=check_chain(A,F,r1,r2,c1-cols_c,c2-cols_c,p1,p2,0,1,0,0,1); //call function check the left
                y=check_chain(A,F,r,r,c1,c2-cols_c,p1,p2,0,0,1,0,1); //call function check up
                if(x&&y){
                    /*printf("%d %d %d %d",r1/2,r2/2,c1/2,c2/2);sleep(2);*/
                    if(!check){
                    check_chain(A,F,r1,r2,c1-cols_c,c2-cols_c,p1,p2,0,1,0,0,0); //call function to move to the left
                    check_chain(A,F,r,r,c1,c2-cols_c,p1,p2,0,0,1,0,0);   //call function to to move up
                    dfsmove(A,F,r1,r2,c1,c2,right,left,up,down,p1,p2);   //make box in the junction
                    }
                    return 1;
                }
            }
            else if(c1-1>=2 && A[r][c1-1]!=-51 && A[r+rows_c][c1-1]!=-51 && A[r+1][c1-cols_c]!=-70&&check!=2){ //moving left then find paths left and up and down
                x=check_chain(A,F,r1,r2,c1-cols_c,c2-cols_c,p1,p2,0,1,0,0,2); //call function check the left
                y=check_chain(A,F,r,r,c1,c2-cols_c,p1,p2,0,0,1,0,2); //call function check up
                z=check_chain(A,F,r+rows_c,r+rows_c,c1,c2-cols_c,p1,p2,0,0,0,1,2); //call function to check down
                if(x&&y&z){
                    /*printf("%d %d %d %d",r1/2,r2/2,c1/2,c2/2);sleep(2);*/
                    if(!check){
                    check_chain(A,F,r1,r2,c1-cols_c,c2-cols_c,p1,p2,0,1,0,0,0); //call function to move to the left
                    check_chain(A,F,r,r,c1,c2-cols_c,p1,p2,0,0,1,0,0);   //call function to to move up
                    check_chain(A,F,r+rows_c,r+rows_c,c1,c2-cols_c,p1,p2,0,0,0,1,0); //call function to to move down
                    dfsmove(A,F,r1,r2,c1,c2,right,left,up,down,p1,p2);   //make box in the junction
                    }
                    return 1;
                }
            }
        }
    }
    return 0;
}
