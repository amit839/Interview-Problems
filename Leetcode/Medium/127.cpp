// https://leetcode.com/problems/word-ladder/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        
        if(s.find(endWord) == s.end()) return 0;
        
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        
        unordered_set<string> visited;
        visited.insert(beginWord);
        
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            
            if(x.first == endWord) return x.second;
            for(int i = 0; i < x.first.size(); i++){
                string t = x.first;
                for(char ch = 'a'; ch <= 'z'; ch++){
                    t[i] = ch;
                    if(s.find(t) != s.end() and visited.find(t) == visited.end()){
                        q.push({t, x.second + 1});
                        visited.insert(t);
                    }
                }
            }
        }
        return 0;
    }
};