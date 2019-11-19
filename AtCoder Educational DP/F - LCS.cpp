// Problem Link : https://atcoder.jp/contests/dp/tasks/dp_f

#include <bits/stdc++.h>
using namespace std;

// Backtracking the Dp table to find the longest common subsequence
string backTrack(int i, int j, string& a, string& b, vector<vector<int>>& dp){

    if(i < 1 or j < 1) return "";

    if(a[i - 1] == b[j - 1]) return backTrack(i - 1, j - 1, a, b, dp) + a[i - 1];

    if(dp[i - 1][j] == dp[i][j]) return backTrack(i - 1 ,j, a, b, dp);
    else return backTrack(i, j - 1, a, b, dp);
}

// Using Iterative Dynmaic programming to calculate Longest Common Subsequence
string lcs(string a, string b){
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    return backTrack(n , m, a, b, dp);
}

void testcase(){
    string a, b;
    cin >> a >> b;
    cout << lcs(a, b);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

#ifdef AKP
    freopen("in.txt", "r", stdin);
#endif

    int t = 1;
    //cin >> t;
    while(t--){
        testcase();
        cout << '\n';
    }
    return 0;
}