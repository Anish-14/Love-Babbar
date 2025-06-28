#include<iostream>
#include<vector>
using namespace std;

// you have given a matrix which is sorted row wise as well as column wise
// eg -->
// 1 4 7 11 15 
// 2 5 8 12 19 
// 3 6 9 16 22 
// 10 13 14 17 24 
// 18 21 23 26 30

// you have given the target and you have to tell whether the target is present or not.
// you have to give a better way to do it(not linear search).



bool SearchMatrix(vector<vector<int> > &v, int target)          // kinda binary search but not exactly.
{                                                               // because matrix is not sorted as a whole.
    int row = v.size();                                         
    int col = v[0].size();

    int rowIndex = 0;                               // we started from the last element of first row.
    int colIndex = col - 1;

    while(rowIndex<row  &&  colIndex>=0)
    {
        int ele = v[rowIndex][colIndex];

        if(ele == target)
        {
            return 1;
        }

        if(ele < target)                            // next row me milega.
        {
            rowIndex++;
        }

        else                                        // pichhle column me milega.
        {
            colIndex--;
        }
    }
    return 0;
}

int main()
{
    vector<vector<int> > v(5,vector<int>(5));

    for(int i = 0; i<5; i++)
    {
        for(int j = 0; j<5; j++)
        {
            cin>>v[i][j];
        }
    }

    cout<<endl;
    int k;
    cout<<"Enter target : ";
    cin>>k;
    cout<<endl;

    for(int i = 0; i<5; i++)
    {
        for(int j = 0; j<5; j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<"key is present : "<<SearchMatrix(v,k)<<endl;
}