#include<iostream>
using namespace std;

//print the pairs having sum equal to a particular no. "s".


// sorting is not correct in this answer.

// 5 0
// 2 -3 3 3 -2   input

// -3 3
// -3 3
// -2 2        output


int main()
 {
    int n;
    cout<<"enter size: ";
    cin>>n;

    int s; 
    cout<<"enter the value of sum: ";
    cin>>s;

    int array[n];

    for(int i = 0; i<n; i++){
        cin>>array[i];
    } 

    int i = 0;
    int element1,element2;

    while(i<n-1){
        element1 = array[i];
        for(int j = i+1; j<n; j++){
            element2 = array[j];
            if(element1+element2==s){  
               cout<<min(element1,element2)<<" ";
               cout<<max(element1,element2);
               cout<<endl;
            }
        }
        i++;
    }   
    return 0;
}

//m2 by babbar

// vector<int>ans;
// for(int i = 0; i<n; i++){

//     for(int j = i+1; j<n; j++){
//         if(arr[i]+arr[j]==s){
//             vector<int>temp;
//             temp.push_back(min(arr[i],arr[j])); 
//             temp.push_back(max(arr[i],arr[j]));
//             ans.push_back(temp);
//         }
//     }
// }
// sort(ans.begin(),ans.end());
// return ans;