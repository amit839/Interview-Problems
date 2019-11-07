class Solution {
public:
    
    int n;
    string s;
    vector<int> dp;
    
    int ways(int i){
        // base case
        if(i < 0) return 1;
        
        if(dp[i] != -1) return dp[i];
        
        int ans = 0;
        if(s[i] != '0') ans = ways(i - 1);
        if(i - 1 > -1 and s[i - 1] == '1') ans += ways(i - 2);
        else if(i - 1 > -1 and s[i - 1] == '2' and s[i] < '7')
            ans += ways(i - 2);
        
        return dp[i] = ans;
    }
    
    int numDecodings(string s) {
        this->s = s;
        n = s.size();
        dp = vector<int>(n + 1, -1);
        return ways(n - 1);
    }
};