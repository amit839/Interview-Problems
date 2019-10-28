// https://leetcode.com/contest/weekly-contest-160/problems/circular-permutation-in-binary-representation/

class Solution {
public:
    
    vector<int> circularPermutation(int n, int start) {
        
        int m = pow(2, n), count = 1;
        vector<bool> pre(m);
        vector<int> output;
        
        pre[start] = 1;
        output.push_back(start);
        
        while(true){
            if(count == m) break;
            
            for(int i = 0; i < n; i++){
                start ^= (1 << i);
                if(!pre[start]){
                    pre[start] = 1;
                    output.push_back(start);
                    count++;
                    break;
                }
                start ^= (1 << i);
            }
        }
        
        return output;
    }
};