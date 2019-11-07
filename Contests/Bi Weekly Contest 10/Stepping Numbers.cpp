Problem : Stepping Numbers

Difficulty:Medium
A Stepping Number is an integer such that all of its adjacent digits have an absolute difference of exactly 1. For example, 321 is a Stepping Number while 421 is not.

Given two integers low and high, find and return a sorted list of all the Stepping Numbers in the range [low, high] inclusive.

Example 1:

Input: low = 0, high = 21
Output: [0,1,2,3,4,5,6,7,8,9,10,12,21]
 

Constraints:

0 <= low <= high <= 2 * 10^9

class Solution {
public:
    
    void generateAll(int i, int n, set<int>& output, int& low, int& high, string input){
        if(i == n){
            long long val = stol(input);
            if(val >= low and val <= high and output.find(val) == output.end()) output.insert(val);
            return;
        }
        int val = input[i - 1] - '0';
        if(val > 0)
            generateAll(i + 1, n, output, low, high, input + to_string(val - 1));
        if(val < 9)
            generateAll(i + 1, n, output, low, high, input + to_string(val + 1));
    }

    vector<int> countSteppingNumbers(int low, int high) {
        set<int> output;
        string input = "";
        for(int i = 1; i < 11; i++)
            for(char j = '0'; j <= '9'; j++)
                generateAll(1, i, output, low, high, input + j);

        vector<int> output2(output.begin(), output.end());

        return output2;
    }
};