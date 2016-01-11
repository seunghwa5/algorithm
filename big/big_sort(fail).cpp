#include <iostream>

using namespace std;

int N;
int **info;

void quickSort(int *a[], int first, int last);
int pivot(int *a[], int first, int last);
void swap(int& a, int& b);
void swapNoTemp(int& a, int& b);

int main()
{
	cin>>N;
	info = new int*[N];
	for(int i=0; i<N; i++)
	{
		info[i] = new int[4];
		info[i][0] = i;
		cin>>info[i][1]>>info[i][2];
	}
	
	quickSort(info, 0, N-1);

	// for(int i=0; i<N; i++)
	// {
	// 	cout<<info[i][0]<<" "<<info[i][1]<<" "<<info[i][2]<<endl;
	// }
	int max_height = info[N-1][2];
	int min_dupl = info[N-1][2];
	info[N-1][3] = 1;
	int rank = 1;
	for(int i=N-2; i>=0; i--)
	{
		if((info[i+1][1]!=info[i][1] && max_height>info[i][2] && min_dupl>info[i][2])
			|| (info[i+1][1]==info[i][1] && max_height>=info[i][2] && min_dupl>=info[i][2]))
		{
			info[i][3] = N-i;
			max_height = info[i+1][2];
			min_dupl = info[i][2];
			rank = N-i;
		}
		else
		{
			info[i][3] = rank;
			if(min_dupl>info[i][2])
				min_dupl = info[i][2];
		}
	}

	for(int i=0; i<N; i++)
	{
		cout<<info[i][0]<<" "<<info[i][1]<<" "<<info[i][2]<<" "<<info[i][3]<<endl;
	}

	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			if(info[j][0]==i)
			{
				cout<<info[j][3]<<" ";
				break;
			}
	cout<<endl;

	return 0;
}

void quickSort( int *a[], int first, int last ) 
{
    int pivotElement;
 
    if(first < last)
    {
        pivotElement = pivot(a, first, last);
        quickSort(a, first, pivotElement-1);
        quickSort(a, pivotElement+1, last);
    }
}
 
int pivot(int *a[], int first, int last) 
{
    int  p = first;
    int pivotElement = a[first][1];
 
    for(int i = first+1 ; i <= last ; i++)
    {
        /* If you want to sort the list in the other order, change "<=" to ">" */
        if(a[i][1] <= pivotElement)
        {
            p++;
            swap(a[i], a[p]);
        }
    }

    swap(a[p], a[first]);

    return p;
}

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swapNoTemp(int& a, int& b)
{
    a -= b;
    b += a;// b gets the original value of a
    a = (b - a);// a gets the original value of b
}
