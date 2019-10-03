// Link to the problem statement : https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        const int n = arr.size();
        int answer = arr[0];
        int suff_no_del = arr[0];
        int suff_one_del = 0;
        
        for(int i = 1; i < n; i++){
            suff_one_del = max(arr[i] + suff_one_del, suff_no_del);
            suff_no_del = max(suff_no_del + arr[i], arr[i]);
            answer = max({answer, suff_no_del, suff_one_del});
        }
        
        return answer;
    }
};