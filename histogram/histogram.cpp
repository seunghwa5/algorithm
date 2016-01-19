#include <iostream>

using namespace std;

int main()
{
	unsigned int num_histo;
	cin>>num_histo;
	
	long *histo = new long[num_histo];
	for (int i = 0; i < num_histo; i++)
		cin>>histo[i];

	long max_rect = 0;
	for (int i = 0; i < num_histo; i++)
	{
		long min_height = histo[i];
		for (int j = i; j < num_histo; j++)
		{
			if (histo[j] < min_height)
				min_height = histo[j];

			long rect = (j - i + 1) * min_height;
			//cout<<rect<<endl;
			if (max_rect < rect)
				max_rect = rect;
		}
	}

	cout<<max_rect<<endl;

	return 0;
}