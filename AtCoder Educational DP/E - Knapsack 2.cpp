// Problem Link : https://atcoder.jp/contests/dp/tasks/dp_e

#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e16;

long long go(int i, int v, vector<int>& weights, vector<int>& values, vector<vector<long long>>& dp) {
    if (v < 0) return INF;
    if (v == 0) return 0;
    if (i == weights.size()) return INF;
    long long& ans = dp[i][v];
    if (ans != -1) return ans;
    return ans = min(go(i + 1, v, weights, values, dp), weights[i] + go(i + 1, v - values[i], weights, values, dp));
}

void testcase() {
    int n, w;
    cin >> n >> w;
    vector<int> weights(n), values(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i] >> values[i];
    }
    long long sum_value = accumulate(values.begin(), values.end(), 0LL);
    vector<vector<long long>> dp(n, vector<long long>(sum_value + 1, -1));
   
 	// dp[i][v] -> min. weight of items to achieve value exactly v using any subset of items [i...n-1]
    // dp[0][v] -> min. weight of items to achieve value exactly v using any subset of items [0...n-1]
    
	for (long long v = sum_value; v >= 0; v--) {
        go(0, v, weights, values, dp);
    }
    long long ans = 0;
    for (long long v = sum_value; v >= 0; v--) {
        if (dp[0][v] <= w) {
            ans = v;
            break;
        }
    }
    cout << ans << "\n";
}

int main(){
#ifdef AKP
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false), cin.tie(0);

    int t = 1;
    //cin >> t;
    while(t--){
    	testcase();
    }
    return 0;
}
