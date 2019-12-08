// https://www.interviewbit.com/problems/dungeon-princess/

// dp[i][j] -> minimum initial health required at position i,j

vector<vector<int>> dp, a;
int n, m;
const int inf = 1e9;

int go(int i, int j){
    if(i == n - 1 and j == m - 1){
        return (a[i][j] > 0 ? 1 : abs(a[i][j]) + 1);
    }
    if(i >= n or j >= m) return inf;
    
    int &ans = dp[i][j];
    if(ans != -1) return ans;
    
    int val = min(go(i + 1, j), go(i, j + 1));
    ans = max(val - a[i][j], 1);
    
    return ans;
}

int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    n = A.size(), m = A[0].size();
    a = A;
    dp = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));
    
    return go(0, 0);
}
