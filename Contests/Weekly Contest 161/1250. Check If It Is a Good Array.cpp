// https://leetcode.com/problems/check-if-it-is-a-good-array/

class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int g = nums[0];
        int n = nums.size();
        for(int i = 1; i < n; i++) g = __gcd(g, nums[i]);
        return g == 1;
    }
};