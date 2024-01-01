FILE *file;

void printintArray(int **arr) {                 //print integer array to a file
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void printcharArray(char** arr) {                   //print character array to a file
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

void writeNames(const char *filename, player *p1, player *p2) {     //write player names to file
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
            fprintf(file, "%d\n", p1->moves);               //write player data to file
            fprintf(file, "%d\n", p2->moves);
            fprintf(file, "%d\n", p1->score);
            fprintf(file, "%d\n", p2->score);
}



//Collective Function to print all game states
void writeGameData(char *filename,player *p1, player *p2){
    file = fopen(filename, "w");
    fprintf(file,"%d\n",savenum);
    fprintf(file,"%d %d\n",seconds, minutes);
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



// Function to read integer from File
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




//Collective Function to the whole save game process
int save_Game(){

    char filename[30];
    char userString[MAX_STRING_LENGTH];
    printf("Enter Game name: \n");
    // Prompt the user for a string

    // Use fgets to read the entire line of input, including spaces
    //scanf("%c", (char *) stdin);
        if(savenum<3){
        char foldername[30];
        char name[MAX];
        getstr(userString);           //get game's name
        convertToLower(userString);     //convert to lowercase

            char stringValue[20];
            sprintf(stringValue, "%d", savenum);        //assign number of saves to a string to append in file names

        int check = mkdir(userString);
    if (!check)
        printf("Folder created\n");                 //check if folder is creater or already exists
    else {
        printf("Unable to create folder\n");
    }

    snprintf(filename, sizeof(filename), "%s/%s.txt", userString,stringValue); // conactenate the game folder path and the version number to file path

savenum++;                               // increas number of saved games
writeGameData(filename,&p1, &p2);       //write game data to the given file name prompted by the user
}
else {
    printf("You've reached maximum number of saves");
    sleep(1);
}
}




void readGameData(char *filename,player *p1, player *p2){
    file = fopen(filename, "r");
        if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);sleep(1);
        system("cls");
        main_menu(pn,pm,pmode,p1,p2);  
 }
    savenum = readInt(filename,savenum);
    seconds = readInt(filename,seconds);
    minutes = readInt(filename,minutes);
    n = readInt(filename,n);
    m = readInt(filename,m);
    rows = rows_c*n+rows_c+1;
    cols = cols_c*m+cols_c+1;
    printf("success\n");sleep(1);
    allocateArrays();
    flag = readInt(filename,flag);
    mode = readInt(filename,mode);   printf("success");sleep(1);

 fgets(p1->name, sizeof(p1->name), file);
        printf("Read from file: %s", p1->name);

 fgets(p2->name, sizeof(p2->name), file);
        printf("Read from file: %s", p2->name);

    printf("success\n");sleep(1);
    p1->moves = readInt(filename,p1->moves);
    p2->moves = readInt(filename,p2->moves);
    p1->score = readInt(filename,p1->score);
    p2->score = readInt(filename,p2->score);
    printf("success\n");sleep(1);

    sleep(1);
    printf("TARSH");
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

void loadGame(){
 char gamename[30];
 char filename[30];

 int version;

printf("Enter Game Name: "); getstr(gamename);
convertToLower(gamename);
printf("\nEnter Game version: ");scanf("%d",&version);
            char versionchar[20];
                sprintf(versionchar, "%d", version);

snprintf(filename, sizeof(filename), "%s/%s.txt", gamename,versionchar);
printf("%s",filename);sleep(2);
readGameData(filename,&p1,&p2);


}