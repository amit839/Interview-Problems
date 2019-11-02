// https://leetcode.com/problems/palindrome-removal/

class Solution {
public:
    
    int go(int i, int j, vector<int>& arr, vector<vector<int>>& dp){
        if(i > j) return 0;
        if(i == j) return 1;
        
        int &ans = dp[i][j];
        if(ans != -1) return ans;
        
        ans = 1 + go(i + 1, j, arr, dp);
        if(arr[i] == arr[i + 1]) ans = min(ans, 1 + go(i + 2, j, arr, dp));
        
        for(int k = i + 2; k <= j; k++){
            if(arr[i] == arr[k])
                ans = min(ans , go(i + 1, k - 1, arr, dp) + go(k + 1, j, arr, dp));
        }
        return ans;
    }
    
    int minimumMoves(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        return go(0, n - 1, arr, dp);
    }
};