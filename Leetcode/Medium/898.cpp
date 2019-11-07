// Link to the problem statement: https://leetcode.com/problems/bitwise-ors-of-subarrays/

// O(n) solution


class Solution {
public:
        
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> result, previous, current;
        for (int i: A) {
            current = {i};
            for (int j: previous) current.insert(i|j);
            previous = current;
            for (int j: previous) result.insert(j);
        }
        return result.size();
    }
};