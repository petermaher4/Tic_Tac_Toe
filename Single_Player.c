int Make_Move(int Arr[][3])//program algurithm
{
	int count=0;
	for(int i=0;i<3;i++)//moves counter
	{
		for(int j=0;j<3;j++)
		{
			if(Arr[i][j]!=-1)
				count++;
		}
	}
	if(count==1)//first move
	{
		int corners=Arr[0][0]*Arr[0][2]*Arr[2][0]*Arr[2][2];
		
		if(corners==0)
			return 5;
		else
			return 1;
	}
	else
	{
		int Row_Sum,
		    Row_Mult,
		    Col_Sum,
		    Col_Mult,
			
		    Dia1_Sum=Arr[0][0]+Arr[1][1]+Arr[2][2],
		    Dia1_Mult=Arr[0][0]*Arr[1][1]*Arr[2][2],
		    Dia2_Sum=Arr[0][2]+Arr[1][1]+Arr[2][0],
		    Dia2_Mult=Arr[0][2]*Arr[1][1]*Arr[2][0],
			
			LRow_Mult=Arr[2][0]*Arr[2][1]*Arr[2][2],
		    LCol_Mult=Arr[0][0]*Arr[1][0]*Arr[2][0],
			LRow_Sum=Arr[2][0]+Arr[2][1]+Arr[2][2],
			LCol_Sum=Arr[2][0]+Arr[2][1]+Arr[2][2],
			
			URow_Mult=Arr[0][0]*Arr[0][1]*Arr[0][2],
		    RCol_Mult=Arr[0][2]*Arr[1][2]*Arr[2][2],
			URow_Sum=Arr[0][0]+Arr[0][1]+Arr[0][2],
			RCol_Sum=Arr[0][2]+Arr[1][2]+Arr[2][2];
			
		/****************************Win_check**********************/
		
		for(int i=0;i<3;i++)
		{
			Row_Sum=Arr[i][0]+Arr[i][1]+Arr[i][2];
		    Row_Mult=Arr[i][0]*Arr[i][1]*Arr[i][2];
			
			if(Row_Sum==1)//Row check
			{
				for(int j=0;j<3;j++)
				{
					
					if(Arr[i][j]==-1)
					{
						int pos;
						pos=(i*3)+j+1;
						return pos;
					}
				}
			}
		}
		
		for(int i=0;i<3;i++)
		{
			Col_Sum=Arr[0][i]+Arr[1][i]+Arr[2][i];
		    Col_Mult=Arr[0][i]*Arr[1][i]*Arr[2][i];
			
			if(Col_Sum==1)//Col check
			{
				for(int j=0;j<3;j++)
				{
					
					if(Arr[j][i]==-1)
					{
						int pos;
						pos=(j*3)+i+1;
						return pos;
					}
				}
			}
		}
		
		if(Dia1_Sum==1)//diagonal 1 check
		{
			for(int j=0;j<3;j++)
			{
				
				if(Arr[j][j]==-1)
				{
					int pos;
					pos=(j*3)+j+1;
					return pos;
				}
			}
		}
		
		else if(Dia2_Sum==1)//diagonal 2 check 
		{
			if(Arr[0][2]==-1)
				return 3;
			else if(Arr[2][0]==-1)
				return 7;
		}
		/****************************Block_check**********************/
		for(int i=0;i<3;i++)
		{
			Row_Sum=Arr[i][0]+Arr[i][1]+Arr[i][2];
		    Row_Mult=Arr[i][0]*Arr[i][1]*Arr[i][2];
			
			if(Row_Sum==-1&&Row_Mult==0)// Row check
			{
				for(int j=0;j<3;j++)
				{
					
					if(Arr[i][j]==-1)
					{
						int pos;
						pos=(i*3)+j+1;
						return pos;
					}
				}
			}
		}
		
		for(int i=0;i<3;i++)
		{
			Col_Sum=Arr[0][i]+Arr[1][i]+Arr[2][i];
		    Col_Mult=Arr[0][i]*Arr[1][i]*Arr[2][i];
			
			if(Col_Sum==-1&&Col_Mult==0)//Col check
			{
				for(int j=0;j<3;j++)
				{
					
					if(Arr[j][i]==-1)
					{
						int pos;
						pos=(j*3)+i+1;
						return pos;
					}
				}
			}
		}
		
		if(Dia1_Sum==-1&&Dia1_Mult==0)//diagonal 1 check
		{
			for(int j=0;j<3;j++)
			{
				
				if(Arr[j][j]==-1)
				{
					int pos;
					pos=(j*3)+j+1;
					return pos;
				}
			}
		}
		
		else if(Dia2_Sum==-1&&Dia2_Mult==0)//diagonal 2 check
		{
			if(Arr[0][2]==-1)
				return 3;
			else if(Arr[2][0]==-1)
				return 7;
		}
		
		/****************************pretict**********************/
		
		if((LRow_Sum==-2&&LRow_Mult==0)&&(LCol_Sum==-2&&LCol_Mult==0))
		{
			for(int i=0;i<3;i++)
			{
				if(Arr[1][i]==-1)
				{
					int pos;
					pos=3+i+1;
					return pos;
				}
			}
		}
		else if((URow_Sum==-2&&URow_Mult==0)&&(RCol_Sum==-2&&RCol_Mult==0))
		{
			for(int i=0;i<3;i++)
			{
				if(Arr[1][i]==-1)
				{
					int pos;
					pos=3+i+1;
					return pos;
				}
			}
		}
		 
	}
	
	/********************************Random_play**********************/
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			
			if(Arr[i][j]==-1)
			{
				int pos;
				pos=(i*3)+j+1;
				return pos;
			}
				
		}
	}
}