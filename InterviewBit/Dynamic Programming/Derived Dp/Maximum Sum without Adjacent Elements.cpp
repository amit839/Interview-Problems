// https://www.interviewbit.com/problems/max-sum-without-adjacent-elements/

int go(int i, int j, vector<vector<int> >& arr, vector<vector<int>>& dp) {
    if (j < 0) return 0;
    if (j == 0) {
        return arr[i][j];
    }
    int& ret = dp[i][j];
    if (ret != -1) return ret;
    int ans1 = arr[i][j] + max(go(0, j - 2, arr, dp), go(1, j - 2, arr, dp));
    int ans2 = max(go(0, j - 1, arr, dp), go(1, j - 1, arr, dp));
    ret = max(ans1, ans2);
    return ret;
}

int Solution::adjacent(vector<vector<int> > &A) {
    int m = A[0].size();
    vector<vector<int>> dp(2, vector<int>(m, -1));
    
    return max(go(0, m - 1, A, dp), go(1, m - 1, A, dp));
}