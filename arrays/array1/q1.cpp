// https://leetcode.com/problems/summary-ranges/?envType=problem-list-v2&envId=array

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> vec;
        if (n == 0) return vec; 
        int a = 0;
        int b = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                b = i;
            } else {
                if (a == b) {
                    vec.push_back(to_string(nums[a]));
                } else {
                    vec.push_back(to_string(nums[a]) + "->" + to_string(nums[b]));
                }
                a = i;
                b = i;
            }
        }
        if (a == b) {
            vec.push_back(to_string(nums[a]));
        } else {
            vec.push_back(to_string(nums[a]) + "->" + to_string(nums[b]));
        }
        return vec;
    }
};