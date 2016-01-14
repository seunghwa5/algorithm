#include <iostream>
//#include <stack>

using namespace std;

int M,N,H;
int ***box;
int mature_count;
// class Node
// {
// public:
// 	int x;
// 	int y;
// 	int z;
// 	Node(int _x, int _y, int _z)
// 	{
// 		this->x = _x;
// 		this->y = _y;
// 		this->z = _z;
// 	}
// };
void spread(int,int,int,int);
void print_box();
bool all_matured();
int main()
{
	//stack<Node> st;

	cin>>M>>N>>H;
	box = new int**[H];
	for(int i=0; i<H; i++)
		box[i] = new int*[N];
	for(int i=0; i<H; i++)
		for(int j=0; j<N; j++)
			box[i][j] = new int[M];
	for(int i=0; i<H; i++)
		for(int j=0; j<N; j++)
			for(int k=0; k<M; k++)
			{
				cin>>box[i][j][k];
			}

	//print_box();

	int stage_count=2;
	mature_count=1;
	while(mature_count!=0)
	{
		mature_count=0;
		for(int i=0; i<H; i++)
			for(int j=0; j<N; j++)
				for(int k=0; k<M; k++)
				{
					if(box[i][j][k]!=stage_count && box[i][j][k]>0)
						spread(i,j,k,stage_count);
						//st.push(Node(i,j,k));
				}
		// while(!st.empty())
		// {
		// 	Node one = st.top();
		// 	spread(one.x, one.y, one.z);
		// 	st.pop();
		// }
		//print_box();
		stage_count++;
	}

	if(all_matured())
		cout<<stage_count-3<<"\n";
	else
		cout<<-1<<"\n";

	return 0;
}
bool all_matured()
{
	for(int i=H-1; i>=0; i--)
		for(int j=N-1; j>=0; j--)
			for(int k=M-1; k>=0; k--)
				if(box[i][j][k]==0)
					return false;
	return true;
}
void spread(int x,int y,int z, int count)
{
	if(x-1>=0 && box[x-1][y][z]==0)
	{
		box[x-1][y][z] = count;
		mature_count++;
	}
	if(y-1>=0 && box[x][y-1][z]==0)
	{
		box[x][y-1][z] = count;
		mature_count++;
	}
	if(z-1>=0 && box[x][y][z-1]==0)
	{
		box[x][y][z-1] = count;
		mature_count++;
	}
	if(x+1<H && box[x+1][y][z]==0)
	{
		box[x+1][y][z] = count;
		mature_count++;
	}
	if(y+1<N && box[x][y+1][z]==0)
	{
		box[x][y+1][z] = count;
		mature_count++;
	}
	if(z+1<M && box[x][y][z+1]==0)
	{
		box[x][y][z+1] = count;
		mature_count++;
	}
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

