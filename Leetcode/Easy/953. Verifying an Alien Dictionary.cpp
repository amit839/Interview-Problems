// Link to the problem statement : https://leetcode.com/problems/verifying-an-alien-dictionary/

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> mp;
        int n = order.size(), m = words.size();
        for(int i = 0; i < n; i++){
            mp[order[i]] = i;
        }
        
        for(int i = 0; i < m - 1; i++){
            string word1 = words[i], word2 = words[i + 1];
            int k = min(word1.size(), word2.size());
            bool f = 0;
            for(int j = 0; j < k; j++){
                if(word1[j] != word2[j]){
                    if(mp[word1[j]] > mp[word2[j]]) return false;
                    f = 1;
                    break;
                }
            }
            if(!f){
                if(word1.size() > word2.size()) return false;
            }
        }
        return true;
    }
};
