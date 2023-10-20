#include <stdio.h>

int Is_Draw(int Arr[][3])//returns 1 if draw 0 if not
{
	int i,j;
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(Arr[i][j]==-1)
				return 0;
		}
	}
	return 1;
}

int Winner(int Arr[][3])//check for win and return winner number and returns 0 if not
{
	int i;
/************************* horizontal check *******************************/
	for(i=0;i<3;i++)
	{
		if(Arr[i][0]!=-1&&Arr[i][0]==Arr[i][1])
		{
			if(Arr[i][0]==Arr[i][2])
				return Arr[i][0]+1;
		}
	}
/************************** vertical check ******************************/

	for(i=0;i<3;i++)
	{
		if(Arr[0][i]!=-1&&Arr[0][i]==Arr[1][i])
		{
			if(Arr[0][i]==Arr[2][i])
				return Arr[0][i]+1;
		}
	}
/************************* diagonal check *******************************/

	if(Arr[0][0]!=-1&&Arr[0][0]==Arr[1][1])
		{
			if(Arr[0][0]==Arr[2][2])
				return Arr[0][0]+1;
		}
	if(Arr[0][2]!=-1&&Arr[0][2]==Arr[1][1])
		{
			if(Arr[0][2]==Arr[2][0])
				return Arr[0][2]+1;
		}
		
	return 0;
}


/*
_1_|_0_|_1_
_0_|_1_|_0_
 1 | 0 | 1 
 
  1 | 0 | 1 
 -----------
  0 | 1 | 0 
 -----------
  1 | 0 | 1 
  */
  
 void Display(int Arr[][3])
 {
	 char arr[3][3];
	 for(int i=0;i<3;i++)
	 {
		 for(int j=0;j<3;j++)
		 {
			 if(Arr[i][j]==-1)
				 arr[i][j]='_';
			 else if(Arr[i][j]==0)
				 arr[i][j]=79;
			 else if(Arr[i][j]==1)
				 arr[i][j]=88;
		 }
	 }
	 printf("\n_%c_|_%c_|_%c_\n",arr[0][0],arr[0][1],arr[0][2]);
	 printf("_%c_|_%c_|_%c_\n",arr[1][0],arr[1][1],arr[1][2]);
	 printf(" %c | %c | %c \n",arr[2][0],arr[2][1],arr[2][2]);
 }
