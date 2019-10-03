// Link to the problem : https://leetcode.com/problems/delete-operation-for-two-strings/

class Solution {
public:
    
    int go(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(i < 0 and j < 0) return 0;
        if(i < 0) return j + 1;
        if(j < 0) return i + 1;
        
        int &ret = dp[i][j];
        if(ret != INT_MAX) return ret;
        
        if(s[i] == t[j]){
            ret = go(i - 1, j - 1, s, t, dp);
        }
        else {
            ret = 1 + min(go(i , j - 1, s, t, dp), go(i - 1, j, s, t, dp));
        }
        
        return ret;
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        
        if(n < 1) return m;
        if(m < 1) return n;
        
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        
        go(n - 1, m - 1, word1, word2, dp);
        
        return dp[n - 1][m - 1];
    }
};