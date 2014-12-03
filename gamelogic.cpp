//gamelogic.cpp

extern static int  guesses[5][4];
extern static int  answer[4];
extern static int  shapeScore[5];
extern static int  correctScore[5];
extern static int  currguess;

void scoreupdate(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (guesses[currguess][i] == answer[i])
		{
			correctScore[currguess] += 1;
		}
	}
   int colorarray[4];
   colorarray[0]=0;
   colorarray[1]=0;
   colorarray[2]=0;
   colorarray[3]=0;
   
   int colorarrayguess[4];
   colorarrayguess[0]=0;
   colorarrayguess[1]=0;
   colorarrayguess[2]=0;
   colorarrayguess[3]=0;
   for (int k = 0; k < 4; k++)
   {
      colorarray[answer[k]] += 1;
   }
   
   for (int u = 0; u < 4; u++)
   {
      colorarrayguess[guesses[currguess][k]] += 1;
   }
   
   for (int m = 0; m < 4; m++)
   {
      if(colorarray[m] <= colorarrayguess[guesses[currguess][m]]) {
         shapeScore[currguess]+=colorarray[m];
      } else {
         shapeScore[currguess]+=colorarrayguess[m];
      }
   }
}