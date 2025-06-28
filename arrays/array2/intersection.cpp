#include<iostream>
using namespace std;
#include<set>
// intersection of two array with size m and n respectively.
// https://leetcode.com/problems/intersection-of-two-arrays/description/

int main()
{
    int n,m;
    cout<<"enter n: ";
    cin>>n;

    cout<<"enter m: ";
    cin>>m;

    int array[n];
    int arr[m];
    int ans[m];
    int l = 0;
    int digit;

    for(int i = 0; i<n; i++){
        cin>>array[i];
    }

    cout<<endl;

    for(int i = 0; i<m; i++){
        cin>>arr[i];
    } 

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(array[i]==arr[j]){
                digit = array[i];
                ans[l] = digit;
                arr[j] = INT_MIN;
                l++;
                break;
            }
        }
    }

    for(int n = 0; n<l; n++){
        cout<<ans[n]<<" ";
    }

    cout<<endl;
    return 0;
}

// another approach TC O(n) and SC O(n)

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, bool> mp;
        int n = nums1.size();
        int m = nums2.size();

        for(int i = 0; i<n; i++){
            if(mp[nums1[i]] == 0){
                // cout<<"anish"<<endl;
                mp[nums1[i]] = true;
            } 
        }

        // for(auto it: mp){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }

        for(int i = 0; i<m; i++){
            if(mp[nums2[i]] == 1){
                // cout<<"patel"<<endl;
                ans.push_back(nums2[i]);
                mp[nums2[i]] = 0;
            }
        }

        return ans;

    }
};



// another approach O(nlogn)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // by default set includes the elements in ascending order
        set<int> result; 
        sort(nums2.begin(),nums2.end());
        set<int> uniques(nums1.begin(),nums1.end());    // we've taken the unique element of nums1
        
        // now we are searching for each unique element from nums1 in num2, if we got it then we insert it in ans
        for(int num:uniques){
            if(binary_search(nums2.begin(),nums2.end(),num)){
                result.insert(num);
            }
        }
        return vector<int>(result.begin(), result.end());
    }
};  





// https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
// this is slightly different question
// for sorted arrays, O(nlogn) if the arrays are not given in sorted manner.

// int i = 0, j = 0;
// int arr1[n],arr2[m],ans[m];

// while(i<n && j<m){

//     if(arr1[i]==arr2[j]){
//         //put this value in ans
//         i++;
//         j++;
//     }
    
//     else if(arr1[i]<arr2[j]){
//         i++;
//     }

//     else
//     {
//         j++;
//     }
// }
// return ans;