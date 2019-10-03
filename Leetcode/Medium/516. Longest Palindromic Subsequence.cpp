// Link to the problem : https://leetcode.com/problems/longest-palindromic-subsequence/

class Solution {
public:
    
    int go(int i, int j , vector<vector<int>> &dp, string &s){
        if(i > j) return 0;
        if(i == j) return 1;
        
        int &ret = dp[i][j];
        if(ret != -1) return ret;
        
        if(s[i] == s[j]){
            ret = 2 + go(i + 1, j - 1, dp, s);
        }
        else ret = max(go(i + 1, j , dp, s), go(i, j - 1, dp, s));
        
        return ret;
    }
    
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if(n < 2) return n;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        go(0, n - 1, dp, s);
        
        return dp[0][n - 1];
    }
};