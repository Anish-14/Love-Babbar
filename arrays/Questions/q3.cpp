#include<iostream>
#include<vector>
using namespace std;

// rotate the array by k
// eg:- [1,5,3,8] and k = 2
// so the answer should be [3,8,1,5]
// https://leetcode.com/problems/rotate-array/description/

// the three ways to solve it
// 1. swap each last element to the start of the array, do this k times. O(k*n) && O(1)
// 2. make a duplicate array and add last k elements in it and then the first n-k elements. O(n) && O(n)
// 3. third is given below



void reverse(vector<int>& nums, int start, int end) {
  while (start < end)
    swap(nums[start++], nums[end--]);
}

// rotate the array
// then rotate first k elements
// then rotate the other n-k elements

void rotate(vector<int>& nums, int k) {
  int n = nums.size();
  k = k % n;
  reverse(nums, 0, n - 1);
  reverse(nums, 0, k - 1);
  reverse(nums, k, n - 1);
}

