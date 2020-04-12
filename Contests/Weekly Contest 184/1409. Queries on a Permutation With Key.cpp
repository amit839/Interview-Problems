// https://leetcode.com/contest/weekly-contest-184/problems/queries-on-a-permutation-with-key/

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> pos(m);
        for(int i = 0; i < m; i++) pos[i] = i + 1;
        
        int n = queries.size();
        vector<int> output(n);
        
        for(int i = 0; i < n; i++){
            int val = queries[i];
            
            for(int j = 0; j < m; j++){
                if(pos[j] == val){
                    output[i] = j;
                    for(int k = j; k > 0; k--){
                        pos[k] = pos[k - 1];
                    }
                    pos[0] = val;
                    break;
                }
            }
        }
        return output;
    }
};