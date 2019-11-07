// Link to the problem statement: https://leetcode.com/contest/weekly-contest-155/problems/minimum-absolute-difference/

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> output;
        int mindiff = INT32_MAX;
        int n = arr.size();
        
        for(int i = 1; i < n; i++){
            mindiff = min(mindiff, arr[i] - arr[i - 1]);
        }
        for(int i = 1; i < n; i++){
            if(arr[i] - arr[i - 1] == mindiff){
                output.push_back({arr[i - 1], arr[i]});
            }
        }
        return output;
    }
};