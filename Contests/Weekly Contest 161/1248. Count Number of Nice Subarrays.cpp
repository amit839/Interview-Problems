// https://leetcode.com/problems/count-number-of-nice-subarrays/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        vector<int> pos;
        for(int i = 0; i < n; i++) if(nums[i] & 1) pos.push_back(i);
        int m = pos.size();
        int prev = -1;
        int i = 0, j = k - 1;
        while(j < m){
            int right = n;
            if(j + 1 < m) right = pos[j + 1];
            ans += (pos[i] - prev) * (right - pos[j]);
            prev = pos[i];
            i++, j++;
        }
        return ans;
    }
};