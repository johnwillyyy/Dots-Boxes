void current_time(double begin){
    double time_spent = 0.0;
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    double minutes = (int)(time_spent / 60) %60;
    time_spent = (int)time_spent%60;
   // printf("%0.0f:0%0.0f",minutes,time_spent);
   return time_spent;
}


