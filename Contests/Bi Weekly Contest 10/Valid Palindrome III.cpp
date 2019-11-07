Problem : Valid Palindrome III

Difficulty:Hard

Given a string s and an integer k, find out if the given string is a K-Palindrome or not.

A string is K-Palindrome if it can be transformed into a palindrome by removing at most k characters from it.
 

Example 1:

Input: s = "abcdeca", k = 2
Output: true
Explanation: Remove 'b' and 'e' characters.
 

Constraints:

1 <= s.length <= 1000
s has only lowercase English letters.
1 <= k <= s.length


class Solution {
public:
    int go(int i, int j , vector<vector<int>> &dp, string &s){
        if(i > j) return 0;
        if(i == j) return 1;
        
        int &ret = dp[i][j];
        if(ret != -1) return ret;
        
        if(s[i] == s[j]){
            ret = 2 + go(i + 1, j - 1, dp, s);
        }
        else ret = max(go(i + 1, j , dp, s), go(i, j - 1, dp, s));
        
        return ret;
    }
    
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if(n < 2) return n;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        go(0, n - 1, dp, s);
        
        return dp[0][n - 1];
    }
    bool isValidPalindrome(string s, int k) {
        int val = longestPalindromeSubseq(s);
        int n = s.size();
        
        return n - val <= k;
    }
};