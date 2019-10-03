// Link to the problem statement: https://leetcode.com/problems/palindromic-substrings/

class Solution {
public:
    
    void checkPalindrome(int i, int j, int& n, string &s, int &ans){
        while(i >=0 and j < n and s[i] == s[j]){
            i--, j++;
        }
        i++;
        ans += (j - i) / 2;
    }
    
    int countSubstrings(string s) {
        int n = s.size();
        int ans = n;
        
        for(int i = 0; i < n; i++){
            checkPalindrome(i, i + 1, n, s, ans);
            checkPalindrome(i - 1, i + 1, n, s, ans);
        }
        
        return ans;
    }
};