// Link to the problem statement : https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/


class Solution {
public:
    
    int total;
    
    long long go(int hat_id, int people_mask, vector<vector<long long>> &dp, vector<vector<int>>& hat){
        if(people_mask == total) return 1;
        
        if(hat_id > 40) return 0;
        
        long long &ans = dp[hat_id][people_mask];
        if(ans != -1) return ans;
        
        ans = go(hat_id + 1, people_mask, dp, hat);
        
        for(auto x: hat[hat_id]){
            if(people_mask & (1 << x)) continue;
            
            ans += go(hat_id + 1, people_mask | (1 << x), dp, hat);
            ans %= 1000000007;
        }
        
        return ans;
    }
    
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
        vector<vector<int>> hat(41);
        for(int i = 0; i < n; i++){
            for(auto x: hats[i]){
                hat[x].push_back(i);
            }
        }
        
        total = (1 << n) - 1;
        vector<vector<long long>> dp(41, vector<long long>(1 << 11, -1));
        
        return go(1, 0, dp, hat);
    }
};