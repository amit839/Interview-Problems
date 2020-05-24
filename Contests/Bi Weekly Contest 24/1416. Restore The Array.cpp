// https://leetcode.com/problems/restore-the-array/

class Solution {
public:
    const int mod = 1e9 + 7;
    
    
    int numberOfArrays(string s, int k) {
        int n = s.size();
        vector<long long> dp(n);

        for(int i = 0; i < n; i++){
            int ct = 0;
            long long val = 0;
        
            for(int j = i; j >= 0; j--){
        
                val += (s[j] - '0') * pow(10, ct);
                ct++;   
        
                if(ct > 10) break;
                if(s[j] == '0') continue;      // ignoring strings with leading zeros 
        
                if(val > 0 and val <= k){
                    dp[i] += (j - 1 > -1 ? dp[j - 1] : 1);
                    dp[i] %= mod;
                }
            }
        }
        
        return dp[n - 1] % mod;
    }
};
