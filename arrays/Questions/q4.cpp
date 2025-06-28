#include<iostream>
#include<vector>
using namespace std;

// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/
// check if rotated and sorted array

// beatiful solution
bool check(vector<int>& nums) {
        int cnt = 0;
        // we'll count ki successive number ek baar hi chhota aaye agar ek se jyaada
        // aa rha hai then problem hai nhi to sab thik hai
        for(int i=1;i<nums.size();i++) {
            if(nums[i] < nums[i-1])
                cnt++;
        }
        // humne last wala circle pura kar liya is check se
        if(nums[nums.size()-1] > nums[0])
            cnt++;
        // less than is used here to cater the situation where all elements are equal.
        return cnt<=1;          // if count <= 1 then return true else false
    }

