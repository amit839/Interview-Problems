// Link to the problem : https://leetcode.com/problems/split-array-largest-sum/

class Solution {
public:
    
    bool divideArr(vector<int>& nums, int m, long long maxsum){
        int n = nums.size(), ct = 1, i = 0;
        long long sum = 0;
        while(i < n){
            sum += nums[i];
            if(sum > maxsum) {
                ct++;
                sum = nums[i];
                if(sum > maxsum) return false;
            }
            i++;
        }
        if(sum > maxsum) ct++;
        return ct <= m;
    }
    
    long long splitArray(vector<int>& nums, int m) {
        long long msum = accumulate(nums.begin(), nums.end(), 0LL);
        long long low = 1, high = msum, mid;
        
        while(low <= high){
            mid = (low + high) >> 1;
            
            bool outcome = divideArr(nums, m, mid);
            if(outcome){
                bool outcome1 = divideArr(nums, m, mid - 1);
                if(!outcome1) return mid;
                else high = mid - 1;
            }
            else low = mid + 1;
        }
        return 0;
    }
};