#include<iostream>
#include<vector>
using namespace std;

// you have to print the given matrix in spiral manner.

// input
// 3 4
// 1  2  3  4
// 5  6  7  8
// 9 10 11 12

// output
// 1 2 3 4 8 12 11 10 9 5 6 7

void spiral(vector<vector<int> > &v)
{
    int firstrow = 0;
    int firstcolumn = 0;
    int lastcolumn = v[0].size()-1;
    int lastrow = v.size()-1;

    while(firstrow <= lastrow && firstcolumn <= lastcolumn)
    {
        for(int j = firstcolumn; j<=lastcolumn; j++)
        {
            cout<<v[firstrow][j]<<" ";          // prints first row.
        }
        firstrow++;

        for(int i = firstrow; i<=lastrow; i++)
        {
            cout<<v[i][lastcolumn]<<" ";        // prints lastcolumn.
        }
        lastcolumn--;

        for(int j = lastcolumn; j>=firstcolumn && firstrow <= lastrow; j--)
        {
            cout<<v[lastrow][j]<<" ";        // prints lastrow.
        }
        lastrow--;

        for(int i = lastrow ; i>=firstrow && firstcolumn <= lastcolumn; i--)
        {
            cout<<v[i][firstcolumn]<<" ";        // prints firstcolumn.
        }
        firstcolumn++;
    }
}

int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int> > v(n,vector<int>(m));
    
    for(int i = 0; i<v.size(); i++)
    {
        for(int j = 0; j<v[i].size(); j++)
        {
            cin>>v[i][j];
        }
    }

    spiral(v);
}