// https://leetcode.com/contest/weekly-contest-158/problems/queens-that-can-attack-the-king/

int dr[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dc[] = {-1, -1, 0, 1, 1, 1, 0, -1};

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        int n = queens.size();
        vector<vector<bool>> pos(8, vector<bool>(8, false));
        for(auto x: queens){
            pos[x[0]][x[1]] = true;
        }
        vector<vector<int>> output;
        
        int x = king[0], y = king[1];
        
        for(int k = 0; k < 8; k++){
            int i = x + dr[k], j = y + dc[k];
            while(i >= 0 and j >= 0 and i < 8 and j < 8){
                if(pos[i][j]){
                    output.push_back({i, j});
                    break;
                }
                i += dr[k];
                j += dc[k];
            }
        }
        
        return output;
        
    }
};