#include <iostream>
#include <cmath>

using namespace std;

int *col;
int N;
int count;
void N_Queens(int);
bool possible(int);
void print_board();

int main()
{
	count = 0;
	cin>>N;
	col = new int[N+1];
	N_Queens(0);
	cout<<count<<endl;
}
void N_Queens(int i)
{
	if(possible(i))
	{
		if(i==N)
		{
			//print_board();
			count++;
		}
		else
			for(int j=1; j<=N; j++)
			{
				col[i+1] = j;
				N_Queens(i+1);
			}
	}
}
bool possible(int i)
{
	for(int j=1; j<i; j++)
	{
		if( abs(i-j)==abs(col[i]-col[j]) || col[i]==col[j])
			return false;
	}
	return true;
}
void print_board()
{
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
			if(col[i]==j)
				cout<<"Q";
			else
				cout<<" ";
		cout<<endl;
	}
	cout<<"------"<<endl;

}