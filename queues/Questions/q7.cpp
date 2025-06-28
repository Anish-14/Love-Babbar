#include <iostream>
using namespace std;

// sliding window maximum
// https://leetcode.com/problems/sliding-window-maximum/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // stores indices of useful elements in decreasing order
        vector<int> ans;

        for (int i = 0; i < nums.size(); ++i) {
            // Remove elements outside the current window
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Remove all elements smaller than current from the back
            while (!dq.empty() && nums[i] >= nums[dq.back()])
                dq.pop_back();

            dq.push_back(i);

            // First k-1 elements form the initial window, so start recording answers from index k-1
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};


