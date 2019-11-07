// Link to the problem statement : https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<string,int> mp1;
        int n = matrix.size(), m = matrix[0].size();
        
        for(int i = 0; i < n; i++){
            string hash1, hash2;
            for(int j = 0; j < m; j++){
                hash1 += matrix[i][j] == 1 ? '1' : '0';
                hash2 += matrix[i][j] == 1 ? '0' : '1';
            }
            mp1[hash1]++;
            mp1[hash2]++;
        }
        int ans = 0;
        for(auto x: mp1){
            ans = max(ans, x.second);
        }
        
        return ans;
    }
};