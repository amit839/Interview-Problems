// https://leetcode.com/contest/weekly-contest-192/problems/the-k-strongest-values-in-an-array/

class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        vector<int> output;
        int n = arr.size();
        int i = 0, j = n - 1;
        int median = arr[(n - 1) / 2];
        
        while(i <= j){
            int a = abs(arr[j] - median), b = abs(arr[i] - median);
            if(a >= b) output.push_back(arr[j]), j--;
            else output.push_back(arr[i]), i++;
        }
        vector<int> out;
        for(int i = 0; i < k; i++) out.push_back(output[i]);
        return out;
    }
};