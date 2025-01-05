#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

/*
char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = '0';

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

int main(){

	char winner = ' ';

	resetBoard();
	while (winner == ' ' && checkFreeSpaces()!=0) {
		printBoard();
		playerMove();
		computerMove();
		winner = checkWinner();
		if (winner != ' ' || checkFreeSpaces() == 0)
		{
			break;
		}
	}

	printBoard();
	printWinner(winner);

	return 0;
}

void resetBoard()
{
	for(int i = 0; i<3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = ' ';
		}
	
	}

}
void printBoard()
{
	printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
	printf("\n---|---|---\n");
	printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
	printf("\n---|---|---\n");
	printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
	printf("\n");
}
int checkFreeSpaces()
{
	int freeSpaces = 9;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] != ' ')
			{
				freeSpaces--;
			}
		}
	}
	return freeSpaces;
}
void playerMove()
{
	int x;
	int y;
	do
	{
		printf("Enter row #(1-3): ");
		scanf_s("%d", &x);
		x--;
		printf("Enter column #(1-3): ");
		scanf_s("%d", &y);
		y--;

		if (board[x][y] != ' ')
		{
			printf("INVALID MOVE\n");
		}
		else
		{
			board[x][y] = PLAYER;
			break;
		}
	} while (board[x][y] != ' ');
}

void computerMove()
{
    if (checkFreeSpaces() > 0)
    {
        int x, y;
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');
        board[x][y] = COMPUTER;
    }
    else
    {
        printf("It's a draw!\n");
    }
}

char checkWinner()
{
    char winner = ' ';
    for (int i = 0;i < 3; i++)
    {
        //check rows
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
        {
            winner = board[i][0];
        }
        //check columns
        else if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ')
        {
            winner = board[0][i];
        }
    }
    //check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')
    {
        winner = board[0][0];
    }
    //check other diagonal
    else if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ')
    {
        winner = board[0][2];
    }
    return winner;
}
void printWinner(char winner)
{
	if (winner == PLAYER)
	{
		printf("YOU WIN");
	}
	else if (winner == COMPUTER)
	{
		printf("YOU LOSE!");	
	}
	else
	{
		printf("IT'S A DRAW");
	}
}
*/
