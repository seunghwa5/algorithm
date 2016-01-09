#include <iostream>

using namespace std;

int max(int x, int y)
{
	if(x<y)
		return y;
	else
		return x;
}
int main()
{
	int num_j, weight;
	cin>>num_j;
	int *w = new int[num_j+1];
	int *v = new int[num_j+1];
	cin>>weight;
	for(int i=1; i<=num_j; i++)
	{
		cin>>w[i]>>v[i];
	}
	int **K = new int*[num_j+1];
	for(int i=0; i<num_j+1; i++)
	{
		K[i] = new int[weight+1];
	}
	// for(int i=0; i<num_j; i++)
	// 	for(int j=0; j<weight; j++)
	// 		K[i][j]=0;
	for(int i=0; i<=num_j; i++)
		K[i][0] = 0;
	for(int i=0; i<=weight; i++)
		K[0][i] = 0;

	for(int i=1; i<=num_j; i++)
	{
		for(int j=1; j<=weight; j++)
		{
			if(w[i]>j)
				K[i][j] = K[i-1][j];
			else
				K[i][j] = max( K[i-1][j], v[i]+K[i][j-w[i]] );
		}
	}
	// for(int i=0; i<=num_j; i++)
	// {
	// 	for(int j=0; j<=weight; j++)
	// 		cout<<K[i][j]<<" ";
	// 	cout<<endl;
	// }
	cout<<K[num_j][weight]<<endl;

	return 0;
}