#include<stdio.h>
#include<math.h>

int isPracticable(int queeArr[]);
void showQueens(int queenArr[],int num);
void enumQueenPosition(int queenArr[]);

int count =0;
int main()
{
	int queenArr[8]; //every number means the location of a queen.
	                 //for example,queenArr[0]=4 means the first line's queen is in the fourth grid.
    enumQueenPosition(queenArr);
	printf("the number of solutions: %d",count);
	putchar('\n');
	getch();

	return 0;
}


int isPracticable(int queenArr[])
{
	int i,j;
	
	for(i=0;i<8;i++)
		for(j=i+1;j<8;j++)
		{
			if(queenArr[i]==queenArr[j])  //two queens in the same line.
				return 0;
			if(abs(queenArr[i]-queenArr[j])==abs(i-j))
				return 0;
		}
	
    return 1;
}
				

void showQueens(int queenArr[],int sol)
{
	int i,j;
    
	printf("......................Solution %d.......................\n",sol);
	for(i=0;i<8;i++)
	{
		for(j=1;j<queenArr[i];j++)
			printf("*");     // print " " in the grids before the queen in the i row. 
		printf("Q");    // the queen.
        for(;j<8;j++)
			printf("*");     // print " " in the grids after the queen.
		putchar('\n');
	}
}

void enumQueenPosition(int queenArr[])
{
	for(queenArr[0]=1;queenArr[0]<=8;queenArr[0]++)      // all the conditions.
		for(queenArr[1]=1;queenArr[1]<=8;queenArr[1]++)
			for(queenArr[2]=1;queenArr[2]<=8;queenArr[2]++)
				for(queenArr[3]=1;queenArr[3]<=8;queenArr[3]++)
					for(queenArr[4]=1;queenArr[4]<=8;queenArr[4]++)
						for(queenArr[5]=1;queenArr[5]<=8;queenArr[5]++)
							for(queenArr[6]=1;queenArr[6]<=8;queenArr[6]++)
								for(queenArr[7]=1;queenArr[7]<=8;queenArr[7]++)
								{
									if(isPracticable(queenArr)==1)  // if the condition is practicable, show it.
									{
										count++;
										showQueens(queenArr,count); 
										getch();
									}
									else
										continue;
								}
}

