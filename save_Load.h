FILE *file;
char read_el[30];
char readz[30];



void writeIntArray(const char *filename, int array[rows][cols]) {
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
                putw(array[i][j],file);        }
        fprintf(file, "\n");
    }
            fprintf(file, "\n");

}
void writeCharArray(const char *filename, char array[rows][cols]) {
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

void writeint(const char *filename, int x) {
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }
            fprintf(file, "%d", x);
            fprintf(file,"\n");

}




void writeGameData(char *filename,player *p1, player *p2){
    file = fopen(filename, "w");
    writeint(filename, n);
    writeint(filename, m);
    writeint(filename, flag);
    writeNames(filename, p1,p2);
    writeData(filename, p1,p2);
    writeCharArray(filename, A);
   // writeIntArray(filename, flagARR);
    fclose(file);

}



void readArray(const char *filename, int array[rows][cols]) {
int num;
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }
        while ( ( num = getw(file)) != EOF ) {
    printf(stderr,"%d\n", num);
  }

}



void readCharArray(const char *filename, int array[rows][cols]){
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
           fscanf(file, "%d\n", &array[i][j]);
           printf("%d ",array[i][j]);
        }
    }
}

void readString(const char *filename, char *buffer){

 if (fgets(buffer, sizeof(buffer), file) != NULL) {
        // Remove the newline character if present
        size_t length = strlen(buffer);
        if (length > 0 && buffer[length - 1] == '\n') {
            buffer[length - 1] = '\0';
        }

        printf("Read string: %s\n", buffer);
    } else {
        perror("Error reading string from file");
    }
}



int readInt(const char *filename, int x) {

    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
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





void loadGame(char *filename,player p1, player p2){


    file = fopen(filename, "r");
    n = readInt(filename,n);
    m = readInt(filename,m);
    rows = rows_c*n+rows_c+1;
    cols = cols_c*m+cols_c+1;
    allocateArrays();
    gameInit();
    flag = readInt(filename,flag);
    readString(filename, p1.name);
    readString(filename, p2.name);
    p1.moves = readInt(filename,p1.moves);
    p2.moves = readInt(filename,p2.moves);
    p1.score = readInt(filename,p1.score);
    p2.score = readInt(filename,p2.score);
    printf("MSHTARSH");
        for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fscanf(file, "%d", flagARR[i][j]);
        }
    }
    fclose(file);

  /*  //gameInit();
     system("cls");
    create_grid(A);
    print_grid(A,flagARR);
    print_data(p1,p2,match_begun,n*m);
    clock_t match_begun = clock();
   gameLoop();
    winnerCheck();
    Top10Save();*/

}


void save_Game(){
    char filename[MAX_FILENAME_LENGTH];
    char userString[MAX_STRING_LENGTH];
    printf("Enter Game name: \n");
    // Prompt the user for a string

    // Use fgets to read the entire line of input, including spaces
    scanf("%c", (char *) stdin);
    if (fgets(userString, sizeof(userString), stdin) != NULL) {
        // Remove the newline character if present
        size_t length = strlen(userString);
        if (length > 0 && userString[length - 1] == '\n') {
            userString[length - 1] = '\0';
        }
    } else {
        perror("Error reading input");
        return 1;
    }
    snprintf(filename, sizeof(filename), "%s.txt", userString);

writeGameData(filename,&p1, &p2);

}
