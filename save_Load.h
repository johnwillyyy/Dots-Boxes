FILE *file;
char read_el[30];
char readz[30];


void printintArray(int **arr) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void printcharArray(char** arr) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}




void writeCharArray(const char *filename, char **array) {
      if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(file, "%d ", array[i][j]);
        }
        fprintf(file, "\n");
    }
}


void writeNames(const char *filename, player *p1, player *p2) {
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }
            fprintf(file, "%s", p1->name);
            fprintf(file,"\n");
            fprintf(file, "%s", p2->name);
            fprintf(file,"\n");
}

void writeData(const char *filename,  player *p1, player *p2) {
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }
            fprintf(file, "%d\n", p1->moves);
            fprintf(file, "%d\n", p2->moves);
            fprintf(file, "%d\n", p1->score);
            fprintf(file, "%d\n", p2->score);
}





void writeGameData(char *filename,player *p1, player *p2){
    file = fopen(filename, "w");


    fprintf(file,"%d %d\n",n, m);
    fprintf(file,"%d %d\n",flag, mode);
    writeNames(filename, p1,p2);
    writeData(filename, p1,p2);


    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(file, "%d ", flagARR[i][j]);
        }
        fprintf(file, "\n");
    }
    writeCharArray(filename, A);


    fclose(file);

}


int readInt(const char *filename, int x) {

    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return 0;
    }
    if (fscanf(file, " %d ", &x) == 1) {
        printf("Read integer: %d\n", x);
    }
    else {
        perror("Error reading integer from file");
    }
    //printf("%d\n",x);
    return x;
    }




int save_Game(){
    char filename[MAX_FILENAME_LENGTH];
    char userString[MAX_STRING_LENGTH];
    printf("Enter a string: \n");
    // Prompt the user for a string

    // Use fgets to read the entire line of input, including spaces
    //scanf("%c", (char *) stdin);

    if (fgets(userString, sizeof(userString), stdin) != NULL) {
        // Remove the newline character if present
            scanf("%c", (char *) stdin);

        size_t length = strlen(userString);
        if (length > 0 && userString[length - 1] == '\n') {
            userString[length - 1] = '\0';
        }
    } else {
        perror("Error reading input");
        return 0;
    }
    snprintf(filename, sizeof(filename), "%s.txt", userString);

writeGameData(filename,&p1, &p2);

}




void loadGame(char *filename,player p1, player p2){

    file = fopen(filename, "r");
    n = readInt(filename,n);
    m = readInt(filename,m);
    rows = rows_c*n+rows_c+1;
    cols = cols_c*m+cols_c+1;
    printf("success\n");sleep(1);
    allocateArrays();
    flag = readInt(filename,flag);
    mode = readInt(filename,mode);   printf("success");sleep(1);

 fgets(p1.name, sizeof(p1.name), file);
        printf("Read from file: %s", p1.name);

 fgets(p2.name, sizeof(p2.name), file);
        printf("Read from file: %s", p2.name);

    printf("success\n");sleep(1);
    p1.moves = readInt(filename,p1.moves);
    p2.moves = readInt(filename,p2.moves);
    p1.score = readInt(filename,p1.score);
    p2.score = readInt(filename,p2.score);
    printf("success\n");sleep(1);

    sleep(5);
    printf("MSHTARSH");
        for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
           fscanf(file, "%d", &flagARR[i][j]);
        }
    }

        for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int asciiValue;
            if (fscanf(file, "%d", &asciiValue) == 1) {
                A[i][j] = (char)asciiValue;
            } else {
                // Handle error or unexpected end of file
                fprintf(stderr, "Error reading from file\n");
                fclose(file);
                return;
            }
        }
    }
    fclose(file);


    printintArray(flagARR);sleep(5);
    printcharArray(A);sleep(5);

    system("cls");
    print_grid(A,flagARR);
    print_data(p1,p2,match_begun,n*m);
    clock_t match_begun = clock();
     gameLoop(A,flagARR);
    winnerCheck();
    Top10Save();

}

