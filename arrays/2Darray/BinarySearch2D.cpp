#include<iostream>
using namespace std;

// apply binary search in 2D array.
// To do this open the 2D array in linear manner in your mind,
// and then map the elements to 2D array.

bool binarysearch(vector<vector<int> > v, int k)
{
    int row = v.size();
    int col = v[0].size();

    int s = 0;
    int e = row*col - 1;

    int mid = s + (e-s)/2;
    while(s<=e)
    {
        int element = v[mid/col][mid%col];

        if(element == k)
        {
            return true;
        }

        if(element > k)
        {
            e = mid - 1;
        }

        else
        {
            s = mid + 1;
        }

        mid = s + (e-s)/2;
    }
    return false;
}

int main()
{
    vector<vector<int> > v(3,vector<int>(3));
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            int ele;
            cin>>ele;
            v[i][j] = ele;
        }
    }

    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<binarysearch(v,27)<<endl;

}