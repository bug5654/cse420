//gamelogic.cpp

extern int guesses[5][4];
extern int answer[4];
extern int shapeScore[5];
extern int correctScore[5];
extern int currguess;

void scoreupdate(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (guesses[currguess][i] == answer[i])
		{
			correctScore[currguess] += 1;
		}
	
		int colorarray[4];
		for (int k = 0; k < 4; k++)
		{
			colorarray[answer[k]] += 1;
		}
		for (int m = 0; m < 4; m++)
		{
			if (guesses[currguess][m] <= answer[m])
				shapeScore[currguess] += answer[m];
			if (guesses[currguess][m] >= answer[m])
				shapeScore[currguess] += answer[m];
		}
	}
}