//  https://leetcode.com/contest/weekly-contest-162/problems/reconstruct-a-2-row-binary-matrix/

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        vector<vector<int>> output(2, vector<int>(n));
        bool found = 1;
        
        for(int i = 0; i < n; i++){
            if(colsum[i] == 0) continue;
            if(colsum[i] == 1){
                if(upper > 0 and upper >= lower) {
                    output[0][i] = 1;
                    upper--;
                }
                else if(lower > 0 and lower >= upper){
                    output[1][i] = 1;
                    lower--;
                }
                else {
                    found = 0;
                    break;
                }
            }
            else {
                if(upper > 0) {
                    output[0][i] = 1, upper--;
                }
                else found = 0;
                
                if(lower > 0) {
                    output[1][i] = 1, lower--;
                }
                else found = 0;
            }
        }
        if(found and (upper == 0 and lower == 0)) return output;
        else return {};
    }
};