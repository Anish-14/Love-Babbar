#include<iostream>
using namespace std;

// https://leetcode.com/problems/3sum/description/
// 3 elements ka sum == 0 ho jaaye

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i = 0; i<n-2; i++){
            // skip the duplicate value, as we have processed for it before
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            // as the array is sorted so anything after positive will also be positive and we can not get sum == 0
            if(nums[i] > 0){
                break;
            }

            int left = i+1;
            int right = n-1;

            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0){
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while(left<right && nums[left] == nums[left+1]){
                        left++;
                    }
                    while(left<right && nums[right] == nums[right-1]){
                        right--;
                    }
                    left++;
                    right--;

                }
                else if(sum < 0){
                    left++;
                }
                else{
                    right--;
                }
            }
        }

        return ans;
    }
};