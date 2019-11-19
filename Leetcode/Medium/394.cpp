class Solution {
public:
    map<int,int> pos;
    string s;
    int n;
    
    string decodeHelper(int i){
        
        if(i == n) return "";
        if(s[i] == ']') return "";
        
        string prefix;
        while( i < n and ((s[i] >= 'a' and s[i] <= 'z') or (s[i] >= 'A' and s[i] <='Z'))){
            prefix += s[i++];
        }
        if(prefix.size() > 0) return prefix + decodeHelper(i);
        
        int times = 0;
        while(s[i] != '['){
            times *= 10;
            times += (s[i] - '0');
            i++;
        }
        
        int end = pos[i];
        string temp = decodeHelper(i + 1);
        string output;
        for(int j = 0; j < times; j++){
            output += temp;
        }
        return output + decodeHelper(end + 1);
    }
    
    
    string decodeString(string s) {
        pos.clear();
        this->s = s;
        stack<int> st;
        n = s.size();
        
        if(n == 0) return "";
        
        for(int i = 0; i < n; i++){
            if(s[i] == '[') st.push(i);
            else if(s[i] == ']'){
                pos[st.top()] = i;
                st.pop();
            }
        }
        
        return decodeHelper(0); 
    }
};