#include <iostream>
#include <math.h>

using namespace std;

int N;
int ***paper;

int four_is(int pnum, int x, int y);
int main()
{
	cin>>N;
	paper = new int**[(int)log2(N)+1];
	for(int i=(int)log2(N); i>=0; i--)
	{
		paper[i] = new int*[(int)pow(2,i)];
		for(int j=0; j<(int)pow(2,i); j++)
			paper[i][j] = new int[(int)pow(2,i)];
	}

	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			cin>>paper[(int)log2(N)][i][j];

	for(int i=(int)log2(N); i>0; i--)
	{
		for(int j=0; j<(int)pow(2,i); j+=2)
		{
			for(int k=0; k<(int)pow(2,i); k+=2)
			{
				paper[i-1][j/2][k/2] = four_is(i,j,k);
				//cout<<paper[i-1][j/2][k/2]<<" ";
			}
			//cout<<endl;
		}
	}
	int count_white = 0;
	int count_blue = 0;
	for(int i=(int)log2(N); i>=0; i--)
	{
		for(int j=0; j<(int)pow(2,i); j++)
		{
			for(int k=0; k<(int)pow(2,i); k++)
			{
				if(paper[i][j][k]==1)
					count_blue++;
				else if(paper[i][j][k]==0)
					count_white++;
			}
		}
	}
	cout<<count_white<<endl;
	cout<<count_blue<<endl;

	return 0;
}
int four_is(int pnum, int x, int y)
{
	if(paper[pnum][x][y]==1 && paper[pnum][x+1][y]==1 && 
		paper[pnum][x][y+1]==1 && paper[pnum][x+1][y+1]==1)
	{
		paper[pnum][x][y]=2;
		paper[pnum][x+1][y]=2;
		paper[pnum][x][y+1]=2;
		paper[pnum][x+1][y+1]=2;
		return 1;
	}
	if(paper[pnum][x][y]==0 && paper[pnum][x+1][y]==0 && 
		paper[pnum][x][y+1]==0 && paper[pnum][x+1][y+1]==0)
	{
		paper[pnum][x][y]=2;
		paper[pnum][x+1][y]=2;
		paper[pnum][x][y+1]=2;
		paper[pnum][x+1][y+1]=2;
		return 0;	
	}

	return 3;
}