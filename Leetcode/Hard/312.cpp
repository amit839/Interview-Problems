// Link to the problem statement : https://leetcode.com/problems/burst-balloons/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        
        vector<vector<int>> dp(n, vector<int>(n));
        
        for(int l = n - 1; l >= 0; l--){
            for(int r = l; r < n; r++){
                for(int i = l; i <= r; i++){
                    dp[l][r] = max(dp[l][r],
                                   nums[i] * (l == 0 ? 1 : nums[l - 1]) * (r == n - 1 ? 1 :nums[r + 1]) + (i == n - 1 ? 0 : dp[i + 1][r]) + (i == 0 ? 0 : dp[l][i - 1])
                                   );
                }
            }
        }
        return dp[0][n - 1];
    }
};