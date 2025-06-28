#include<iostream>
using namespace std;

int max(int num[] , int size){
   int max = INT_MIN;
   for(int i = 0; i<size; i++){
        if(num[i] > max){
            max = num[i];
        }
   }
   return max;
}

int min(int num[] , int size){
   int min = INT_MAX;
   for(int i = 0; i<size; i++){
        if(num[i] < min){
            min = num[i];
        }
   }
   return min;
}


int main()
{
    int size;
    cout<<"enter size below 1000: ";
    cin>>size;

    int num[1000];

    for(int i = 0; i<size; i++ ){
        cin>>num[i];
    }

    cout<<"max value in array is: "<<max(num,size)<<endl;
    cout<<"min value in array is: "<<min(num,size)<<endl;
 
   return 0;
} 