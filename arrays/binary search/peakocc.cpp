#include<iostream>
using namespace std;

// we have to return the peak index in an mountain array.

int peakindex(int arr[],int n)
{
    int s = 0;
    int e = n-1;

    int mid = s + (e-s)/2;

    while(s<=e){
        if((arr[mid] - arr[mid-1]) > 0  && (arr[mid] - arr[mid+1]) > 0 )
        {
            return mid;
        }

        else if((arr[mid] - arr[mid-1]) < 0  && (arr[mid] - arr[mid+1]) > 0 ) // for right side
        {
            e = mid - 1;
        }

        else if((arr[mid] - arr[mid-1]) > 0  && (arr[mid] - arr[mid+1]) < 0 ) // for left side
        {
            s = mid + 1;
        }

       mid = s + (e-s)/2; 

    }
    return -1;
   
}

int main()
{
    int n;
    cout<<"enter the length of array "<<endl;
    cin>>n;

    int arr[n];

    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }

    int peak = peakindex(arr,n);
    cout<<"the peak index in this array is "<<peak<<endl;

}