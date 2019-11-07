//  https://leetcode.com/problems/word-ladder-ii/


class Solution {
public:
    
    int difference(string a, string b){
        int ct = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i]) ct++;
        }
        return ct;
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        bool found = false;
        for(int i = 0; i < wordList.size(); i++) if(wordList[i] == beginWord) {
            found = true;
            break;
        }
        if(!found)  wordList.push_back(beginWord);
        map<string, int> id;
        int n = wordList.size();
        // creating a map of words to id to create a graph
        for(int i = 0; i < n; i++){
            id[wordList[i]] = i;
        }
        if(id.find(endWord) == id.end()) return {};
        int sourceId = id[beginWord], destinationId = id[endWord];
        
        vector<vector<int>> adj(n);
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(difference(wordList[i], wordList[j]) == 1){
                    int id1 = id[wordList[i]], id2 = id[wordList[j]];
                    adj[id1].push_back(id2);
                    adj[id2].push_back(id1);
                }
            }
        }
        
        queue<pair<int, vector<int>>> q;
        q.push({sourceId, {sourceId}});
        
        vector<vector<int>> temp;
        
        vector<bool> visited(n);
        visited[sourceId] = 1;
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int currentId = it.first;
            
            
            visited[currentId] = 1;
            if(currentId == destinationId){
                if(temp.size() == 0) temp.push_back(it.second);
                else{
                    if(temp[0].size() > it.second.size()) {
                        temp.clear();
                        temp.push_back(it.second);
                    }   
                    else if(temp[0].size() == it.second.size()){
                        temp.push_back(it.second);
                    }
                }
                continue;
            }
            
            for(auto x : adj[currentId]){
                if(!visited[x]){
                    vector<int> path = it.second;
                    path.push_back(x);
                    q.push({x, path});
                }
            }
        }
        
        vector<vector<string>> output;
        for(auto x: temp){
            vector<string> abc;
            for(auto y : x){
                abc.push_back(wordList[y]);
            }
            output.push_back(abc);
        }
        return output;
    }
};