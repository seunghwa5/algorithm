#include <iostream>
#include <cmath>

using namespace std;

void quickSort(int *a[], int first, int last, int index);
int pivot(int *a[], int first, int last, int index);
void swap(int& a, int& b);
void swapNoTemp(int& a, int& b);

int main()
{
	int N, num_point;

	cin>>N>>num_point;
	int **points = new int*[num_point];
	for(int i=0; i<num_point; i++)
	{
		points[i] = new int[2];
		cin>>points[i][0]>>points[i][1];
	}

	quickSort(points, 0, num_point-1, 0);
	quickSort(points, 0, num_point-1, 1);

	int center_index = ((float)num_point/2.0+0.5)/1-1;
	int median_x = points[center_index][0];
	int median_y = points[center_index][1];

	//cout<<median_x<<" "<<median_y<<endl;

	int move_count=0;
	for(int i=0; i<num_point; i++)
	{
		//cout<<points[i][0]<<" "<<points[i][1]<<endl;
		move_count += abs(points[i][0]-median_x);
		move_count += abs(points[i][1]-median_y);
	}
	cout<<move_count<<endl;


	return 0;
}

void quickSort( int *a[], int first, int last ,int index) 
{
    int pivotElement;
 
    if(first < last)
    {
        pivotElement = pivot(a, first, last, index);
        quickSort(a, first, pivotElement-1, index);
        quickSort(a, pivotElement+1, last, index);
    }
}
 
int pivot(int *a[], int first, int last, int index) 
{
    int  p = first;
    int pivotElement = a[first][index];
 
    for(int i = first+1 ; i <= last ; i++)
    {
        /* If you want to sort the list in the other order, change "<=" to ">" */
        if(a[i][index] <= pivotElement)
        {
            p++;
            swap(a[i][index], a[p][index]);
        }
    }

    swap(a[p][index], a[first][index]);

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
