#include<iostream>
using namespace std;

// Problem statement
// array diya hai odd size ka, usme sab element 2-2 baar hai ek ko chhodkar. We have to that akela element.


// int unique(int array[],int size){                     not working.
//     int digit;
//     int count = 0;
//     for(int i = 0; i<size; i++){
//         digit = array[i];
//         for(int j = 0; i<size ; j++){

//             if(digit==array[j]){
//                 count++;
//             }
        
//         }
//         if(count == 1){
//             break;
//         }
//         count = 0;
//     }
//     return digit;
// }

int unique(int array[],int size){
    int ans = 0;
    for(int i = 0; i<size; i++){                // ^ is xor function. o^n = n . and n^n = 0;  lec 10 love babbar.
        ans = ans^array[i];
    }
    return ans;
}

// find the unique number.


int main() 
{
    int n;
    cout<<"enter n and size is (2n+1): ";
    cin>>n;

    int size = 2*n+1;

    int array[size];

    for(int i = 0; i<size; i++){
        cin>>array[i];
    } 

    cout<<"start"<<endl;
    int ans = unique(array,size);
    cout<<ans<<endl; 
    cout<<"end"<<endl;

    return 0;
}