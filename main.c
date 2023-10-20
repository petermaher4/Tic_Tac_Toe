#include <stdio.h>
#include <stdlib.h>
#include "Check_Condition.h"
#include "Single_Player.h"

int main()
{
	int Mode=0;
	int Player=0;
	int Next_Position;
	int Arr[3][3]={{-1,-1,-1},{-1,-1,-1},{-1,-1,-1}};
	
	printf("please select mode \nSingle player -> 1\nMulti players -> 2\nnote: to Exit the game at any time enter 0\n");
	scanf("%d",&Mode);
	
	while (Mode!=1&&Mode!=2)//check validation of mode input
	{
		printf("Wrong Mode Input\t");
		scanf("%d",&Mode);
	}
	
	while(Mode==2)//start game multi
	{
		system("cls");
		Display(Arr);
		
		printf("player %d's turn\t",Player+1);
		scanf("%d",&Next_Position);
		
		if(Next_Position!=0)// check Exit Condition if 0 was entered the game will exit
		{
			while(Next_Position<1||Next_Position>9||*(*(Arr)+Next_Position-1)!=-1)//position validation
			{
				printf("Wrong position Input\t");
				scanf("%d",&Next_Position);
			}
		}
		else 
			break; //Exit
		
		*(*(Arr)+Next_Position-1)=Player;
		
		
		if(Winner(Arr))//check if anyone won
		{
			char again;
			Display(Arr);
			printf("player %d is winner\n",Winner(Arr));
			
			printf("do you want to play again ?	y or n:	");
			scanf(" %c",&again);
			while(again!='y'&&again!='n')
			{
				printf("Wrong Input\t");
				scanf(" %c",&again);
			}
			if(again=='n')//exit game
				break;
			else if(again=='y')//reset Array
			{
				for(int i=0;i<3;i++)
				{
					for(int j=0;j<3;j++)
						Arr[i][j]=-1;
				}
				Player=1;
			}
		}
		else if(Is_Draw(Arr))//check if nobody won and last move was done
		{
			char again;
			Display(Arr);
			printf("the game is draw\n");
			
			printf("do you want to play again ?	y or n:	");
			scanf(" %c",&again);
			while(again!='y'&&again!='n')
			{
				printf("Wrong Input\t");
				scanf(" %c",&again);
			}
			if(again=='n')
				break;
			else if(again=='y')
			{
				for(int i=0;i<3;i++)
				{
					for(int j=0;j<3;j++)
						Arr[i][j]=-1;
				}
				Player=1;
			}
		}
		if(Player==0)//switch player
			Player=1;
		else
			Player=0;
		
	}
	
	while(Mode==1)//game start Single mode
	{
		system("cls");
		Display(Arr);
		
		if(Player==0)//player
		{
			printf("player %d's turn\t",Player+1);
			scanf("%d",&Next_Position);
			
			if(Next_Position!=0)// check Exit Condition
			{
				while(Next_Position<1||Next_Position>9||*(*(Arr)+Next_Position-1)!=-1)
				{
					printf("Wrong position Input\t");
					scanf("%d",&Next_Position);
				}
			}
			else 
				break;
			
			*(*(Arr)+Next_Position-1)=Player;	
		}
		else if(Player==1)//program
		{
			Next_Position=Make_Move(Arr);
			*(*(Arr)+Next_Position-1)=Player;
		}
		
		if(Winner(Arr))//check if any one won
		{
			char again;
			Display(Arr);
			if(Winner(Arr)==1)//case player  won
			printf("YOU WIN\n");
			if(Winner(Arr)==2)//case program won
			printf("YOU LOSE\n");
			
			printf("do you want to play again ?	y or n:	");
			scanf(" %c",&again);
			while(again!='y'&&again!='n')
			{
				printf("Wrong Input\t");
				scanf(" %c",&again);
			}
			if(again=='n')//Exit game
				break;
			else if(again=='y')//play again
			{
				for(int i=0;i<3;i++)//reset Array to inital
				{
					for(int j=0;j<3;j++)
						Arr[i][j]=-1;
				}
				Player=1;
			}
		}
		else if(Is_Draw(Arr))//check if nobody won and last move was done
		{
			char again;
			Display(Arr);
			printf("the game is draw\n");
			
			printf("do you want to play again ?	y or n:	");
			scanf(" %c",&again);
			
			while(again!='y'&&again!='n')
			{
				printf("Wrong Input\t");
				scanf(" %c",&again);
			}
			if(again=='n')//Exit game
				break;
			else if(again=='y')//play again
			{
				for(int i=0;i<3;i++)//reset Array
				{
					for(int j=0;j<3;j++)
						Arr[i][j]=-1;
				}
				Player=1;
			}
		}
		if(Player==0)//switch player
			Player=1;
		else
			Player=0;
	}
	
	
}