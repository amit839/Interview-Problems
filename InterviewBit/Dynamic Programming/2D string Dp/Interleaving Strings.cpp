// https://www.interviewbit.com/problems/interleaving-strings/

int n, m, l;
string a, b, c;

int go(int i, int j, int k, vector<vector<int>>& dp){
    if(k == l and i == n and j == m) return 1;
    if(k == l) return 0;
    int &ans = dp[i][j];
    if(ans != -1) return ans;
    
    if(i < n and j < m and a[i] == c[k] and b[j] == c[k]){
        ans = go(i + 1, j, k + 1, dp) | go(i, j + 1, k + 1, dp);
    }
    else if(i < n and a[i] == c[k]){
        ans = go(i + 1, j, k + 1, dp);
    }
    else if(j < m and b[j] == c[k]){
        ans = go(i, j + 1, k + 1, dp);
    }
    return ans;
}

int Solution::isInterleave(string A, string B, string C) {
    n = A.size(), m = B.size(), l = C.size();
    a = A, b = B, c = C;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    
    int ans = go(0, 0, 0, dp);
    return ans == -1 ? 0 : ans;
}
