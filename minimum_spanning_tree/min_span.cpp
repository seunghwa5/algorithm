#include <iostream>

using namespace std;
int N;
bool *reachable;
int reachable_num;
int **cost;
int total_cost;
void connect()
{
	int min_cost=-1;
	int min_node;
	for(int k=0; k<N; k++)
	{
		if(reachable[k]==false)
			continue;
		for(int j=0; j<N; j++)
		{
			if(cost[k][j]==0)
				continue;
			if(reachable[j])
				continue;
			if(min_cost==-1 || min_cost>cost[k][j])
			{
				min_cost = cost[k][j];
				min_node = j;
			}
		}
	}
	total_cost += min_cost;
	reachable[min_node] = true;
	reachable_num++;
	if(reachable_num!=N)
		connect();
}
int main()
{
	cin>>N;
	reachable = new bool[N];
	reachable_num = 0;
	total_cost = 0;
	cost = new int*[N];
	for(int i=0; i<N; i++)
		cost[i] = new int[N];
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			cin>>cost[i][j];
	reachable[0] = true;
	reachable_num++;
	connect();
	cout<<total_cost<<endl;
}