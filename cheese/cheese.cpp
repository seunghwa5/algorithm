#include <iostream>

using namespace std;

int col, row;
int **map;
bool **possible;
int cheese_count;

void print_map()
{
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++)
			cout<<map[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}

void init_possible()
{
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++)
			possible[i][j] = true;
	}
}

void melt_cheese(int x, int y, int hour)
{
	possible[x][y] = false;
	//print_map();
	if (x-1 >= 0 && possible[x-1][y] == true) {
		if (map[x-1][y] == -1) {
			map[x-1][y] = hour;
			cheese_count--;
		} else if (map[x-1][y] != hour) {
			melt_cheese(x-1, y, hour);
		}
	}
	if (y-1 >= 0  && possible[x][y-1] == true) {
		if (map[x][y-1] == -1) {
			map[x][y-1] = hour;
			cheese_count--;
		} else if (map[x][y-1] != hour) {
			melt_cheese(x, y-1, hour);
		}
	}
	if (x+1 < col && possible[x+1][y] == true) {
		if (map[x+1][y] == -1) {
			map[x+1][y] = hour;
			cheese_count--;
		} else if (map[x+1][y] != hour) {
			melt_cheese(x+1, y, hour);
		}
	}
	if (y+1 < row && possible[x][y+1] == true) {
		if (map[x][y+1] == -1) {
			map[x][y+1] = hour;
			cheese_count--;
		} else if (map[x][y+1] != hour) {
			melt_cheese(x, y+1, hour);
		}
	}

}

int main()
{
	cin>>col>>row;
	map = new int *[col];
	possible = new bool *[col];
	for (int i = 0; i < col; i++) {
		map[i] = new int[row];
		possible[i] = new bool[row];
	}

	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			cin>>map[i][j];
			if (map[i][j] == 1) {
				map[i][j] = -1;
				cheese_count++;
			}
		}
	}
	//print_map();

	int hour = 0;
	while (cheese_count > 0) {
		hour++;
		init_possible();
		melt_cheese(0, 0, hour);
		//print_map();
	}
	cout<<hour<<endl;

	int count_last = 0;
	for (int i = 0; i < col; i++) {
		for(int j = 0; j < row; j++) {
			if(map[i][j] == hour)
				count_last++;
		}
	}
	cout<<count_last<<endl;

	return 0;
}