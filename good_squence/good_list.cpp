#include <iostream>

using namespace std;
int *good_list;
int list_count;
bool is_good(int i)
{
	good_list[list_count] = i;
	list_count++;
	for(int i=1; i<=list_count/2; i++)
	{
		bool dupl = true;
		for(int j=0; j<i; j++)
		{
			if(good_list[list_count-i+j]!=good_list[list_count-i*2+j])
			{
				dupl = false;
				break;
			}
		}
		if(dupl)
		{
			list_count--;
			return false;
		}
	}
	return true;
}
int main()
{
	int N;
	cin>>N;
	good_list = new int[N];
	list_count = 0;
	for(int j=0; j<N; j++)
		for(int i=1; i<=9; i++)
			if(is_good(i))
				break;

	for(int i=0; i<list_count; i++)
		cout<<good_list[i];
	cout<<endl;

	return 0;
}