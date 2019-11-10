//  https://leetcode.com/contest/weekly-contest-162/problems/maximum-score-words-formed-by-letters/

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> mp(26);
        for(auto x: letters) mp[x - 'a']++;
        
        int n = words.size(), m = (1 << n), ans = 0;

        // Using bits jo generate all the possible subsets.
        for(int i = 1; i < m; i++){
            vector<int> freq(26);
            for(int j = 0; j < n; j++){
                if(i & (1 << j)){
                    for(auto x: words[j]) freq[x - 'a']++;
                }
            }
            int tans = 0;
            bool found = 1;
            for(int i = 0; i < 26; i++){
                if(freq[i] <= mp[i]){
                    tans += score[i] * freq[i];
                }
                else {
                    found = 0;
                    break;
                }
            }
            if(found) ans = max(ans, tans);
        }
        return ans;
    }
};