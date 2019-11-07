// Link to the problem : https://leetcode.com/problems/longest-common-subsequence/

class Solution {
public:
    
    int go(int i, int j , string &s, string &t, vector<vector<int>> &dp){
        if(i < 0 or j < 0) return 0;
        
        int &ret = dp[i][j];
        if(ret != -1) return ret;
        
        if(s[i] == t[j]){
            ret = 1 + go(i - 1, j - 1, s, t, dp);
        }
        else {
            ret = max(go(i, j - 1, s, t, dp), go(i - 1, j, s, t, dp));
        }
        return ret;
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        go(n - 1, m - 1, text1, text2, dp);
        
        return dp[n - 1][m - 1];
    }
};