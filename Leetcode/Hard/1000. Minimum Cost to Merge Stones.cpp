// Link to the problem statement: https://leetcode.com/problems/minimum-cost-to-merge-stones/

const int inf = 1e9;

int go(vector<int> &A, int i, int j, int m, int K, vector<int> &prefix, vector<vector<vector<int>>> &dp){
    if((j - i + 1 - m) % (K - 1) != 0) return inf;

    int &cost = dp[i][j][m];
    if(cost != inf) return cost;

    if(m == 1){
        cost = prefix[j + 1] - prefix[i] + go(A, i, j, K, K, prefix, dp);
    }
    else{
        for(int mid = i; mid < j; mid++){
            cost = min(cost, go(A, i, mid, 1, K, prefix, dp) + go(A, mid + 1, j, m - 1, K, prefix, dp));
        }
    }
    return cost;
}

class Solution {
public:
    int mergeStones(vector<int>& A, int K) {
        int n = A.size();
        if(n == 0 or ((n - 1) % (K - 1) != 0)) return -1;

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(K + 1, inf)));

        vector<int> prefix(n + 1);
        for(int i = 0; i < n; i++){
            prefix[i + 1] = prefix[i] + A[i];
        }
        for(int i = 0; i < n; i++){
            dp[i][i][1] = 0;
        }
        go(A, 0, n - 1, 1, K, prefix, dp);
        return dp[0][n - 1][1];
    }
};