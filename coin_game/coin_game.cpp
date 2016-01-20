#include <iostream>

using namespace std;

void print_game(bool **game, int round_num)
{
	for (int i = 0; i <= round_num; i++) {
		for (int j = 0; j <= round_num; j++) {
			cout<<game[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

int main()
{
	int round_num;
	int input_num;
	cin>>round_num>>input_num;

	bool **game = new bool *[round_num+1];
	for (int i = 0; i <= round_num; i++) {
		game[i] = new bool[round_num+1];
		for (int j = 0; j <= round_num; j++)
			game[i][j] = true;
	}

	for (int i = 0; i <= round_num; i++) {
		for (int j = 0; j <= round_num; j++) {
			if (j > i + round_num - j + 1) {
				game[i][j] = false;
			}
			if (i > j + round_num - i + 2) {
				game[i][j] = false;
			}
		}
	}
	//print_game(game, round_num);
	
	for (int i = 0; i < input_num; i++) {
		int younghee, dongsu;
		cin>>younghee>>dongsu;
		cout<<game[younghee][dongsu]<<endl;
	}

	return 0;
}
