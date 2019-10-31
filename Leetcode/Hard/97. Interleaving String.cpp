// https://leetcode.com/problems/interleaving-string/

class Solution {
public:
    int n, m, l;
    string a, b, c;
    
    bool go(int i, int j, int k, vector<vector<int>>& dp){
        
        if(k == l and i == n and j == m) return true;
        
        if( dp[i][j] != -1) return dp[i][j];
        
        int& ans = dp[i][j];
        if(i < n and j < m and c[k] == a[i] and c[k] == b[j]){
            ans = go(i + 1, j, k + 1, dp) | go(i, j + 1, k + 1, dp);
        }
        else if(i < n and c[k] == a[i]){
            ans = go(i + 1, j, k + 1, dp);
        }
        else if(j < m and c[k] == b[j]){
            ans = go(i, j + 1, k + 1, dp);
        }
        else ans = false;
        
        return ans;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        n = s1.size(), m = s2.size(), l = s3.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        a = s1, b = s2, c = s3;
        
        return go(0, 0, 0, dp);
    }
};