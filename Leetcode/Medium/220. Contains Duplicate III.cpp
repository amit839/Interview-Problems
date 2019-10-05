// Link to the problem statement : https://leetcode.com/problems/contains-duplicate-iii/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        for(int i = 0; i < n ;i++){
            for(int j = i+1;j<=min(n-1,i+k);j++){
                long long val = abs((long long)nums[j]-nums[i]);
                
                if(val<=t) return true;
            }
        }
        return false;
    }
};