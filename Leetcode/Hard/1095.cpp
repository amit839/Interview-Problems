// Link to the problem statement : https://leetcode.com/problems/find-in-mountain-array/

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int st = 0, ed = n - 1, mid;
        
        int mountIndex = -1, mynum;
        while(st <= ed){
            mid = (st + ed) >> 1;
            
            int val = mountainArr.get(mid);
            if(mid - 1 >= 0 and mid + 1 < n){
                int leftval = mountainArr.get(mid - 1);
                int rightval = mountainArr.get(mid + 1);
                
                if(val > leftval and val > rightval){
                    mountIndex = mid;
                    mynum = val;
                    break;
                }
                else if(val > leftval and val < rightval) st = mid + 1;
                else ed = mid - 1;
            }
            else if(mid - 1 >= 0){
                int leftval = mountainArr.get(mid - 1);
                if(val > leftval){
                    mountIndex = mid;
                    mynum = val;
                    break;
                }
                else ed = mid - 1;
            }
            else if(mid + 1 < n){
                int rightval = mountainArr.get(mid + 1);
                if(val > rightval){
                    mountIndex = mid;
                    mynum = val;
                    break;
                }
                else st = mid + 1;
            }
        }
        
        
        st = 0 , ed = mountIndex;
        while(st <= ed){
            mid = (st + ed) >> 1;
            int val = mountainArr.get(mid);
            
            if(val == target) return mid;
            else if(val < target) st = mid + 1;
            else ed = mid - 1;
        }
        st = mountIndex + 1 , ed = n - 1;
        while(st <= ed){
            mid = (st + ed) >> 1;
            int val = mountainArr.get(mid);
            
            if(val == target) return mid;
            else if(val > target) st = mid + 1;
            else ed = mid - 1;
        }
        
        return -1;
    }
};