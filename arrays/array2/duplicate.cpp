#include<iostream>
using namespace std;

// get the the number which came twice while entering the numbers into array from 1 to n-1 and an extra number in between.
// https://leetcode.com/problems/find-the-duplicate-number/


// the most important thing to understand in this solution is that we are applying 
// binary search on the range [1,n] not on the array.
// we take mid of 1 and n, if elements in the array have more values which are less than
// the mid then there is an extra value between [1,mid] hence the answer lie left
// of mid and in the other case at right of mid, [mid,n].

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 0;

            // Count the numbers less than or equal to mid
            for (int num : nums) {
                if (num <= mid) {
                    count++;
                }
            }

            // If count is greater than mid, the duplicate lies in the left half
            if (count > mid) {
                right = mid;
            } else { // Otherwise, it lies in the right half
                left = mid + 1;
            }
        }

        return left;
    }
};
  