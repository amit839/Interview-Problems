//`https://leetcode.com/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroPos = -1;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == 0) {
                if(zeroPos == -1) zeroPos = i;
            }
            else if(zeroPos != -1){
                swap(nums[i], nums[zeroPos]);
                zeroPos++;
            }
        }
    }
};