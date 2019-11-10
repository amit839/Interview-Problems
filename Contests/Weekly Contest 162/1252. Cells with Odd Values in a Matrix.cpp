// https://leetcode.com/contest/weekly-contest-162/problems/cells-with-odd-values-in-a-matrix/

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int>> arr(n, vector<int>(m));
        for(auto x: indices){
            int row = x[0], col = x[1];
            for(int i = 0; i < n; i++){
                arr[i][col]++;
            }
            for(int j = 0; j < m; j++){
                arr[row][j]++;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(arr[i][j] & 1) ans++;
            }
        }
        return ans;
    }
};