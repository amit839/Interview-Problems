// https://leetcode.com/problems/decompress-run-length-encoded-list/

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int n = nums.size();
        vector<int> output;
        for(int i = 0; i < n; i += 2){
            int freq = nums[i];
            int val = nums[i + 1];
            while(freq--){
                output.push_back(val);
            }
        }
        return output;
    }
};