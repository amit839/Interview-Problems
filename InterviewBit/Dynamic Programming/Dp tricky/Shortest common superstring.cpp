// https://www.interviewbit.com/problems/shortest-common-superstring/

int n, inf;

vector<vector<int>> common, dp;
vector<string> a;

int get_len(string& a, string& b){
    int n = a.size();
    int m = b.size();
    int i = 0, j = 0;

    while (i < n) {
        if (j == m) j = 0;

        if (a[i] == b[j]) {
            i++;
            j++;
        }else {
            if (j == 0) i++;

            j = 0;
        }
    }

    return j;
}

// dp[i][j] -> minimum size to merge j strings ending with i

int go(int i, int mask) {
    if (__builtin_popcount(mask) == n) return 0;

    int& ans = dp[i][mask];
    if (ans != -1) return ans;

    ans = inf;

    for (int j = 0; j < n; j++) {
        if (mask & (1 << j)) continue;
        if (j == i) continue;
        ans = min(ans, go(j, mask | (1 << j)) + ((int)a[j].size() - common[i][j]));
    }

    return ans;
}

int Solution::solve(vector<string> &A) {
    
    a.clear();
    dp.clear();
    common.clear();

    a = A;
    n = a.size();

    common = vector<vector<int>>(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            common[i][j] = get_len(a[i], a[j]);
            common[j][i] = get_len(a[j], a[i]);
        }
    }

    dp = vector<vector<int>>(n, vector<int>(1 << n, -1));

    int ans = 0;
    for (string e : a) ans += e.size();
    inf = ans;

    for (int i = 0; i < n; i++) {
        ans = min(ans, (int)a[i].size() + go(i, (1 << i)));
    }

    return ans;
}