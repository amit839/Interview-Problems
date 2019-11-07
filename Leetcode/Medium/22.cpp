// https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    
    void go(vector<string>& output, string ans, int open, int close){
        if(open < 0 or close < 0) return;
        if(open > close) return;
        if(open == 0 and close == 0) {
            output.push_back(ans);
            return;
        }
        go(output, ans + '(', open - 1, close);
        go(output, ans + ')', open, close - 1);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> output;
        go(output, "", n, n);
        return output;
    }
};