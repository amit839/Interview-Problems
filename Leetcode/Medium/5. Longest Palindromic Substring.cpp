// Link to the problem statement: https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    
    void isPalindrome(string &s, int j, int k, int &n, int &ans, string &output){
        while(j >= 0 and k < n and s[j] == s[k]){
            j--;
            k++;
        }
        j++;
        if(k - j > ans){
            ans = k - j;
            output = s.substr(j, k - j);
        }
    }
    
    string longestPalindrome(string s) {
        int n = s.size();
        
        int ans = 0;
        string output;
        
        for(int i = 0; i < n; i++){
            
            isPalindrome(s, i, i + 1, n, ans, output);// check for even length palindrome
            isPalindrome(s, i - 1, i + 1, n, ans, output);// check for odd length palindrome
        }
        return output;
    }
};