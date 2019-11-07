// Link to the problem statement : https://leetcode.com/problems/path-with-maximum-gold/

int dr[] = {0, -1, 0, 1};
int dc[] = {-1, 0, 1, 0};

int ans;

class Solution {
public:
    
    void go(int i, int j, int& n, int& m, vector<vector<int>>& grid, vector<vector<bool>>& visited, int tans){
        ans = max(ans, tans);
        
        if(i >= n or j >= m or i < 0 or j < 0 or visited[i][j] or grid[i][j] == 0) return;
        
        visited[i][j] = true;
        tans += grid[i][j];
        
        for(int k = 0; k < 4; k++){
            int x = i + dr[k], y = j + dc[k];
            go(x, y, n, m, grid, visited, tans);
        }
        visited[i][j] = false;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        ans = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                vector<vector<bool>> visited(n, vector<bool>(m, false));
                int tans = 0;
                go(i, j, n, m, grid, visited, tans);
            }
        }
        
        return ans;
    }
};