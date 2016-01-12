#include <iostream>

using namespace std;

int N;
int *children;
bool *counted;
int sequential;
int **DP;

void count_sequential(int x)
{
	for(int i=x; i<N; i++)
	{

	}
}
void print_DP()
{
	cout<<endl;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cout<<DP[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
int main()
{
	cin>>N;
	children = new int[N];
	counted = new bool[N];
	DP = new int*[N];
	for(int i=0; i<N; i++)
	{
		DP[i] = new int[N];
		cin>>children[i];
		counted[i] = false;
	}

	for(int i=0; i<N; i++)
	{
		for(int j=i+1; j<N; j++)
		{
			if(children[i]<children[j])
			{
				DP[i][j] = 1;
			}
		}
	}
	//print_DP();

	int max_sequential = 0;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			for(int k=0; k<N; k++)
			{
				if(DP[j][i]>0 && DP[i][k]>0 && DP[j][k]<DP[j][i]+DP[i][k])
				{
					DP[j][k] = DP[j][i]+DP[i][k];
					if(max_sequential<DP[j][k])
						max_sequential = DP[j][k];
				}
			}
		}
	}
	//print_DP();
	//cout<<max_sequential+1<<endl;
	cout<<N-max_sequential-1<<endl;

	return 0;
}