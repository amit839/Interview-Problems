//  https://leetcode.com/problems/array-transformation/

class Solution {
public:
    bool check(vector<int>& a, vector<int>& b){
        int n = a.size();
        for(int i = 0; i < n; i++){
            if(a[i] != b[i]) return false;
        }
        return true;
    }
    
    vector<int> transformArray(vector<int>& a) {
        int n = a.size();
        vector<int> b(n);
        b[0] = a[0], b[n - 1] = a[n - 1];
        
        while(true){
            for(int i = 1; i < n - 1; i++){
                if(a[i] < a[i - 1] and a[i] < a[i + 1]) b[i] = a[i] + 1;
                else if(a[i] > a[i - 1] and a[i] > a[i + 1]) b[i] = a[i] - 1;
                else b[i] = a[i];
            }
            if(check(a, b)) return b;
            a = b;
        }
        return b;
    }
};