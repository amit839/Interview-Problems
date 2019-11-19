class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> arr(3);
        for(auto x: nums){
            arr[x % 3].push_back(x);
        }
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if(sum % 3 == 0) return sum;
        
        int ans = 0;
        
        if(sum % 3 == 1){
            if(arr[1].size() > 0)
                ans = max(ans, sum - arr[1][0] );
            
            if(arr[2].size() > 1)
                ans = max(ans, sum - arr[2][0] - arr[2][1]);
        }
        else{
            if(arr[1].size() > 1)
                ans = max(ans, sum - arr[1][0] - arr[1][1]);
            
            if(arr[2].size() > 0)
                ans = max(ans, sum - arr[2][0]);
        }
        return ans;
        
    }
};