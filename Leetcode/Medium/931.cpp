const int INF = 1e9;
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        vector<int> dp(A[0].begin(), A[0].end());
        
        for(int i = 1; i < n; i++){
            vector<int> newDp(n, INF);
            for(int j = 0; j < n; j++){
                newDp[j] = min(newDp[j], A[i][j] + min({dp[j],j - 1 > -1 ? dp[j - 1] : INF, j + 1 < n ? dp[j + 1] : INF}) );
            }
            dp = newDp;
        }
        return *min_element(dp.begin(), dp.end());
    }
};