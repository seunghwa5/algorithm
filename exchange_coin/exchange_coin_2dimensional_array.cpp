#include <iostream>

using namespace std;
#define INT_MAX 7654321

void print_DP(int **DP, int num_coin, int total_value)
{
	for (int i = 0; i <= num_coin; i++) {
		for (int j = 0; j <= total_value; j++) {
			cout<<DP[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	int num_coin;
	cin>>num_coin;

	int *values = new int[num_coin+1];
	for (int i = 1; i <= num_coin; i++) {
		cin>>values[i];
	}

	int total_value;
	cin>>total_value;

	int **DP = new int *[num_coin+1];
	for (int i = 0; i<= num_coin; i++) 
		DP[i] = new int[total_value+1];

	for (int i = 0; i<= num_coin; i++)
		DP[i][0] = 0;

	for (int i = 0; i<= total_value; i++)
		DP[0][i] = INT_MAX;

	for (int i = 1; i <= num_coin; i++) {
		for (int j = 1; j <= total_value; j++) {
			int before_value = DP[i-1][j];
			int now_value = -1;
			for (int k = 1; k <= j / values[i]; k++) {
				if (DP[i][j-k*values[i]] == -1)
					continue;
				if (now_value == -1)
					now_value = k + DP[i][j-k*values[i]];
				else
					now_value = min(now_value, k + DP[i][j-k*values[i]]);
			}

			if (before_value == -1 && now_value == -1) {
				DP[i][j] = -1;
			} else if (before_value == -1) {
				DP[i][j] = now_value;
			} else if (now_value == -1) {
				DP[i][j] = before_value;
			} else {
				DP[i][j] = min(before_value, now_value);
			}
		}
	}
	//print_DP(DP, num_coin, total_value);
	if(DP[num_coin][total_value] == -1)
		cout<<"impossible"<<endl;
	else
		cout<<DP[num_coin][total_value]<<endl;

	return 0;
}	