class Solution {
public:
    
    int n, m;
    string s, p;
    vector<vector<int>> dp;
    
    string transform(string p){
        string s;
        int n = p.size();
        s += p[0];
        for(int i = 1; i < n; i++){
            if(p[i] == '*' and s[(int)s.size() - 1] == '*') continue;
            s += p[i];
        }
        return s;
    }
    
    
    bool go(int i, int j){
        if(i < 0 and j < 0) return 1;
        
        if(i < 0){
            return p[j] == '*' ? go(i, j - 2) : 0;
        }
        if(j < 0) return 0;
        
        int &ans = dp[i][j];
        if(ans != -1) return ans;
        
        if(s[i] == p[j] or p[j] == '.') ans = go(i - 1, j - 1);
        else if(p[j] != '*') ans = false;
        else {
            ans = go(i, j - 1) || go(i, j - 2);
            if(j - 1 > -1 and (s[i] == p[j - 1] or p[j - 1] == '.')) ans |= go(i - 1, j);
        }
        return ans;
    }
    
    bool isMatch(string s, string p) {
        this->p = transform(p);
        this->s = s;
        n = s.size(), m = p.size();
        dp = vector<vector<int>>(n, vector<int>(m, -1));
        return go(n - 1, m - 1);
    }
};