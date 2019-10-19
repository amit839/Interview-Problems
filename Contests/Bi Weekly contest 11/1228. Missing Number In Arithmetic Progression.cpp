// https://leetcode.com/contest/biweekly-contest-11/problems/missing-number-in-arithmetic-progression/

class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int sum = (n + 1) * ( arr[0] + arr[n - 1]) / 2;
        for(auto x: arr) sum -= x;
        return sum;
    }
};