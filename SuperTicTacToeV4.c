#include <stdio.h>
#include <stdlib.h>


const char PLAYER1 = 'X';
const char PLAYER2 = 'O';

char games[9][3][3]; // Array to store all sub-games

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove(int currentSubGame, char player, int* lastMoveX, int* lastMoveY);
void printWinner(char winner);
//char checkWinner();
int getNextSubGame(int x, int y);
char checkSmallBoardWinner(char board[3][3]);
int isBoardPlayable(int subGame);

int main() {
    printf("Each turn, you mark one of the small squares. When you get three in a row on a small board, you have won that board\nTo win the game, you need to win three small boards in a row.\n");
    printf("You don not get to pick which of the nine boards to play on.That is determined by your opponents previous move\nWhichever square he picks, that is the board you must play in next. (And whichever square you pick will determine which board he plays on next.)\n");
    printf("\n FAQS \n");
    printf("\n1, What if my opponent sends me to a board that is already been won?\n\tIn that case, congratulations, you get to go anywhere you like, on any of the other boards.\n\t(This means you should avoid sending your opponent to an already - won board!)\n");
    printf("2, What if one of the small boards results in a tie ? I recommend that the board counts for neither X nor O.\n\tBut, if you feel like a crazy variant, you could agree before the game to count a tied board for both X and O.");
    printf("\n\n\n");

    char winner = ' '; // No winner yet
    int currentSubGame = -1; // Initially, no specific sub-game is enforced
    int lastMoveX = -1, lastMoveY = -1; // Track the last move within a sub-game
    resetBoard(); // Initialize all boards to empty
    printBoard();

    // Game loop
    while (winner == ' ' && checkFreeSpaces() > 0) {
        // Player X's turn
        if (currentSubGame == -1) {
            // Allow Player X to choose the first sub-game freely
            do {
                printf("Player X, choose the starting sub-game (1-9): ");
                scanf_s("%d", &currentSubGame);
                currentSubGame -= 1; // Adjust to 0-based indexing
                if (currentSubGame < 0 || currentSubGame >= 9) {
                    printf("Invalid choice. Try again.\n");
                }
            } while (currentSubGame < 0 || currentSubGame >= 9);
        }

        printf("\nPlayer X's turn in sub-game %d\n", currentSubGame + 1);
        playerMove(currentSubGame, PLAYER1, &lastMoveX, &lastMoveY);
        printBoard();

        // Check if sub-game is won
        char subGameWinner = checkSmallBoardWinner(games[currentSubGame]);
        if (subGameWinner != ' ') {
            printf("Player %c wins sub-game %d!\n", subGameWinner, currentSubGame + 1);
        }

        // Determine the next sub-game based on Player X's move
        currentSubGame = getNextSubGame(lastMoveX, lastMoveY);

        // Handle full or won boards
        if (!isBoardPlayable(currentSubGame)) {
            printf("The next sub-game is unavailable. Choose any other playable sub-game.\n");
            do {
                printf("Choose a playable sub-game (1-9): ");
                scanf_s("%d", &currentSubGame);
                currentSubGame -= 1; // Adjust to 0-based indexing
            } while (!isBoardPlayable(currentSubGame));
        }

        // Player O's turn
        printf("\nPlayer O's turn in sub-game %d\n", currentSubGame + 1);
        playerMove(currentSubGame, PLAYER2, &lastMoveX, &lastMoveY);
        printBoard();

        // Check if sub-game is won
        subGameWinner = checkSmallBoardWinner(games[currentSubGame]);
        if (subGameWinner != ' ') {
            printf("Player %c wins sub-game %d!\n", subGameWinner, currentSubGame + 1);
        }

        // Determine the next sub-game based on Player O's move
        currentSubGame = getNextSubGame(lastMoveX, lastMoveY);

        // Handle full or won boards
        if (!isBoardPlayable(currentSubGame)) {
            printf("The next sub-game is unavailable. Choose any other playable sub-game.\n");
            do {
                printf("Choose a playable sub-game (1-9): ");
                scanf_s("%d", &currentSubGame);
                currentSubGame -= 1; // Adjust to 0-based indexing
            } while (!isBoardPlayable(currentSubGame));
        }
    }

    // Print the final result
    printBoard();
    printWinner(winner);

    return 0;
}

void resetBoard() {
    for (int g = 0; g < 9; g++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                games[g][i][j] = ' '; // Initialize all cells to empty
            }
        }
    }
}

int checkFreeSpaces() {
    int freeSpaces = 0;
    for (int g = 0; g < 9; g++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (games[g][i][j] == ' ') {
                    freeSpaces++;
                }
            }
        }
    }
    return freeSpaces;
}

void printBoard()
{
	 printf(" %c | %c | %c   ||", games[0][0][0], games[0][0][1], games[0][0][2]); printf("\t  %c | %c | %c   ||", games[1][0][0], games[1][0][1], games[1][0][2]); printf("   %c | %c | %c ", games[2][0][0], games[2][0][1], games[2][0][2]);
     printf("\n---|---|---  ||  ---|---|---  ||  ---|---|---\n");
	 printf(" %c | %c | %c   ||", games[0][1][0], games[0][1][1], games[0][1][2]); printf("\t  %c | %c | %c   ||", games[1][1][0], games[1][1][1], games[1][1][2]); printf("   % c | % c | % c ", games[2][1][0], games[2][1][1], games[2][1][2]);
     printf("\n---|---|---  ||  ---|---|---  ||  ---|---|---\n");
	 printf(" %c | %c | %c   ||", games[0][2][0], games[0][2][1], games[0][2][2]); printf("\t  %c | %c | %c   ||", games[1][2][0], games[1][2][1], games[1][2][2]); printf("   %c | %c | %c ", games[2][2][0], games[2][2][1], games[2][2][2]);
    
     printf("\n===========================================\n");
	 printf(" %c | %c | %c   ||", games[3][0][0], games[3][0][1], games[3][0][2]); printf("\t  %c | %c | %c   ||", games[4][0][0], games[4][0][1], games[4][0][2]); printf("   %c | %c | %c ", games[5][0][0], games[5][0][1], games[5][0][2]);
     printf("\n---|---|---  ||  ---|---|---  ||  ---|---|---\n");
	 printf(" %c | %c | %c   ||", games[3][1][0], games[3][1][1], games[3][1][2]); printf("\t  %c | %c | %c   ||", games[4][1][0], games[4][1][1], games[4][1][2]); printf("   %c | %c | %c ", games[5][1][0], games[5][1][1], games[5][1][2]);
     printf("\n---|---|---  ||  ---|---|---  ||  ---|---|---\n");
	 printf(" %c | %c | %c   ||", games[3][2][0], games[3][2][1], games[3][2][2]); printf("\t  %c | %c | %c   ||", games[4][2][0], games[4][2][1], games[4][2][2]); printf("   %c | %c | %c ", games[5][2][0], games[5][2][1], games[5][2][2]);
     printf("\n");
     printf("===========================================\n");
	 printf(" %c | %c | %c   ||", games[6][0][0], games[6][0][1], games[6][0][2]); printf("\t  %c | %c | %c   ||", games[7][0][0], games[7][0][1], games[7][0][2]); printf("   %c | %c | %c ", games[8][0][0], games[8][0][1], games[8][0][2]);
     printf("\n---|---|---  ||  ---|---|---  ||  ---|---|---\n");
	 printf(" %c | %c | %c   ||", games[6][1][0], games[6][1][1], games[6][1][2]); printf("\t  %c | %c | %c   ||", games[7][1][0], games[7][1][1], games[7][1][2]); printf("   %c | %c | %c ", games[8][1][0], games[8][1][1], games[8][1][2]);
     printf("\n---|---|---  ||  ---|---|---  ||  ---|---|---\n");
	 printf(" %c | %c | %c   ||", games[6][2][0], games[6][2][1], games[6][2][2]); printf("\t  %c | %c | %c   ||", games[7][2][0], games[7][2][1], games[7][2][2]); printf("   %c | %c | %c ", games[8][2][0], games[8][2][1], games[8][2][2]);
	 printf("\n\n");
}

int getNextSubGame(int x, int y) {
    return x * 3 + y; 
    // ( row * 3 ) + col 
}

char checkSmallBoardWinner(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        // Check rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0];
        }
        // Check columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return board[0][i];
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2];
    }
    return ' '; // No winner yet
}

int isBoardPlayable(int subGame) {
    if (checkSmallBoardWinner(games[subGame]) != ' ') {
        return 0; // Board is won
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (games[subGame][i][j] == ' ') {
                return 1; // Board has empty spaces
            }
        }
    }
    return 0; // Board is full
}

void playerMove(int currentSubGame, char player, int* lastMoveX, int* lastMoveY) {
    int x, y;
    do {
        printf("Enter row #(1-3): ");
        scanf_s("%d", &x);
        x--;   //adjusts input for 0-based indexing
        printf("Enter column #(1-3): ");
        scanf_s("%d", &y);
        y--; //adjusts input for 0-based indexing
        if (x < 0 || x >= 3 || y < 0 || y >= 3 || games[currentSubGame][x][y] != ' ') {
            printf("Invalid move. Try again.\n");
        }
        else {
            games[currentSubGame][x][y] = player;
            *lastMoveX = x;
            *lastMoveY = y;
            break;
        }
    } while (1);
}

void printWinner(char winner) {
    if (winner == PLAYER1) {
        printf("Player X wins the game!\n");
    }
    else if (winner == PLAYER2) {
        printf("Player O wins the game!\n");
    }
    else {
        printf("It's a draw!\n");
    }
}
//char checkWinner()
//{
//    char winner = ' ';
//    for (int i = 0;i < 3; i++)
//    {
//        //check rows
//        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
//        {
//            winner = board[i][0];
//        }
//        //check columns
//        else if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ')
//        {
//            winner = board[0][i];
//        }
//    }
//    //check diagonals
//    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')
//    {
//        winner = board[0][0];
//    }
//    //check other diagonal
//    else if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ')
//    {
//        winner = board[0][2];
//    }
//    return winner;
//}
//
//char checkWinner()
//{
//    char winner = ' ';
//
//
//
//
//}
