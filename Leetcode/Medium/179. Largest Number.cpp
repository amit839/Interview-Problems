// https://leetcode.com/problems/largest-number/

bool comp(string a, string b){
    string c = a + b, d = b + a;
    return stoll(c) > stoll(d);
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> input;
        for(auto x: nums) input.push_back(to_string(x));
        
        sort(input.begin(), input.end(), comp);
        
        string output;
        for(auto x: input) output += x;
        
        int id = 0;
        while(id < output.size() and output[id] == '0') id++;
        
        return id == output.size() ? "0" : output.substr(id);
    }
};