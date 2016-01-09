#include <iostream>
#include <string.h>

using namespace std;

int **schedule;
void swap(int i, int j)
{
	int *temp = schedule[i];
	schedule[i] = schedule[j];
	schedule[j] = temp;
}
int main()
{
	int meeting;
	cin>>meeting;
	schedule = new int*[meeting+1];
	for(int i=0; i<=meeting; i++)
		schedule[i] = new int[3];
	for(int i=1; i<=meeting; i++)
		cin>>schedule[i][0]>>schedule[i][1]>>schedule[i][2];

	for(int i=1; i<=meeting; i++)
	{
		for(int j=1; j<meeting; j++)
		{
			if(schedule[j][2]>schedule[j+1][2])
				swap(j,j+1);
		}
	}

	// for(int i=1; i<=meeting; i++)
	// 	cout<<schedule[i][0]<<" "<<schedule[i][1]<<" "<<schedule[i][2]<<endl;
	int *result=new int[meeting+1];
	int count=0;
	int end=0;
	for(int i=1; i<=meeting; i++)
	{
		if(schedule[i][1]>=end)
		{
			result[count] = schedule[i][0];
			count++;
			end = schedule[i][2];
		}
	}
	cout<<count<<endl;
	for(int i=0; i<count; i++)
		cout<<result[i]<<" ";
}