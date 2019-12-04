// https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-iii/

int Solution::maxProfit(const vector<int> &A) {
    int n = A.size();
    if(n == 0) return 0;
    
    vector<int> dp(n);
    int minval = A[0];
    for(int i = 1; i < n; i++){
        dp[i] = max(A[i] - minval, dp[i - 1]);
        minval = min(minval, A[i]);
    }
    int maxval = A[n - 1];
    int ans = 0;
    for(int i = n - 2; i > -1; i--){
        if(maxval > A[i]){
            ans = max(ans, dp[i - 1] + maxval - A[i]);
        }
        maxval = max(A[i], maxval);
    }
    return ans;
}
