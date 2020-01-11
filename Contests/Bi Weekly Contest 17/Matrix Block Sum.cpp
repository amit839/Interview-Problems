// https://leetcode.com/problems/matrix-block-sum/

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int n = mat.size(), m = mat[0].size();
        
        vector<vector<int>> output(n, vector<int>(m));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int startRow = max(0, i - K), endRow = min(n - 1, i + K);
                int startCol = max(0, j - K), endCol = min(m - 1, j + K);
                for(int p = startRow; p <= endRow; p++){
                    for(int q = startCol; q <= endCol; q++){
                        output[i][j] += mat[p][q];
                    }
                }
            }
        }
        
        return output;
    }
};