#include<iostream>
using namespace std;

bool searchkey(int array[],int size,int key){
    for(int i = 0; i<size; i++){
        if(array[i]==key)
        return 1;
    }
    return 0;
}

// in this problem we are linearly searching key by matching every value in array 

int main()
{
    int size;
    cout<<"enter size: ";
    cin>>size;

    int array[10000];

    for(int i = 0; i<size; i++){
        cin>>array[i];
    }

    int key;
    cout<<"enter the key: ";
    cin>>key;

    bool found = searchkey(array,size,key);

    if(found==1){
        cout<<"key is present"<<endl;
    }
    else
    cout<<"key is absent"<<endl;


    return 0;
}