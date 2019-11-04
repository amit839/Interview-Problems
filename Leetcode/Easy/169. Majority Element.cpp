//  https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0, previous = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] == previous) count++;
            else count--;
            if(count < 1) previous = nums[i], count = 1;
        }
        return previous;
    }
};