#include<iostream>
using namespace std;

// in this program we swap alternate numbers.

void swapalternate(int array[],int size){
    for(int i = 0; i<size; i+=2){
        if(i+1<size){
            swap(array[i],array[i+1]);
        }
    }
}

void printArray(int array[],int size){
    for(int i = 0; i<size; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int size;
    cout<<"enter size: ";
    cin>>size;

    int array[size];

    for(int i = 0; i<size; i++){
        cin>>array[i];
    } 

    cout<<"here it all starts "<<endl;

    printArray(array,size);
    swapalternate(array,size);
    printArray(array,size);

    cout<<"here it all ends"<<endl;
    

    return 0;
}