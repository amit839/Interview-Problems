// Link to the problem : https://leetcode.com/problems/word-search/

int dr[] = {0, -1, 0, 1};
int dc[] = {-1, 0, 1, 0};

class Solution {
public:
      
    bool findWord(int i, int j, int id, int n, string& word, vector<vector<char>>& board){
        
        if(id == n) return true;
        
        if(i < 0 or j < 0 or i >= board.size() or j >= board[0].size()) return false;
        
        if(word[id] != board[i][j]) return false;
        
        board[i][j] ^= 1234;
        
        for(int k = 0; k < 4; k++){
            int r = dr[k] + i, c = dc[k] + j;
            
            if(findWord(r, c, id + 1, n, word, board)) return true;
            
        }
        board[i][j] ^= 1234;
        return false;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
       
        int n = board.size(), m = board[0].size();
        
        int p = word.size();
        if(p == 0) return true;
        
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                if(findWord(i, j, 0, p, word, board)) return true;
            }
        }    
        return false;
    }
};