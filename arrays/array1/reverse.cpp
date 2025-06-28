#include<iostream>
using namespace std;

// reversing the array.

void reverse(int num[], int size){
    
    int start = 0;
    int end = size - 1;

    while(start<=end){
         swap(num[start],num[end]);
         start++;
         end--;
    }

}


int main()
{
    int num[5] = {1,2,3,4,5};

    for(int i =0; i<5; i++){
        cout<<num[i];
    }
    cout<<endl;

    reverse(num,5);

     for(int i =0; i<5; i++){
        cout<<num[i];
    }
    cout<<endl;

    return 0;
}