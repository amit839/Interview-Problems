class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        
        while(k--){
            int prev = grid[n - 1][m - 1];
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    int val = grid[i][j];
                    grid[i][j] = prev;
                    prev = val;
                }
            }
        }
        return grid;
    }
};