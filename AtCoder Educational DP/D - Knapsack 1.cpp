// https://atcoder.jp/contests/dp/tasks/dp_d

#include <bits/stdc++.h>
using namespace std;

long long go(int currentIndex, vector<int>& values, vector<int>& weights, int capacity, vector<vector<long long>>& dp){

    if(capacity <= 0 or currentIndex >= values.size()) return 0;

    long long &ans = dp[currentIndex][capacity];
    if(ans != -1) return ans;

    long long profit1 = 0;
    if(capacity - weights[currentIndex] >= 0){
        profit1 = go(currentIndex + 1,  values, weights, capacity - weights[currentIndex], dp) + values[currentIndex];
    }
    long long profit2 = go(currentIndex + 1, values, weights, capacity, dp);
    ans = max(profit1, profit2);

    return ans;
}

void testcase(){
    int n, w;
    cin >> n >> w;

    vector<int> values(n), weights(n);
    for(int i = 0; i < n; i++) cin >> weights[i] >> values[i];

    vector<vector<long long>> dp(n + 1, vector<long long>(w + 1, -1));
    go(0, values, weights, w, dp);
    cout << dp[0][w];
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
