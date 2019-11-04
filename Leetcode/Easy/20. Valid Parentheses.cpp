//  https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{' ) st.push(i);
            else {
                
                if(s[i] == ')'){
                    if(st.empty()) return false;
                    if(s[st.top()] == '(') st.pop();
                    else return false;
                }
                else if(s[i] == ']'){
                    if(st.empty()) return false;
                    if(s[st.top()] == '[') st.pop();
                    else return false;
                }
                else if(s[i] == '}'){
                    if(st.empty()) return false;
                    if(s[st.top()] == '{') st.pop();
                    else return false;
                }
            }
        }
        return st.empty();
    }
};