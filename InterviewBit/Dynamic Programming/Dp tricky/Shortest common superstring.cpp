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

bool kmp(string& text, string& pattern) {
    int n = text.size(), m = pattern.size();

    vector<int> lps(m, 0);
    int i = 0, j = 1;
    while (j < m) {
        if (pattern[i] == pattern[j]) {
            lps[j] = i + 1;
            i++, j++;
        }
        else {
            if (i == 0) j++;
            else i = lps[i - 1];
        }
    }

    i = 0, j = 0;

    while (i < n and j < m) {
        if (text[i] == pattern[j]) i++, j++;
        else if(j > 0 ) j = lps[j - 1];
        else i++;
    }

    return j == m;
}

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
    n = 0;

    sort(A.begin(), A.end(), [](string x, string y)->bool{
        return x.size() < y.size();
    });

    vector<string> new_a;

    for(int i = 0; i < n; i++) {
        bool found = 0;
        for(int j = i + 1; j < n; j++) {
            if(kmp(A[j], A[i])){
                found = 1;
                break;
            }
        }
        if(!found) new_a.push_back(a[i]);
    }

    if(new_a.empty()){
        a = A;
    }else{
        a = new_a;
    }

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