// https://leetcode.com/problems/product-of-array-except-self/

// Method 1 : Time Complexity O(N) , Space Complexity O(N)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n), suffix(n);
        prefix[0] = nums[0];
        suffix[n - 1] = nums[n - 1];
        for(int i = 1; i < n; i++){
            prefix[i] = nums[i] * prefix[i - 1];
        }
        for(int i = n - 2; i > -1; i--){
            suffix[i] = nums[i] * suffix[i + 1];
        }
        vector<int> output(n);
        output[0] = suffix[1];
        output[n - 1] = prefix[n - 2];
        
        for(int i = 1; i < n - 1; i++){
            output[i] = prefix[i - 1] * suffix[i + 1];
        }
        return output;
    }
};

// Method 2 : Time Complexity O(N), Space Complexity O(1)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n);
        
        int p = 1;
        
        for(int i = 0; i < n; i++){
            output[i] = p;
            p *= nums[i];
        }
        p = 1;
        for(int i = n - 1; i > -1; i--){
            if(i < n - 1) output[i] *= p;
            p *= nums[i];
        }
        return output;
    }
};