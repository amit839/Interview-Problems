// link to the problem statement : https://leetcode.com/contest/weekly-contest-151/problems/compare-strings-by-frequency-of-the-smallest-character/

class Solution {
public:
    int f(string s){
        int freq[26] = {0};
        for(auto x: s) freq[x - 'a']++;
        for(int i = 0; i < 26; i++) if(freq[i] > 0) return freq[i];
        return 0;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> output, rhs;
        for(auto x: words){
            rhs.push_back(f(x));
        }
        sort(rhs.begin(), rhs.end());
        int n = rhs.size();
        for(auto x: queries){
            int val = f(x);
            bool f = 1;
            for(int i = 0; i < n; i++){
                if(rhs[i] > val){
                    output.push_back(n - i);
                    f = 0;
                    break;
                }
            }
            if(f) output.push_back(0);
        }
        return output;
    }
};