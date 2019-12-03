// https://www.interviewbit.com/problems/ways-to-decode/

int Solution::numDecodings(string A) {
    int n = A.size();
    vector<int> dp(n + 1);
    dp[n] = 1;
    for(int i = n - 1; i >= 0; i--){
        if(A[i] == '0'){
            dp[i] = 0;
            continue;
        }
        dp[i] += dp[i + 1];
        if(i + 1 < and (stoi(A.substr(i, 2)) < 27)) dp[i] += dp[i + 2];
    }
    return dp[0];
}
