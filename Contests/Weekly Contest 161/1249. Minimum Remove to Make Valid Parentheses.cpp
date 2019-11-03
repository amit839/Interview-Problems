//  https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        
        set<int> valid;
        stack<int> st;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                if(!st.empty()){
                    valid.insert(st.top());
                    st.pop();
                    valid.insert(i);
                }
            }
        }
        string output;
        for(int i = 0; i < n; i++){
            if(s[i] == '(' or s[i] == ')'){
                if(valid.find(i) != valid.end()) output += s[i];
            }
            else output += s[i];
        }
        return output;
    }
};