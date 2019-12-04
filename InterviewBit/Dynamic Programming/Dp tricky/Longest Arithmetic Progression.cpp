// https://www.interviewbit.com/problems/longest-arithmetic-progression/

int Solution::solve(const vector<int> &a) {
    int n=a.size();
    
    int ans=1;
    
    vector<map<int,int>> dp(n);
    
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            int d=a[i]-a[j];
            
            dp[i][d]=max(dp[i][d],1+ max(dp[j][d], 1));
            
            ans=max(ans,dp[i][d]);
        }
    }
    
    return ans;
}