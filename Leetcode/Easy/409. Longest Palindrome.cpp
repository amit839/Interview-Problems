// https://leetcode.com/problems/longest-palindrome/

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> mp;
        for(auto x: s) mp[x]++;
        
        int Sum = 0;
        
        bool isoddPresent = false;
        for(auto x: mp){
            if(x.second & 1) {
                isoddPresent = true;
            }
            Sum += (x.second / 2) * 2;
        }
        return Sum + isoddPresent;
        
    }
};