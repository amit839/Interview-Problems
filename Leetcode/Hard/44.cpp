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