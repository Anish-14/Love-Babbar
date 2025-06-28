#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter size: ";
    cin>>n;

    int array[n];

    for(int i = 0; i<n; i++){
        cin>>array[i];
    } 

    int count = 0;

    for(int i = 0; i<n; i++){
        if(array[i]==0){
            count++;
        }
    }

    int sort[n];

    for(int j = 0; j<n; j++){
        if(j<count){
            array[j] = 0;
        }
        else
        array[j] = 1;
    }

    for(int m = 0; m<n; m++){
        cout<<array[m]<<" ";
    }



    return 0;
}