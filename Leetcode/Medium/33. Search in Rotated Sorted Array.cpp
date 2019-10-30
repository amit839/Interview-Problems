// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    
    int binarySearch(vector<int>& nums, int st, int ed, int target){
        int mid;
        while(st <= ed){
            mid = (st + ed) >> 1;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) st = mid + 1;
            else ed = mid - 1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int id = -1, st, mid, ed, n = nums.size();
        bool found = false;
        st = 1, ed = n - 1;
        while(st <= ed){
            mid = (st + ed) >> 1;
            if(nums[mid] < nums[0]){
                if(nums[mid - 1] >= nums[0]) {
                    id = mid;
                    found = true;
                    break;
                } 
                else ed = mid - 1;
            }
            else st = mid + 1;
        }
        
        if(!found){
            return binarySearch(nums, 0, n - 1, target);
        }
        else {
            
            int ans = binarySearch(nums, 0, id - 1, target);
            if(ans != -1) return ans;
            return binarySearch(nums, id, n - 1, target);
        }
    }
};