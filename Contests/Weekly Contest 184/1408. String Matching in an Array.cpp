// https://leetcode.com/contest/weekly-contest-184/problems/string-matching-in-an-array/

bool comp(string &a, string &b){
    if(a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

bool found(string &a, string &b){
    return b.find(a) != string::npos;
}
    
class Solution {
public:
    
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        
        vector<string> output;
        int n = words.size();
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(found(words[i], words[j])){
                    output.push_back(words[i]);
                    break;
                }
            }
        }
        
        return output;
    }
};