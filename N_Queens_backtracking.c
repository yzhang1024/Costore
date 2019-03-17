#include<stdio.h>
#include<math.h>
#define QUEENS_COUNT 8  //adjust the number of the queens you want.

void showQueens(int queenArr[],int sol);
int isClash(int queenArr[],int row);
void putQueen(int queenArr[],int row);



int count=0;  //record the amount of solutions.

int main()
{
	int queenArr[QUEENS_COUNT];

	putQueen(queenArr,0);
  
	return 0;
}
   

void showQueens(int queenArr[],int sol)
{
	int i,j;
    
	printf("......................Solution %d.......................\n",sol);
	for(i=0;i<QUEENS_COUNT;i++)
	{
		for(j=1;j<queenArr[i];j++)
			printf("*");     // print "*" in the grids before the queen in the i row. 
		printf("Q");    
        for(;j<QUEENS_COUNT;j++)
			printf("*");     // print "*" in the grids after the queen.
		putchar('\n');
	}
}

int isClash(int queenArr[],int row)
{   
	int i;
	
	for(i=0;i<row;i++)
	{
		if(queenArr[i]==queenArr[row])  // two queens in the same line.
			return 1;
		if(abs(queenArr[row]-queenArr[i])==abs(row-i))
			return 1;
	}
	return 0;
}

void putQueen(int queenArr[],int row)
{
	int i;

	for(i=1;i<=QUEENS_COUNT;i++)
	{
		queenArr[row]=i;  // put the queen in the line.
        if(isClash(queenArr,row)!=1)
		{      // no clash.
			if(row==QUEENS_COUNT-1)
			{  // all the rows have been testified.
				count++;
				showQueens(queenArr,count);
			}
			else
				putQueen(queenArr,row+1);
		}
	}
}