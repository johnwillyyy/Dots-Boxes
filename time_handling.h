int current_time(double begin){
    double time_spent = 0.0;
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    minutes = (int)(time_spent / 60) %60;
    time_spent = (int)time_spent%60;
    //printf("%0.0f:0%0.0f",minutes,time_spent);
    seconds = time_spent;
    return time_spent;
}


/*void *timerThread(void *arg) {

    int *exitFlag = (int *)arg;
    //printf("I ENTERED THREAD");
    while (!*exitFlag) {
           // printf("%d",current_time(player_begun));
        if(current_time(player_begun)>=60){
            system("cls");
            print_grid(A,flagARR);
            print_data(p1,p2,match_begun,n*m);
            human_move(A,flagARR,uARR,rARR,&p1,&p2);
            return NULL;}
        sleep(1); // Check for exit every second
    }

    //printf("Timer thread is exiting\n");
    return NULL;
}*/