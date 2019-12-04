// https://www.interviewbit.com/problems/n-digit-numbers-with-digit-sum-s-/

const int mod = 1e9 + 7;

vector<vector<int>> dp;

// dp[i][j] -> No. of ways for length i with sum j

int go(int index, int target){
    if(target < 0) return 0;
    if(index < 1){
        return target == 0;
    }
    
    int &ans = dp[index][target];
    if(ans != -1) return ans;
    
    ans = 0;
    for(int k = 0; k < 10; k++){
        if(index == 1 and k == 0) continue;
        ans = ((ans % mod) + (go(index - 1, target - k) % mod)) % mod;
    }
    return ans;
}

int Solution::solve(int n, int target) {
    dp = vector<vector<int>>(n + 1, vector<int>(target + 1, -1));
    return go(n, target);
}
