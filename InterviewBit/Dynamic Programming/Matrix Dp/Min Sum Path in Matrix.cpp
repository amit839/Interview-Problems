// https://www.interviewbit.com/problems/min-sum-path-in-matrix/

// dp[i][j] -> minimum path from (0, 0) to (i, j)

int Solution::minPathSum(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();
    vector<vector<int>> dp(n, vector<int>(m));
    dp[0][0] = A[0][0];
    for(int i = 1; i < n; i++) dp[i][0] = A[i][0] + dp[i - 1][0];
    for(int j = 1; j < m; j++) dp[0][j] = A[0][j] + dp[0][j - 1];
    
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + A[i][j];
        }
    }
    return dp[n - 1][m - 1];
}
