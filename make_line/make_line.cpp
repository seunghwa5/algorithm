#include <iostream>

using namespace std;

int main()
{
	int N;
	int *line;
	int *LIS;

	cin>>N;
	line = new int[N];
	LIS = new int[N];
	for(int i=0; i<N; i++)
	{
		cin>>line[i];
	}

	for(int i=0; i<N; i++)
	{
		LIS[i] = 1;
		for(int j=0; j<i; j++)
		{
			if(line[j]+1==line[i] && LIS[j]+1>LIS[i])
				LIS[i] = LIS[j]+1;
		}
	}

	int max_correct = 0;
	for(int i=0; i<N; i++)
	{
		if(max_correct<LIS[i])
			max_correct = LIS[i];
	}
	cout<<N-max_correct<<endl;


	return 0;
}