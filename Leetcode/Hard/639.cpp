const int mod = 1e9 + 7;

void add(int &a, int b){
    a = (a * 1LL + b) % mod;
}

int mul(int a, int b){
    return (a * 1LL * b) % mod;
}

class Solution {
public:
    
    int n;
    string s;
    vector<int> dp;
    
    int ways(int i){
        // base case
        if(i < 0) return 1;
        
        int &ans = dp[i];
        if(ans != -1) return dp[i];
        
        ans = 0;
        if(s[i] == '*'){
            add(ans, mul(9, ways(i - 1))); // one digit
            if(i - 1 > -1){ // two digit
                if(s[i - 1] == '1'){
                    add(ans,mul(9, ways(i - 2)));
                }
                else if(s[i - 1] == '2'){
                    add(ans, mul(6, ways(i - 2)));
                }
                else if(s[i - 1] == '*'){
                    add(ans, mul(15, ways(i - 2)));
                }
            }
        }
        else{
            if(s[i] != '0') ans = ways(i - 1); // one digit
            
            // two digit
            if(i - 1 > -1 and s[i - 1] == '1') add(ans, ways(i - 2));
            else if(i - 1 > -1 and s[i - 1] == '2' and s[i] < '7')
                add(ans, ways(i - 2));
            else if(i - 1 > -1 and s[i - 1] == '*'){
                add(ans, ways(i - 2));
                if(s[i] < '7') add(ans, ways(i - 2));
            }
        }
        
        return dp[i] = ans;
    }
    
    int numDecodings(string s) {
        this->s = s;
        n = s.size();
        dp = vector<int>(n + 1, -1);
        return ways(n - 1);
    }
};