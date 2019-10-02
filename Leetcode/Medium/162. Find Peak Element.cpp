// Link to the problem : https://leetcode.com/problems/find-peak-element/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
       
        int n = nums.size();
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        
        int st = 1, ed = n-2, mid;
        while(st<=ed){
            mid = (st+ed)>>1;
            if(nums[mid]>nums[mid-1] and nums[mid]>nums[mid+1]) return mid;
            if(nums[mid]>nums[mid-1] and nums[mid]<nums[mid+1]) st = mid+1;
            else ed = mid - 1;
        }
        
        return 0;
    }
};