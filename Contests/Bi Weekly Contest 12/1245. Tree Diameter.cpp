// https://leetcode.com/problems/tree-diameter/

int ans;

class Solution {
public:
    
    int dfs(int id, int parent, vector<vector<int>>& edges){
        
        int max1 = 0, max2 = 0;
        for(auto x: edges[id]){
            if(x == parent) continue;
            
            int temp = dfs(x, id, edges);
            
            if(temp > max1){
                max2 = max1;
                max1 = temp;
            }
            else if(temp > max2){
                max2 = temp;
            }
        }
        ans = max(ans, max1 + max2 + 1);
        return max(max1, max2) + 1;
    }
    
    int treeDiameter(vector<vector<int>>& a) {
        int n = a.size() + 1;
        vector<vector<int>> edges(n + 1);
        for(auto x: a){
            edges[x[0]].push_back(x[1]);
            edges[x[1]].push_back(x[0]);
        }
        ans = 0;
        dfs(0, -1, edges);
        
        return ans - 1;
    }
};