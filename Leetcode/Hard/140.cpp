class Solution {
public:
    
    struct Data {
        int can;
        vector<string> sen;
        Data(int a) {
            can = a;
        }
        Data(int a, vector<string> b) {
            can = a;
            sen = b;
        }
    };
    
    int n;
    set<string> dic;
    vector<Data> dp;
    string s;
    
    Data go(int i) {
        if (i == n){
            return Data(1, {""});
        }
        if (dp[i].can != -1) {
            return dp[i];
        }
        string prefix;
        vector<string> mySen;
        for (int j = i; j < n; j++) {
            prefix += s[j];
            if (dic.count(prefix)) {
                Data got = go(j+1);
                if (got.can) {
                    for (auto e : got.sen) {
                        if (e.empty()) mySen.push_back(prefix);
                        else mySen.push_back(prefix + " " + e);
                    }
                }
            }
        }
        return dp[i] = Data(!mySen.empty(), mySen);
    }
    
    vector<string> wordBreak(string a, vector<string>& wordDict) {
        s = a;
        dic = set<string>(wordDict.begin(), wordDict.end());
        n = s.size();
        
        dp = vector<Data>(n+1, {-1,{}});
        
        return go(0).sen;
    }
};