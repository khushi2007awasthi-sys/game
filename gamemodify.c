#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char choice;

    do {
        srand((unsigned)time(0));

        int x = 1;                      // player lane: 0,1,2
        int step = 0;                   // obstacle vertical position
        int obstaclePos = rand() % 3;   // obstacle lane
        int score = 0;
        int lives = 3;

        while (1) {
            // ---- INPUT ----
            if (_kbhit()) {
                int ch = getch();
                if (ch == 0 || ch == 224) {
                    ch = getch(); // second code
                    if (ch == 75 && x > 0) x--;     // left arrow
                    else if (ch == 77 && x < 2) x++; // right arrow
                } else if (ch == 'a' || ch == 'A') {
                    if (x > 0) x--;   // A key for left
                } else if (ch == 'd' || ch == 'D') {
                    if (x < 2) x++;   // D key for right
                }
            }

            // ---- DRAW ----
            system("cls");
            printf("|--- --- ---|\n");

            for (int i = 0; i < 10; i++) {
                if (i == step) {
                    if (obstaclePos == 0)
                        printf("| c        |\n");   // obstacle 'c'
                    else if (obstaclePos == 1)
                        printf("|     c    |\n");
                    else
                        printf("|        c |\n");
                } else {
                    printf("|           |\n");
                }
            }

            // player 'p' at bottom row
            if (x == 0)
                printf("| p        |\n");
            else if (x == 1)
                printf("|     p    |\n");
            else
                printf("|        p |\n");

            // status
            printf("\nScore: %d   Lives: %d\n", score, lives);
            printf("Controls: Left/Right arrows or A/D\n");

            // ---- COLLISION ----
            if (step == 10 && x == obstaclePos) {
                lives--;
                if (lives == 0) {
                    printf("\nGAME OVER!\n");
                    break;
                } else {
                    printf("\nCollision! Lives left: %d\n", lives);
                    Sleep(800);
                    step = 0;
                    obstaclePos = rand() % 3;
                }
            }

            Sleep(120);
            step++;

            // reset obstacle when it passes bottom
            if (step > 10) {
                step = 0;
                obstaclePos = rand() % 3;
                score++;
            }
        }

        printf("\nFinal Score: %d\n", score);
        printf("Play again? (y/n): ");
        choice = getch();

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
