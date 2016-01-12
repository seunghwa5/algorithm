#include <iostream>

using namespace std;

int main()
{
	int N;
	cin>>N;
	int *children = new int[N];
	int *LIS = new int[N];

	for(int i=0; i<N; i++)
		cin>>children[i];

	for(int i=0; i<N; i++)
	{
		LIS[i] = 1;
		for(int j=0; j<i; j++)
		{
			if(children[j]<children[i] && LIS[j]+1 > LIS[i])
				LIS[i] = LIS[j]+1;
		}
	}

	int max_sequential = 0;
	for(int i=0; i<N; i++)
	{
		if(max_sequential<LIS[i])
			max_sequential = LIS[i];
	}
	cout<<N-max_sequential<<endl;

	return 0;
}