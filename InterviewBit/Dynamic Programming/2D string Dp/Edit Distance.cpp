// https://www.interviewbit.com/problems/edit-distance/

int Solution::minDistance(string A, string B) {
    int n = A.size(), m = B.size();
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for(int i = 0; i <= n; i++) dp[i][0] = i;
    for(int j = 0; j <= m; j++) dp[0][m] = j;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));            
        }
    }
    return dp[n][m];
}


