#include <iostream>
#include <string.h>

using namespace std;

int limit;
int num_center;
int ***DP;

void print_DP()
{
	for (int i = 0; i < num_center + 2; i++)
	{
		for (int j = 0; j < num_center + 2; j++)
		{
			cout<<DP[i][j][0]<<" "<<DP[i][j][1]<<" "<<DP[i][j][2]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;
}

int main()
{
	cin>>limit;
	cin>>num_center;
	DP = new int **[num_center + 2];

	for (int i = 0; i < num_center + 2; i++) {
		DP[i] = new int *[num_center + 2];
		for (int j = 0; j < num_center + 2; j++)
			DP[i][j] = new int[3];
	}

	for (int i = 0; i < num_center + 1; i++) {
		cin>>DP[i][i + 1][1];
		DP[i][i + 1][2] = i;
	}

	for (int i = 1; i < num_center + 1; i++) {
		cin>>DP[i][i + 1][0];
	}

	int distance;
	int min_time;
	int min_interval;
	int min_index;
	for (int i = num_center - 1; i >= 0; i--)
	{
		distance = DP[i][i + 1][1];
		for (int j = i + 2; j <= num_center + 1; j++)
		{
			min_time = DP[i][i + 1][0] + DP[i + 1][j][0];
			min_interval = DP[i + 1][j][1];
			min_index = DP[i + 1][j][2];
			if (DP[i][j - 1][1] + DP[j - 1][j][1] > limit)
			{
				for (int k = i + 1; k < j; k++)
				{
					if(min_time > DP[i][k][0] + DP[k][j][0])
					{
						min_time = DP[i][k][0] + DP[k][j][0];
						min_interval = DP[k][j][1];
						min_index = DP[k][j][2];
					}
					else if(min_time == DP[i][k][0] + DP[k][j][0] && min_interval > DP[k][j][1])
					{
						min_time = DP[i][k][0] + DP[k][j][0];
						min_interval = DP[k][j][1];
						min_index = DP[k][j][2];
					}
				}
				DP[i][j][0] = min_time;
				//cout<<min_interval<<endl;
				distance = min_interval;
				DP[i][j][1] = min_interval;
				DP[i][j][2] = min_index;
			}
			else
			{
				DP[i][j][0] = DP[i][j - 1][0];
				distance += DP[j - 1][j][1];
				DP[i][j][1] = distance;
				DP[i][j][2] = DP[i][j - 1][2];
			}
			//print_DP();
		}
		//cout<<distance<<endl;
	}

	cout<<DP[0][num_center + 1][0]<<endl;

	int dropped_by = 0;
	int cnt_dropped_by = 0;
	int *result_dropped_by = new int[num_center];
	for (int i = 0; i < num_center + 2; i++)
	{
		if (dropped_by != DP[0][i][2])
		{
			result_dropped_by[cnt_dropped_by] = DP[0][i][2];
			dropped_by = DP[0][i][2];
			cnt_dropped_by++;
		}
	}
	cout<<cnt_dropped_by<<endl;
	for (int i = 0; i < cnt_dropped_by; i++)
		cout<<result_dropped_by[i]<<" ";
	cout<<endl;
	//print_DP();

	return 0;
}