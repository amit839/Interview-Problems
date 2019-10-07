// Link to the problem statement : https://leetcode.com/problems/increasing-triplet-subsequence/

// Time Complexity -> O(n), Space Complexity -> O(n)

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n), suffix(n);
        for(int i = 0; i < n; i++){
            if(i == 0) prefix[i] = nums[i];
            else prefix[i] = min(prefix[i - 1], nums[i]);
        }
        for(int i = n - 1; i >= 0; i--){
            if(i == n - 1) suffix[i] = nums[i];
            else suffix[i] = max(suffix[i + 1], nums[i]);
        }
        for(int i = 1; i < n - 1; i++){
            if(nums[i] > prefix[i - 1] and nums[i] < suffix[i + 1]) return true;
        }
        return false;
    }
};

// Time Complexity -> O(n), Space Complexity -> O(1)

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int small = INT32_MAX, big = INT32_MAX;
        for(auto x: nums){
            if(x <= small) small = x;
            else if(x <= big) big = x;
            else return true;
        }
        return false;
    }
};