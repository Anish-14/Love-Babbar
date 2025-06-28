//  https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // it's like we are saying that there are only two types of int in the array
        // when its the majority one then we increase the freq and otherwise decrease it
        // and as more than n/2 times the majority number has occur 
        // we will change the majority element (res) only when the net freq(majority) will become 0
        

        // res will save the curr majority element
        int res = 0;
        int majority = 0;       // this will save the net freq of the majority element
        
        for (int num : nums) {
            if (majority == 0) {
                res = num;
            }
            
            if(num == res){
                majority += 1;
            }
            else{
                majority += -1;
            }
        }
        
        return res; 
    }
};