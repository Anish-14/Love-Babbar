#include<iostream>
using namespace std;

// search in rotated sorted array
// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int getPivot(vector<int> &nums, int n){
        if(nums[n-1] >= nums[0]){
            return 0;
        }
        int s = 0; 
        int e = n-1;
        int mid = s + (e-s)/2;

        while(s < e){
            if(nums[mid] >= nums[0]){
                s = mid + 1;
            }
            else{
                e = mid;
            }
            mid = s + (e-s)/2;
        }
        return s;
    }

    int binarySearch(vector<int> &nums, int s, int e, int k){
        int mid = s + (e-s)/2;
        while(s <= e){
            if(nums[mid] == k){
                return mid;
            }
            else if(nums[mid] > k){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
            mid = s + (e-s)/2;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = getPivot(nums,n);

        if(target >= nums[pivot] && target <= nums[n-1]){
            return binarySearch(nums,pivot,n-1,target);
        }
        else{
            return binarySearch(nums,0,pivot-1,target);
        }
    }
};