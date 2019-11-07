class Solution {
public:
    
    int n;
    set<string> dic;
    vector<int> dp;
    string s;
    
    int go(int i) {
        if (i == n) return 1;
        if (dp[i] != -1) return dp[i];
        string prefix;
        for (int j = i; j < n; j++) {
            prefix += s[j];
            if (dic.count(prefix)) {
                if (go(j+1)) return dp[i] = 1;
            }
        }
        return dp[i] = 0;
    }
    
    bool wordBreak(string a, vector<string>& wordDict) {
        s = a;
        dic = set<string>(wordDict.begin(), wordDict.end());
        n = s.size();
        dp = vector<int>(n+1, -1);
        return go(0);
    }
};