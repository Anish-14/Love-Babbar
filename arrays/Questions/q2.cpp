#include<iostream>
#include<vector>
using namespace std;

// Move zeroes to end.
// https://leetcode.com/problems/move-zeroes/description/


// in this problem we will move nonZero elements to the left rather than moving zero to the right side to maintain the order also.
void moveZeroes(vector<int> & nums){
    int nonZero = 0;        // shows that the first nonzero value should come at this index

    for(int i = 0; i<nums.size(); i++){

        // find the nonzero values in the array and when found place them at their right place
        // by the help of nonZero variable.
        // and ignore the zeroes which comes in the path, move to the next element in the array.
        if(nums[i] != 0){
            swap(nums[i], nums[nonZero]);
            nonZero++;
        }
    }

}



