#include <iostream>

using namespace std;

int total_cost;
int yogurt;

int main()
{

	int N_week, keep_cost;
	yogurt = 0;
	total_cost = 0;

	cin>>N_week>>keep_cost;
	int **info = new int*[N_week];
	for(int i=0; i<N_week; i++)
	{
		info[i] = new int[2];
		cin>>info[i][0]>>info[i][1];
	}

	for(int i=0; i<N_week; i++)
	{
		int min_cost = -1;
		//save cost
		int price = info[i][0];
		int need = info[i][1];
		for(int j=0; j<i; j++)
		{
			int save_milk_cost = (i-j)*keep_cost*need+info[j][0]*need;
			if( min_cost==-1 || save_milk_cost<min_cost )
				min_cost = save_milk_cost;
		}
		//buy cost
		if(i==0 || min_cost>need*price)
		{
			total_cost += need*price;
			//cout<<need*price<<endl;
		}
		else
		{
			total_cost += min_cost;
			//cout<<min_cost<<endl;
		}

	}
	cout<<total_cost<<endl;

	return 0;
}