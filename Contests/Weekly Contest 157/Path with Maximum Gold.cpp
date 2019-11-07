/*
Problem: Path with Maximum Gold

Difficulty:Medium
In a gold mine grid of size m * n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

Every time you are located in a cell you will collect all the gold in that cell.
From your position you can walk one step to the left, right, up or down.
You can't visit the same cell more than once.
Never visit a cell with 0 gold.
You can start and stop collecting gold from any position in the grid that has some gold.
 

Example 1:

Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
Output: 24
Explanation:
[[0,6,0],
 [5,8,7],
 [0,9,0]]
Path to get the maximum gold, 9 -> 8 -> 7.
Example 2:

Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
Output: 28
Explanation:
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.
 

Constraints:

1 <= grid.length, grid[i].length <= 15
0 <= grid[i][j] <= 100
There are at most 25 cells containing gold.

*/

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