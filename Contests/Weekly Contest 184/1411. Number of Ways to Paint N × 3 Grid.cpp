// https://leetcode.com/contest/weekly-contest-184/problems/number-of-ways-to-paint-n-3-grid/

const int mod = 1e9 + 7;

class Solution {
public:
    int numOfWays(int n) {
        if(n == 1) return 12;
        
        vector<pair<long long, long long>> dp(n + 1);
        dp[1].first = dp[1].second = 6;
        
        for(int i = 2; i < n; i++){
            dp[i].first = (dp[i - 1].first * 3LL + dp[i - 1].second * 2LL) % mod;
            dp[i].second = (dp[i - 1].first * 2LL + dp[i - 1].second * 2LL ) % mod;
        }
        
        int ans = (dp[n - 1].first * 5 + dp[n - 1].second * 4 ) % mod;
        return ans;
    }
};