// https://www.interviewbit.com/problems/unique-paths-in-a-grid/

// dp[i][j] -> unique paths from 0,0 to i, j

int n, m;
vector<vector<int>> dp, input;

int go(int i, int j){
    if(i < 0 or j < 0) return 0;
    if(input[i][j]) return 0;
    
    if(i == 0 and j == 0) return 1;

    int &ans = dp[i][j];
    if(ans != -1) return ans;
    
    return ans = go(i - 1, j) + go(i, j - 1);
}

int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    n = A.size(), m = A[0].size();
    input = A;
    dp = vector<vector<int>>(n, vector<int>(m, -1));
    return go(n - 1, m - 1);
}
