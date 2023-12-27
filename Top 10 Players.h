
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 50


void readTopScores(player topPlayers[MAX_NAME_LENGTH]);
void writeTopScores(player topPlayers[MAX_NAME_LENGTH]);
void updateTopScores(player topPlayers[MAX_NAME_LENGTH], const char *winnerName, int winnerScore);

//int main() {
    // Example usage:
    player topPlayers[MAX_PLAYERS];

    // Simulate a game result
    const char *winnerName;
    int winnerScore;

    // Read current top scores from file
  //  readTopScores(topPlayers);

    // Update top scores based on the latest game result
   // updateTopScores(topPlayers, winnerName, winnerScore);

    // Write the updated top scores to the file
  //  writeTopScores(topPlayers);

 //   return 0;
//}

void readTopScores(player topPlayers[MAX_PLAYERS]) {
    FILE *file = fopen("top_scores.txt", "r");

    if (file == NULL) {
        // File does not exist or cannot be opened, initialize scores to 0
        for (int i = 0; i < MAX_PLAYERS; ++i) {
            strcpy(topPlayers[i].name, "Unknown");
            topPlayers[i].score = 0;
        }
    } else {
        // Read top scores from file
        for (int i = 0; i < MAX_PLAYERS; ++i) {
            fscanf(file, "%s %d", topPlayers[i].name, &topPlayers[i].score);
        }

        fclose(file);
    }
}

void writeTopScores(player topPlayers[MAX_PLAYERS]) {
    FILE *file = fopen("top_scores.txt", "w");

    if (file == NULL) {
        fprintf(stderr, "Error opening file for writing.\n");
        exit(EXIT_FAILURE);
    }

    // Write top scores to file
    for (int i = 0; i < MAX_PLAYERS; ++i) {
        fprintf(file, "%s %d\n", topPlayers[i].name, topPlayers[i].score);
    }

    fclose(file);
}

void updateTopScores(player topPlayers[MAX_PLAYERS], const char *winnerName, int winnerScore) {
    // Check if the winner's score is higher than any of the current top scores
    for (int i = 0; i < MAX_PLAYERS; ++i) {
        if (winnerScore > topPlayers[i].score) {
            // Shift scores down to make room for the new high score
            for (int j = MAX_PLAYERS - 1; j > i; --j) {
                strcpy(topPlayers[j].name, topPlayers[j - 1].name);
                topPlayers[j].score = topPlayers[j - 1].score;
            }

            // Insert the new high score
            strcpy(topPlayers[i].name, winnerName);
            topPlayers[i].score = winnerScore;

            break; // Exit the loop after updating the scores
        }
    }
}

void display(){
    FILE *file = fopen("top_scores.txt", "r");

    // Check if the file was opened successfully
    if (file == NULL) {
        perror("Error opening file");
        return 1; // Return an error code
    }

    // Read and print each character from the file
    int character;
    printf(CYN"");
    while ((character = fgetc(file)) != EOF) {
        putchar(character);
    }

    // Close the file
    fclose(file);
}
