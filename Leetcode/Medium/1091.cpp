// Link to the problem statement : https://leetcode.com/problems/shortest-path-in-binary-matrix/

struct cell{
    int i, j, dist;
    cell(int a, int b, int c): i(a), j(b), dist(c){}
};

int dr[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dc[] = {-1 , -1, 0, 1, 1, 1, 0, -1};

class Solution {
        
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> val(n, vector<int>(m, INT32_MAX));
        
        queue<cell> q;
        if(grid[0][0]) return -1;
        
        cell temp(0,0,1);
        q.push(temp);
        
        val[0][0] = 1;
        
        while(!q.empty()){
            temp = q.front();
            q.pop();
            
            for(int k = 0; k < 8; k++){
                int x = temp.i + dr[k], y = temp.j + dc[k], distance = temp.dist + 1;
                
                if(x < 0 or x >= n or y < 0 or y >=m or grid[x][y] == 1 or val[x][y] <= distance) continue;
                
                val[x][y] = distance;
                q.push({x, y, distance});
            }
            
        }
        
        return val[n - 1][m - 1] == INT32_MAX ? -1 : val[n - 1][m - 1];
    }
};