//https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0, ans = 1;
        for(auto x: nums) {
            sum += x;
            if(sum < 1) ans = min(ans, sum);
        }
        if(ans < 1) return abs(ans) + 1;
        return 1;
    }
};