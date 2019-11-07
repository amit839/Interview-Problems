// link to the problem statement : https://leetcode.com/contest/weekly-contest-152/problems/can-make-palindrome-from-substring/

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int m = queries.size(), n = s.size();
        vector<bool> output(m, false);
        
        vector<vector<int>> arr(n, vector<int>(26, 0));
        
        for(int i = 0; i < n; i++){
            arr[i][s[i]-'a']++;
            for(int j = 0; j < 26; j++){
                if(i > 0) arr[i][j] += arr[i - 1][j];
            }
        }
        
        for(int i = 0; i < m; i++){
            int st = queries[i][0], ed = queries[i][1], comp = queries[i][2];
            int oddct = 0;
            for(int j = 0; j < 26; j++){
                if(st > 0) {
                    if((arr[ed][j] - arr[st - 1][j]) % 2 != 0) oddct++;
                }
                else if(arr[ed][j] % 2 != 0) oddct++;
            }
            oddct /= 2;
            
            if(comp >= oddct) output[i] = true;
        }
        return output;
    }
};