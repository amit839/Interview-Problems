// https://leetcode.com/problems/jump-game/

// Method 1 - Time Complexity O(N ^ 2), Space Complexity O(N)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n);
        dp[0] = 1;
        for(int i = 0; i < n; i++){
            if(!dp[i]) continue;
            for(int j = i + 1; j <= min(n - 1, i + nums[i]); j++){
                dp[j] = 1;
            }
        }
        return dp[n - 1];
    }
};

// Method 2 - Time Complexity O(N), Space Complexity O(1)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int count = nums[0];
        for(int i = 1; i < n; i++){
            if(count < 1) return false;
            count--;
            count = max(count, nums[i]);
        }
        return true;
    }
};