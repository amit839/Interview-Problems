// https://leetcode.com/problems/subsets/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> output;
    vector<int> arr;
    
    void go(int i, vector<int>& temp){
        if(i == n) {
            output.push_back(temp);
            return;
        }
        go(i + 1, temp);
        temp.push_back(arr[i]);
        go(i + 1, temp);
        temp.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        set<int> dist(nums.begin(), nums.end());
        arr.assign(dist.begin(), dist.end());
        output.assign({});
        n = arr.size();
        
        vector<int> temp;
        go(0, temp);
        return output;
    }
};

