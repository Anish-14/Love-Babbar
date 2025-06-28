#include<iostream>
using namespace std;


// Find the valu of the smallest element (pivot) in a rotated sorted array
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

// we can also modify this question to ask the index instead of the value

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(nums[n-1] >= nums[0]){
            return nums[0];
        }

        int s = 0; 
        int e = n-1;
        int mid = s + (e-s)/2;

        // let us break the array in two sorted arrays at the pivot point it breaks in two
        // now if the mid lies in first sorted part then we push it to right and vice versa.
        while(s < e){
            if(nums[mid] >= nums[0]){ // yani agar hum first sorted array me hai, then solution lies in right direction
                s = mid + 1;
            }
            else{
                e = mid;
            }
            mid = s + (e-s)/2;
        }
        return nums[s];
    }
};