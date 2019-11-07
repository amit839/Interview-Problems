class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, runningSum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            runningSum += nums[i];
            ans = max({ans, runningSum, nums[i]});
            if(runningSum < 0) runningSum = max(0, nums[i]);
        }
        return ans;
    }
};