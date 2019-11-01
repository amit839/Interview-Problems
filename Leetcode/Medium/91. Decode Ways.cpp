// https://leetcode.com/problems/decode-ways/

class Solution {
public:
    
    int ways(int i, string s, vector<int>& dp){
        if(i == s.size()) return 1;
        if(s[i] == '0') return 0;
        
        if(dp[i] != -1) return dp[i];
        
        int val = i < s.size() - 1 ? stoi(s.substr(i, 2)) : 27;
        int ans = ways(i + 1, s, dp);
        if(val < 27) ans += ways(i + 2, s, dp);
        
        return dp[i] = ans;
    }
    
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1, -1);
        return ways(0, s, dp);  
    }
};