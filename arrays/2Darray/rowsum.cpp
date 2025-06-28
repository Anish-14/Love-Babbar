#include<iostream>
#include<cstring>
using namespace std;

int main()
{
   int arr[3][4];

    cout<<"fill the array 12 elements"<<endl;
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<4; j++)
        {
            cin>>arr[i][j];
        }
    } 

    //print 
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<4; j++)
        {
           cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }


    int ans[3];

    int sum = 0;

    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<4; j++)
        {
            sum += arr[i][j];
        }
        ans[i] = sum;
        sum = 0;
    } 

    for(int i = 0; i<3; i++)
    {
        cout<<ans[i]<<endl;
    }



    // largest sum

    cout<<"largest row sum is : ";
    int maxindex = 0;
    int i = 1;

    for(; i<3; i++)
    {
        if(ans[i]>ans[maxindex])
        {
            maxindex = i;
        }
    }

    cout<<ans[maxindex]<<endl;

    cout<<"it's index is : "<<maxindex<<endl;
    
}