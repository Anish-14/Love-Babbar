#include<iostream>
using namespace std;

// sum of all elements of array.

int sum(int num[],int size){
    int ans = 0;
    for(int i = 0; i<size; i++){
        ans += num[i];
    }

    return ans;
}

int main()
{
    int size;
    cout<<"enter size: ";
    cin>>size;

    int num[10000];
    for(int i = 0;i<size; i++){
        cin>>num[i];
    }

    cout<<"sum of elements of num are: "<<sum(num,size)<<endl;

    return 0;
}