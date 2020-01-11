// https://leetcode.com/problems/distinct-echo-substrings/

class Solution {
public:
    int distinctEchoSubstrings(string text) {
        set<string> st;
        int n = text.size();
        for(int i = 0; i < n; i++){
            string t;
            int m = 0;
            for(int j = i; j < n; j++){
                t += text[j];
                m++;
                
                if(m + j >= n) break;
                
                bool ck = 1;
                int id = j + 1, k = i;
                while(k <= j){
                    if(text[id++] != text[k++]) {
                        ck = 0;
                        break;
                    }
                }
                if(ck) st.insert(t);
            }
        }
        return st.size();
    }
};