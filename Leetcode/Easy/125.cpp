class Solution {
public:
    
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        for(int i = 0; i < n; i++) if(isalpha(s[i])) s[i] = tolower(s[i]);
        while(i < j){
            while(i < n and !isalnum(s[i])) i++;
            while(j > -1 and !isalnum(s[j])) j--;
            if(i > j) break;
            if(s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }
};