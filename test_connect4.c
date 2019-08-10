/* ENGGEN131 Project - C Project - 2018 */
/* Connect Four */
#include "connect4.h"

/*
This program is designed to let you TEST the functions you have written in connect4.c.
You can test one function at a time, or you can play a complete game of Connect Four,
in which case you will need to have completed all of the functions.  If you want to test
just one of your functions, you should write the appropriate test code in the
MyTestFunction() function.  Initially, this function contains all of the test code from
the project handout.
*/
void MyTestFunction(void);
void PlayConnectFour(void);

/*
This function is where you can write your own test code, to test the functions that you
have written in the connect.c source file.  Currently, this function contains all of the
examples from the project handout document.  You can make any changes to this function
that you like.
*/
void MyTestFunction(void)
{
	// An example of code that you could use to test Task One.
	// You should write additional tests of your own
	printf("\nTESTING TASK ONE:\n");
	printf("=================\n");
	printf("   Prize = %d\n", SecondPlacePrize(200, 100, 200));
	printf("   Prize = %d\n", SecondPlacePrize(45, 600, 590));

	// An example of code that you could use to test Task Two.
	// You should write additional tests of your own
	printf("\nTESTING TASK TWO:\n");
	printf("=================\n");
	int valuesA[10] = {1,2,1,2,1,1,1,1,2,1};
	int valuesB[15] = {1,2,1,2,1,1,1,2,2,1,1,4,4,4,4};
	int valuesC[15] = {5,6,7,8,8,8,8,8,8,8,8,8,8,8,8};
	int result;
	result = FourInARow(valuesA, 10);
	printf("   Result = %d\n", result);
	result = FourInARow(valuesB, 15);
	printf("   Result = %d\n", result);
	result = FourInARow(valuesC, 15);
	printf("   Result = %d\n", result);
	result = FourInARow(valuesC, 6);
	printf("   Result = %d\n", result);

	// An example of code that you could use to test Task Three.
	// You should write additional tests of your own
	printf("\nTESTING TASK THREE:\n");
	printf("===================\n");
	printf("   Decimal = %d\n", BinaryToDecimal(101));
	printf("   Decimal = %d\n", BinaryToDecimal(1));
	printf("   Decimal = %d\n", BinaryToDecimal(11111111));
	printf("   Decimal = %d\n", BinaryToDecimal(100000000));

	// An example of code that you could use to test Task Four.
	// You should write additional tests of your own
	printf("\nTESTING TASK FOUR:\n");
	printf("===================\n");
	double grpA[5]={4.3,2.1,6.7,5.0,1.2};
	double grpB[10]={4.3,2.1,6.7,5.0,1.2,9.9,7.0,3.0,6.6,6.5};
	double medianAbilityA, medianAbilityB;
	medianAbilityA = MedianAbility(grpA, 5);
	medianAbilityB = MedianAbility(grpB, 10);
	printf("   Median ability Group A = %.2f\n", medianAbilityA);
	printf("   Median ability Group B = %.2f\n", medianAbilityB);

	// An example of code that you could use to test Task Five.
	// You should write additional tests of your own
	printf("\nTESTING TASK FIVE:\n");
	printf("===================\n");
	char nameA[100] = "The       Champ";
	char nameB[100] = "     I    AM      THE     GREATEST    ";
	char nameC[100] = "Therearenospaceshereatall";
	RemoveSpaces(nameA);
	RemoveSpaces(nameB);
	RemoveSpaces(nameC);
	printf("   Name A = [%s]\n", nameA);
	printf("   Name B = [%s]\n", nameB);
	printf("   Name C = [%s]\n", nameC);

	// An example of code that you could use to test Task Six.
	// You should write additional tests of your own
	printf("\nTESTING TASK SIX:\n");
	printf("===================\n");
	int board6[MAX_SIZE][MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			board6[i][j] = -1;
		}
	}
	printf("   Board of size 8x8:\n");
	InitialiseBoard(board6, 8);
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("   ");
		for (int j = 0; j < MAX_SIZE; j++) {
			printf("%d ", board6[i][j]);
		}
		printf("\n");
	}
	printf("   Board of size 5x5:\n");
	InitialiseBoard(board6, 5);
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("   ");
		for (int j = 0; j < MAX_SIZE; j++) {
			printf("%d ", board6[i][j]);
		}
		printf("\n");
	}

	// An example of code that you could use to test Task Seven.
	// You should write additional tests of your own
	printf("\nTESTING TASK SEVEN:\n");
	printf("=====================\n");
	int board7[MAX_SIZE][MAX_SIZE];
	int rowPosition, colPosition;
	int size7 = 8;
	InitialiseBoard(board7, size7);
	AddMoveToBoard(board7, size7, 'N', 1, 1, &rowPosition, &colPosition);
	printf("   Token position: row=%d, col=%d\n", rowPosition, colPosition);
	AddMoveToBoard(board7, size7, 'E', 4, 2, &rowPosition, &colPosition);
	printf("   Token position: row=%d, col=%d\n", rowPosition, colPosition);
	AddMoveToBoard(board7, size7, 'S', 5, 1, &rowPosition, &colPosition);
	printf("   Token position: row=%d, col=%d\n", rowPosition, colPosition);
	for (int i = 0; i < size7; i++) {
		printf("   ");
		for (int j = 0; j < size7; j++) {
			printf("%d ", board7[i][j]);
		}
		printf("\n");
	}

	// An example of code that you could use to test Task Eight.
	// You should write additional tests of your own
	printf("\nTESTING TASK EIGHT:\n");
	printf("=====================\n");
	int board8[MAX_SIZE][MAX_SIZE];
	int rowPos, colPos;
	int size8 = 5;
	int hasWon;
	InitialiseBoard(board8, size8);
	AddMoveToBoard(board8, size8, 'N', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 1, 2, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 1, 2, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 1, 2, &rowPos, &colPos);
	for (int i = 0; i < size8; i++) {
		printf("   ");
		for (int j = 0; j < size8; j++) {
			printf("%d ", board8[i][j]);
		}
		printf("\n");
	}
	printf("   Checking for win for Player 2 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board8, size8, 2, rowPos, colPos);
	printf("   Result = %d\n", hasWon);
	AddMoveToBoard(board8, size8, 'N', 0, 1, &rowPos, &colPos);
	for (int i = 0; i < size8; i++) {
		printf("   ");
		for (int j = 0; j < size8; j++) {
			printf("%d ", board8[i][j]);
		}
		printf("\n");
	}
	printf("   Checking for win for Player 1 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board8, size8, 1, rowPos, colPos);
	printf("   Result = %d\n", hasWon);

	// An example of code that you could use to test Task Nine.
	// You should write additional tests of your own
	printf("\nTESTING TASK NINE:\n");
	printf("====================\n");
	int board9[MAX_SIZE][MAX_SIZE];
	int size9 = 4;
	char boardString[250];
	InitialiseBoard(board9, size9);
	GetDisplayBoardString(board9, size9, boardString);
	printf("   The length of the board string is: %d\n", strlen(boardString));
	printf("%s", boardString);
	size9 = 10;
	InitialiseBoard(board9, size9);
	GetDisplayBoardString(board9, size9, boardString);
	printf("   The length of the board string is: %d\n", strlen(boardString));
	printf("%s", boardString);

	// An example of code that you could use to test Task Ten.
	printf("\nTESTING TASK TEN:\n");
	printf("===================\n");
	printf("   You can test Task Ten by implementing the two Bot functions in connect.c.\n");
	printf("   If you then play a tournament, of many games, between the two bots, you \n");
	printf("   can see which one is performing the best.  This might help you to refine \n");
	printf("   the strategies that you are using. \n");

}

/*********************************************************************************/
/*
The main function for the test program.  The user is asked whether they want to test their
functions or play a game of connect four.  Based on the user's input, the appropriate function
is called.
*/
int main(void)
{
	int input;
	printf("ENGGEN131 Project - Semester Two - 2018\n");
	printf("                                 _      __                 \n");
	printf("                                | |    / _|                \n");
	printf("  ___ ___  _ __  _ __   ___  ___| |_  | |_ ___  _   _ _ __ \n");
	printf(" / __/ _ \\| '_ \\| '_ \\ / _ \\/ __| __| |  _/ _ \\| | | | '__|\n");
	printf("| (_| (_) | | | | | | |  __/ (__| |_  | || (_) | |_| | |   \n");
	printf(" \\___\\___/|_| |_|_| |_|\\___|\\___|\\__| |_| \\___/ \\__,_|_|   \n");
	printf("\nWould you like to:\n\n");
	printf("  0 = Test individual functions in connect.c\n");
	printf("      [you should write your own test code for this in MyTestFunction()]\n");
	printf("  1 = Play Connect Four\n");
	printf("      [this will only work if you to have completed all of the functions)]\n");
	printf("\nPlease enter your choice [0 or 1]:  ");
	scanf("%d", &input);
	if (input == 0) {
		MyTestFunction();
	} else {
		PlayConnectFour();
	}

	return 0;
}

/*********************************************************************************/
/*
This function is called when a human player is asked to enter their move.  The character
(representing the side of the board) and the digit (representing the row/column) are
returned via the pointers *side and *move.
*/
void GetMoveHuman(char *side, int *move, int player)
{
	char a = ' ';
	char b = ' ';
	printf("Player %d: enter move [side/position]: ", player);
	while (!(a == 'N' || a == 'W' || a == 'E' || a == 'S')) {
		scanf("%c", &a);
	}
	while (!(b >= '0' && b <= '9')) {
		scanf("%c", &b);
	}
	*side = a;
	*move = (int)(b - '0');
}

/*********************************************************************************/
/*
This function plays one game of Connect Four.  The starting player (either 1 or 2) is provided
as input.  This function returns the player who won the game.
*/
int PlayOneGame(int startingPlayer, int size, int gameType)
{
	int board[MAX_SIZE][MAX_SIZE];
	char displayBoardString[(MAX_SIZE+5)*(MAX_SIZE+5)];
	int player, gameOver, move, lastRow, lastCol;
	char side;

	player = startingPlayer;
	gameOver = 0;

	// Initialise the board, and display it if a human is involved in this game
	InitialiseBoard(board, size);
	if (gameType != 3) {
		GetDisplayBoardString(board, size, displayBoardString);
		printf("%s", displayBoardString);
	}

	// Play one move at a time, displaying the board if necessary, until the game is over
	while (!gameOver) {
		if (gameType == 1) {
			GetMoveHuman(&side, &move, player);
		} else if (gameType == 2) {
			if (player == 1) {
				GetMoveHuman(&side, &move, player);
			} else {
				GetMoveBot1(board, size, player, &side, &move);
			}
		} else {
			if (player == 1) {
				GetMoveBot1(board, size, player, &side, &move);
			} else {
				GetMoveBot2(board, size, player, &side, &move);
			}
		}
		AddMoveToBoard(board, size, side, move, player, &lastRow, &lastCol);
		gameOver = CheckGameOver(board, size, player, lastRow, lastCol);
		if (gameType != 3) {
			GetDisplayBoardString(board, size, displayBoardString);
			printf("%s", displayBoardString);
		}
		if (!gameOver) {
			player = 3 - player;
		}
	}
	return player;
}

/*********************************************************************************/
/*
This function plays Connect Four.  The user can choose the size of the board, who the
players will be (human or bot) and how many games will be played (if the bots are competing).
*/
void PlayConnectFour(void)
{
	int size, gameType, numberOfGames, result;
	int i, wins1, wins2, player;

	// Initialise the seed for the random number generator
	srand((unsigned int)time(NULL));

	// Prompt the user for the board size
	printf("\n\n==================");
	printf("\nEnter board size: ");
	scanf("%d", &size);

	// Get play options:
	printf("Options:\n");
	printf(" [1] = Human vs. Human\n");
	printf(" [2] = Human vs. Bot1\n");
	printf(" [3] = Bot1 vs. Bot2\n");
	printf("Choose game type: ");
	scanf("%d", &gameType);
	numberOfGames = 1;
	result = 0;
	// If two bots are playing a tournament, let the user choose how many games
	if (gameType == 3) {
		printf("Number of games: ");
		scanf("%d", &numberOfGames);
	}

	wins1 = 0;
	wins2 = 0;

	// Player 1 will always start the first game
	// If a tournament is played (between two bots), the starting player alternates
	player = 1;

	for (i = 0; i < numberOfGames; i++) {
		result = PlayOneGame(player, size, gameType);
		if (result == 1) {
			wins1++;
		} else {
			wins2++;
		}
		// Switch the starting player for the next game
		player = 3 - player;
	}

	// If a single game was played, show the result of the game, otherwise report the result of the tournament:
	if (numberOfGames == 1) {
		printf("\nGame over! Congratulations! Winner is Player %d\n\n", result);
	} else {
		printf("\nTournament over! Games played = %d\nPlayer 1 wins = %d / Player 2 wins = %d\n\n", numberOfGames, wins1, wins2);
	}
}
