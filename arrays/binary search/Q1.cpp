#include<iostream>
using namespace std;

// we have to rerurn the index of array whose value matches with key(k) if key not present 
// array should be sorted.
// here it is in ascending order.

int binarysearch(int arr[],int n,int k)
{
    int start = 0;
    int end = n-1 ;
    int mid = start + (end-start)/2;

    while(start<=end)
    {
        if(arr[mid] == k)
        {
            return mid;
        }
        if(arr[mid] < k)
        {
            start = mid+1;
        }
        else if(arr[mid] > k)
        {
            end = mid - 1;
        }

        mid = start + (end-start)/2;   
    }
    return -1;
}


int main()
{
    int n;
    cout<<"enter the value of n: ";
    cin>>n;

    int array[n];

    for(int i = 0; i<n; i++)
    {
        cin>>array[i];
    }

    cout<<binarysearch(array,n,8)<<endl;
    cout<<binarysearch(array,n,9)<<endl;

}