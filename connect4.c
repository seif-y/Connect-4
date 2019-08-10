/* ENGGEN131 C Project - 2018 */
/* Connect Four */

#include "connect4.h"

/*
Author: Seif Younes
*/


//Type move: represents a move made by the bot (i.e. side and row/column)
typedef struct
{
	//'side' represents the side of the board that the token will be placed from, and 'num'
	//represents the row/column number on that given side.
	char side;
	int num;
}Move;


//The DeleteCharacter function gets rid of the character at a certain index of a string
void DeleteCharacter(char word[], int index)
{
	//Loop through the string from the index of the character to be removed
	while (word[index] != '\0')
	{
		//Override the currentchar with the one that comes after it. At the end, the final char will
		//be replaced by '\0', which will decrease the length of the string
		word[index] = word[index + 1];
		index++;
	}
}

//The Sort function uses the insertion sort algorithm to sort an array of doubles
void SortArray(double array[], int length)
{
	int i, j;
	double temp;

	//Loop 'i' from the index of the second value to index of the final value
	for (i = 1; i < length; i++)
	{
		//Set 'j' to the index preceding 'i'
		j = i - 1;

		//While loop keeps swapping the current value with the preceding one until it is in the 
		//correct position, i.e. the preceding value is less than the current value. This effectively
		//places the value that was at array[j] in the correct position relative to all the values in
		//the array up to index i -1
		while ((array[j + 1] <= array[j]) && (j >= 0))
		{
			temp = array[j];
			array[j] = array[j + 1];
			array[j + 1] = temp;
			j--;
		}
	}
}

int SecondPlacePrize(int prize1, int prize2, int prize3)
{
	//For a given number, there are 2 scenarios where it can be the middle value. For example:
	//prize2 > prize1 > prize3 OR prize3 > prize1 > prize2 are the only cases where prize 1 is
	//the middle value. If both those statements are false, then prize1 cannot be the middle value.

	//If prize 1 is the middle value, return prize 1
	if (((prize2 >= prize1) && (prize1 >= prize3)) || ((prize3 >= prize1) && (prize1 >= prize2)))
	{
		return prize1;
	}
	//Else, if prize 2 is the middle value, return prize 2
	else if (((prize1 >= prize2) && (prize2 >= prize3)) || ((prize3 >= prize2) && (prize2 >= prize1)))
	{
		return prize2;
	}
	//If neither if statement turned out to be true, then prize3 is the middle value by default
	else
	{
		return prize3;
	}
}

int FourInARow(int values[], int length)
{
	//For loop going through the full array
	for (int i = 0; i < length-3; i++)
	{
		//If the current value is equal to the 3 values proceeding it, thats 4 in a row
		if ((values[i] == values[i + 1]) && (values[i] == values[i + 2]) && (values[i] == values[i + 3]))
		{
			//Return the index of the element that begins the 4 in a row
			return i;
		}
	}

	//If the for loop has completed without returning any indeces, then it doesn't contain 4 in a row
	return -1;
}

int BinaryToDecimal(int binary)
{
	int decimal = 0;
	int exp = 0;

	//Each iteration of this loop checks the final digit of 'binary' and adds the corresponding 
	//power of 2 if that digit is equal to 1. It then works backwards until it reaches the first
	//digit, and increases the value of 'exp' by 1 before moving onto the next digit
	while (binary > 0)
	{
		//If the last digit is 1, increase 'decimal' by 2^exp
		if (binary % 2 == 1)
		{
			//For loop to calculate 2^exp because c doesn't like exponents
			int power = 1;
			for (int i = 0; i < exp; i++)
			{
				power *= 2;
			}

			//Add 2^exp to 'decimal'
			decimal += power;
		}

		//Divide 'binary' by 10 to move onto the preceding digit
		binary = binary / 10;

		//Increment 'exp' by 1 so that it adds the correct power of 2 in the next iteration
		exp++;
	}

	return decimal;
	
}

double MedianAbility(double abilities[], int length)
{
	//Use SortArray function to sort the 'abilities' array in ascending order
	SortArray(abilities, length);

	//If the array has an odd amount of values, use the middle value. Otherwise, return the average
	//of the two middle values
	if (length % 2 == 1) { return abilities[length / 2]; }
	else { return (abilities[length / 2] + abilities[length / 2 - 1]) / 2; }

}

void RemoveSpaces(char *name)
{
	//Loop until the end of the array. When 2 consecutive spaces are found, it gets rid of the second
	//one. After the outer loop is completed, the 'name' array should have no redundant spaces
	int i = 0;
	while (name[i] != '\0')
	{
		if ((name[i] == ' ') && (name[i + 1] == ' '))
		{
			//Use DeleteCharacter function to remove the redundant space at i + 1
			DeleteCharacter(name, i + 1);
		}

		//Do not increment if there are still redundant spaces.
		if ((name[i] != ' ') || (name[i + 1] != ' ')) 
		{
			i++; 
		}
	}
}

void InitialiseBoard(int board[MAX_SIZE][MAX_SIZE], int size)
{
	//Creates a square of empty spaces (values of 0). The side length of the square is equal to the
	//'size' input.
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			board[i][j] = 0;
		}
	}

	// If size is even, place 4 fixed pieces in the middle
	if (size % 2 == 0)
	{
		board[size / 2][size / 2] = 3;
		board[size / 2][size / 2 - 1] = 3;
		board[size / 2 - 1][size / 2] = 3;
		board[size / 2 - 1][size / 2 - 1] = 3;
	}
	// If the size is odd, place one fixed piece in the middle
	else
	{
		board[size / 2][size / 2] = 3;
	}
}

void AddMoveToBoard(int board[MAX_SIZE][MAX_SIZE], int size, char side, int move, int player, int *lastRow, int *lastCol)
{
//Series of if statements to place the token depending on the side it is inserted from. Each if
//block contains a while loop that checks the next position for the token's movement. If that
//position is not an empty space (== 0) the while loop is broken and the token stays in its
//last position

int row, col;

//N: start from top, go down until obstructed
if ((side == 'N') && (board[0][move] == 0))
{
	row = 0;
	col = move;
	while ((board[row + 1][col] == 0) && (row != size - 1))
	{
		row++;
	}
}

//S: start on bottom, go up until obstructed
else if ((side == 'S') && (board[size - 1][move] == 0))
{
	row = size - 1;
	col = move;
	while ((board[row - 1][col] == 0) && (row != 0))
	{
		row--;
	}
}

//E: Start on right side, go left until obstructed
else if ((side == 'E') && (board[move][size - 1] == 0))
{
	row = move;
	col = size - 1;
	while ((board[row][col - 1] == 0) && (col != 0))
	{
		col--;
	}
}

//W: start on left side, go right until obstructed
else if ((side == 'W') && (board[move][0] == 0))
{
	row = move;
	col = 0;
	while ((board[row][col + 1] == 0) && (col != size - 1))
	{
		col++;
	}
}

//If the initial space for the token is obstructed, lastCol and lastRow are set to -1
else
{
	row = -1;
	col = -1;
}

//Set lastRow to row, and lastCol to col
*lastRow = row;
*lastCol = col;

//Place the token in the correct position
if (*lastRow != -1)
{
	board[*lastRow][*lastCol] = player;
}
}

int CheckGameOver(int board[MAX_SIZE][MAX_SIZE], int size, int player, int row, int col)
{
	int i, j;
	
	//Check horizontal line
	for (j = col - 3; j <= col; j++)
	{
		//Make sure the possible 4 points are within the confines of the board
		if ((j >= 0) && (j+3 < size))
		{
			//Check if the current point and the 3 points to its right create 4 in a row
			if ((board[row][j] == player) && (board[row][j + 1] == player) && (board[row][j + 2] == player) && (board[row][j + 3] == player))
			{
				return player;
			}
		}
	}

	//Check vertical line
	for (i = row - 3; i <= row; i++)
	{
		//Make sure the possible 4 points are within the confines of the board
		if ((i >= 0) && (i + 3 <= size))
		{
			//Check if the current point and the 3 points below it create 4 in a row
			if ((board[i][col] == player) && (board[i + 1][col] == player) && (board[i + 2][col] == player) && (board[i + 3][col] == player))
			{
				return player;
			}
		}
	}

	//Check diagonal line (top-left to bottom-right)
	for (j = col - 3; j <= col; j++)
	{
		//Set this value to the row corresponding to the column of the point on the diagonal line
		//i.e. if j = col - 1, i = row - 1
		i = row - (col - j);

		//Make sure the possible 4 points are within the confines of the board
		if ((i >= 0) && (j >= 0) && (i+3 < size) && (j+3 < size))
		{
			//Check if the current point and the 3 points below and to the right create 4 in a row
			if ((board[i][j] == player) && (board[i + 1][j + 1] == player) && (board[i + 2][j + 2] == player) && (board[i + 3][j + 3] == player))
			{
				return player;
			}
		}
	}

	//Check diagonal line (top-right to bottom-left)
	for (j = col - 3; j <= col; j++)
	{
		//Set this value to the row corresponding to the column of the point on the diagonal line
		//i.e. if j = col - 3, i = row + 3
		i = row + (col - j);

		//Make sure the possible 4 points are within the confines of the board
		if ((i-3 >= 0) && (j >= 0) && (i < size) && (j + 3 < size))
		{
			//Check if the current point and the 3 points above and to the right create 4 in a row
			if ((board[i][j] == player) && (board[i - 1][j + 1] == player) && (board[i - 2][j + 2] == player) && (board[i - 3][j + 3] == player))
			{
				return player;
			}
		}
	}

	//If the function has not already returned the winning player, then the game must go on, because this
	//is connect 4, the game of champions, and a winner must be decided.
	return 0;
}

void GetDisplayBoardString(int board[MAX_SIZE][MAX_SIZE], int size, char *boardString)
{
	int i;

	//Set the length of the board string to the correct value
	int length = (size + 4)*(size + 4) + (size + 4);
	boardString[length] = '\0';

	//FOR LOOP
	for (i = 0; i < size; i++)
	{
		//Place dashes in the corners
		if (i < 2)
		{
			//Top left
			boardString[i] = '-';
			boardString[size + 3 - i] = '-';

			//Top right
			boardString[size + 5 + i] = '-';
			boardString[2 * size + 8 - i] = '-';

			//Bottom right
			boardString[length - 2 - i] = '-';
			boardString[length - size - 7 - i] = '-';

			//Bottom left
			boardString[length - size - 4 - i] = '-';
			boardString[length - (2 * size) - 9 - i] = '-';

		}

		//Place '\n' at the end of each line
		boardString[size + 4 + i * (size + 5)] = '\n';
		boardString[size + 4 + (i + 4) * (size + 5)] = '\n';

		//Place 'N' and each column number on the top rows
		boardString[i + 2] = 'N';
		boardString[size + 7 + i] = (char) i + '0';

		//Place 'S' and column numbers on the bottom rows
		boardString[length - 4 - i] = 'S';
		boardString[length - size - 9 - i] = (char) (size - 1 - i) + '0';

		//Place 'W' and row numbers on leftmost columns
		boardString[(i + 2) * (size + 5)] = 'W';
		boardString[(i + 2) * (size + 5) + 1] = (char) i + '0';

		//Place 'E' and each row number on rightmost columns
		boardString[(i + 2) * (size + 5) + size + 3] = 'E';
		boardString[(i + 2) * (size + 5) + size + 2] = (char) i + '0';

		//Now that the outer area has been completed, place the board itself.
		for (int j = 0; j < size; j++)
		{
			//Place a period for empty spaces
			if (board[i][j] == 0)
			{
				boardString[(i + 2)*(size + 5) + 2 + j] = '.';
			}

			//Place an X for player 1
			else if (board[i][j] == 1)
			{
				boardString[(i + 2)*(size + 5) + 2 + j] = 'X';
			}

			//Place an O for player 2
			else if (board[i][j] == 2)
			{
				boardString[(i + 2)*(size + 5) + 2 + j] = 'O';
			}

			//Place a # for the barriers in the middle of the board.
			else
			{
				boardString[(i + 2)*(size + 5) + 2 + j] = '#';
			}
		}
	}
}

void GetMoveBot1(int board[MAX_SIZE][MAX_SIZE], int size, int player, char *side, int *move)
{
	//First step is to check for any winning moves. This code is similar to the code used in the
	//CheckGameOver function

	//The arrays 'rows' and 'cols' represent the row and column of each winning position that is
	//found. Whenever a winning position is found, its co-ordinates are added to the appropriate
	//array.
	int rows[96] = { 0 };
	int cols[96] = { 0 };
	int index = 0;
	int i, j;
	
	//Check for horizontal winning positions.
	//Start at board[0][0 -> 3], end at board[size-1][size-4 -> size-1]
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 3; j++)
		{
			//Check for positions where a winning position can be made. This can be one of the
			//following: [. X X X]  [X . X X]  [X X . X]  [ X X X .]

			//Check for [. X X X]
			if ((board[i][j] == 0) && (board[i][j + 1] == player) && (board[i][j + 2] == player) && (board[i][j + 3] == player))
			{
				rows[index] = i;
				cols[index] = j;
				index++;
			}

			//Check for [X . X X]
			if ((board[i][j] == player) && (board[i][j + 1] == 0) && (board[i][j + 2] == player) && (board[i][j + 3] == player))
			{
				rows[index] = i;
				cols[index] = j + 1;
				index++;
			}

			//Check for [X X . X]
			if ((board[i][j] == player) && (board[i][j + 1] == player) && (board[i][j + 2] == 0) && (board[i][j + 3] == player))
			{
				rows[index] = i;
				cols[index] = j + 2;
				index++;
			}

			//Check for [X X X .]
			if ((board[i][j] == player) && (board[i][j + 1] == player) && (board[i][j + 2] == player) && (board[i][j + 3] == 0))
			{
				rows[index] = i;
				cols[index] = j + 3;
				index++;
			}
		}
	}

	//Check for vertical winning positions
	//Start at board[0 -> 3][0], end at board[size-4 -> size-1][size-1]
	for (i = 0; i < size - 3; i++)
	{
		for (j = 0; j < size; j++)
		{
			//Check for positions where a winning position can be made. This can be one of the
			//following: [. X X X]  [X . X X]  [X X . X]  [ X X X .]

			//Check for [. X X X]
			if ((board[i][j] == 0) && (board[i + 1][j] == player) && (board[i + 2][j] == player) && (board[i + 3][j] == player))
			{
				rows[index] = i;
				cols[index] = j;
				index++;
			}

			//Check for [X . X X]
			if ((board[i][j] == player) && (board[i + 1][j] == 0) && (board[i + 2][j] == player) && (board[i + 3][j] == player))
			{
				rows[index] = i + 1;
				cols[index] = j;
				index++;
			}

			//Check for [X X . X]
			if ((board[i][j] == player) && (board[i + 1][j] == player) && (board[i + 2][j] == 0) && (board[i + 3][j] == player))
			{
				rows[index] = i + 2;
				cols[index] = j;
				index++;
			}

			//Check for [X X X .]
			if ((board[i][j] == player) && (board[i + 1][j] == player) && (board[i + 2][j] == player) && (board[i + 3][j] == 0))
			{
				rows[index] = i + 3;
				cols[index] = j;
				index++;
			}
		}
	}

	//Check for diagonal (top left to bottom right) winning positions
	//Start at board[0 -> 3][0 -> 3], end at board[size-4 -> size-1][size-4 -> size-1]
	for (i = 0; i < size - 3; i++)
	{
		for (j = 0; j < size - 3; j++)
		{
			//Check for positions where a winning position can be made. This can be one of the
			//following: [. X X X]  [X . X X]  [X X . X]  [ X X X .]

			//Check for [. X X X]
			if ((board[i][j] == 0) && (board[i + 1][j + 1] == player) && (board[i + 2][j + 2] == player) && (board[i + 3][j + 3] == player))
			{
				rows[index] = i;
				cols[index] = j;
				index++;
			}

			//Check for [X . X X]
			if ((board[i][j] == player) && (board[i + 1][j + 1] == 0) && (board[i + 2][j + 2] == player) && (board[i + 3][j + 3] == player))
			{
				rows[index] = i + 1;
				cols[index] = j + 1;
				index++;
			}

			//Check for [X X . X]
			if ((board[i][j] == player) && (board[i + 1][j + 1] == player) && (board[i + 2][j + 2] == 0) && (board[i + 3][j + 3] == player))
			{
				rows[index] = i + 2;
				cols[index] = j + 2;
				index++;
			}

			//Check for [X X X .]
			if ((board[i][j] == player) && (board[i + 1][j + 1] == player) && (board[i + 2][j + 2] == player) && (board[i + 3][j + 3] == 0))
			{
				rows[index] = i + 3;
				cols[index] = j + 3;
				index++;
			}
		}
	}

	//Check for diagonal (bottom left to top right) winning positions
	//Start at board[size-1 -> size-4][0 -> 3], end at board[3 -> 0][size-4 -> size-1]
	for (i = size - 1; i > 2; i--)
	{
		for (j = 0; j < size - 3; j++)
		{
			//Check for positions where a winning position can be made. This can be one of the
			//following: [. X X X]  [X . X X]  [X X . X]  [ X X X .]
			
			// Check for [. X X X]
			if ((board[i][j] == 0) && (board[i - 1][j + 1] == player) && (board[i - 2][j + 2] == player) && (board[i - 3][j + 3] == player))
			{
				rows[index] = i;
				cols[index] = j;
				index++;
			}

			// Check for [X . X X]
			if ((board[i][j] == player) && (board[i - 1][j + 1] == 0) && (board[i - 2][j + 2] == player) && (board[i - 3][j + 3] == player))
			{
				rows[index] = i - 1;
				cols[index] = j + 1;
				index++;
			}

			// Check for [X X . X]
			if ((board[i][j] == player) && (board[i - 1][j + 1] == player) && (board[i - 2][j + 2] == 0) && (board[i - 3][j + 3] == player))
			{
				rows[index] = i - 2;
				cols[index] = j + 2;
				index++;
			}

			// Check for [X X X .]
			if ((board[i][j] == player) && (board[i - 1][j + 1] == player) && (board[i - 2][j + 2] == player) && (board[i - 3][j + 3] == 0))
			{
				rows[index] = i - 3;
				cols[index] = j + 3;
				index++;
			}
		}
	}
	

	//By this point, the program should have made a list of spaces that could be winning positions
	//The next step is to find out where to place the token so that it reaches the winning position
	int MoveFound = 0;
	int x = 0;

	//For this loop, 'x' is the index of the current winning position. 'i' and 'j' are used to represent 
	//the row and column where the token would land if placed from a certain position.
	while ((x < index) && (!MoveFound))
	{
		//For each side, a while loop is used to determine where the token would end up if dropped
		//from that side. If the final position matches that of the winning position, then MoveFound
		//is set to true, and 'side' and 'move' are set to the corresponding values for that move.
		
		//Check north side
		i = 0;
		j = cols[x];
		if (board[i][j] == 0)
		{
			while ((board[i + 1][j] == 0) && (i < size))
			{
				i++;
			}
			if (i == rows[x])
			{
				MoveFound = 1;
				*move = cols[x];
				*side = 'N';
			}
		}

		//Check south side
		i = size - 1;
		j = cols[x];
		if (board[i][j] == 0)
		{
			while ((board[i - 1][j] == 0) && (i >= 0))
			{
				i--;
			}
			if (i == rows[x])
			{
				MoveFound = 1;
				*move = cols[x];
				*side = 'S';
			}
		}

		//Check east side
		i = rows[x];
		j = size - 1;
		if (board[i][j] == 0)
		{
			while ((board[i][j - 1] == 0) && (j >= 0))
			{
				j--;
			}
			if (j == cols[x])
			{
				MoveFound = 1;
				*move = rows[x];
				*side = 'E';
			}
		}

		//Check west side
		i = rows[x];
		j = 0;
		if (board[i][j] == 0)
		{
			while ((board[i][j + 1] == 0) && (j < size))
			{
				j++;
			}
			if (j == cols[x])
			{
				MoveFound = 1;
				*move = rows[x];
				*side = 'W';
			}
		}

		//Increment 'x'
		x++;
	}

	//By this point, if there was a winning move, the bot should have found it. If there is no winning
	//move, 'MoveFound' will still be 0. If this is the case, the bot should look for any open positions
	//and make a move in one of them.
	if (!MoveFound)
	{
		//Use 'Move' type tocreate an array of all the available moves that the bot could make 
		//(i.e. places where the entry point of the token would not be blocked)
		Move AvailableMoves[40];
		index = 0;

		//Check for available moves on North and South side by looping through all columns
		for (j = 0; j < size; j++)
		{
			//Check North side of the current column
			if (board[0][j] == 0)
			{
				AvailableMoves[index].num = j;
				AvailableMoves[index].side = 'N';
				index++;
			}
			
			//Check South side of the current column
			if (board[size - 1][j] == 0)
			{
				AvailableMoves[index].num = j;
				AvailableMoves[index].side = 'S';
				index++;
			}
		}

		//Check for available moves on East and West side by looping through all rows
		for (i = 0; i < size; i++)
		{
			//Check West side for current row
			if (board[i][0] == 0)
			{
				AvailableMoves[index].num = i;
				AvailableMoves[index].side = 'W';
				index++;
			}

			//Check East side for current row
			if (board[i][size - 1] == 0)
			{
				AvailableMoves[index].num = i;
				AvailableMoves[index].side = 'E';
				index++;
			}
		}

		//Now that all the available moves have been found, one of them is picked at random.
		x = rand() % index;
		*move = AvailableMoves[x].num;
		*side = AvailableMoves[x].side;
	}

	//Display the bot's move
	printf("Bot 1 has chosen: %c%d\n", *side, *move);

}

void GetMoveBot2(int board[MAX_SIZE][MAX_SIZE], int size, int player, char *side, int *move)
{
	//This Bot does the exact same thing as Bot 1. It calls the function for Bot 1 to make its move
	GetMoveBot1(board, size, player, side, move);
}
