FILE *file;
char read_el[30];
char readz[30];

#define MAX_FILENAME_LENGTH 100
#define MAX_STRING_LENGTH 50

void writeArray(const char *filename, int array[rows][cols]) {
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




void saveGame(char *filename, int array[rows][cols], int arr2[rows][cols],player *p1, player *p2){
    file = fopen(filename, "w");

    writeint(filename, n);
    writeint(filename, m);
    writeint(filename, flag);
    writeNames(filename, p1,p2);
    writeData(filename, p1,p2);
    writeArray(filename, array);
    writeArray(filename, arr2);



    fclose(file);

}



void readArray(const char *filename, int array[rows][cols]) {

    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
           fscanf(file, "%d\n", &array[i][j]);
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

/*void assignStringToStruct(player *p, const char *inputString) {
    // Allocate memory for the string in the struct
    p->name = strdup(inputString);

    if (p->name == NULL) {
        perror("Error allocating memory for string");
        return 0;    }
}
*/

void readInt(const char *filename) {

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
    printf("%d\n",x);
    }





void loadGame(char *filename, int array[rows][cols], int arr2[rows][cols],player *p1, player *p2,int x){
    file = fopen(filename, "r");
    readArray(filename, array);
    readArray(filename, arr2);
    readString(filename, read_el);
    readString(filename, readz);

    readInt(filename);
    readInt(filename);
    readInt(filename);



    fclose(file);


    //assignStringToStruct(p1, read_el);
    //assignStringToStruct(p2, readz);
}


void askUserForString(){
    char filename[MAX_FILENAME_LENGTH];
    char userString[MAX_STRING_LENGTH];
    printf("Enter a string: \n");
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

saveGame(filename, A, flagARR ,&p1, &p2);

}
