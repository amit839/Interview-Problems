// https://leetcode.com/contest/weekly-contest-160/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

int ans;

class Solution {
public:
    
    void go(int i, int n, vector<int>& sequence, vector<string>& arr){
        if(i == n){
            int freq[26] = {0};
            for(auto x: sequence){
                for(auto y : arr[x]){
                    freq[y - 'a']++;
                    if(freq[y - 'a'] > 1) return;
                }
            }
            int ct = 0;
            for(int k = 0; k < 26; k++) if(freq[k]) ct++;
            ans = max(ans, ct);
            return;
        }
        go(i + 1, n, sequence, arr);
        sequence.push_back(i);
        go(i + 1, n, sequence, arr);
        sequence.pop_back();
        
    }
    
    int maxLength(vector<string>& arr) {
        ans = 0;
        int n = arr.size();
        vector<int> sequence;
        
        go(0, n, sequence, arr);
        
        return ans;
    }
};