// https://leetcode.com/contest/weekly-contest-158/problems/maximum-equal-frequency/

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int n = nums.size(), ans = 2;
        map<int,int> freq;
        map<int, set<int>> bucket;
        set<int> dist;

        int newid = -1, sz = 0;

        for(int i = 0; i < n; i++){
            dist.insert(nums[i]);
            freq[nums[i]]++;
            int val = freq[nums[i]];

            if(newid == val - 1){
                sz--;
            }
            bucket[val - 1].erase(nums[i]);
            bucket[val].insert(nums[i]);


            int dSize = dist.size();

            if(bucket[val].size() >= sz){
                sz = bucket[val].size();
                newid = val;
            }
            if(dSize - sz == 1){
                if(bucket[1].size() == 1 or bucket[newid + 1].size() == 1){
                    ans = max(ans, i + 1);
                }
            }
            else if(dSize == sz){
                if(newid == 1 or newid == i + 1) ans = max(ans, i + 1);
            }
        }

        return ans;
    }
};