#include <iostream>

using namespace std;

int **map;
int M,N,K;
int count;

int find_space(int x, int y)
{
	map[x][y] = -1;
	count++;
	if(x-1>=0 && map[x-1][y]!=-1)
		find_space(x-1,y);
	if(x+1<M && map[x+1][y]!=-1)
		find_space(x+1,y);
	if(y-1>=0 && map[x][y-1]!=-1)
		find_space(x,y-1);
	if(y+1<N && map[x][y+1]!=-1)
		find_space(x,y+1);
}
void print_map()
{
	for(int i=0; i<M; i++)
	{
		for(int j=0; j<N; j++)
		{
			cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	int space_num = 1;
	int start_x, start_y, end_x, end_y;

	cin>>M>>N>>K;
	int *result = new int[M*N/2];
	int result_num=0;
	map = new int*[M]; //M*N array

	for(int i=0; i<M; i++)
		map[i] = new int[N];

	for(int i=0; i<K; i++)
	{
		cin>>start_x>>start_y>>end_x>>end_y;
		for(int j=start_y; j<end_y; j++)
		{
			for(int k=start_x; k<end_x; k++)
			{
				map[j][k] = -1;
			}
		}
	}
	//print_map();

	for(int i=0; i<M; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(map[i][j]!=-1)
			{
				count = 0;
				find_space(i, j);
				space_num++;
				result[result_num] = count;
				result_num++;
				//print_map();
			}
		}
	}
	for(int i=0; i<result_num; i++)
		for(int j=0; j<result_num-1; j++)
			if(result[j]>result[j+1])
			{
				int temp = result[j];
				result[j] = result[j+1];
				result[j+1] = temp;
			}

	cout<<result_num<<endl;
	for(int i=0; i<result_num; i++)
		cout<<result[i]<<" ";
	cout<<endl;
}