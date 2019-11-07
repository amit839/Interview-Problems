// Link to the problem statement : https://leetcode.com/problems/jump-game-ii

// Method 1 : Time Complexity : O(N * N)

const int MAX = 1e9;
 
int Solution::jump(vector<int> &A) {
    int n = A.size();
    vector<int> dp(n, MAX);
    dp[0] = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j <= min(n - 1, i + A[i]); j++){
            dp[j] = min(dp[j], dp[i] + 1);
        }
    }
    return dp[n - 1] >= MAX ? -1 : dp[n - 1];
}

// Method 2 : Time Complexity : O(N)

class Solution {
public:
    int jump(vector<int>& A) {
        int n = A.size();
        int jumps = 0, curEnd = 0, curFarthest = 0;
        for (int i = 0; i < n - 1; i++) {
            curFarthest = max(curFarthest, i + A[i]);
            if (i == curEnd) {
                jumps++;
                curEnd = curFarthest;
            }
        }
        return jumps;
    }
};