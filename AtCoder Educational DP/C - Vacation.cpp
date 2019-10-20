// https://atcoder.jp/contests/dp/tasks/dp_c

#include <bits/stdc++.h>
using namespace std;


void testcase(){
    int n;
    cin >> n;
    vector<vector<int>> input(3, vector<int>(n));
    for(int i = 0; i < n; i++){
        cin >> input[0][i] >> input[1][i] >> input[2][i];
    }

    vector<vector<int>> dp(3, vector<int>(n));

    for(int i = 0; i < 3; i++) dp[i][0] = input[i][0];

    for(int i = 1; i < n; i++){
        dp[0][i] = max(dp[1][i - 1], dp[2][i - 1]) + input[0][i];
        dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]) + input[1][i];
        dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]) + input[2][i];
    }
    cout << max({dp[0][n - 1], dp[1][n - 1], dp[2][n - 1]});
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

#ifdef AKP
    freopen("in.txt","r", stdin);
#endif

    int t = 1;
    //cin >> t;
    while(t--){
        testcase();
        cout << '\n';
    }
    return 0;
}