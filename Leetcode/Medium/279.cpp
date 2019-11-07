class Solution {
public:
    const int INF = 1e6;
    int m;
    vector<int> coin;
    vector<vector<int>> dp;
    
    int go(int i, int sum) {
        if (sum == 0) return 0;
        if (sum < 0) return INF;
        if (i == m) return INF; // sum > 0
        int& ans = dp[i][sum];
        if (ans != -1) return ans;
        return ans = min({1+go(i, sum-coin[i]), 1+go(i+1, sum-coin[i]), go(i+1, sum)});        
    }
    int numSquares(int n){
        coin.clear();
        for(int i = 1; i * i <= n; i++){
            coin.push_back(i * i);
        }
        m = coin.size();
        dp = vector<vector<int>>(m + 1, vector<int>(n + 1, -1));
        return go(0, n);
    }
    
};
