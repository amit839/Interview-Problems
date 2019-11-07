// https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> output;
        int n = matrix.size();
        if(n == 0) return output;
        int m = matrix[0].size();
        int rowStart = 0, rowEnd = n - 1, colStart = 0, colEnd = m - 1;
        
        while(rowStart <= rowEnd and colStart <= colEnd){
            for(int j = colStart; j <= colEnd; j++){
                output.push_back(matrix[rowStart][j]);
            }
            rowStart++;
            if(rowStart > rowEnd) break;
            for(int i = rowStart; i <= rowEnd; i++){
                output.push_back(matrix[i][colEnd]);
            }
            colEnd--;
            if(colStart > colEnd) break;
            for(int j = colEnd; j >= colStart; j--){
                output.push_back(matrix[rowEnd][j]);
            }
            rowEnd--;
            if(rowStart > rowEnd) break;
            for(int i = rowEnd; i >= rowStart; i--){
                output.push_back(matrix[i][colStart]);
            }
            colStart++;
        }
        return output;
    }
};