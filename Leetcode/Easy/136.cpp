//  https://leetcode.com/problems/single-number/submissions/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorSum = 0;
        for(auto x: nums) xorSum ^= x;
        return xorSum;
    }
};