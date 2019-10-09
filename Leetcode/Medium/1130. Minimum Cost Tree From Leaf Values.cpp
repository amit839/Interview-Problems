// Link to the problem statement: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/

// dp[i][j] -> mininum cost to create a tree from i to j
// Base condition -> if(i >= j) return 0;

// Final Answer -> dp[0][n - 1];

class Solution {
public:
      
    int go(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& rangeMax){
        if(i >= j) return 0;
        
        int& ans = dp[i][j];
        if(ans != INT32_MAX) return ans;
        
        for(int k = i; k < j; k++){
            int leftans = go(i, k, dp, rangeMax);
            int rightans = go(k + 1, j, dp, rangeMax);
            ans = min(ans, leftans + rightans + (rangeMax[i][k] * rangeMax[k + 1][j]));
        }
        return ans;
    }
    
    
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> rangeMax(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            int maxVal = arr[i];
            for(int j = i; j < n; j++){
                maxVal = max(maxVal, arr[j]);
                rangeMax[i][j] = maxVal;
            }
        }
        
        vector<vector<int>> dp(n, vector<int>(n, INT32_MAX));
        
        go(0, n - 1, dp, rangeMax);
        
        return dp[0][n - 1];
    }
};