// https://leetcode.com/problems/top-k-frequent-elements/

// Method 1 : Time Complexity O(N log(N))

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = mp.size();
        for(auto x: nums) mp[x]++;
        
        vector<int> output;
        
        priority_queue<pair<int,int>> pq;
        
        for(auto x: mp){
            pq.push({x.second, x.first});
        }
        
        while(k--){
            output.push_back(pq.top().second);
            pq.pop();
        }
        
        return output;
    }
};

// Method 2 : Time Complexity O(N log(M - K)) where M is distinct elements in array

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        
        for(auto x: nums) mp[x]++;
        int n = mp.size();
        vector<int> output;
        
        priority_queue<pair<int,int>> pq;
        
        for(auto x: mp){
            pq.push({x.second, x.first});
            if(pq.size() > n - k ){
                output.push_back(pq.top().second);
                pq.pop();
            }
        }
        
        
        return output;
    }
};