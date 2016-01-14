#include <iostream>
#include <queue>

using namespace std;

int M,N,H;
int ***box;
bool ***visit;

class Node
{
public:
	int x;
	int y;
	int z;
	int day;
	Node(int _x, int _y, int _z, int _day)
	{
		this->x = _x;
		this->y = _y;
		this->z = _z;
		this->day = _day;
	}
};

void print_box();
int main()
{
	queue<Node> Queue;

	cin>>M>>N>>H;
	box = new int**[H];
	visit = new bool**[H];
	for(int i=0; i<H; i++)
	{
		box[i] = new int*[N];
		visit[i] = new bool*[N];
	}
	for(int i=0; i<H; i++)
		for(int j=0; j<N; j++)
		{
			box[i][j] = new int[M];
			visit[i][j] = new bool[M];
		}
	int cnt_not_matured = 0;
	for(int i=0; i<H; i++)
		for(int j=0; j<N; j++)
			for(int k=0; k<M; k++)
			{
				int tomato;
				cin>>tomato;
				box[i][j][k] = tomato;
				if(tomato==0)
					cnt_not_matured++;
				if(tomato==1)
					Queue.push(Node(i,j,k,0));
			}

	int current_day;
	while(!Queue.empty())
	{
		int x = Queue.front().x;
		int y = Queue.front().y;
		int z = Queue.front().z;
		current_day = Queue.front().day;
		Queue.pop();
		//print_box();
		if(x-1>=0 && box[x-1][y][z]==0)
		{
			Queue.push(Node(x-1,y,z,current_day+1));
			box[x-1][y][z] = 1;
			cnt_not_matured--;
		}
		if(x+1<H && box[x+1][y][z]==0)
		{
			Queue.push(Node(x+1,y,z,current_day+1));
			box[x+1][y][z] = 1;
			cnt_not_matured--;
		}
		if(y-1>=0 && box[x][y-1][z]==0)
		{
			Queue.push(Node(x,y-1,z,current_day+1));
			box[x][y-1][z] = 1;
			cnt_not_matured--;
		}
		if(y+1<N && box[x][y+1][z]==0)
		{
			Queue.push(Node(x,y+1,z,current_day+1));
			box[x][y+1][z] = 1;
			cnt_not_matured--;
		}
		if(z-1>=0 && box[x][y][z-1]==0)
		{
			Queue.push(Node(x,y,z-1,current_day+1));
			box[x][y][z-1] = 1;
			cnt_not_matured--;
		}
		if(z+1<M && box[x][y][z+1]==0)
		{
			Queue.push(Node(x,y,z+1,current_day+1));
			box[x][y][z+1] = 1;
			cnt_not_matured--;
		}
	}
	if(cnt_not_matured!=0)
		cout<<-1<<endl;
	else
		cout<<current_day<<endl;
					
	return 0;
}
void print_box()
{
	cout<<"-------------------"<<endl;
	for(int i=0; i<H; i++)
	{
		for(int j=0; j<N; j++)
		{
			for(int k=0; k<M; k++)
			{
				cout<<box[i][j][k]<<" ";
			}
			cout<<endl;
		}
		cout<<"-------------------"<<endl;
	}
}