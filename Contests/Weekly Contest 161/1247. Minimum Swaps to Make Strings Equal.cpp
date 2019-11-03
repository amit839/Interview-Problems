//  https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xcount = 0, ycount = 0;
        for(auto x: s1) if(x == 'x') xcount++; else ycount++;
        for(auto x: s2) if(x == 'x') xcount++; else ycount++;

        if((xcount & 1) or (ycount & 1)) return -1;

        int a = 0, b = 0, ans = 0, n = s1.size();

        for(int i = 0; i < n; i++){
            if(s1[i] == 'x' and s2[i] == 'y') a++;
            else if(s1[i] == 'y' and s2[i] == 'x') b++;
        }
        return (a + 1) / 2 + (b + 1) / 2;
    }
};