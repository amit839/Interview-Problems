// https://www.interviewbit.com/problems/length-of-longest-subsequence/

int Solution::longestSubsequenceLength(const vector<int> &A) {
    int n = A.size();
    
    if(n == 0) return 0;
    
    vector<int> dp1(n, 0), dp2(n, 0);
    
    dp1[0] = dp2[n - 1] = 1;
    
    for(int i = 1; i < n; i++){
        int ans1 = 1;
        for(int j = 0; j < i; j++){
            if(A[j] < A[i]){
                ans1 = max(ans1, dp1[j] + 1);
            }
        }
        dp1[i] = ans1;
    }
    
    for(int i = n - 2; i > -1; i--){
        int ans2 = 1;
        for(int j = n - 1; j > i; j--){
            if(A[j] < A[i]){
                ans2 = max(ans2, dp2[j] + 1);
            }
        }
        dp2[i] = ans2;
    }
   
    int ans = max(dp1[n - 1], dp2[0]);
    
    for(int i = 0; i < n; i++){
        ans = max(ans, dp1[i] + dp2[i] - 1);
    }
    
    return ans;
}