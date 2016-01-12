#include <iostream>

using namespace std;

int N;
int **bottom;

bool is_empty_tile(int start_x, int start_y, int end_x, int end_y);
void fill(int start_x, int start_y, int end_x, int end_y);
void print_bottom();
int main()
{
	cin>>N;
	bottom = new int*[N];
	for(int i=0; i<N; i++)
		bottom[i] = new int[N];

	int hole_x, hole_y;
	cin>>hole_x>>hole_y;
	bottom[hole_x][hole_y]=5;

	//print_bottom();

	fill(0,0,N,N);

	bottom[hole_x][hole_y] = 0;

	print_bottom();

	return 0;
}
void print_bottom()
{
	//cout<<endl;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cout<<bottom[i][j]<<" ";
		}
		cout<<endl;
	}
	//cout<<endl;
}
void fill(int start_x, int start_y, int end_x, int end_y)
{

	int mid_x = (start_x+end_x)/2;
	int mid_y = (start_y+end_y)/2;
	bool one, two, three, four;
	one = is_empty_tile(start_x, start_y, mid_x, mid_y);
	two = is_empty_tile(start_x, mid_y, mid_x, end_y);
	three = is_empty_tile(mid_x, start_y, end_x, mid_y);
	four = is_empty_tile(mid_x, mid_y, end_x, end_y);

	if( !one && two && three && four )
	{
		//bottom[mid_x-1][mid_y-1] = 1;
		bottom[mid_x][mid_y-1] = 1;
		bottom[mid_x-1][mid_y] = 1;
		bottom[mid_x][mid_y] = 1;
	}
	else if( one && !two && three && four )
	{
		bottom[mid_x-1][mid_y-1] = 2;
		//bottom[mid_x][mid_y-1] = 1;
		bottom[mid_x][mid_y-1] = 2;
		bottom[mid_x][mid_y] = 2;
	}
	else if( one && two && !three && four )
	{
		bottom[mid_x-1][mid_y-1] = 3;
		bottom[mid_x-1][mid_y] = 3;
		//bottom[mid_x-1][mid_y] = 1;
		bottom[mid_x][mid_y] = 3;
	}
	else if( one && two && three && !four )
	{
		bottom[mid_x-1][mid_y-1] = 4;
		bottom[mid_x][mid_y-1] = 4;
		bottom[mid_x-1][mid_y] = 4;
		//bottom[mid_x][mid_y] = 1;
	}
	//print_bottom();

	if(start_x<mid_x-1)
	{
		fill(start_x, start_y, mid_x, mid_y);
		fill(mid_x, start_y, end_x, mid_y);
		fill(start_x, mid_y, mid_x, end_y);
		fill(mid_x, mid_y, end_x, end_y);
	}

}
bool is_empty_tile(int start_x, int start_y, int end_x, int end_y)
{
	for(int i=start_x; i<end_x; i++)
	{
		for(int j=start_y; j<end_y; j++)
		{
			if(bottom[i][j]!=0)
				return false;
		}
	}
	return true;
}