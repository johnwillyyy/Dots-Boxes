void gameLoop(){
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
         /*  printArray(uARR, 50);
            printf("\n");
            printArray(rARR, count);
            printf("\n");
            printf("Count = %d | ",count);
            printf("MOVECOUNT = %d | ", movecount);
            printf("FLAG = %d\n", flag);*/ 
    }












}