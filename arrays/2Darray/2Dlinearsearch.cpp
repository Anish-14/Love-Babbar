#include<iostream>
#include<cstring>
using namespace std;

bool ispresent(int arr[][4],int k)
{
    for(int i = 0; i<3; i++){
        for(int j = 0; j<4; j++){
            if(arr[i][j] == k)
            return true;
        }
    }
    return false;
}

int main()
{
    cout<<"fill rows & columns"<<endl;
    int arr[3][4];

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

    int k ;
    cout<<"enter key"<<endl;
    cin>>k;

    if(ispresent(arr,k))
    {
        cout<<"key found"<<endl;
    }
    else
    {
        cout<<"key not found"<<endl;
    }

    
}