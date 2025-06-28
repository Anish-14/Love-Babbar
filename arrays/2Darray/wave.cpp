#include<iostream>
#include<cstring>
using namespace std;

// printing elements like a wave 
// Given a 2D matrix, print its elements in a wave (or zig-zag column-wise) pattern.

/*  input
vector<vector<int>> mat = {
    {1,  2,  3},
    {4,  5,  6},
    {7,  8,  9}
};

output :- 1 4 7 8 5 2 3 6 9
*/

int main()
{
    int N;
    int M;

    cout<<"rows : ";
    cin>>N;

    cout<<"columns : ";
    cin>>M;

    int arr[N][M];

    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<M; j++)
        {
            cin>>arr[i][j];
        }
    }

    for(int j = 0; j<M; j++)
    {
        if(j%2 == 0)
        {
            for(int i = 0; i<N; i++)
            {
                cout<<arr[i][j]<<" ";
            }
        }
        else
        {
            for(int i = N - 1; i>=0; i--)
            {
                cout<<arr[i][j]<<" ";
            }
        }
    }
}