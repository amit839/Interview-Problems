//  https://leetcode.com/contest/weekly-contest-162/problems/number-of-closed-islands/ 

int dr[] = {0, -1, 0, 1};
int dc[] = {-1, 0, 1, 0};

class Solution {
public:
    
    int n, m;
    vector<vector<bool>> visited;
    
    void dfs(int i, int j, vector<vector<int>>& grid){
        if(i < 0 or j < 0 or i >= n or j >= m or visited[i][j] or grid[i][j] == 1) return;
        
        visited[i][j] = 1;
        for(int k = 0; k < 4; k++){
            int x = i + dr[k], y = j + dc[k];
            dfs(x, y, grid);
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        vector<pair<int,int>> pos;
        n = grid.size(), m = grid[0].size();
        visited = vector<vector<bool>>(n, vector<bool>(m, 0));
        
        vector<pair<int,int>> boundary;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!grid[i][j]) {
                    if(i == 0 or i == n - 1 or j == 0 or j == m - 1) boundary.push_back({i, j});
                    else pos.push_back({i, j});
                }
            }
        }
        // Doing a DFS from all the boundary lands
        for(auto x: boundary){
            int i = x.first, j = x.second;
            if(!visited[i][j]) {
                dfs(i, j, grid);
            }
        }
        int ans = 0;
        
        // Counting the connected components using DFS
        for(auto x: pos){
            int i = x.first, j = x.second;
            if(!visited[i][j]){
                dfs(i, j, grid);
                ans++;
            }
        }
        return ans;
    }
};