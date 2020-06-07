// https://leetcode.com/contest/weekly-contest-192/problems/paint-house-iii/


class Solution {
public:
    
    int m, n, target;
    vector<int> house;
    vector<vector<int>> cost;
    
    int dp[110][23][110];
    
    int go(int id, int prevcolor, int currTarget){
        
        if(id == m){
            if(currTarget != target) return 1e6;
            return 0;
        }
        
        if(dp[id][prevcolor][currTarget] != -1) return dp[id][prevcolor][currTarget];
        
        int ans = 1e6;
        
        if(house[id] > 0){
            if(house[id] == prevcolor) ans = go(id + 1, house[id], currTarget);
            else if(currTarget < target) ans = go(id + 1, house[id], currTarget + 1);
            
            return dp[id][prevcolor][currTarget] = ans;
        }
        
        for(int i = 1; i <= n; i++){
            if(i == prevcolor){
                ans = min(ans, go(id + 1, i, currTarget) + cost[id][i - 1]);
            }
            else if(currTarget < target) ans = min(ans, go(id + 1, i, currTarget + 1) + cost[id][i - 1]);
        }
        
        return dp[id][prevcolor][currTarget] = ans;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost1, int m1, int n1, int target1) {
        m = m1, n = n1, target = target1;
        house = houses;
        cost = cost1;

        memset(dp, -1, sizeof dp);
        
        int ans = go(0, 22, 0);
        if(ans >= 1e6) return -1;
        return ans;
    }
};