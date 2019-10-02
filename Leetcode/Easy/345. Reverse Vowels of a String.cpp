class Solution {
public:
    
    bool isVowel(char ch){
        if(ch >= 'A' and ch <= 'Z') ch = ch - 'A' + 'a';
        return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u';
    }
    
    string reverseVowels(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        
        while(i < j){
            bool a = isVowel(s[i]), b = isVowel(s[j]);
            if(a and b){
                swap(s[i], s[j]);
                i++, j--;
            }
            else if(a){
                j--;
            }
            else if(b){
                i++;
            }
            else{
                i++, j--;
            }
        }
        return s;
    }
};