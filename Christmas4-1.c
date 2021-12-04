#include <stdio.h>


void input_card();
int fill_and_check_winner();
int checkWins();
void printBoard();

int max = 0;

int main()
{
	int array[5][5];
	int array_fastest[5][5];
	//int checkNums[27] = {7,4,9,5,11,17,23,2,0,14,21,24,10,16,13,6,15,25,12,22,18,20,8,19,3,26,1};
 	int checkNums[100] = {6,69,28,50,36,84,49,13,48,90,1,33,71,0,94,59,53,58,60,96,30,34,29,91,11,41,77,95,17,80,85,93,7,9,74,89,18,25,26,8,87,38,68,5,12,43,27,46,62,73,16,55,22,4,65,76,54,52,83,10,21,67,15,47,45,40,35,66,79,51,75,39,64,24,37,72,3,44,82,32,78,63,57,2,86,31,19,92,14,97,20,56,88,81,70,61,42,99,23,98}; 
	int movestowin = 101;
	int movestowinOld = 101;
	int boardID = 0;
	int fastest_board = 0;
	int winner;
	
	for(int i = 0; i < 100; i++)
	{
		input_card(array);
		boardID += 1;
		movestowin = fill_and_check_winner(array,checkNums,movestowin);
		printf(" BOARDID : %d",boardID);
		if(movestowin < movestowinOld)
		{
			movestowinOld = movestowin;
			fastest_board = boardID;
			winner = max;
			for(int i2 = 0; i2 < 5; i2++)
			{
				for(int i3 = 0; i3 < 5; i3++)
				{
					array_fastest[i2][i3] = array[i2][i3];
				}
			}
		}
	}
	
	printf("%d\n",fastest_board);
	printBoard(array_fastest);
	
	int sum = 0;
	for(int i = 0; i < 5; i++)
	{
		for(int i2 = 0; i2 < 5; i2++)
		{
			if(array_fastest[i][i2] != -1)
			{
				sum += array_fastest[i][i2];
			}
		}
	}
	
	printf("Sum : %d Max : %d\n",sum,winner);
	sum = sum * winner;
	printf("%d",sum);
}

int fill_and_check_winner(int array[][5],int checkNums[],int currentMoves)
{
	int moves;
	int isWin;
	for(int i = 0; i < 100; i++)//for every number in the checkNums list
	{
		for(int i2 = 0; i2 < 5; i2++)//check in c i2
		{
			for(int i3 = 0; i3 < 5; i3++)//r i3
			{
				if(array[i2][i3] == checkNums[i])
				{
					array[i2][i3] = -1;
					moves += 1;
					isWin = checkWins(array,checkNums[i]);
					//max = array[i2][i3];
					
					if(isWin == 0)
					{
						//printf("\t\tWORKS!");
						//printBoard(array);
						max = checkNums[i];
						printf("The winning number: %d ", checkNums[i]);//the last number filled in
						printf("The number of moves: %d ",moves);
						return moves;
					}
				}
			}
		}
	}
	printBoard(array);
	return currentMoves;
}

int checkWins(int array[][5],int lastNum)
{
	int isFive = 0;
	for(int i = 0; i < 5; i++)
	{
		isFive = 0;
		for(int i2 = 0; i2 < 5; i2++)
		{
			if(array[i][i2] == -1)
			{
				isFive += 1;
			}
			if(isFive == 5)
			{
				//printf("WINNER!\n");
				//printf("\t\t\t\t%d",lastNum);
				return 0;
				
			}
		}
	}
	
	isFive = 0;
	for(int i3 = 0; i3 < 5; i3++)
	{
		isFive = 0;
		for(int i4 = 0; i4 < 5; i4++)
		{
			if(array[i4][i3] == -1)
			{
				isFive += 1;
			}
			if(isFive == 5)
			{
				return 0;
			}
		}
	}
	
	//printf("LOSER!\n");
	return -1;
}


void input_card(int array[][5])
{
	int userInput = 0;
	for(int i = 0; i < 5; i++)
	{
		for(int i2 = 0; i2 < 5; i2++)
		{
			scanf("%d",&userInput);
			array[i][i2] = userInput;
		}
			
	}
	
	
	
}

void printBoard(int array[][5])
{
	printf("\n\n");
	for(int i = 0; i < 5; i++)
	{
		printf("\n");
		for(int i2 = 0; i2 < 5; i2++)
		{
			printf("%d ",array[i][i2]);
		}
	} 
	printf("\n\n");
	
}