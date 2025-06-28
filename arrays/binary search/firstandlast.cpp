#include<iostream>
using namespace std;

// we have to find the first and last occurance of the key in an array.

int firstindex(int arr[],int n, int k)
{
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;
    int f = -1;

    while(s<=e)
    {
        if(arr[mid] == k)
        {   
            f = mid;
            e = mid - 1;
        }

        else if(arr[mid] < k)
        {
            s = mid+1;
        }

        else if(arr[mid] > k)
        {
            e = mid - 1;
        }

        mid = s + (e-s)/2;   
    }
    return f;
}

int lastindex(int arr[],int n, int k)
{
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;
    int l = -1;

    while(s<=e)
    {
        if(arr[mid] == k)
        {   
            l = mid;
            s = mid + 1;
        }

        else if(arr[mid] < k)
        {
            s = mid+1;
        }

        else if(arr[mid] > k)
        {
            e = mid - 1;
        }

        mid = s + (e-s)/2;   
    }
    return l;
}

int main()
{
    int n;
    cout<<"enter the length of array "<<endl;
    cin>>n;

    int k ;
    cout<<"enter the key: "<<endl;
    cin>>k;

    int arr[n];
    
    cout<<"enter the values of array :"<<endl;
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }

    cout<<firstindex(arr,n,k)<<endl;
    cout<<lastindex(arr,n,k)<<endl;
}