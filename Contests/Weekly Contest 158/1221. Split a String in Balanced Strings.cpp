// https://leetcode.com/contest/weekly-contest-158/problems/split-a-string-in-balanced-strings/


class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0, ct = 0;
        for(auto x: s){
            if(x == 'L') ct++;
            else ct--;
            if(ct == 0) ans++;
        }
        return ans;
    }
};