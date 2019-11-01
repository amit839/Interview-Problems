// 322. Coin Change

class Solution {
public:
    int n;
    const int MAX = 1e9;
    int go(int amount, vector<int>& coins, vector<int>& dp){
        if(amount < 0) return MAX;
        if(amount == 0) return 0;

        if(dp[amount] != -1) return dp[amount];

        int ans = MAX;

        for(auto x: coins){
            ans = min(ans, go(amount - x, coins, dp) + 1);
        }
        return dp[amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        vector<int> dp(amount + 1, -1);
        int ans = go(amount, coins, dp);
        return ans >= MAX ? -1 : ans;
    }
};