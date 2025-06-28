#include<iostream>
using namespace std;

//find all the numbers in array which comes twice.
// https://leetcode.com/problems/find-all-duplicates-in-an-array/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        int n = nums.size();
        for(int i = 0; i<n; i++){
            int k = abs(nums[i]);
            if(nums[k-1] < 0){
                ans.push_back(k);
            }
            nums[k-1] *= -1;
        }
        
        return ans;
    }
};