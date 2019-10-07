// Link to the problem statement : https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;
        vector<int> steps(n,0);
        int furthest = 0; 
        for(int i = 0; i < n; ++i) {
            if(nums[i] + i >= n-1) {
              
                return steps[i]+1;
            }
            if(nums[i] + i > furthest) { 
                int start = furthest+1 < n?furthest+1:n-1;
                int end = nums[i]+i+1< n?nums[i]+i+1:n-1;
                int step = 1 + steps[i];
                fill(steps.begin()+start, steps.begin()+end, step);
                furthest = nums[i] + i;
            }
        }
        return nums[n-1];
    }
};