// https://leetcode.com/contest/weekly-contest-192/problems/shuffle-the-array/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> output(2 * n);
        int i = 0, j = n, k = 0;
        while(i < n){
            output[k] = nums[i];
            output[k + 1] = nums[j];
            i++, j++, k+=2;
        }
        return output;
    }
};