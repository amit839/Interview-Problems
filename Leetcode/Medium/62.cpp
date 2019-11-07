class Solution {
public:
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n, vector<int>(m));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 and j == 0) dp[i][j] = 1;
                else dp[i][j] = (i - 1 > -1 ? dp[i - 1][j] : 0) + (j - 1 > -1 ? dp[i][j - 1] : 0);
            }
        }
        return dp[n - 1][m - 1];
    }
};