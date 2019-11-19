class Solution {
public:
    string s, p;
    vector<vector<int>> dp;
    int n, m;
    
    bool go(int i, int j){
        // base cases
        
        if(i < 0 and j < 0) return 1;
        if(i < 0){
            if(p[j] != '*') return 0;
            return go(i, j - 1);
        }
        if(j < 0) return 0;
        
        int &ans = dp[i][j];
        if(ans != -1) return ans;
        
        
        if (s[i] == p[j] or p[j] == '?')
            ans = go(i - 1, j - 1);

        else if(p[j] != '*') 
            ans = false;

        else {
            ans = go(i, j - 1) // zero use of *
                || go(i - 1, j); // one or more use of *
        }
        return ans;
    }
    
    bool isMatch(string s, string p) {
        this->s = s;
        this->p = p;
        n = s.size(), m = p.size();
        
        dp = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));
        
        return go(n - 1, m - 1);
    }
};


int Solution::isMatch(const string a, const string b) {
    int n = a.size(), m = b.size();
    vector<int> prev(m + 1), current(m + 1);
    
    prev[0] = 1;
    for(int j = 1; j <= m; j++) if(b[j - 1] == '*') prev[j] = prev[j - 1];
    
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i - 1] == b[j - 1] or b[j - 1] == '?') current[j] = prev[j - 1];
            else if(b[j - 1] != '*') current[j] = 0;
            else {
                current[j] = current[j - 1] | prev[j];
            }
        }
        prev = current;
    }
    
    return prev[m];
}
