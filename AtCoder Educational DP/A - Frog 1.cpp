// https://atcoder.jp/contests/dp/tasks/dp_a

#include <bits/stdc++.h>
using namespace std;
 
 
void testcase(){
    int n;
    cin >> n;
    vector<int> input(n);
    for(int i = 0; i < n; i++) cin >> input[i];
 
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        for(int k = i + 1; k < min(i + 3, n); k++){
            dp[k] = min(dp[k], dp[i] + abs(input[i] - input[k]));
        }
    }
    cout << dp[n - 1];
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