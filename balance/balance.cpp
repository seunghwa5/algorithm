//with Floyd-Warshall algorithm
#include <iostream>

using namespace std;

int num_thing;
bool **graph;

int main()
{
    int num_pair;
    int big_one, small_one;

    cin>>num_thing;
    cin>>num_pair;

    graph = new bool*[num_thing];
    for(int i=0; i<num_thing; i++)
    {
        graph[i] = new bool[num_thing];
    }

    for(int i=0; i<num_pair; i++)
    {
        cin>>big_one>>small_one;
        big_one-=1;
        small_one-=1;
        graph[big_one][small_one]=true;
    }

    for (int k = 0; k < num_thing; ++k)
    {
        for (int i = 0; i < num_thing; ++i)
        {
            for (int j = 0; j < num_thing; ++j)
            {
                if (graph[i][j])
                    continue;
                if (graph[i][k] && graph[k][j])
                    graph[i][j]=true;
            }
        }
    }

    for(int i=0; i<num_thing; i++)
    {
        int result=0;
        for(int j=0; j<num_thing; j++)
        {
            if(graph[i][j])
                result++;
            else if(graph[j][i])
                result++;
        }
        cout<<num_thing-1-result<<endl;
    }

    return 0;
}