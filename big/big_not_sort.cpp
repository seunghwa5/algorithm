#include <iostream>

using namespace std;

int N;
int **info;

int main()
{
	cin>>N;
	info = new int*[N];
	for(int i=0; i<N; i++)
	{
		info[i] = new int[4];
		info[i][0] = i;
		cin>>info[i][1]>>info[i][2];
	}
	
	int bigger_count = 0;
	for(int i=0; i<N; i++)
	{
		bigger_count = 0;
		for(int j=0; j<N; j++)
		{
			if(i==j)
				continue;
			if(info[i][1]<info[j][1] && info[i][2]<info[j][2])
				bigger_count++;
		}
		cout<<bigger_count+1<<" ";
	}
	cout<<endl;

}